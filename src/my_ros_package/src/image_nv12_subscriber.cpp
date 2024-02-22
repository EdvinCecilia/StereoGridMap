#include <rclcpp/rclcpp.hpp>
#include <opencv2/opencv.hpp>
#include "custom_msgs/msg/image_nv12.hpp"  // 替换为您自定义消息的实际路径
#include <cv_bridge/cv_bridge.h>
#include <sensor_msgs/msg/image.hpp>
#include <cstdint>
#include <algorithm>
using namespace std;
using namespace cv;

uint8_t data_buff[1280 * 960 * 2] = {0}; // 根据实际需要调整缓冲区大小


struct MinMaxAverage {
    float min;
    float max;
    float average;
};


MinMaxAverage calculateDepthStatistics(const uint16_t* disparityData, int width, int height, double focalLength, double baseline) {
    float maxDepth = 0;
    // std::cout << "maxDepth: " << maxDepth << std::endl;
    float minDepth = numeric_limits<float>::max();
    float sumDepth = 0;
    size_t validPixels = 0;
    size_t totalPixels = width * height;

    for (size_t i = 0; i < totalPixels; ++i) {
        uint16_t rawDisparity = disparityData[i];
        float disparity = (rawDisparity & 0x0fff) / 32.0f;
        if (disparity > 0) {
            float depth = (focalLength * baseline) / disparity;
            // std::cout << "Disparity: " << disparity << ", Depth: " << depth << std::endl;
            maxDepth = std::max(maxDepth, depth);
            if (depth > maxDepth) {
		std::cout << "New Max Depth: " << depth << " at Disparity: " << disparity << std::endl;
	    }
            minDepth = std::min(minDepth, depth);
            sumDepth += depth;
            validPixels++;
        }
    }

    float averageDepth = validPixels > 0 ? sumDepth / validPixels : 0;
    return {minDepth, maxDepth, averageDepth};
}


MinMaxAverage findMinMaxAndAverage(const uint16_t* data, size_t length) {
    if (data == nullptr || length == 0) {
        return {0, 0, 0}; // 防止空指针或空数组
    }

    uint32_t sum = 0;
    uint16_t max = data[0];
    uint16_t min = data[0];

    for (size_t i = 0; i < length; ++i) {
        sum += data[i];
        if (data[i] > max) {
            max = data[i];
        }
        if (data[i] < min) {
            min = data[i];
        }
    }

    float average = static_cast<float>(sum) / length;
    return {min, max, average};
}

cv::Mat raw_2_rgb(uint16_t *raw, int width, int height)
{

    size_t length = width * height;
    MinMaxAverage result = findMinMaxAndAverage(raw, length);
    // std::cout <<"sizeof(raw): " << sizeof(raw) << std::endl;
    // std::cout <<"Length: " << length << "Min: " << result.min << ", Max: " << result.max << ", Average: " << result.average << std::endl;
    
    cv::Mat img_pseudocolor = cv::Mat::zeros(height, width, CV_8UC3);//这使用opencv构造RGB图像
    int m_minDisp =0;
    int m_maxDisp = 20;
    float a1=(float)64/1009;
    float a2=(float)249/1009;
    float a3=(float)377/1009;
    float a4=(float)632/1009;
    float a5=(float)696/1009;
    float a6=(float)881/1009;
    float b1=(float)1009/64;
    float b2=(float)1009/185;
    float b3=(float)1009/128;
    float b4=(float)1009/255;
    float b5=(float)1009/64;
    float b6=(float)1009/185;

    for (int y = 0; y < height; y++)//转为伪彩色图像的具体算法
    {
      uchar* pColor = img_pseudocolor.ptr<uchar>(y);
      for (int x = 0; x < width; x++)
      {
        int baseByte = 3 * x;
        float temp = (raw[y * width + x] & 4095) / 32.0f ;
        if (temp <= m_minDisp)
        {
          temp = 0.0f;
        }
        else if (temp >= m_maxDisp)
        {
          temp=1.0f;
        }
        else
        {
          temp = float(temp/float(m_maxDisp));
        }

        //BGR 顺序
        if (temp < a1)
        {
          temp=float((temp-0)*b1);
          pColor[baseByte] =  uchar(min(max(temp,(float)0),(float)1)*255.0f);
          pColor[baseByte + 1] = 0;
          pColor[baseByte + 2] = 0;
        }
        else if (temp < a2)
        {
          temp=float((temp-a1)*b2);
          pColor[baseByte] = uchar(min(max((1-temp),(float)0),(float)1)*255.0f);
          pColor[baseByte + 1] = 0;
          pColor[baseByte + 2] = uchar(min(max(temp,(float)0),(float)1)*255.0f);
        }
        else if (temp < a3)
        {
          temp=float((temp-a2)*b3);
          pColor[baseByte] = uchar(min(max(temp,(float)0),(float)1)*255.0f);
          pColor[baseByte + 1] = 0;
          pColor[baseByte + 2] = 255;
        }
        else if (temp < a4)
        {
          temp=(float)((temp-a3)*b4);
          pColor[baseByte] = uchar(min(max(1-temp,(float)0),(float)1)*255.0f);
          pColor[baseByte + 1] = uchar(min(max(temp,(float)0),(float)1)*255.0f);
          pColor[baseByte + 2] = uchar(min(max(1-temp,(float)0),(float)1)*255.0f);
        }
        else if (temp < a5)
        {
          temp=(float)((temp-a4)*b5);
          pColor[baseByte] = uchar(min(max(temp,(float)0),(float)1)*255.0f);
          pColor[baseByte + 1] = 255;
          pColor[baseByte + 2] = 0;
        }
        else if(temp < a6)
        {
          temp=(float)((temp-a5)*b6);
          pColor[baseByte] = uchar(min(max(1-temp,(float)0),(float)1)*255.0f);
          pColor[baseByte + 1] = 255;
          pColor[baseByte + 2] = uchar(min(max(temp,(float)0),(float)1)*255.0f);
        }
        else
        {
          pColor[baseByte + 2] = 255;
        }
      }
    }
    return img_pseudocolor;
}

