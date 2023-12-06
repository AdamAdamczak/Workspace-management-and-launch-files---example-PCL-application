// Copyright 2023 AdamA
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

#ifndef ADAMCZAK_PLANE_SEG__ADAMCZAK_PLANE_SEG_HPP_
#define ADAMCZAK_PLANE_SEG__ADAMCZAK_PLANE_SEG_HPP_

#include <cstdint>

#include "adamczak_plane_seg/visibility_control.hpp"
#include "pcl/point_types.h"
#include "pcl/filters/voxel_grid.h"

#include <pcl/ModelCoefficients.h>
#include <pcl/io/pcd_io.h>
#include <pcl/sample_consensus/method_types.h>
#include <pcl/sample_consensus/model_types.h>
#include <pcl/segmentation/sac_segmentation.h>
#include "sensor_msgs/msg/point_cloud2.hpp"
#include <pcl/filters/extract_indices.h>

namespace adamczak_plane_seg
{

class ADAMCZAK_PLANE_SEG_PUBLIC AdamczakPlaneSeg
{
public:
  AdamczakPlaneSeg();
  void setParameters(float leaf_size);
  void findPlane(
    const pcl::PointCloud<pcl::PointXYZ> & pcl_input,
    pcl::PointCloud<pcl::PointXYZ> & pcl_output);
private:
  float pam_;
};

}  // namespace adamczak_plane_seg

#endif  // ADAMCZAK_PLANE_SEG__ADAMCZAK_PLANE_SEG_HPP_
