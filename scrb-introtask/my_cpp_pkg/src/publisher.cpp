#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
//base package and msg string type

class IntroPublisher : public rclcpp::Node 
{

    
	public:
		//the declaration of count_(0) declares together WITH the constructor instead of within it.
		IntroPublisher() : Node("intro_publisher"),count_(0) {//constructor
			//this-> is the equivalent of using self.
			//<std_msg...> defines the type	
			//we use the string_topic topic and set the queue/buffer to 5.
						
			
			auto string_publisher_=this->create_publisher<std_msgs::msg::String>("string_topic",5);
			//params are period, callback, group
			auto timer_=this->create_wall_timer(
					std::chrono::seconds(1), //every second
					//std::bind(a,b) makes it so that function a is called from b (maybe??)
					std::bind(&IntroPublisher::timer_callback, this)
					);:
		}
		


	private:
		void timer_callback(){
			auto msg = std_msgs::msg::String();
			msg.data = "Hello " + std::to_string(count_++);
			RCLCPP_INFO(this->get_logger(),"Publishing: %s", msg.data.c_str());
			publisher_->publish(msg);
		}
		rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_; // Publisher
		rclcpp::TimerBase::SharedPtr timer_;
		int count_;


};
	



int main(int argc, char **argv){
	rclcpp::init(argc, argv);
	auto node = std::make_shared<IntroPublisher>(); 
	rclcpp::spin(node);
	rclcpp::shutdown();
	return 0;
}