void convertEndian(uint16_t& value) {
    value = (value >> 8) | (value << 8);
    }


class ImageNv12Subscriber : public rclcpp::Node {
public:
    ImageNv12Subscriber() : Node("image_nv12_subscriber") {
        subscription_ = this->create_subscription<custom_msgs::msg::ImageNv12>(
            "/vision_diff", 10, std::bind(&ImageNv12Subscriber::topic_callback, this, std::placeholders::_1));
        publisher_ = this->create_publisher<sensor_msgs::msg::Image>("pseudo_color_image", 10);
    }

private:
    void topic_callback(const custom_msgs::msg::ImageNv12::SharedPtr msg) {
        // RCLCPP_INFO(this->get_logger(), "Received Image - Width: %d, Height: %d, Data Size: %zu",
         //           msg->width, msg->height, msg->data.size());

        // 检查图像尺寸是否符合预期
        if (msg->width * msg->height * 2 != sizeof(data_buff)) {
            RCLCPP_ERROR(this->get_logger(), "Image size does not match buffer size.");
            return;
        }

        // 使用 memcpy 复制数据到缓冲区
        memcpy(data_buff, msg->data.data(), msg->width * msg->height * 2);

        // 对缓冲区中的数据进行大小端转换
        uint16_t* data_ptr = reinterpret_cast<uint16_t*>(data_buff);
        for (int i = 0; i < msg->width * msg->height; ++i) {
            convertEndian(data_ptr[i]);
        }
        
        MinMaxAverage depthStats = calculateDepthStatistics(data_ptr, msg->width, msg->height, 1092.904615, 0.119549819);
        RCLCPP_INFO(this->get_logger(), "Depth - Min: %f, Max: %f, Average: %f",
                            depthStats.min, depthStats.max, depthStats.average);

        // 生成伪彩色图像
        cv::Mat pseudo_color_image = raw_2_rgb(data_ptr, msg->width, msg->height);

        // 使用 cv_bridge 转换并发布图像
        auto image_msg = cv_bridge::CvImage(std_msgs::msg::Header(), "bgr8", pseudo_color_image).toImageMsg();
        publisher_->publish(*image_msg);
    }

    rclcpp::Subscription<custom_msgs::msg::ImageNv12>::SharedPtr subscription_;
    rclcpp::Publisher<sensor_msgs::msg::Image>::SharedPtr publisher_;
};

int main(int argc, char* argv[]) {
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<ImageNv12Subscriber>());
    rclcpp::shutdown();
    return 0;
}


