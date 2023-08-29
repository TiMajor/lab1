#include "ros/ros.h"
#include "turtlesim/Pose.h"
#include "geometry_msgs/Twist.h"


void turtleCallback(const turtlesim::Pose::ConstPtr& msg);


int main (int argc, char **argv)
{
	// Initialize the node, setup the NodeHandle for handling the communication with the ROS
	//system
	ros::init(argc, argv, "turtlebot_subscriber");
ros::NodeHandle n;
	ros::Subscriber sub = n.subscribe("turtle1/pose", 1,turtleCallback);
	
	// Define the subscriber to turtle's position;
	ros::Publisher pub=n.advertise<geometry_msgs::Twist>("turtle1/cmd_vel", 1000);
	
	ros::Rate loop_rate(1);
	while (ros::ok())
  {
	geometry_msgs::Twist my_vel;
	my_vel.linear.x = 1.0;
	my_vel.linear.y = 0.0;
	my_vel.linear.z = 0.0;
	my_vel.angular.x = 0.0;
	my_vel.angular.y = 0.0;
	my_vel.angular.z = 1.0;
	pub.publish(my_vel);
	ros::spinOnce();
	loop_rate.sleep();
  }
	

	return 0;
}
void turtleCallback(const turtlesim::Pose::ConstPtr& msg)
{
	ROS_INFO("Turtle subscriber@[%f, %f, %f]",
	msg->x, msg->y, msg->theta);
	
}