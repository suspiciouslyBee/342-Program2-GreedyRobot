////
//  File: Robot
//
//  Author: June
//
//  Class: 342
//
//  Description: Robot class that represents position. Has a recursive method
//  for moving to a point in the shortest path.
////

#ifndef ROBOT_H_
#define ROBOT_H_

#include <cstdlib>
#include <string>
#include <vector>

#include "point.h"


namespace GreedyRobot {

  class Robot {
  public:
    //GoF
    Robot();
    Robot(const Point &origin, const int &maxDistance);
    Robot(const Robot &rhs);
    ~Robot();
    
    //Function returns a vector list of paths meeting shortest distance. User
    //shall keep retain a copy if needed, can count vector elements for number
    //of valid paths
    std::vector<std::string> GeneratePaths(const Point &dest, Point curr, 
                                           Point combo, std::string path);
    int MaxDistance() const;
    void SetMaxDistance(const int &maxDistance);

    Point Origin() const;
    void SetOrigin(const Point &origin);
  private:

    Point origin_;
    int maxDistance_;
  };
}

#endif //ROBOT_H_
