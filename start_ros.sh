#source set_ros_ip.sh
source devel/setup.bash
rosnode kill -a

# run other launch files on any launch file 
# this is example shell script 
# convert pub_node to Lead Launch file that run other launch file
roslaunch pub_node pub_node.launch

