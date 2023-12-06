cmake_minimum_required(VERSION 3.14)
project(adamczak_filtering_launch)

find_package(ament_cmake_auto REQUIRED)
ament_auto_find_build_dependencies(REQUIRED
  ${${PROJECT_NAME}_BUILD_DEPENDS}
  ${${PROJECT_NAME}_BUILDTOOL_DEPENDS}
)

add_compile_options(-Wall -Wextra -pedantic -Werror)

set(ADAMCZAK_FILTERING_LAUNCH_LIB_SRC
  src/adamczak_filtering_launch.cpp
)

set(ADAMCZAK_FILTERING_LAUNCH_LIB_HEADERS
  include/adamczak_filtering_launch/adamczak_filtering_launch.hpp
  include/adamczak_filtering_launch/visibility_control.hpp
)

ament_auto_add_library(${PROJECT_NAME} SHARED
  ${ADAMCZAK_FILTERING_LAUNCH_LIB_SRC}
  ${ADAMCZAK_FILTERING_LAUNCH_LIB_HEADERS}
)

set(ADAMCZAK_FILTERING_LAUNCH_NODE_SRC
  src/adamczak_filtering_launch_node.cpp
)

set(ADAMCZAK_FILTERING_LAUNCH_NODE_HEADERS
  include/adamczak_filtering_launch/adamczak_filtering_launch_node.hpp
)

ament_auto_add_library(${PROJECT_NAME}_node SHARED
  ${ADAMCZAK_FILTERING_LAUNCH_NODE_SRC}
  ${ADAMCZAK_FILTERING_LAUNCH_NODE_HEADERS}
)
rclcpp_components_register_node(${PROJECT_NAME}_node
  PLUGIN "adamczak_filtering_launch::AdamczakFilteringLaunchNode"
  EXECUTABLE ${PROJECT_NAME}_node_exe
)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  ament_lint_auto_find_test_dependencies()

  ament_add_ros_isolated_gtest(test_adamczak_filtering_launch
    test/test_adamczak_filtering_launch.cpp
  )
  ament_target_dependencies(test_adamczak_filtering_launch ${TEST_SOURCES})
  target_link_libraries(test_adamczak_filtering_launch ${PROJECT_NAME})
endif()

ament_auto_package(INSTALL_TO_SHARE
  launch
  config
)
