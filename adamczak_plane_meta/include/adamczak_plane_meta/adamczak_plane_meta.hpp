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

#ifndef ADAMCZAK_PLANE_META__ADAMCZAK_PLANE_META_HPP_
#define ADAMCZAK_PLANE_META__ADAMCZAK_PLANE_META_HPP_

#include <cstdint>

#include "adamczak_plane_meta/visibility_control.hpp"
#include <pcl/point_types.h>
#include <pcl/conversions.h>
#include <pcl_conversions/pcl_conversions.h>
#include <pcl/common/centroid.h>
#include "sensor_msgs/msg/point_cloud2.hpp"
// #include "adamczak_filtering_msgs/msg/filtering.hpp"



namespace adamczak_plane_meta
{

class ADAMCZAK_PLANE_META_PUBLIC AdamczakPlaneMeta
{
public:
  AdamczakPlaneMeta();
  void findCenter(const pcl::PointCloud<pcl::PointXYZ> & pcl_input,
    Eigen::Vector4f &centroid);
  
  void setParameters(float pam);
  private:
  float pam_;
};

}  // namespace adamczak_plane_meta

#endif  // ADAMCZAK_PLANE_META__ADAMCZAK_PLANE_META_HPP_
