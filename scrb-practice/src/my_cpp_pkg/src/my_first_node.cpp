#include "rclcpp/rclcpp.hpp"
//class inherits from rclcpp::Node
class ClassNode : public rclcpp::Node
	{
		public:
		       ClassNode() : Node("named_node"), counter_(0)
		{       //this-> just indicates its coming from the node class. not mandatory.
			RCLCPP_INFO(this->get_logger(), "msg from the class");		
			timer_ = this->create_wall_timer(std::chrono::seconds(1), std::bind(&ClassNode::timerCallback,this));


		}

		private:

			void timerCallback(){
				RCLCPP_INFO(this->get_logger(), "another msg %d",counter_);
				counter_++;
			}
			rclcpp::TimerBase::SharedPtr timer_;//_ to denote private attribute
			int counter_;
	
	};



int main(int argc, char **argv){ 
    rclcpp::init(argc,argv);
    auto node = std::make_shared<ClassNode>(); 
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}
