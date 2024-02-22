#include "GridMap.h"

// 构造函数
GridMap::GridMap(int width, int height, float resolution)
    : width_(width), height_(height), resolution_(resolution) {
    cells.resize(height, std::vector<GridCell>(width));
}

// 使用点云更新栅格地图
void GridMap::updateFromPointCloud(const SimplePointCloud& cloud, float img_width, float fov, float beta_r) {
    try {
        if (fov <= 0 || beta_r <= 0) {
            throw std::invalid_argument("FOV and beta_r must be positive.");
        }
        clearMap();
        countPointsInCells(cloud);
        calculateAverageHeights();
        // 将FOV的一半从度数转换为弧度
        float half_fov_rad = fov / 2.0f * (M_PI / 180.0f);

        // 相机位于图像底部中心，朝向正上方
        float viewPointX = width_ / 2.0f;
        float viewPointY = height_; // 图像底部

        for (int y = 0; y < height_; ++y) {
            for (int x = 0; x < width_; ++x) {
                float relativeX = (x - viewPointX) * resolution_;
                float relativeY = viewPointY * resolution_ - y * resolution_;

                // 计算栅格与视场中心的水平角度
                float angle = std::atan2(std::abs(relativeX), relativeY);

                // 标记视场角以外的栅格为未知
                if (angle > half_fov_rad) {
                    cells[y][x].unknown = true;
                } else {
                    cells[y][x].unknown = false; // 视场角内的栅格标记为已知
                }
            }
        }

        std::vector<float> ar_values = calculateArValues(img_width, fov);
        adjustGridsByOccupancy(beta_r, ar_values);
    } catch (const std::exception& e) {
        std::cerr << "Error in updateFromPointCloud: " << e.what() << std::endl;
    }
}

// 清空地图，重置所有栅格状态
void GridMap::clearMap() {
    for (auto& row : cells) {
        for (auto& cell : row) {
            cell.occupied = false;
            cell.unknown = true;
            cell.count = 0;
            cell.averageHeight = 0;
        }
    }
}

bool GridMap::isUnknown(int x, int y) const {
    if (x < 0 || x >= width_ || y < 0 || y >= height_) {
        throw std::out_of_range("Grid coordinates out of range.");
    }
    return cells[y][x].unknown;
}

// 检查指定栅格是否被占用
bool GridMap::isOccupied(int x, int y) const {
    if (x < 0 || x >= width_ || y < 0 || y >= height_) {
        // 可以选择抛出异常或返回默认值
        throw std::out_of_range("Grid coordinates out of range.");
    }
    return cells[y][x].occupied;
}

// 设置指定栅格的占用状态
void GridMap::setOccupied(int x, int y, bool occupied) {
    if (x < 0 || x >= width_ || y < 0 || y >= height_) {
        throw std::out_of_range("Grid coordinates out of range.");
    }
    cells[y][x].occupied = occupied;
}

// 计算每个栅格的ar值
std::vector<float> GridMap::calculateArValues(float img_width, float fov) {
    if (fov <= 0) {
        throw std::invalid_argument("Field of view must be positive.");
    }
    std::vector<float> ar_values(height_);
    for (int i = 0; i < height_; ++i) {
        // 防止除以零或无效的tan值
        if (std::tan(fov / 2) == 0) {
            throw std::runtime_error("Invalid tan value for field of view.");
        }
        float depth = 40.0; // 根据实际情况调整深度
        ar_values[i] = (img_width * resolution_) / (2 * depth * std::tan(fov / 2));
    }
    return ar_values;
}

// 找出最大点数的栅格索引
int GridMap::findMaxCountCell(float beta_r, const std::vector<float>& ar_values) {
    int max_count = 0;
    int imax = -1;
    for (int i = 0; i < height_; ++i) {
        for (int j = 0; j < width_; ++j) {
            if (cells[i][j].count > max_count) {
                max_count = cells[i][j].count;
                imax = i * width_ + j;
            }
        }
    }
    return imax;
}

// 更新栅格的占用状态
void GridMap::adjustGridsByOccupancy(float beta_r, const std::vector<float>& ar_values) {
    for (int i = 0; i < height_; ++i) {
        for (int j = 0; j < width_; ++j) {
            float bi = ar_values[i] * cells[i][j].averageHeight / resolution_;
            //float Ti = beta_r * ar_values[i] * bi;
            float Ti = 2.0;
            //std::cout << "Ti: " << Ti << std::endl;
            cells[i][j].occupied = cells[i][j].count > Ti;
        }
    }
}

