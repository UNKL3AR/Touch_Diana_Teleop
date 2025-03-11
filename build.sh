#!/bin/bash

if [ "$(basename "$PWD")" != "Touch_Diana_Teleop" ]; then
    echo "Error: You must be in the 'Touch_Diana_Teleop' directory to run this script."
    exit 1
fi

echo "Building custom interfaces ROS2 packages: sri_interface and omni_msgs"
colcon build --packages-select sri_interface omni_msgs || { echo "First build failed"; exit 1; }

echo "Setting up ROS2 environment"
source install/setup.bash

echo "Building all ROS2 packages"
colcon build || { echo "Second build failed"; exit 1; }

echo "Build process completed successfully"

source install/setup.bash