# SCRB INTRO TASK
to whom it may concern, jump to [how to run](#how_to_run) if you want to test this.

?? denotes uncertainty and that i would like to review my understanding
## Goal
to make a simple subscriber and publisher in ROS2;
using both C++ and Python, where each language has its own publisher and subscriber;
using both `ament_cmake` and `ament_python` respectively.
This is a simple demo that has the 'talker' log the data it publishes, and has a 'listener' that logs and transforms the data from the publisher using its subscriptions.

## how_to_run
the packages displaying subscriber and publisher are under `scrb-introtask`.
### running python pkg
1. `cd` into `scrb-introtask` and run `colcon build packages-select intro_py_pkg`
3. ensure that your ros2 humble install is sourced. i have my `~/.bashrc` source my install with `source /home/taylor/ros2_humble/install/setup.bash` on my virtual machine
4. source the package after every build with `source install/setup.bash`
5. run with `ros2 run intro_py_pkg talker` and `ros2 run intro_py_pkg listener`
6. they should now be running
### running c++ pkg
1. `cd` into `scrb-introtask` and run `colcon build packages-select my_cpp_pkg` (i know, different naming convention.. my mistake)
2. ensure that your ros2 humble install is sourced. i have my `~/.bashrc` source my install with `source /home/taylor/ros2_humble/install/setup.bash` on my virtual machine
3. source the package after every build with `source install/setup.bash`
4. run with `ros2 run my_cpp_pkg talker` and `ros2 run my_cpp_pkg listener`
5. they should now be running 

## Implementation notes (for personal review)
### Python version

#### package creation
rclpy is a base librarystd_msgs for messages to be compiled into .msg files. This file tells ros2 how to serialize the data and send it over Data Distribution service (DDS) (generally for communication between nodes??)
run the command within the project directory
`ros2 pkg create my_py_pkg --build-type ament_python --dependencies rclpy std_msgs`
#### Publisher & Subscriber
comments are left in the following files to describe my thinking. for future projects its reccomended to at least add docs that describe each function (equivalent of javadoc for Python??)
`/scrb-introtask/intro_py_pkg/intro_py_pkg/publisher.py`
`/scrb-introtask/intro_py_pkg/intro_py_pkg/subscriber.py`

#### Setup.py
straight forward, just go to `scrb-introtask/intro_py_pkg/setup.py` and change `entry_points` to:
```python
entry_points={
        'console_scripts': [
            'talker = intro_py_pkg.publisher:main',
            'listener = intro_py_pkg.subscriber:main',
        ],
    },

```

#### Build, Source and Run
**BUILD** with `colcon build` inside `/scrb-introtask` (but NOT within any of its subdirectories)
**SOURCE** with `source /opt/ros/humble/setup.bash` and then `source install/setup.bash`, in that order, every time you open a terminal. Alternatively, you can add these lines to the end of `~/.bashrc` which runs every time you open a bash instance.
**RUN** `ros2 run intro_py_pkg listener` in one terminal and `ros2 run intro_py_pkg talker`in another, each in the scrb-introtask directory.

after running, the talker terminal should output something like

```bash
[INFO] [1774908214.801016244] [intro_publisher]: Publishing on string_topic: Hello 3
[INFO] [1774908215.769533802] [intro_publisher]: Publishing on int_topic: x=3
[INFO] [1774908215.770791927] [intro_publisher]: Publishing on string_topic: Hello 4
[INFO] [1774908216.771189791] [intro_publisher]: Publishing on int_topic: x=4
```

and the listener terminal should output something like

```bash
[INFO] [1774908217.771419309] [intro_subscriber]: i heard int: 3, f(3)=30
[INFO] [1774908217.776027978] [intro_subscriber]: i heard string: Hello 3
[INFO] [1774908218.771503936] [intro_subscriber]: i heard int: 4, f(4)=40
[INFO] [1774908218.776542349] [intro_subscriber]: i heard string: Hello 4
```

### C++ version
#### package creation
run this within the project directory 
`ros2 pkg create my_cpp_pkg --build-type ament_cmake --dependencies rclcpp std_msgs`

#### Publisher & Subscriber
comments are left in the code to describe my thinking. for future projects its reccomended to at least add docs that describe each function (equivalent of javadoc for C++??)

#### CMakeLists.txt
