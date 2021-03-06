

#include <moveit/move_group_interface/move_group.h>
#include <moveit/planning_scene_interface/planning_scene_interface.h>

#include <moveit_msgs/DisplayRobotState.h>
#include <moveit_msgs/DisplayTrajectory.h>

#include <moveit_msgs/AttachedCollisionObject.h>
#include <moveit_msgs/CollisionObject.h>

#include <iostream>

#include <industrial_trajectory_filters/filter_base.h>
#include <industrial_trajectory_filters/uniform_sample_filter.h>

// For time parametrisation
#include <moveit/trajectory_processing/iterative_time_parameterization.h>

int main(int argc, char **argv)
{
  ros::init(argc, argv, "move_group_interface_tutorial");
  ros::NodeHandle node_handle;  
  ros::AsyncSpinner spinner(1);
  spinner.start();
  
  moveit::planning_interface::MoveGroup group("arm_gp");

  moveit::planning_interface::PlanningSceneInterface planning_scene_interface;  

  ros::Publisher display_publisher = node_handle.advertise<moveit_msgs::DisplayTrajectory>("/move_group/display_planned_path", 1, true);
  moveit_msgs::DisplayTrajectory display_trajectory;
  
  moveit::planning_interface::MoveGroup::Plan my_plan;

	// Get the robot at a writing position
  std::vector<double> group_variable_values;
  // Get the current state in joint-space
	group.getCurrentState()->copyJointGroupPositions(group.getCurrentState()->getRobotModel()->getJointModelGroup(group.getName()), group_variable_values);
	group_variable_values[0] = 0.00030141533641;
  group_variable_values[1] = -0.282702579197;
  group_variable_values[2] = 2.02282357331;
  group_variable_values[3] = 1.40210660429;
  group_variable_values[4] = 2.2867037502e-07;
	group.setJointValueTarget(group_variable_values);
	group.plan(my_plan);
	group.execute(my_plan);
	
	
	
	// Now to make a drawing
	geometry_msgs::Pose start_pose = group.getCurrentPose().pose;
  geometry_msgs::Pose target_pose = start_pose;

	// Creating the sine data
	double amplitude = 0.1;
	double w = 30.0;
	double step = 0.01;
	double upperLimit_x = 0.2;
	double lowerLimit_x = -0.2;
	double offset = 0.15;
	int size = round( (upperLimit_x - lowerLimit_x)/step) + 1;
	double x[size];
	double y[size];
	x[0] = lowerLimit_x;
	for(int i = 1; i < size; i++) {
		x[i] = x[i-1] + step;
	}
	for(int i = 0; i < size; i++) {
		y[i] = amplitude*sin((x[i]+offset)*w)+0.3;
	}
	
	// Inserting the sine data to waypoints
	std::vector<geometry_msgs::Pose> waypoints;
	for(int i = 0; i < size; i++) {
		target_pose.position.x = y[i];
		target_pose.position.y = x[i];
		waypoints.push_back(target_pose);
	}
	// The same sine data but backwards
	for(int i = size-1; i != -1; i--) {
		target_pose.position.x = y[i];
		target_pose.position.y = x[i];
		waypoints.push_back(target_pose);
	}
	
	// Back to start position
	waypoints.push_back(start_pose);

  moveit_msgs::RobotTrajectory trajectory;
  double fraction = group.computeCartesianPath(waypoints,
                                               0.05,  // eef_step
                                               0.0,   // jump_threshold
                                               trajectory);
  ROS_INFO("Visualizing plan 4 (cartesian path) (%.2f%% acheived)",
        fraction * 100.0);    

	// Adding time parametrization to the "trajectory"
  robot_trajectory::RobotTrajectory rt(group.getCurrentState()->getRobotModel(), "arm_gp");
  rt.setRobotTrajectoryMsg(*group.getCurrentState(), trajectory);
  trajectory_processing::IterativeParabolicTimeParameterization iptp;
  bool success = iptp.computeTimeStamps(rt);
  ROS_INFO("Computed time stamp %s",success?"SUCCEDED":"FAILED");
  rt.getRobotTrajectoryMsg(trajectory);
  
  // Filtering the "trajectory" with Uniform Sampler
  industrial_trajectory_filters::MessageAdapter t_in;
  t_in.request.trajectory = trajectory.joint_trajectory;
  industrial_trajectory_filters::MessageAdapter t_out;
  industrial_trajectory_filters::UniformSampleFilterAdapter adapter;
  adapter.update(t_in, t_out);
  
  // Adding the "trajectory" to the plan.
	trajectory.joint_trajectory = t_out.request.trajectory;
  my_plan.trajectory_ = trajectory;
	if (fraction == 1.0) {
		group.execute(my_plan);
	} else
		ROS_WARN("Could not compute the cartesian path :( ");
// END_TUTORIAL

  ros::shutdown();  
  return 0;
}

