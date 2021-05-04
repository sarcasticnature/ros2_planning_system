// Copyright 2019 Intelligent Robotics Lab
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef PLANSYS2_PROBLEM_EXPERT__PROBLEMEXPERTCLIENT_HPP_
#define PLANSYS2_PROBLEM_EXPERT__PROBLEMEXPERTCLIENT_HPP_

#include <optional>
#include <string>
#include <vector>

#include "plansys2_problem_expert/ProblemExpertInterface.hpp"

#include "plansys2_msgs/msg/node.hpp"
#include "plansys2_msgs/msg/param.hpp"
#include "plansys2_msgs/msg/tree.hpp"
#include "plansys2_msgs/srv/add_problem_goal.hpp"
#include "plansys2_msgs/srv/affect_node.hpp"
#include "plansys2_msgs/srv/affect_param.hpp"
#include "plansys2_msgs/srv/exist_node.hpp"
#include "plansys2_msgs/srv/get_problem.hpp"
#include "plansys2_msgs/srv/get_problem_goal.hpp"
#include "plansys2_msgs/srv/get_problem_instance_details.hpp"
#include "plansys2_msgs/srv/get_problem_instances.hpp"
#include "plansys2_msgs/srv/get_node_details.hpp"
#include "plansys2_msgs/srv/get_states.hpp"
#include "plansys2_msgs/srv/is_problem_goal_satisfied.hpp"
#include "plansys2_msgs/srv/remove_problem_goal.hpp"
#include "plansys2_msgs/srv/clear_problem_knowledge.hpp"

#include "rclcpp/rclcpp.hpp"

namespace plansys2
{

class ProblemExpertClient : public ProblemExpertInterface
{
public:
  explicit ProblemExpertClient(rclcpp::Node::SharedPtr provided_node);

  std::vector<plansys2_msgs::msg::Param> getInstances();
  bool addInstance(const plansys2::Instance & instance);
  bool removeInstance(const plansys2::Instance & instance);
  std::optional<plansys2_msgs::msg::Param> getInstance(const std::string & name);

  std::vector<plansys2_msgs::msg::Node> getPredicates();
  bool addPredicate(const plansys2_msgs::msg::Node & predicate);
  bool removePredicate(const plansys2_msgs::msg::Node & predicate);
  bool existPredicate(const plansys2_msgs::msg::Node & predicate);
  std::optional<plansys2_msgs::msg::Node> getPredicate(const std::string & predicate);

  std::vector<plansys2_msgs::msg::Node> getFunctions();
  bool addFunction(const plansys2_msgs::msg::Node & function);
  bool removeFunction(const plansys2_msgs::msg::Node & function);
  bool existFunction(const plansys2_msgs::msg::Node & function);
  bool updateFunction(const plansys2_msgs::msg::Node & function);
  std::optional<plansys2_msgs::msg::Node> getFunction(const std::string & function);

  plansys2_msgs::msg::Tree getGoal();
  bool setGoal(const plansys2_msgs::msg::Tree & goal);
  bool clearGoal();
  bool clearKnowledge();
  bool isGoalSatisfied(const plansys2_msgs::msg::Tree & goal);

  std::string getProblem();

private:
  rclcpp::Client<plansys2_msgs::srv::AddProblemGoal>::SharedPtr
    add_problem_goal_client_;
  rclcpp::Client<plansys2_msgs::srv::AffectParam>::SharedPtr
    add_problem_instance_client_;
  rclcpp::Client<plansys2_msgs::srv::AffectNode>::SharedPtr
    add_problem_predicate_client_;
  rclcpp::Client<plansys2_msgs::srv::AffectNode>::SharedPtr
    add_problem_function_client_;
  rclcpp::Client<plansys2_msgs::srv::GetProblemGoal>::SharedPtr
    get_problem_goal_client_;
  rclcpp::Client<plansys2_msgs::srv::GetProblemInstanceDetails>::SharedPtr
    get_problem_instance_details_client_;
  rclcpp::Client<plansys2_msgs::srv::GetProblemInstances>::SharedPtr
    get_problem_instances_client_;
  rclcpp::Client<plansys2_msgs::srv::GetNodeDetails>::SharedPtr
    get_problem_predicate_details_client_;
  rclcpp::Client<plansys2_msgs::srv::GetStates>::SharedPtr
    get_problem_predicates_client_;
  rclcpp::Client<plansys2_msgs::srv::GetNodeDetails>::SharedPtr
    get_problem_function_details_client_;
  rclcpp::Client<plansys2_msgs::srv::GetStates>::SharedPtr
    get_problem_functions_client_;
  rclcpp::Client<plansys2_msgs::srv::GetProblem>::SharedPtr
    get_problem_client_;
  rclcpp::Client<plansys2_msgs::srv::RemoveProblemGoal>::SharedPtr
    remove_problem_goal_client_;
  rclcpp::Client<plansys2_msgs::srv::ClearProblemKnowledge>::SharedPtr
    clear_problem_knowledge_client_;
  rclcpp::Client<plansys2_msgs::srv::AffectParam>::SharedPtr
    remove_problem_instance_client_;
  rclcpp::Client<plansys2_msgs::srv::AffectNode>::SharedPtr
    remove_problem_predicate_client_;
  rclcpp::Client<plansys2_msgs::srv::AffectNode>::SharedPtr
    remove_problem_function_client_;
  rclcpp::Client<plansys2_msgs::srv::ExistNode>::SharedPtr
    exist_problem_predicate_client_;
  rclcpp::Client<plansys2_msgs::srv::ExistNode>::SharedPtr
    exist_problem_function_client_;
  rclcpp::Client<plansys2_msgs::srv::AffectNode>::SharedPtr
    update_problem_function_client_;
  rclcpp::Client<plansys2_msgs::srv::IsProblemGoalSatisfied>::SharedPtr
    is_problem_goal_satisfied_client_;
  rclcpp::Node::SharedPtr node_;
};

}  // namespace plansys2

#endif  // PLANSYS2_PROBLEM_EXPERT__PROBLEMEXPERTCLIENT_HPP_
