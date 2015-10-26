#!/usr/bin/env python
__author__ = 'flier'

import rospy
from leap_motion.msg import leap
from leap_motion.msg import leapros
from std_msgs.msg import UInt16

# Native datatypes, I've heard this is bad practice, use the geometry messages instead.
# def callback(data):
#    rospy.loginfo(rospy.get_name() + ": Leap Raw Data %s" % data)

pub_for_move = rospy.Publisher('leap_move', UInt16, queue_size=10)

# Callback of the ROS subscriber, just print the received data.
def callback_ros(data):
    rospy.loginfo(": Leap ROS Data %s" % data.palmpos)
    msg=0
    if data.palmpos.y <= 100:
        msg = msg | (1<<16)
    elif data.palmpos.y >= 300:
        msg = msg | (1<<15)
    elif data.palmpos.x <= -100:
        msg = msg | (1<<14)
    elif data.palmpos.x >= 70:
        msg = msg | (1<<13)
    rospy.loginfo(": Move Data %s" % msg)
    pub_for_move.publish(msg)
    


# Yes, a listener aka subscriber ;) obviously. Listens to: leapmotion/data
def listener():
    rospy.init_node('leap_sub', anonymous=True)
    # rospy.Subscriber("leapmotion/raw", leap, callback)
    rospy.Subscriber("leapmotion/data", leapros, callback_ros)
    rospy.spin()


if __name__ == '__main__':
    listener()
