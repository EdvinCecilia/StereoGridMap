#ifndef SIMPLE_POINT_CLOUD_H
#define SIMPLE_POINT_CLOUD_H

#include <vector>

/**
 * @brief 简单的点云数据结构，包含每个点的三维坐标和置信度。
 */
struct PointXYZConfidence {
    float x, y, z; // The coordinates of the point.
    uint8_t confidence; // The confidence level of the point.
};

/**
 * @brief 简单的点云数据类型，是一系列 SimplePoint 结构的集合。
 */
struct SimplePointCloud {
    std::vector<PointXYZConfidence> points; // A vector to store multiple points.

    // Add a point to the point cloud.
    void addPoint(const PointXYZConfidence& point) {
        points.push_back(point);
    }

    // Assuming there's a need to calculate the average height for each point.
    float getAverageHeight() const {
        if (points.empty()) return 0.0f;
        
        float total_height = 0.0f;
        for (const auto& point : points) {
            total_height += point.z; // Assuming 'z' is the height component.
        }
        return total_height / points.size();
    }
};

#endif // SIMPLE_POINT_CLOUD_H
