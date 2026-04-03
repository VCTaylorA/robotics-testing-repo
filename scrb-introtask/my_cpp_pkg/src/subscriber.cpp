#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

class IntroSubscriber : public rclcpp::Node
{


	public:
		IntroSubscriber() : Node("intro_subscriber") {//constructor
			//this-> is the equivalent of using self.
			//<std_msg...> defines the type	
			//we use the string_topic topic and set the queue/buffer to 5.
						
			auto string_subscriber_ = this->create_subscriber<std_msgs::msg::String >("string_topic",5);
			//params are period, callback, group
			auto timer_=this->create_wall_timer(
					//std::bind(a,b) makes it so that function a is called from b (maybe??)
					std::bind(&IntroPublisher::timer_callback, this)
			
					
					);
		}
		


	private:
		void callback(const =){
		RCLCPP_INFO(this->get_logger(), "I heard: %s", msg->data.c_str());// instead of using (*msg).data we use msg->data
		
		
		}

		
		


};
	



int main(int argc, char **argv){
	rclcpp::init(argc, argv);



	rclcpp::shutdown();
	return 0;
}
