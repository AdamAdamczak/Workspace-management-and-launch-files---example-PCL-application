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

#ifndef ADAMCZAK_FILTERING_LAUNCH__ADAMCZAK_FILTERING_LAUNCH_NODE_HPP_
#define ADAMCZAK_FILTERING_LAUNCH__ADAMCZAK_FILTERING_LAUNCH_NODE_HPP_

#include <memory>
#include <rclcpp/rclcpp.hpp>

#include "adamczak_filtering_launch/adamczak_filtering_launch.hpp"

namespace adamczak_filtering_launch
{
using AdamczakFilteringLaunchPtr = std::unique_ptr<adamczak_filtering_launch::AdamczakFilteringLaunch>;

class ADAMCZAK_FILTERING_LAUNCH_PUBLIC AdamczakFilteringLaunchNode : public rclcpp::Node
{
public:
  explicit AdamczakFilteringLaunchNode(const rclcpp::NodeOptions & options);

private:
  AdamczakFilteringLaunchPtr adamczak_filtering_launch_{nullptr};
  int64_t param_name_{123};
};
}  // namespace adamczak_filtering_launch

#endif  // ADAMCZAK_FILTERING_LAUNCH__ADAMCZAK_FILTERING_LAUNCH_NODE_HPP_
