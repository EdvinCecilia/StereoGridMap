#ifndef SIMPLE_POINT_CLOUD_H
#define SIMPLE_POINT_CLOUD_H

#include <vector>
#include <cstdint>
#include<stdexcept>
#include<limits>

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
/**
 * @brief 简单的点云数据类型，是一系列 SimplePoint 结构的集合。
 */
struct SimplePointCloud {
    std::vector<PointXYZConfidence> points; // A vector to store multiple points.

    // Add a point to the point cloud.
    void addPoint(const PointXYZConfidence& point) {
        points.push_back(point);
    }

    // Get the maximum values of X, Y, Z coordinates in the point cloud.
    PointXYZConfidence getMaxCoordinates() const {
        PointXYZConfidence maxCoords;
        maxCoords.x = maxCoords.y = maxCoords.z = std::numeric_limits<float>::lowest();

        for (const auto& point : points) {
            if (point.x > maxCoords.x) maxCoords.x = point.x;
            if (point.y > maxCoords.y) maxCoords.y = point.y;
            if (point.z > maxCoords.z) maxCoords.z = point.z;
        }

        return maxCoords;
    }

    // Calculate the centroid of the point cloud.
    PointXYZConfidence getCentroid() const {
        PointXYZConfidence centroid;
        if (points.empty()) return centroid;

        float sumX = 0.0f, sumY = 0.0f, sumZ = 0.0f;
        for (const auto& point : points) {
            sumX += point.x;
            sumY += point.y;
            sumZ += point.z;
        }

        centroid.x = sumX / points.size();
        centroid.y = sumY / points.size();
        centroid.z = sumZ / points.size();
        return centroid;
    }
    
    size_t getNumberOfPoints() const {
	return points.size();
    }
};

#endif // SIMPLE_POINT_CLOUD_H
