from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, LogInfo
from launch_ros.actions import Node
from launch.substitutions import LaunchConfiguration, PathJoinSubstitution
from launch_ros.substitutions import FindPackageShare
from launch.actions import IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource

def launch_setup(context, *args, **kwargs):
    param_path = LaunchConfiguration('adamczak_filtering_launch_param_file').perform(context)
    if not param_path:
        param_path = PathJoinSubstitution(
            [FindPackageShare('adamczak_filtering_launch'), 'config', 'adamczak_filtering_launch.param.yaml']
        ).perform(context)

    adamczak_filtering_launch_node = Node(
        package='adamczak_filtering_launch',
        executable='adamczak_filtering_launch_node_exe',
        name='adamczak_filtering_launch_node',
        parameters=[param_path],
        output='screen',
        arguments=['--ros-args', '--log-level', 'info', '--enable-stdout-logs'],
    )

    return [
        adamczak_filtering_launch_node
    ]


def generate_launch_description():
    declared_arguments = []

    def add_launch_arg(name: str, default_value: str = None):
        declared_arguments.append(
            DeclareLaunchArgument(name, default_value=default_value)
        )

    add_launch_arg('adamczak_filtering_launch_param_file', '')
    param_path = PathJoinSubstitution(
            [FindPackageShare('adamczak_filtering_launch'), 'config', 'rviz_config.rviz'])

    return LaunchDescription([
        *declared_arguments,
        Node(
                package='rviz2',
                executable='rviz2',
                name='rviz2',
                output='screen',
                arguments=['-d', param_path],
            ),
        Node(
            package='noise_filter',
            executable='noise_filter_node_exe',
            name='noise_filter',
            output='screen',
            remappings=[
                ("/input_cloud", "/phoxi/phoxi_camera/cloud"),
                ("/output_cloud", "/noise_filter/cloud_filtered"),
            ],
            # parameters=[LaunchConfiguration('src/perception/noise_filter/config/defaults.param.yaml')],
            arguments=['--ros-args', '--log-level', 'info', '--enable-stdout-logs'],
        ),

        Node(
            package='adamczak_plane_seg',
            executable='adamczak_plane_seg_node_exe',
            name='adamczak_plane_seg',
            output='screen',
            remappings=[
                ("input_cloud", "/noise_filter/cloud_filtered"),
                ("output_cloud", "/plane_segmentation")
            ],
            # parameters=[LaunchConfiguration('adamczak_plane_seg_config_param_file')],
      	      arguments=['--ros-args', '--log-level', 'info', '--enable-stdout-logs'],
        ),

        Node(
            package='adamczak_plane_meta',
            executable='adamczak_plane_meta_node_exe',
            name='adamczak_plane_meta_node',
            remappings=[
                ("/plane_segmentation", "/metadata_cloud"),
            ],
            # parameters=[LaunchConfiguration('adamczak_plane_meta_config_param_file')],
            output='screen',
            arguments=['--ros-args', '--log-level', 'info', '--enable-stdout-logs'],
        ),
            
        
    ])
