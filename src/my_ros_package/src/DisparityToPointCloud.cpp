#include "DisparityToPointCloud.h"
#include <cmath>

// 构造函数初始化相机参数
DisparityToPointCloud::DisparityToPointCloud(double fx, double fy, double cx, double cy, double baseline)
    : fx_(fx), fy_(fy), cx_(cx), cy_(cy), baseline_(baseline) {}

// 根据视差信息转换为点云
SimplePointCloud DisparityToPointCloud::ConvertToPointCloud(const std::vector<uint16_t>& disparity_data, int width, int height) {
    SimplePointCloud cloud;
        for (int v = 0; v < height; ++v) {
            for (int u = 0; u < width; ++u) {
                uint16_t rawDisparity = disparity_data[v * width + u];
                float disparity = (rawDisparity & 0x0fff) / 32.0f;
                
                if (disparity == 0.0) continue;
                // std::cout << "disparity_value: " << disparity_value << std::endl;

                double depth = fx_ * baseline_ / disparity;
                PointXYZConfidence point;
                point.x = (u - cx_) * depth / fx_;
                point.y = (v - cy_) * depth / fy_;
                point.z = depth;
                // std::cout << "point.x: " << point.x << "  point.y: " << point.y << "  point.z:" << point.z << std::endl;
                // point.confidence = confidence;

                cloud.addPoint(point);
            }
        }
        return cloud;
}

// 更新栅格地图占用状态
void DisparityToPointCloud::UpdateGridMap(GridMap& gridMap, const SimplePointCloud& cloud, float img_width, float fov, float beta_r) {
    // 使用点云数据更新栅格地图的状态
    gridMap.updateFromPointCloud(cloud, img_width, fov, beta_r);
}
