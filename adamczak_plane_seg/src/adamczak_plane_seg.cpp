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

#include "adamczak_plane_seg/adamczak_plane_seg.hpp"


#include <iostream>

namespace adamczak_plane_seg
{

AdamczakPlaneSeg::AdamczakPlaneSeg()
{}

void AdamczakPlaneSeg::findPlane(
   const pcl::PointCloud<pcl::PointXYZ> &pck_input,
   pcl::PointCloud<pcl::PointXYZ> & pcl_output)
{
pcl::ModelCoefficients::Ptr coefficients (new pcl::ModelCoefficients);
pcl::PointIndices::Ptr inliers (new pcl::PointIndices);
pcl::SACSegmentation<pcl::PointXYZ> seg;
seg.setOptimizeCoefficients (true);
seg.setModelType(pcl::SACMODEL_PLANE);
seg.setMethodType(pcl::SAC_RANSAC);
seg.setDistanceThreshold (0.01);
seg.setInputCloud(pck_input.makeShared());
seg.segment (*inliers, *coefficients);
pcl::ExtractIndices<pcl::PointXYZ> extract;
extract.setInputCloud(pck_input.makeShared());
extract.setIndices(inliers);
extract.setNegative(false);
extract.filter(pcl_output);
}


void AdamczakPlaneSeg::setParameters(float leaf_size){
   pam_ = leaf_size;
}
}  // namespace adamczak_plane_seg
