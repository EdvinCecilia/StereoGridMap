#include "rclcpp/rclcpp.hpp"
#include "custom_msgs/msg/image_nv12.hpp"  // 替换为您的视差消息类型
#include "DisparityToPointCloud.h"
#include "GridMap.h"
#include "SimplePointCloud.h"
#include <opencv2/opencv.hpp>
#include <vector>
#include <cstdint>
#include <yaml-cpp/yaml.h>
#include <sensor_msgs/msg/image.hpp>
#include <cv_bridge/cv_bridge.h>

class DisparityProcessingNode : public rclcpp::Node {
public:
    DisparityProcessingNode()
    : Node("disparity_processing_node"){  
       loadConfig("/home/edvin/ros2_ws/src/my_ros_package/src/config.yaml");

       // 使用加载的配置来初始化对象
       converter = DisparityToPointCloud::createFromConfig(camera_fx, camera_fy, camera_cx, camera_cy, camera_baseline);
       gridMap = GridMap::createFromConfig(grid_width, grid_height, grid_resolution);
       image_pub_ = this->create_publisher<sensor_msgs::msg::Image>("/processed_image", 10);
       subscription_ = this->create_subscription<custom_msgs::msg::ImageNv12>(
            "/vision_diff", 10,
        std::bind(&DisparityProcessingNode::disparityCallback, this, std::placeholders::_1));
    }
    

private:
    void disparityCallback(const custom_msgs::msg::ImageNv12::SharedPtr msg) {
        const uint16_t* disparity_data = reinterpret_cast<const uint16_t*>(msg->data.data());
        int width = msg->width;
        int height = msg->height;

        // 执行大小端转换并生成点云
        std::vector<uint16_t> data_copy(disparity_data, disparity_data + width * height);
        for (auto& value : data_copy) {
            convertEndian(value);
        }
        SimplePointCloud cloud = converter->ConvertToPointCloud(data_copy, width, height);
        PointXYZConfidence maxCoords = cloud.getMaxCoordinates();
        PointXYZConfidence centroid = cloud.getCentroid();

        std::cout << "最大坐标：(" << maxCoords.x << ", " << maxCoords.y << ", " << maxCoords.z << ")" << std::endl;
        std::cout << "质心坐标：(" << centroid.x << ", " << centroid.y << ", " << centroid.z << ")" << std::endl;
        size_t numberOfPoints = cloud.getNumberOfPoints();
        std::cout << "点云中的点数量: " << numberOfPoints << std::endl;
        

        // 更新栅格地图
        gridMap->updateFromPointCloud(cloud, width, fov, 1);
        // gridMap->visualize(display_width, display_height);
        cv::Mat processed_image = gridMap->visualize(display_width, display_height);

        // 转换为 ROS 消息并发布
        sensor_msgs::msg::Image ros_image;
        cv_bridge::CvImage cv_image;
        cv_image.image = processed_image;
        cv_image.encoding = "bgr8";
        cv_image.toImageMsg(ros_image);
        image_pub_->publish(ros_image);

        // 可视化栅格地图
        //visualizeGridMap(gridMap);
    }

    void convertEndian(uint16_t& value) {
        value = (value >> 8) | (value << 8);
    }
    
    void loadConfig(const std::string& config_file) {
        YAML::Node config = YAML::LoadFile(config_file);

        // 加载相机参数
        camera_fx = config["camera"]["fx"].as<double>();
        camera_fy = config["camera"]["fy"].as<double>();
        camera_cx = config["camera"]["cx"].as<double>();
        camera_cy = config["camera"]["cy"].as<double>();
        camera_baseline = config["camera"]["baseline"].as<double>();

        // 加载栅格地图参数
        grid_width = config["grid_map"]["width"].as<int>();
        grid_height = config["grid_map"]["height"].as<int>();
        grid_resolution = config["grid_map"]["resolution"].as<float>();

        // 加载可视化参数
        fov = config["visualization"]["fov"].as<float>();
        display_width = config["visualization"]["display_width"].as<int>();
        display_height = config["visualization"]["display_height"].as<int>();
    }
    
    double camera_fx, camera_fy, camera_cx, camera_cy, camera_baseline;
    int grid_width, grid_height;
    float grid_resolution;
    float fov;
    int display_width, display_height;
    

    rclcpp::Subscription<custom_msgs::msg::ImageNv12>::SharedPtr subscription_;
    rclcpp::Publisher<sensor_msgs::msg::Image>::SharedPtr image_pub_;
    std::unique_ptr<DisparityToPointCloud> converter;
    std::unique_ptr<GridMap> gridMap;
};

int main(int argc, char* argv[]) {
    rclcpp::init(argc, argv);
    auto node = std::make_shared<DisparityProcessingNode>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}
