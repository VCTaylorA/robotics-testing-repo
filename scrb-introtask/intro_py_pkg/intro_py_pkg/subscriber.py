#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from std_msgs.msg import String 
from std_msgs.msg import Int8

class IntroSubscriber(Node):
    def __init__(self):
        super().__init__('intro_subscriber')
        # subscribe to String messages on 'string_topic'
        self.string_subscription_ = self.create_subscription(String, 'string_topic', self.string_callback, 5)
        # subscribe to Int8 messages on 'int_topic'
        self.int8_subscription_ = self.create_subscription(Int8, 'int_topic', self.int8_callback, 5)
        
        
    # callback for String messages
    def string_callback(self, strmsg):
        self.get_logger().info(f'i heard string: {strmsg.data}')

    # callback for Int8 messages
    def int8_callback(self, int8msg):
        self.get_logger().info(f'i heard int: {int8msg.data}, f({int8msg.data})={int8msg.data*10}')
        
        

def main(args=None):
    rclpy.init(args=args)
    node = IntroSubscriber() 
    rclpy.spin(node)
    node.destroy_node() 
    rclpy.shutdown()



if __name__ == "__main__":
	main()