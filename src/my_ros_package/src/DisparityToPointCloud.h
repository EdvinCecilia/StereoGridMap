#ifndef DISPARITY_TO_POINT_CLOUD_H
#define DISPARITY_TO_POINT_CLOUD_H

#include <vector>
#include "SimplePointCloud.h"  // 自定义点云结构体的头文件
#include "GridMap.h"
#include <iostream>

typedef struct{
    uint32_t   head;          //0x55aa55aa
    uint8_t    type;
    uint8_t    command;
    uint8_t    action;
    uint32_t   timestamp;
}HEAD;

typedef struct{
    uint16_t width;
    uint16_t height;
    uint8_t  type;
    uint8_t  channels;
}NX2PC_INFO;

typedef struct{
    uint16_t id;
    uint8_t  complete;
    uint16_t number;
    uint16_t length;
    uint8_t  data[1200];
}NX2PC_DATA;

//接收相机发送的数据的结构体
typedef struct{
    HEAD          header;
    NX2PC_DATA    data;
    NX2PC_INFO    info;
}TCP_NX2PC_MSG;

/**
 * @class DisparityToPointCloud
 * @brief 从双目相机的视差图中生成点云，并转换为栅格地图的类。
 */
class DisparityToPointCloud {
public:
    /**
     * @brief 构造函数
     * @param fx 相机X轴的焦距
     * @param fy 相机Y轴的焦距
     * @param cx 相机X轴的光心
     * @param cy 相机Y轴的光心
     * @param baseline 双目相机的基线距离
     */
    DisparityToPointCloud(double fx, double fy, double cx, double cy, double baseline);
    
    
    // Static factory method
    static std::unique_ptr<DisparityToPointCloud> createFromConfig(double fx, double fy, double cx, double cy, double baseline) {
        return std::make_unique<DisparityToPointCloud>(fx, fy, cx, cy, baseline);
    }

    /**
     * @brief 将视差数据转换为点云
     * @param disparity_data 包含视差数据的结构体指针
     * @return 转换得到的点云
     */
    SimplePointCloud ConvertToPointCloud(const std::vector<uint16_t>& disparity_data, int width, int height);
    
    /**
     * @brief 更新栅格地图数据。
     * @param disparity_data 包含视差数据的 TCP_NX2PC_MSG 结构体指针。
     */
    void UpdateGridMap(GridMap& gridMap, const SimplePointCloud& cloud, float img_width, float fov, float beta_r);

private:
    double fx_, fy_, cx_, cy_, baseline_; // 相机参数
    float min_confidence_ = 0.5;
};

#endif // DISPARITY_TO_POINT_CLOUD_H
