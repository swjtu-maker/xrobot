# xrobot
A Mobile Robot Project From Southwest Jiaotong University Makerspace Robotics Research Team.
Website:http://swjtu-maker.github.io/xrobot/

＃Intel Realsense  R200 on the robot head ros system.
xrobot机器人跑的是ros操作系统，使用了一个Intel出品的realsense R200  三维摄像头。
驱动摄像头采用的是 https://github.com/kaorun55/RealSense-ROS 的方法。
如果要在自己的ros系统上跑Intel Realsense R200，需要执行以下步骤：
1、内核驱动
git clone  https://github.com/kaorun55/RealSense-ROS
然后，cd到 r200_install，目录，执行install.sh ，安装有关的内核驱动。
2、ros包
到realsense_dist/2.3目录，执行install_realsense_ros.sh，来安装realsense包。
安装完毕，可以使用命令：roslaunch realsense realsense_r200_launch.launch， 来启动realsense 的节点和服务。
3、图像调用示例程序
@kaorun55 的RealSense－ROS项目提供了realsense_sample包，在realsense_dist/2.3/sample路径。
将这个目录拷贝到catkin工作目录，并make后。配置catkin的环境变量，即可执行：
roslaunch realsense_sample realsense_image_viewer_launch.launch
看到图像。
4、导航示例
@kaorun55 的RealSense－ROS项目还提供了realsense_dist_nav的示例，这一块还有待研究。