// 统计每个栅格中的点数
void GridMap::countPointsInCells(const SimplePointCloud& cloud) {
    for (const auto& point : cloud.points) {
        if (point.z < 0) continue;  // 忽略负深度值

        int gridX = static_cast<int>((point.x / resolution_) + (width_ / 2));
        int gridZ = static_cast<int>(height_ - (point.z / resolution_));

        // 确保索引在地图边界内
        if (gridX >= 0 && gridX < width_ && gridZ >= 0 && gridZ < height_) {
            cells[gridZ][gridX].count++;
            cells[gridZ][gridX].averageHeight += point.z;
        }
    }
}

// 计算每个栅格的平均高度
void GridMap::calculateAverageHeights() {
    for (auto& row : cells) {
        for (auto& cell : row) {
            if (cell.count > 0) {
                cell.averageHeight /= cell.count;
            }
        }
    }
}

void GridMap::visualize() const {
    int width = this->width_;
    int height = this->height_;

    cv::Mat image(height, width, CV_8UC3, cv::Scalar(255, 255, 255));

    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            if (this->isOccupied(x, y)) {
                image.at<cv::Vec3b>(cv::Point(x, y)) = cv::Vec3b(0, 0, 255); // 被占用: 红色
            } else if (this->isUnknown(x, y)) {
                image.at<cv::Vec3b>(cv::Point(x, y)) = cv::Vec3b(128, 128, 128); // 未知: 灰色
            } else {
                image.at<cv::Vec3b>(cv::Point(x, y)) = cv::Vec3b(0, 255, 0); // 空闲: 绿色
            }
        }
    }
    cv::Mat resized_image;
    cv::resize(image, resized_image, cv::Size(500, 500));

    cv::imshow("GridMap Visualization", resized_image);
    cv::waitKey(1);
}

cv::Mat GridMap::visualize(int display_width, int display_height) const {
    
    auto currentTime = std::chrono::high_resolution_clock::now();
    double fps = 1.0 / std::chrono::duration<double>(currentTime - lastFrameTime).count();
    lastFrameTime = currentTime;

    // 创建原始大小的图像
    cv::Mat image(height_, width_, CV_8UC3, cv::Scalar(255, 255, 255));

    // 绘制栅格地图
    for (int y = 0; y < height_; ++y) {
        for (int x = 0; x < width_; ++x) {
            if (isOccupied(x, y)) {
                image.at<cv::Vec3b>(cv::Point(x, y)) = cv::Vec3b(0, 0, 255);
            } else if (isUnknown(x, y)) {
                image.at<cv::Vec3b>(cv::Point(x, y)) = cv::Vec3b(128, 128, 128);
            } else {
                image.at<cv::Vec3b>(cv::Point(x, y)) = cv::Vec3b(0, 255, 0);
            }
        }
    }

    // 缩放图像
    cv::Mat resized_image;
    cv::resize(image, resized_image, cv::Size(display_width, display_height), 0, 0, cv::INTER_NEAREST);

    // 计算实际高度代表的距离
    float actualHeightDistance = height_ * resolution_;

    // 绘制表示高度的线段
    int linePosX = 30; // 线段的水平位置
    cv::line(resized_image, cv::Point(linePosX, 10), cv::Point(linePosX, display_height - 10), cv::Scalar(0, 0, 255), 2);

    // 绘制高度距离文本
    std::string heightText = std::to_string(static_cast<int>(actualHeightDistance)) + " m";
    int textPosX = linePosX + 5; // 文本的水平位置
    int textPosY = display_height / 2; // 文本的垂直位置
    cv::putText(resized_image, heightText, cv::Point(textPosX, textPosY), cv::FONT_HERSHEY_SIMPLEX, 0.5, cv::Scalar(0, 0, 255), 1, cv::LINE_AA);

    // 显示图像

    // 绘制 FPS
    std::string fpsText = "FPS: " + std::to_string(static_cast<int>(fps));
    cv::putText(resized_image, fpsText, cv::Point(10, 20), cv::FONT_HERSHEY_SIMPLEX, 0.5, cv::Scalar(255, 255, 255));

//    // 显示图像
//    cv::imshow("GridMap Visualization", resized_image);
//    cv::waitKey(1);
    return resized_image;
}
