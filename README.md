# 双目视差图转栅格地图工具集 🌐🔍

本项目提供了一套工具，旨在将双目相机产生的视差图转换为点云数据，并进一步生成栅格地图。这些工具虽然在ROS 2环境下开发和测试，但设计上保持了较好的独立性，使得其中的核心功能模块可以在非ROS环境下使用。

## 🌟 特点

- **视差图处理**🔍：独立的视差图处理模块，可用于提取深度信息。
- **点云生成**☁️：将视差数据转换为三维点云，无需依赖ROS环境。
- **栅格地图构建**🗺️：基于点云数据创建栅格地图，适用于多种应用场景。
- **模块独立性**🛠️：核心模块如点云处理和栅格地图更新设计为可独立使用。

## 🛠️ 环境要求

- C++编译环境（推荐GCC或Clang）
- OpenCV库（用于图像处理和可视化）
- yaml-cpp库（用于配置文件解析）

## ⚙️ 安装与编译

1. **安装依赖库**：

   - 安装OpenCV：

     ```
     sudo apt-get install libopencv-dev
     ```

   - 安装yaml-cpp：

     ```
     sudo apt-get install libyaml-cpp-dev
     ```

2. **编译项目**：

   使用CMake或您喜欢的编译系统编译项目。如果您在ROS环境下工作，可以使用`colcon`构建。

   ```
   mkdir build && cd build
   cmake ..
   make
   ```

## 📂 项目结构

本项目包含以下主要部分：

- `custom_msgs/`：存放自定义ROS消息类型定义，用于双目视差图和其他自定义数据格式。
- `my_ros_package/`：主要的ROS包目录，包含实现双目视差图处理、点云生成和栅格地图更新的代码。

### `my_ros_package/` 目录结构

- ```
  src/
  ```

  ：源代码目录，包含核心功能的实现。

  - `DisparityProcessingNode.cpp`：节点实现，处理视差图，生成点云，并更新栅格地图。
  - `DisparityToPointCloud.cpp`：实现将视差图转换为点云的功能。
  - `GridMap.cpp`：栅格地图处理的实现，包括更新和可视化功能。
  - `SimplePointCloud.cpp`：简单的点云数据结构实现。
  - `config.yaml`：配置文件示例，定义了相机参数和栅格地图的相关设置。

## 🚀 使用方法

### 在ROS环境下

1. **配置**：

   在`config.yaml`中设置相机参数和栅格地图参数。

2. **启动节点**：

   使用ROS运行节点：

   ```
   bashCopy code
   ros2 run <包名> disparity_processing_node
   ```

### 在非ROS环境下

1. **集成到您的项目**：

   将核心模块（如`DisparityToPointCloud`, `GridMap`）集成到您的项目中，并按需调用API。

2. **示例用法**：

   参考以下伪代码示例集成点云生成和栅格地图更新：

   ```
   // 初始化模块
   DisparityToPointCloud converter(fx, fy, cx, cy, baseline);
   GridMap gridMap(width, height, resolution);
   
   // 处理视差图
   SimplePointCloud cloud = converter.ConvertToPointCloud(disparity_data, width, height);
   
   // 更新栅格地图
   gridMap.updateFromPointCloud(cloud, img_width, fov, beta_r);
   ```

## 📝 示例代码

参考`DisparityProcessingNode.cpp`来了解如何在ROS环境下使用这些模块。对于非ROS环境，请参考各模块的头文件和实现文件来了解API的使用方法。

## 📘 双目视差图到栅格地图原理

为了深入了解本项目背后的理论和技术原理，包括如何从双目视差图生成点云，以及如何将点云数据转换为栅格地图，您可以参考以下资源：

- [双目视差图到点云的转换（原理+代码）](https://blog.csdn.net/qq_41037856/article/details/134701111?spm=1001.2014.3001.5502) 📚

该资源提供了详细的理论背景和实现细节，有助于更好地理解项目的工作原理。

## 🤝 贡献

欢迎通过GitHub pull requests或issues贡献您的代码或提出项目相关的问题。我们非常欢迎各种形式的贡献，包括功能改进、bug修复或文档完善。