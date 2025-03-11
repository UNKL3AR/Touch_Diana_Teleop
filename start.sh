#!/bin/bash
cd "$(dirname "$0")"
gnome-terminal -- bash -c "source install/setup.bash; ros2 run diana_humble TouchxPose; sleep 5; ros2 run diana_humble touchx_lifecycle_node; exec bash"
gnome-terminal -- bash -c "source install/setup.bash; ros2 launch omni_common omni_state.launch.py; exec bash"
gnome-terminal -- bash -c "source install/setup.bash; sleep 2;ros2 run master_slave_map omni_diana_pose; exec bash"
gnome-terminal -- bash -c "source install/setup.bash; exec bash"

