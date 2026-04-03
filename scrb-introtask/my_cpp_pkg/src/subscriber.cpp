#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
//see publisher.cpp for more comments on the methods (theyre relatively similar)
class IntroSubscriber : public rclcpp::Node
{


	public:
		IntroSubscriber() : Node("intro_subscriber") {//constructor
			//<std_msg...> defines the type	
			//we use the string_topic topic and set the queue/buffer to 5.
						
			string_subscription_ = this->create_subscription<std_msgs::msg::String>(
				"string_topic", 5, std::bind(&IntroSubscriber::callback, this, std::placeholders::_1));
		}
		


	private:
		void callback(const std_msgs::msg::String::SharedPtr msg)
		{
			RCLCPP_INFO(this->get_logger(), "I heard: %s", msg->data.c_str());
		}

		rclcpp::Subscription<std_msgs::msg::String>::SharedPtr string_subscription_;


};
	



int main(int argc, char **argv){

	rclcpp::init(argc, argv);
	rclcpp::spin(std::make_shared<IntroSubscriber>());
	rclcpp::shutdown();
	return 0;
}
