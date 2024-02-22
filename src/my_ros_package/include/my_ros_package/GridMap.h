#ifndef GRIDMAP_H
#define GRIDMAP_H

#include "my_ros_package/SimplePointCloud.h"
#include <vector>
#include <cmath>

/**
 * @struct GridCell
 * @brief 表示栅格地图中的单个栅格
 *
 * 用于存储栅格的状态信息，如是否被占用、点的数量和平均高度。
 */
struct GridCell {
    bool occupied = false;   // 栅格是否被占用
    int count = 0;           // 栅格内点的数量
    float averageHeight = 0; // 栅格内所有点的平均高度
};

/**
 * @class GridMap
 * @brief 管理栅格地图的类
 *
 * 提供更新栅格地图状态的方法，基于点云数据处理栅格的占用情况。
 */
class GridMap {
public:
    /**
     * @brief 构造函数
     * @param width 栅格地图的宽度
     * @param height 栅格地图的高度
     * @param resolution 每个栅格的分辨率（单位：米）
     */
    GridMap(int width, int height, float resolution);

    /**
     * @brief 使用点云更新栅格地图
     * @param cloud 点云数据
     * @param img_width 图像的宽度
     * @param fov 摄像机视场角
     * @param beta_r 比例系数
     */
    void updateFromPointCloud(const SimplePointCloud& cloud, float img_width, float fov, float beta_r);

    /**
     * @brief 清空地图，重置所有栅格状态
     */
    void clearMap();

    /**
     * @brief 检查指定栅格是否被占用
     * @param x 栅格的x坐标
     * @param y 栅格的y坐标
     * @return 栅格是否被占用
     */
    bool isOccupied(int x, int y) const;

    /**
     * @brief 设置指定栅格的占用状态
     * @param x 栅格的x坐标
     * @param y 栅格的y坐标
     * @param occupied 栅格是否被占用
     */
    void setOccupied(int x, int y, bool occupied);

private:
    std::vector<std::vector<GridCell>> cells;
    int width_;
    int height_;
    float resolution_;

    /**
     * @brief 计算每个栅格的ar值
     * @param img_width 图像的宽度
     * @param fov 摄像机视场角
     * @return 包含每个栅格ar值的向量
     */
    std::vector<float> calculateArValues(float img_width, float fov);

    /**
     * @brief 找出最大点数的栅格索引
     * @param beta_r 比例系数
     * @param ar_values 包含每个栅格ar值的向量
     * @return 最大点数栅格的索引
     */
    int findMaxCountCell(float beta_r, const std::vector<float>& ar_values);

    /**
     * @brief 更新栅格的占用状态
     * @param beta_r 比例系数
     * @param ar_values 包含每个栅格ar值的向量
     */
    void adjustGridsByOccupancy(float beta_r, const std::vector<float>& ar_values);

    /**
     * @brief 统计每个栅格中的点数
     * @param cloud 点云数据
     */
    void countPointsInCells(const SimplePointCloud& cloud);

    /**
     * @brief 计算每个栅格的平均高度
     */
    void calculateAverageHeights();
};

#endif // GRIDMAP_H
