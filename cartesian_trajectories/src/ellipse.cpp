

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
  geometry_msgs::Pose target_pose2 = start_pose;
  std::vector<geometry_msgs::Pose> waypoints;
  
  waypoints.push_back(start_pose);

	// 1st quadrant
	target_pose2.position.x = 0.2001; 
	target_pose2.position.y = 0.0100;
	waypoints.push_back(target_pose2);
	target_pose2.position.x = 0.2005; 
	target_pose2.position.y = 0.0200;
	waypoints.push_back(target_pose2);
	target_pose2.position.x = 0.2011; 
	target_pose2.position.y = 0.0300;
	waypoints.push_back(target_pose2);
	target_pose2.position.x = 0.2020; 
	target_pose2.position.y = 0.0400;
	waypoints.push_back(target_pose2);
	target_pose2.position.x = 0.2032; 
	target_pose2.position.y = 0.0500;
	waypoints.push_back(target_pose2);
	target_pose2.position.x = 0.2046; 
	target_pose2.position.y = 0.0600;
	waypoints.push_back(target_pose2);
	target_pose2.position.x = 0.2063; 
	target_pose2.position.y = 0.0700;
	waypoints.push_back(target_pose2);
	target_pose2.position.x = 0.2083; 
	target_pose2.position.y = 0.0800;
	waypoints.push_back(target_pose2);
	target_pose2.position.x = 0.2107; 
	target_pose2.position.y = 0.0900;
	waypoints.push_back(target_pose2);
	target_pose2.position.x = 0.2134; 
	target_pose2.position.y = 0.1000;
	waypoints.push_back(target_pose2);
	target_pose2.position.x = 0.2165; 
	target_pose2.position.y = 0.1100;
	waypoints.push_back(target_pose2);
	target_pose2.position.x = 0.2200; 
	target_pose2.position.y = 0.1200;
	waypoints.push_back(target_pose2);
	target_pose2.position.x = 0.2240; 
	target_pose2.position.y = 0.1300;
	waypoints.push_back(target_pose2);
	target_pose2.position.x = 0.2286; 
	target_pose2.position.y = 0.1400;
	waypoints.push_back(target_pose2);
	target_pose2.position.x = 0.2339; 
	target_pose2.position.y = 0.1500;
	waypoints.push_back(target_pose2);
	target_pose2.position.x = 0.2400; 
	target_pose2.position.y = 0.1600;
	waypoints.push_back(target_pose2);
	target_pose2.position.x = 0.2473; 
	target_pose2.position.y = 0.1700;
	waypoints.push_back(target_pose2);
	target_pose2.position.x = 0.2564; 
	target_pose2.position.y = 0.1800;
	waypoints.push_back(target_pose2);
	target_pose2.position.x = 0.2688; 
	target_pose2.position.y = 0.1900;
	waypoints.push_back(target_pose2);
	target_pose2.position.x = 0.3000; 
	target_pose2.position.y = 0.2000;
	waypoints.push_back(target_pose2);
	// 2nd quadrant
	target_pose2.position.x = 0.3312; 
	target_pose2.position.y = 0.1900;
	waypoints.push_back(target_pose2);
	target_pose2.position.x = 0.3436; 
	target_pose2.position.y = 0.1800;
	waypoints.push_back(target_pose2);
	target_pose2.position.x = 0.3527; 
	target_pose2.position.y = 0.1700;
	waypoints.push_back(target_pose2);
	target_pose2.position.x = 0.3600; 
	target_pose2.position.y = 0.1600;
	waypoints.push_back(target_pose2);
	target_pose2.position.x = 0.3661; 
	target_pose2.position.y = 0.1500;
	waypoints.push_back(target_pose2);
	target_pose2.position.x = 0.3714; 
	target_pose2.position.y = 0.1400;
	waypoints.push_back(target_pose2);
	target_pose2.position.x = 0.3760; 
	target_pose2.position.y = 0.1300;
	waypoints.push_back(target_pose2);
	target_pose2.position.x = 0.3800; 
	target_pose2.position.y = 0.1200;
	waypoints.push_back(target_pose2);
	target_pose2.position.x = 0.3835; 
	target_pose2.position.y = 0.1100;
	waypoints.push_back(target_pose2);
	target_pose2.position.x = 0.3866; 
	target_pose2.position.y = 0.1000;
	waypoints.push_back(target_pose2);
	target_pose2.position.x = 0.3893; 
	target_pose2.position.y = 0.0900;
	waypoints.push_back(target_pose2);
	target_pose2.position.x = 0.3917; 
	target_pose2.position.y = 0.0800;
	waypoints.push_back(target_pose2);
	target_pose2.position.x = 0.3937; 
	target_pose2.position.y = 0.0700;
	waypoints.push_back(target_pose2);
	target_pose2.position.x = 0.3954; 
	target_pose2.position.y = 0.0600;
	waypoints.push_back(target_pose2);
	target_pose2.position.x = 0.3968; 
	target_pose2.position.y = 0.0500;
	waypoints.push_back(target_pose2);
	target_pose2.position.x = 0.3980; 
	target_pose2.position.y = 0.0400;
	waypoints.push_back(target_pose2);
	target_pose2.position.x = 0.3989; 
	target_pose2.position.y = 0.0300;
	waypoints.push_back(target_pose2);
	target_pose2.position.x = 0.3995; 
	target_pose2.position.y = 0.0200;
	waypoints.push_back(target_pose2);
	target_pose2.position.x = 0.3999; 
	target_pose2.position.y = 0.0100;
	waypoints.push_back(target_pose2);
	target_pose2.position.x = 0.4000; 
	target_pose2.position.y = 0.0000;
	waypoints.push_back(target_pose2);
	// 3rd quadrant
	target_pose2.position.x = 0.3999; 
	target_pose2.position.y = -0.0100;
	waypoints.push_back(target_pose2);
	target_pose2.position.x = 0.3995; 
	target_pose2.position.y = -0.0200;
	waypoints.push_back(target_pose2);
	target_pose2.position.x = 0.3989; 
	target_pose2.position.y = -0.0300;
	waypoints.push_back(target_pose2);
	target_pose2.position.x = 0.3980; 
	target_pose2.position.y = -0.0400;
	waypoints.push_back(target_pose2);
	target_pose2.position.x = 0.3968; 
	target_pose2.position.y = -0.0500;
	waypoints.push_back(target_pose2);
	target_pose2.position.x = 0.3954; 
	target_pose2.position.y = -0.0600;
	waypoints.push_back(target_pose2);
	target_pose2.position.x = 0.3937; 
	target_pose2.position.y = -0.0700;
	waypoints.push_back(target_pose2);
	target_pose2.position.x = 0.3917; 
	target_pose2.position.y = -0.0800;
	waypoints.push_back(target_pose2);
	target_pose2.position.x = 0.3893; 
	target_pose2.position.y = -0.0900;
	waypoints.push_back(target_pose2);
	target_pose2.position.x = 0.3866; 
	target_pose2.position.y = -0.1000;
	waypoints.push_back(target_pose2);
	target_pose2.position.x = 0.3835; 
	target_pose2.position.y = -0.1100;
	waypoints.push_back(target_pose2);
	target_pose2.position.x = 0.3800; 
	target_pose2.position.y = -0.1200;
	waypoints.push_back(target_pose2);
	target_pose2.position.x = 0.3760; 
	target_pose2.position.y = -0.1300;
	waypoints.push_back(target_pose2);
	target_pose2.position.x = 0.3714; 
	target_pose2.position.y = -0.1400;
	waypoints.push_back(target_pose2);
	target_pose2.position.x = 0.3661; 
	target_pose2.position.y = -0.1500;
	waypoints.push_back(target_pose2);
	target_pose2.position.x = 0.3600; 
	target_pose2.position.y = -0.1600;
	waypoints.push_back(target_pose2);
	target_pose2.position.x = 0.3527; 
	target_pose2.position.y = -0.1700;
	waypoints.push_back(target_pose2);
	target_pose2.position.x = 0.3436; 
	target_pose2.position.y = -0.1800;
	waypoints.push_back(target_pose2);
	target_pose2.position.x = 0.3312; 
	target_pose2.position.y = -0.1900;
	waypoints.push_back(target_pose2);
	target_pose2.position.x = 0.3000; 
	target_pose2.position.y = -0.2000;
	waypoints.push_back(target_pose2);
	// 4th quadrant
	target_pose2.position.x = 0.2688; 
	target_pose2.position.y = -0.1900;
	waypoints.push_back(target_pose2);
	target_pose2.position.x = 0.2564; 
	target_pose2.position.y = -0.1800;
	waypoints.push_back(target_pose2);
	target_pose2.position.x = 0.2473; 
	target_pose2.position.y = -0.1700;
	waypoints.push_back(target_pose2);
	target_pose2.position.x = 0.2400; 
	target_pose2.position.y = -0.1600;
	waypoints.push_back(target_pose2);
	target_pose2.position.x = 0.2339; 
	target_pose2.position.y = -0.1500;
	waypoints.push_back(target_pose2);
	target_pose2.position.x = 0.2286; 
	target_pose2.position.y = -0.1400;
	waypoints.push_back(target_pose2);
	target_pose2.position.x = 0.2240; 
	target_pose2.position.y = -0.1300;
	waypoints.push_back(target_pose2);
	target_pose2.position.x = 0.2200; 
	target_pose2.position.y = -0.1200;
	waypoints.push_back(target_pose2);
	target_pose2.position.x = 0.2165; 
	target_pose2.position.y = -0.1100;
	waypoints.push_back(target_pose2);
	target_pose2.position.x = 0.2134; 
	target_pose2.position.y = -0.1000;
	waypoints.push_back(target_pose2);
	target_pose2.position.x = 0.2107; 
	target_pose2.position.y = -0.0900;
	waypoints.push_back(target_pose2);
	target_pose2.position.x = 0.2083; 
	target_pose2.position.y = -0.0800;
	waypoints.push_back(target_pose2);
	target_pose2.position.x = 0.2063; 
	target_pose2.position.y = -0.0700;
	waypoints.push_back(target_pose2);
	target_pose2.position.x = 0.2046; 
	target_pose2.position.y = -0.0600;
	waypoints.push_back(target_pose2);
	target_pose2.position.x = 0.2032; 
	target_pose2.position.y = -0.0500;
	waypoints.push_back(target_pose2);
	target_pose2.position.x = 0.2020; 
	target_pose2.position.y = -0.0400;
	waypoints.push_back(target_pose2);
	target_pose2.position.x = 0.2011; 
	target_pose2.position.y = -0.0300;
	waypoints.push_back(target_pose2);
	target_pose2.position.x = 0.2005; 
	target_pose2.position.y = -0.0200;
	waypoints.push_back(target_pose2);
	target_pose2.position.x = 0.2001; 
	target_pose2.position.y = -0.0100;
	waypoints.push_back(target_pose2);
	waypoints.push_back(start_pose);
	
	int size = waypoints.size();
	for(int i = size-1; i != -1; i--) {
		waypoints.push_back(waypoints.at(i));
	}
	
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
	if (fraction == 1.0) 
		group.execute(my_plan);
	else
		ROS_WARN("Could not compute the cartesian path :( ");
// END_TUTORIAL

	// Arm goes back to work position
	group_variable_values[0] = 0.0;
  group_variable_values[1] = -0.938212290489;
  group_variable_values[2] = 1.8604486489;
	group_variable_values[3] = 2.21935629517;
	group_variable_values[4] = 0.0;
	group.setJointValueTarget(group_variable_values);
	group.plan(my_plan);
	group.execute(my_plan);

  ros::shutdown();  
  return 0;
}

