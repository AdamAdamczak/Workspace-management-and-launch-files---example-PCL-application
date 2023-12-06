cmake_minimum_required(VERSION 3.8)
project(adamczak_plane_seg)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()
add_compile_options(-std=c++17)

find_package(ament_cmake_auto REQUIRED)
find_package(PCL REQUIRED)


ament_auto_find_build_dependencies(REQUIRED
  ${${PROJECT_NAME}_BUILD_DEPENDS}
  ${${PROJECT_NAME}_BUILDTOOL_DEPENDS}
)

# add_compile_options(-Wall -Wextra -pedantic -Werror)

set(ADAMCZAK_PLANE_SEG_SRC
  src/adamczak_plane_seg.cpp
)

set(ADAMCZAK_PLANE_SEG_HEADERS
  include/adamczak_plane_seg/adamczak_plane_seg.hpp
  include/adamczak_plane_seg/visibility_control.hpp
)

ament_auto_add_library(adamczak_plane_seg SHARED
  ${ADAMCZAK_PLANE_SEG_SRC}
  ${ADAMCZAK_PLANE_SEG_HEADERS}
)

set(ADAMCZAK_PLANE_SEG_NODE_SRC
  src/adamczak_plane_seg_node.cpp
)

set(ADAMCZAK_PLANE_SEG_NODE_HEADERS
  include/adamczak_plane_seg/adamczak_plane_seg_node.hpp
  include/adamczak_plane_seg/visibility_control.hpp

)

ament_auto_add_library(${PROJECT_NAME}_node SHARED
  ${ADAMCZAK_PLANE_SEG_NODE_SRC}
  ${ADAMCZAK_PLANE_SEG_NODE_HEADERS}
)

include_directories(${PCL_INCLUDE_DIRS})
link_directories(${PCL_LIBRARY_DIRS})
add_definitions(${PCL_DEFINITIONS})

rclcpp_components_register_node(adamczak_plane_seg_node
  PLUGIN "adamczak_plane_seg::AdamczakPlaneSegNode"
  EXECUTABLE adamczak_plane_seg_node_exe
)
target_link_libraries(adamczak_plane_seg
    ${PCL_LIBRARIES}
)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  set(ament_cmake_copyright_FOUND TRUE)
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_auto_package(
  INSTALL_TO_SHARE
  launch
  config
)
