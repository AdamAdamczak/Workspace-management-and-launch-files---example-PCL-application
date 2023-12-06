cmake_minimum_required(VERSION 3.14)
project(adamczak_filtering_msgs)

find_package(ament_cmake_auto REQUIRED)
find_package(rosidl_default_generators REQUIRED)
find_package(geometry_msgs REQUIRED)

ament_auto_find_build_dependencies(REQUIRED
  ${${PROJECT_NAME}_BUILD_DEPENDS}
  ${${PROJECT_NAME}_BUILDTOOL_DEPENDS}
)

add_compile_options(-Wall -Wextra -pedantic -Werror)

# Generate interfaces first
rosidl_generate_interfaces(${PROJECT_NAME}
  "msg/Filtering.msg"
  DEPENDENCIES geometry_msgs std_msgs
)

# Add library for the generated messages
set(ADAMCZAK_FILTERING_MSGS_LIB_SRC
  src/adamczak_filtering_msgs.cpp
)

set(ADAMCZAK_FILTERING_MSGS_LIB_HEADERS
  include/adamczak_filtering_msgs/adamczak_filtering_msgs.hpp
  include/adamczak_filtering_msgs/visibility_control.hpp
)

ament_auto_add_library(${PROJECT_NAME}_lib SHARED
  ${ADAMCZAK_FILTERING_MSGS_LIB_SRC}
  ${ADAMCZAK_FILTERING_MSGS_LIB_HEADERS}
)

# Add node using the generated messages
set(ADAMCZAK_FILTERING_MSGS_NODE_SRC
  src/adamczak_filtering_msgs_node.cpp
)

set(ADAMCZAK_FILTERING_MSGS_NODE_HEADERS
  include/adamczak_filtering_msgs/adamczak_filtering_msgs_node.hpp
)

ament_auto_add_library(${PROJECT_NAME}_node SHARED
  ${ADAMCZAK_FILTERING_MSGS_NODE_SRC}
  ${ADAMCZAK_FILTERING_MSGS_NODE_HEADERS}
)

rclcpp_components_register_node(${PROJECT_NAME}_node
  PLUGIN "adamczak_filtering_msgs::AdamczakFilteringMsgsNode"
  EXECUTABLE ${PROJECT_NAME}_node_exe
)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  ament_lint_auto_find_test_dependencies()

  ament_add_ros_isolated_gtest(test_adamczak_filtering_msgs
    test/test_adamczak_filtering_msgs.cpp
  )
  ament_target_dependencies(test_adamczak_filtering_msgs ${TEST_SOURCES})
  target_link_libraries(test_adamczak_filtering_msgs ${PROJECT_NAME}_lib)
endif()

ament_auto_package(INSTALL_TO_SHARE
  launch
  config
)
