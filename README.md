# Force_Teleop

## Version

linux: ubuntu22.04

ros2: humble

TouchDriver: 2022_04_04

OpenHaptics: 3.4.0



## Introduce

This repository is a master-slave teleoperation control system with force feedback. The master arm uses Geomagic Touch x, and the slave arm uses diana7_med. Mainly includes the following ros2 packages:

#### diana_humble: 

Manipulator control code

#### srifts: 

Ros2 driver and filtering of six axis force-torque sensor

#### master_slave_map:

Master-slave remote operation workspace mapping package

#### omni_common:

Touchx ros2 driver package

refer:https://github.com/stevens-armlab/Geomagic_Touch_ROS2

#### sri_interface&omni_msgs:

Custom force sensor and haptic device ros2 message type



## Preparation

#### Touchx Driver:

https://github.com/UNKL3AR/Touchx-Driver



#### serial library installation:

http://wjwwood.io/serial/doc/1.1.0/index.html

```bash
git clone git://github.com/wjwwood/serial.git
cd serial&mkdir build
cd build
cmake ..
make
sudo make install
```



## Compilation steps

Create a new terminal:

```bash
cd Force_Feedback_Teleoperation
colcon build --packages-select sri_interface omni_msgs
source install/setup.bash
colcon build
```



## Preliminary steps

#### 0.Touchx and force sensor serial port authorization

Create a new terminal:

```bash
./setup.bash
```



## Run steps

#### 1.Start the Touchx node and calibrate Touchx

Create a new terminal:

```bash
cd Force_Feedback_Teleoperation
source install/setup.bash
ros2 launch omni_common omni_state.launch.py  #Touchx ros2 node
```

###### Tips:

To calibrate touchx, you need to move up, down, left, right, and front in three axes in parallel until the terminal displays a successful calibration prompt.



#### 2.Start the master-slave mapping node

Create a new terminal:

```bash
cd Force_Feedback_Teleoperation
source install/setup.bash
ros2 run master_slave_map omni_diana_pose  #master_slave mapping
```

###### Tips:

Touchx should be fixed to the initial pose when starting this node, because the initial pose of the manipulator needs to be mapped with Touch



#### 3.Start the life node of the manipulator

Create a new terminal:

```bash
cd Force_Feedback_Teleoperation
source install/setup.bash
ros2 run diana_humble TouchPose  #The manipulator moves to the preset position
ros2 run diana_humble touch_lifecycle_node  #Start lifecycle node
```



#### lifecycle  command

Create a new terminal:

```
cd Force_Feedback_Teleoperation
source install/setup.bash
```

Touchx mapping points

```bash
ros2 lifecycle set /touchx_lifecycle_node configure 
```

Real time control

```bash
ros2 lifecycle set /touchx_lifecycle_node activate
```

Exit real-time control

```bash
ros2 lifecycle set /touchx_lifecycle_node deactivate
```



#### 4.Activate force feedback

Create a new terminal:

```bash
cd Force_Feedback_Teleoperation
source install/setup.bash
ros2 run srifts forcesensor #Activate force sensor
```

Create a new terminal:

```bash
cd Force_Feedback_Teleoperation
source install/setup.bash
ros2 run srifts kalman #Kalman filtering and force feedback topic
```

