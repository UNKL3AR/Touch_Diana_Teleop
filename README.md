# 带有力反馈的主从异构式遥操作系统

## 设备介绍

主端设备采用Geomagic公司的六自由度商用力反馈手柄Touch（原omni phantom）

从端设备采用Agile（北京思灵）公司的7自由度协作机械臂Diana7 Med

力采集设备采用SRI（南宁宇立）公司的6维力传感器M3733C、采集卡M8128B

## 版本需求

软件开发过程中使用平台及SDK版本如下：

linux: ubuntu22.04

ROS2: humble

OpenHaptics: 3.4.0


## ROS2功能包介绍

#### diana_humble: 

机械臂控制包

#### srifts_tcp: 

力传感器驱动及力数据处理包

#### master_slave_map:

主从映射处理包

#### omni_common:

Touch驱动包

refer:https://github.com/stevens-armlab/Geomagic_Touch_ROS2

#### sri_interface&omni_msgs:

自定义信息包


## 编译

创建终端：
```bash
cd Touch_Diana_Teleop
colcon build --packages-select sri_interface omni_msgs
source install/setup.bash
colcon build
```

## 准备工作

#### 串口权限
老版本Touchx以及USB版力传感器

创建终端:

```bash
sudo chmod 777 /dev/ttyACM0
sudo chmod 777 /dev/ttyUSB0
```

## 操作步骤

#### 1.启动Touch节点

创建一个新终端:

```bash
cd Touch_Diana_Teleop
source install/setup.bash
ros2 launch omni_common omni_state.launch.py 
```

###### Tips:
Touch不需要标定
Touchx需要标定
校准touchx需要上下左右前三个轴平行移动，直到终端显示校准成功的提示。


#### 2.启动主从映射节点

创建一个新终端:

```bash
cd Touch_Diana_Teleop
source install/setup.bash
ros2 run master_slave_map omni_diana_pose
```

###### Tips:

启动此节点时，Touch/Touchx 应固定为初始姿势，机械臂的初始位姿是根据Touch/Touchx算出来的。



#### 3.启动机械臂节点

创建一个新终端:

```bash
cd Touch_Diana_Teleop
source install/setup.bash
ros2 run diana_humble TouchPose 
ros2 run diana_humble touch_lifecycle_node 
```

###### Tips:

机械臂初始位置
```bash
double joint[7] = {-0.01383, 0.532705, 0.010528, 2.09436, -0.0228301, -0.490275, 1.57379 };
```



#### 生命节点（ROS2 lifecycle）指令

创建一个新终端:

```bash
cd Touch_Diana_Teleop
source install/setup.bash
```

主从位置同步配置

```bash
ros2 lifecycle set /touchx_lifecycle_node configure 
```

开启实时遥操作控制

```bash
ros2 lifecycle set /touchx_lifecycle_node activate
```

退出实时遥操作控制

```bash
ros2 lifecycle set /touchx_lifecycle_node deactivate
```



#### 4.开启力反馈效果

创建一个新终端:

```bash
cd Touch_Diana_Teleop
source install/setup.bash
ros2 run srifts_tcp srifts
```

创建一个新终端:

```bash
cd Touch_Diana_Teleop
source install/setup.bash
ros2 run srifts feedback
```

