#include "ros/ros.h"
#include "std_msgs/String.h"

#include <sstream>

int main(int argc, char **argv)
{
    
    //start the node, must be used before using any other part of the ROS system
    ros::init(argc, argv, "talker")

    // Node handle is the main access point for communications with the ROS system. The first
    //  NodeHandle constructed will full initialize this node, and the last will close it.
    ros::NodeHandle n;

    ros::Publisher chatter_pub = n.advertise<std_msgs::String>("chatter", 1000);

    ros::Rate loop_rate(10);

    int count = 0;

    while (ros::ok())
    {
        std_msgs::String msg; // Message object, 'stuff' it full of data, then publish it

        std::stringstream ss;
        ss << "hello world" << count;
        msg.data = ss.str();

        ROS_INFO("%s", msg.data.c_str());

        // The publish function is how you send messages, the parameteris the message object.
        // The type of object must agree with the type given as a template to the advertise <>() call above.

        chatter_pub.publish(msg);

        ros::spinOnce();
        ++count;
    }


    return 0;
}   