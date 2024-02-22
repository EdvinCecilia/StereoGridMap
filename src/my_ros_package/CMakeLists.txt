cmake_minimum_required(VERSION 3.5)
project(my_ros_package)

# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(custom_msgs REQUIRED)  # Replace with your actual dependencies
find_package(OpenCV REQUIRED) # 查找OpenCV
find_package(yaml-cpp REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(cv_bridge REQUIRED)



if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # comment the line when a copyright and license is added to all source files
  set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # comment the line when this package is in a git repo and when
  # a copyright and license is added to all source files
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
# include_directories(include/${PROJECT_NAME})


# Declare a C++ executable
add_executable(image_nv12_subscriber src/image_nv12_subscriber.cpp)
add_executable(disparity_processing_node src/DisparityProcessingNode.cpp src/DisparityToPointCloud.cpp src/GridMap.cpp)
target_link_libraries(disparity_processing_node ${OpenCV_LIBRARIES})
target_link_libraries(disparity_processing_node ${YAML_CPP_LIBRARIES})

target_link_libraries(image_nv12_subscriber ${OpenCV_LIBRARIES})
target_link_libraries(image_nv12_subscriber ${YAML_CPP_LIBRARIES})

# Specify libraries to link a library or executable target against
ament_target_dependencies(disparity_processing_node
  rclcpp
  custom_msgs
  yaml-cpp
  sensor_msgs
  cv_bridge
)

ament_target_dependencies(image_nv12_subscriber
  rclcpp
  custom_msgs
  yaml-cpp
  sensor_msgs
  cv_bridge
)

# Install the executable
install(TARGETS
  disparity_processing_node
  DESTINATION lib/${PROJECT_NAME}
)

install(TARGETS
  image_nv12_subscriber
  DESTINATION lib/${PROJECT_NAME}
)

# Install launch files
#install(DIRECTORY launch/
#  DESTINATION share/${PROJECT_NAME}/launch
#)


