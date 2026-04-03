# SCRB INTRO TASK
?? denotes uncertainty and that i should review my understanding

## Goal
to make a simple subscriber and publisher in ROS2;
using both C++ and Python, where each language has its own publisher and subscriber;
using both `ament_cmake` and `ament_python` respectively.
This is a simple demo that has the 'talker' log the data it publishes, and has a 'listener' that logs and transforms the data from the publisher using its subscriptions.

## how to run


## Implementation notes
### Python version

#### package creation
rclpy is a base librarystd_msgs for messages to be compiled into (language specific??) .msg files. This file tells ros2 how to serialize the data and send it over Data Distribution service (DDS) (generally for communication between nodes??)
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
