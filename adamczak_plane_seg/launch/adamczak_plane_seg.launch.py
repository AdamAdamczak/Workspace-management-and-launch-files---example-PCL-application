# Copyright 2022 Amadeusz Szymko
# Perception for Physical Interaction Laboratory at Poznan University of Technology
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node


def generate_launch_description():
    adamczak_plane_seg_launch_pkg_prefix = get_package_share_directory("adamczak_plane_seg")

    adamczak_plane_seg_config_param = DeclareLaunchArgument(
        'adamczak_plane_seg_config_param_file',
        default_value=[adamczak_plane_seg_launch_pkg_prefix, '/config/adamczak_plane_seg.param.yaml'],
        description='Node config.'
    )

    adamczak_plane_seg = Node(
        package='adamczak_plane_seg',
        executable='adamczak_plane_seg_node_exe',
        name='adamczak_plane_seg',
        output='screen',
        remappings=[
                ("input_cloud", "/noise_filter/cloud_filtered"),
                ("output_cloud", "/plane_segmentation")
                ],
        parameters=[
            LaunchConfiguration('adamczak_plane_seg_config_param_file')
        ],
        arguments=['--ros-args', '--log-level', 'info', '--enable-stdout-logs']
    )

    ld = LaunchDescription([
        adamczak_plane_seg_config_param,
        adamczak_plane_seg,
    ])
    return ld
