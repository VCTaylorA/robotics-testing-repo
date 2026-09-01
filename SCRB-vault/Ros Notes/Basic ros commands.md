# set up workspace
```bash

taylor@numbatros:~/Documents/example_ws$ mkdir src
taylor@numbatros:~/Documents/example_ws$ colcon build

```


# Creating a CPP package
```bash
ros2 pkg create pkg_name --build-type ament_cmake --dependencies rclcpp
```

## Ros 2 bag
```
ros2 bag record --all
or
ros2 bag record [topic]

ros2 bag play [filename]
```


