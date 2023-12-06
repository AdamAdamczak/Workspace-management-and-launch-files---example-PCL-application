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

#include "adamczak_plane_meta/adamczak_plane_meta_node.hpp"
using namespace std::chrono_literals;

namespace adamczak_plane_meta
{
auto custom_qos = rclcpp::QoS(rclcpp::KeepLast(1), rmw_qos_profile_sensor_data);

AdamczakPlaneMetaNode::AdamczakPlaneMetaNode(const rclcpp::NodeOptions & options)
:  Node("adamczak_plane_meta", options)
{RCLCPP_INFO(this->get_logger(), "Init");
  
  cloud_sub_ = this->create_subscription<sensor_msgs::msg::PointCloud2>(
    "input_cloud", custom_qos, std::bind(
      &AdamczakPlaneMetaNode::cloudCallback, this,
      std::placeholders::_1));
  
  cloud_pub_ = this->create_publisher<adamczak_filtering_msgs::msg::Filtering>("output_meta", custom_qos);
  auto pam = this->declare_parameter("pam", 0.01);
  adamczak_plane_meta_ = std::make_unique<AdamczakPlaneMeta>();
  adamczak_plane_meta_->setParameters(pam);
  
}

void AdamczakPlaneMetaNode::cloudCallback(const sensor_msgs::msg::PointCloud2::SharedPtr msg) const
    {
        pcl::PointCloud<pcl::PointXYZ>::Ptr pcl_input(new pcl::PointCloud<pcl::PointXYZ>);
        Eigen::Vector4f centroid;
        adamczak_filtering_msgs::msg::Filtering meta_msg;
        pcl::fromROSMsg(*msg, *pcl_input);
        adamczak_plane_meta_->findCenter(*pcl_input,centroid);
        // RCLCPP_INFO(this->get_logger(), "Center of the plane: (%f, %f, %f)", centroid[0], centroid[1], centroid[2]);

        meta_msg.header=msg->header;
        meta_msg.vector3_data.x = centroid[0];
        meta_msg.vector3_data.y = centroid[1];
        meta_msg.vector3_data.z = centroid[2];
        meta_msg.height = msg->height;
        meta_msg.width = msg->width;
        meta_msg.row_step = msg->row_step;


        cloud_pub_->publish(meta_msg);


    
    }


}  // namespace adamczak_plane_meta

#include "rclcpp_components/register_node_macro.hpp"

RCLCPP_COMPONENTS_REGISTER_NODE(adamczak_plane_meta::AdamczakPlaneMetaNode)
