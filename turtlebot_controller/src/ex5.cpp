#include "ros/ros.h"
#include "turtlesim/Pose.h"
#include "geometry_msgs/Twist.h"
#include "turtlesim/Kill.h"
#include "turtlesim/Spawn.h"
#include "turtlesim/TeleportAbsolute.h"

void turtleCallback(const turtlesim::Pose::ConstPtr& msg);
float absx=10.0, absy=0.0, abstheta=0.0;

int main (int argc, char **argv)
{
	// Initialize the node, setup the NodeHandle for handling the communication with the ROS
	//system
	ros::init(argc, argv, "turtlebot_exercise5");
ros::NodeHandle n;
    ros::ServiceClient client1 = n.serviceClient<turtlesim::Kill>("/kill");
    turtlesim::Kill srv1;
    srv1.request.name="turtle1";
    client1.call(srv1);

    ros::ServiceClient client2 = n.serviceClient<turtlesim::Spawn>("/spawn");
	turtlesim::Spawn srv2;
    srv2.request.x=5.5;
	srv2.request.y=5.5;
    srv2.request.theta=3.14/2.0;
    srv2.request.name= "Turtle_Yernazar";
    client2.call(srv2);

	ros::ServiceClient client3 = n.serviceClient<turtlesim::TeleportAbsolute>("/Turtle_Yernazar/teleport_absolute");
	turtlesim::TeleportAbsolute srv3;
	srv3.request.x=11;
	srv3.request.y=0;
	client3.call(srv3);


	ros::Subscriber sub = n.subscribe("Turtle_Yernazar/pose", 1,turtleCallback);
	
	// Define the subscriber to turtle's position;
	ros::Publisher pub=n.advertise<geometry_msgs::Twist>("Turtle_Yernazar/cmd_vel", 1000);
	
	ros::Rate loop_rate(10);
	while (ros::ok())
  {
	geometry_msgs::Twist my_vel;
	if(absx>0.5){
	my_vel.linear.x = -4.0;
	my_vel.linear.y = 0.0;
	my_vel.linear.z = 0.0;
	my_vel.angular.x = 0.0;
	my_vel.angular.y = 0.0;
	my_vel.angular.z = 0.0;
	}
	else{
		break;
	}
	pub.publish(my_vel);
	ros::spinOnce();
	loop_rate.sleep();
  };

	while (ros::ok())
  {
	geometry_msgs::Twist my_vel;
	if(absy<10.5){
	my_vel.linear.x = 0.0;
	my_vel.linear.y = 4.0;
	my_vel.linear.z = 0.0;
	my_vel.angular.x = 0.0;
	my_vel.angular.y = 0.0;
	my_vel.angular.z = 0.0;
	}
	else{
		break;
	}
	pub.publish(my_vel);
	ros::spinOnce();
	loop_rate.sleep();
  }


while (ros::ok())
  {
	geometry_msgs::Twist my_vel;
	if(absx<10.5){
	my_vel.linear.x = 4.0;
	my_vel.linear.y = 0.0;
	my_vel.linear.z = 0.0;
	my_vel.angular.x = 0.0;
	my_vel.angular.y = 0.0;
	my_vel.angular.z = 0.0;
	}
	else{
		break;
	}
	pub.publish(my_vel);
	ros::spinOnce();
	loop_rate.sleep();
  }

while (ros::ok())
  {
	geometry_msgs::Twist my_vel;
	if(absy>0.5){
	my_vel.linear.x = 0.0;
	my_vel.linear.y = -4.0;
	my_vel.linear.z = 0.0;
	my_vel.angular.x = 0.0;
	my_vel.angular.y = 0.0;
	my_vel.angular.z = 0.0;
	}
	else{
		break;
	}
	pub.publish(my_vel);
	ros::spinOnce();
	loop_rate.sleep();
  }
//triangle
while (ros::ok())
  {
	geometry_msgs::Twist my_vel;
	if(absy<10.5){
	my_vel.linear.x = -2.0;
	my_vel.linear.y = 2.0;
	my_vel.linear.z = 0.0;
	my_vel.angular.x = 0.0;
	my_vel.angular.y = 0.0;
	my_vel.angular.z = 0.0;
	}
	else{
		break;
	}
	pub.publish(my_vel);
	ros::spinOnce();
	loop_rate.sleep();
  }
  while (ros::ok())
  {
	geometry_msgs::Twist my_vel;
	if(absy>0.5){
	my_vel.linear.x = 0.0;
	my_vel.linear.y = -2.0;
	my_vel.linear.z = 0.0;
	my_vel.angular.x = 0.0;
	my_vel.angular.y = 0.0;
	my_vel.angular.z = 0.0;
	}
	else{
		break;
	}
	pub.publish(my_vel);
	ros::spinOnce();
	loop_rate.sleep();
  }
  while (ros::ok())
  {
	geometry_msgs::Twist my_vel;
	if(absx<10.5){
	my_vel.linear.x = 2.0;
	my_vel.linear.y = 0.0;
	my_vel.linear.z = 0.0;
	my_vel.angular.x = 0.0;
	my_vel.angular.y = 0.0;
	my_vel.angular.z = 0.0;
	}
	else{
		break;
	}
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
	absx =msg->x;
	absy=msg->y;
	abstheta=msg->theta;
}