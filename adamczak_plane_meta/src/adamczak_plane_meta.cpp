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

#include "adamczak_plane_meta/adamczak_plane_meta.hpp"

#include <iostream>

namespace adamczak_plane_meta
{

AdamczakPlaneMeta::AdamczakPlaneMeta()
{
}

void AdamczakPlaneMeta::findCenter(const pcl::PointCloud<pcl::PointXYZ> & pcl_input,
    Eigen::Vector4f &centroid)
{
    pcl::compute3DCentroid(pcl_input,centroid);
    
    

}
void AdamczakPlaneMeta::setParameters(float pam){
   pam_ = pam;
}
}  // namespace adamczak_plane_meta
