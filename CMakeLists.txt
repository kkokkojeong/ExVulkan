cmake_minimum_required(VERSION 3.15)
project(ExVulkan)

set(CMAKE_CXX_STANDARD 14)

# Vulkan library
#include_directories(${VULKAN_SDK}/Frameworks/vulkan.framework)
include_directories(/Users/seokcheol/vulkansdk-macos-1.2.131.2/macOS/Frameworks/vulkan.framework)
link_libraries(/Users/seokcheol/vulkansdk-macos-1.2.131.2/macOS/Frameworks/vulkan.framework)
#target_link_libraries(/Users/seokcheol/vulkansdk-macos-1.2.131.2/macOS/Frameworks/vulkan.framework)

# add_executable(ExVulkan main.cpp)
add_executable(ExVulkan sample-api/01-instance.cpp)


#target_link_libraries(cmake_testapp_boost ${Boost_LIBRARIES})