#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

// TODO build with this package maybe?
#include "sensor_msgs/msg/magnetic_field.hpp"

class ImuSubscriber : public rclcpp::Node
{


	public:
		ImuSubscriber() : Node("imu_subscriber") {//constructor

			//the yaw (i.e. the untransformed cardinal direction) is taken from the topic "imu_data_msg" which is published from the tm_imu_node.cpp's MagneticField
			
			yaw_subscription_ = this->create_subscription<sensor_msgs::msg::MagneticField>(//TODO include sensor msgs
				"imu_data_rpy", //topic 
				5,  //queue depth (i.e. how many msgs to buffer if they arrive faster than callback can call them)
				std::bind(&ImuSubscriber::callback, this, std::placeholders::_1)); /*binds the function to be called when a message arrives*/
		}
		


	private:
		void callback(const sensor_msgs::msg::MagneticField::SharedPtr msg)
		{

			double yaw = msg->magnetic_field.z;

			const char * direction = "↖ NW";
			if (yaw >= 337.5 || yaw < 22.5)
				direction = "↑ N";
			else if (yaw < 67.5)
				direction = "↗ NE";
			else if (yaw < 112.5)
				direction = "→ E";
			else if (yaw < 157.5)
				direction = "↘ SE";
			else if (yaw < 202.5)
				direction = "↓ S";
			else if (yaw < 247.5)
				direction = "↙ SW";
			else if (yaw < 292.5)
				direction = "← W";

			RCLCPP_INFO(this->get_logger(), "%s | yaw: %.2f", direction, yaw);


			//RCLCPP_INFO(this->get_logger(), "YAW: %f", yaw);
		
			
		}

		rclcpp::Subscription<sensor_msgs::msg::MagneticField>::SharedPtr yaw_subscription_;


};
	



int main(int argc, char **argv){

	rclcpp::init(argc, argv);
	rclcpp::spin(std::make_shared<ImuSubscriber>());
	rclcpp::shutdown();
	return 0;
}
