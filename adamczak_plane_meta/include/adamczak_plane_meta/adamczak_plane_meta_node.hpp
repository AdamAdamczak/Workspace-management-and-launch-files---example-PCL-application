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

#ifndef ADAMCZAK_PLANE_META__ADAMCZAK_PLANE_META_NODE_HPP_
#define ADAMCZAK_PLANE_META__ADAMCZAK_PLANE_META_NODE_HPP_

#include <memory>
#include <rclcpp/rclcpp.hpp>

#include "adamczak_plane_meta/adamczak_plane_meta.hpp"

#include "rclcpp/node.hpp"
#include "rclcpp/rclcpp.hpp"
#include <pcl/point_types.h>
#include <pcl/conversions.h>
#include <adamczak_filtering_msgs/msg/filtering.hpp>


namespace adamczak_plane_meta
{
using AdamczakPlaneMetaPtr = std::unique_ptr<adamczak_plane_meta::AdamczakPlaneMeta>;

class ADAMCZAK_PLANE_META_PUBLIC AdamczakPlaneMetaNode : public rclcpp::Node
{
public:
  explicit AdamczakPlaneMetaNode(const rclcpp::NodeOptions & options);

private:
  void cloudCallback(const sensor_msgs::msg::PointCloud2::SharedPtr msg) const;
  std::unique_ptr<AdamczakPlaneMeta> adamczak_plane_meta_{nullptr};
  rclcpp::Subscription<sensor_msgs::msg::PointCloud2>::SharedPtr cloud_sub_;
  rclcpp::Publisher<adamczak_filtering_msgs::msg::Filtering>::SharedPtr cloud_pub_;
  
};
}  // namespace adamczak_plane_meta

#endif  // ADAMCZAK_PLANE_META__ADAMCZAK_PLANE_META_NODE_HPP_
