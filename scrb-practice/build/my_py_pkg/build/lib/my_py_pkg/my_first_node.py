#!/usr/bin/env python3
import rclpy
from rclpy.node import Node

class ClassNode(Node):
    
    #constructor
    def __init__(self):
        super().__init__("a_named_node")
        self.get_logger().info("a message from constructor")
        self.counter_ =0 #trailing _ is a python convention to denote "attribute of the class"
        
        self.create_timer(1.0,self.timer_callback) # every second, call timer_callback
        # note that we arent calling thre function with timer_callback(), we are just referencing it.
    
    def timer_callback(self):
        self.get_logger().info("msg from timer_callback:" +str(self.counter_))
        self.counter_ = self.counter_ +1



def main(args=None):
    rclpy.init(args=args)
    myNode = ClassNode()
    myNode.get_logger().info("a message from main")
    rclpy.spin(myNode) #keeps node alive.
    rclpy.shutdown() #shut down the node.




#makes this runnable from terminal.
if __name__ == "__main__":
    main()