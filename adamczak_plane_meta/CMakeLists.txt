cmake_minimum_required(VERSION 3.14)
project(adamczak_plane_meta)

find_package(ament_cmake_auto REQUIRED)
ament_auto_find_build_dependencies(REQUIRED
  ${${PROJECT_NAME}_BUILD_DEPENDS}
  ${${PROJECT_NAME}_BUILDTOOL_DEPENDS}
)
# find_package(PCL REQUIRED)
find_package(PCL REQUIRED COMPONENTS common)
find_package(adamczak_filtering_msgs REQUIRED)
# find_package(adamczak_filtering_msgs REQUIRED)

add_compile_options(-Wall -Wextra -pedantic )

set(ADAMCZAK_PLANE_META_LIB_SRC
  src/adamczak_plane_meta.cpp
)

set(ADAMCZAK_PLANE_META_LIB_HEADERS
  include/adamczak_plane_meta/adamczak_plane_meta.hpp
  include/adamczak_plane_meta/visibility_control.hpp
)

ament_auto_add_library(${PROJECT_NAME} SHARED
  ${ADAMCZAK_PLANE_META_LIB_SRC}
  ${ADAMCZAK_PLANE_META_LIB_HEADERS}
)

set(ADAMCZAK_PLANE_META_NODE_SRC
  src/adamczak_plane_meta_node.cpp
)

set(ADAMCZAK_PLANE_META_NODE_HEADERS
  include/adamczak_plane_meta/adamczak_plane_meta_node.hpp
)

ament_auto_add_library(${PROJECT_NAME}_node SHARED
  ${ADAMCZAK_PLANE_META_NODE_SRC}
  ${ADAMCZAK_PLANE_META_NODE_HEADERS}
)
include_directories(${PCL_INCLUDE_DIRS})

link_directories(${PCL_LIBRARY_DIRS})
add_definitions(${PCL_DEFINITIONS})
rclcpp_components_register_node(${PROJECT_NAME}_node
  PLUGIN "adamczak_plane_meta::AdamczakPlaneMetaNode"
  EXECUTABLE ${PROJECT_NAME}_node_exe
)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  ament_lint_auto_find_test_dependencies()

  ament_add_ros_isolated_gtest(test_adamczak_plane_meta
    test/test_adamczak_plane_meta.cpp
  )
  ament_target_dependencies(test_adamczak_plane_meta ${TEST_SOURCES})
  target_link_libraries(test_adamczak_plane_meta ${PROJECT_NAME})
endif()

ament_auto_package(INSTALL_TO_SHARE
  launch
  config
)
