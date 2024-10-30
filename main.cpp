////
//  File: Robot Main
//  
//  Author: June
//
//  Class: 342
//
//  Description: Interfaces Robot to a CLI interface. Supports a grid up to one
//  billion in each cardinal direction, where each space is each integer. Prints
//  all shortest direct paths to destination and number of paths.
//
//
//  Args:
//  `max_distance`  : Max distance in one direction robot can travel
//  `robot_x`       : Robot starting x pos
//  `robot_y`       : Robot starting y pos
//  `treasure_x`    : Treasure x pos
//  `treasure_y`    : Treasure y pos
//
//  Returns:
//    0 : Normal function
//    1 : Point under/overflow (via Point)
////

#include <iostream>
#include <sstream>
#include <vector>

#include "point.h"
#include "robot.h"


int main(int argc, char *argv[]) {

  std::stringstream parser;
  int array[5] = {0};


  for(int i = 1; i < 6; i++){ 
    parser << argv[i];
    parser >> array[i];
    parser.str(""); //Reset sstream for next var
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
