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

#ifndef ADAMCZAK_FILTERING_MSGS__ADAMCZAK_FILTERING_MSGS_NODE_HPP_
#define ADAMCZAK_FILTERING_MSGS__ADAMCZAK_FILTERING_MSGS_NODE_HPP_

#include <memory>
#include <rclcpp/rclcpp.hpp>

#include "adamczak_filtering_msgs/adamczak_filtering_msgs.hpp"

namespace adamczak_filtering_msgs
{
using AdamczakFilteringMsgsPtr = std::unique_ptr<adamczak_filtering_msgs::AdamczakFilteringMsgs>;

class ADAMCZAK_FILTERING_MSGS_PUBLIC AdamczakFilteringMsgsNode : public rclcpp::Node
{
public:
  explicit AdamczakFilteringMsgsNode(const rclcpp::NodeOptions & options);

private:
  AdamczakFilteringMsgsPtr adamczak_filtering_msgs_{nullptr};
  int64_t param_name_{123};
};
}  // namespace adamczak_filtering_msgs

#endif  // ADAMCZAK_FILTERING_MSGS__ADAMCZAK_FILTERING_MSGS_NODE_HPP_
