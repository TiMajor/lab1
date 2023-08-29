#include "ros/ros.h"
#include "turtlesim/Spawn.h"

int main (int argc, char **argv)
{
	// Initialize the node, setup the NodeHandle for handling the communication with the ROS
	//system
	ros::init(argc, argv, "spawner");
ros::NodeHandle nh;
	ros::ServiceClient client1 = nh.serviceClient<turtlesim::Spawn>("/spawn");

	turtlesim::Spawn srv1;
    srv1.request.x=1.0;
	srv1.request.y=5.0;
    srv1.request.theta=0.0;
    srv1.request.name= "Turtle_Yernazar";
    client1.call(srv1);

	return 0;
}