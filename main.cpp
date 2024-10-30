////
//  File: Robot Main
//  
//  Author: June
//
//  Class: 342
//
//  Description: Interfaces Robot to a CLI interface. 
//
//  INPUT: max_distance, robot_x, robot_y, treasure_x, treasure_y
////

#include <iostream>
#include <sstream>
#include <vector>

#include "point.h"
#include "robot.h"


int main(int argc, char *argv[]) {

  std::stringstream parser;
  int array[6] = {0};


  for(int i = 1; i < 6; i++){ 
    parser << argv[i];
    parser >> array[i];
    parser.str("");
    parser.clear();
  }

  GreedyRobot::Point origin(array[2], array[3]);
  GreedyRobot::Point treasure(array[4], array[5]);
  GreedyRobot::Robot robot(origin, array[1]);
  GreedyRobot::Point zeroTemplate(0,0);


  std::vector<std::string> answer;
  answer = robot.GeneratePaths(treasure, robot.Origin(), zeroTemplate, "");
  
  for(int i = 0; i < answer.size(); i++) {
    std::cout << answer.at(i) << std::endl;
  }
  std::cout << "Number of paths: " << answer.size() << std::endl;
  return 0;
}
