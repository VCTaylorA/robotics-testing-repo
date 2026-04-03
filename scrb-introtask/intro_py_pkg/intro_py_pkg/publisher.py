#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from std_msgs.msg import String

#tried String and it works, but i want to try with other types.
from std_msgs.msg import Int8


class IntroPublisher(Node):
    def __init__(self):
        super().__init__("intro_publisher") #constructor initializes with name
        
        #recall that a topic is like a bus that carries a message of some type.
        #in this case we use the String type from std_msgs as our message.
        # we set our buffer (queue size) to hold 5 messages.
         
        # Publisher for String messages on 'string_topic'
        self.string_publisher_ = self.create_publisher(String, 'string_topic', 5)
        # Publisher for Int8 messages on 'int_topic'
        self.int8_publisher_ = self.create_publisher(Int8, 'int_topic', 5)
        self.count = 0
        self.timer = self.create_timer(1.0, self.timer_callback) # starts a timer that calls the timer_callback function every second.
        
    def timer_callback(self):
        # create and publish Int8 message
        int8msg = Int8()
        int8msg.data = self.count
        self.int8_publisher_.publish(int8msg)
        self.get_logger().info(f'Publishing on int_topic: x={int8msg.data}')

        # create and publish String message
        strmsg = String()
        strmsg.data = f'Hello {self.count}'
        self.string_publisher_.publish(strmsg)
        self.get_logger().info(f'Publishing on string_topic: {strmsg.data}')

        # Increment counter for next message
        self.count += 1
        
        
        
        
        

def main(args=None):
    rclpy.init(args=args)
    node = IntroPublisher() 
    rclpy.spin(node)
    
    node.destroy_node() 
    rclpy.shutdown()



if __name__ == "__main__":
	main()