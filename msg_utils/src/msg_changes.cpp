#include <ros/ros.h>
#include <geometry_msgs/Pose.h>
#include <geometry_msgs/PoseStamped.h>

void msg_callback(const geometry_msgs::PoseConstPtr &pose, ros::NodeHandle& nh) {
    ros::Publisher msg_pub = nh.advertise<geometry_msgs::PoseStamped>("/ardrone_1/vi_sensor/ground_truth/posestamped", 1000);
    geometry_msgs::PoseStamped msg;
    msg.pose = *pose;
    msg.header.stamp = ros::Time::now();
    msg_pub.publish(msg);
    ros::spin();
}

int main(int argc, char *argv[])
{
    ros::init(argc, argv, "msg_changes");  
    ros::NodeHandle nh;
    ros::Subscriber msg_sub = nh.subscribe<geometry_msgs::Pose>("/ardrone_1/vi_sensor/ground_truth/pose", 1000, boost::bind(msg_callback, _1, nh));
    ros::spin();
    return 0;
}
