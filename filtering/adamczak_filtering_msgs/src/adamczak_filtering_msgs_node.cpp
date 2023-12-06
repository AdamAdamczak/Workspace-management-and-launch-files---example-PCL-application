// Copyright 2023 AAdamczak
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "adamczak_filtering_msgs/adamczak_filtering_msgs_node.hpp"

namespace adamczak_filtering_msgs
{

AdamczakFilteringMsgsNode::AdamczakFilteringMsgsNode(const rclcpp::NodeOptions & options)
:  Node("adamczak_filtering_msgs", options)
{
  adamczak_filtering_msgs_ = std::make_unique<adamczak_filtering_msgs::AdamczakFilteringMsgs>();
  param_name_ = this->declare_parameter("param_name", 456);
  adamczak_filtering_msgs_->foo(param_name_);
}

}  // namespace adamczak_filtering_msgs

#include "rclcpp_components/register_node_macro.hpp"

RCLCPP_COMPONENTS_REGISTER_NODE(adamczak_filtering_msgs::AdamczakFilteringMsgsNode)
