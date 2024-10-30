//// Stub header: Robot implementation

#include <cstdlib>
#include <string>
#include <vector>

#include "robot.h"

namespace GreedyRobot {
  
  Robot::Robot() {
    origin_.SetPoint(0,0);
    maxDistance_ = 0;
  }

  Robot::Robot(const Point &origin, const int &maxDistance) {
    origin_ = origin;
    maxDistance_ = maxDistance;
  }

  Robot::Robot(const Robot &rhs) {
    SetOrigin(rhs.Origin());
    SetMaxDistance(rhs.MaxDistance());
  }

  Robot::~Robot() {
    origin_.SetPoint(0,0);
    maxDistance_ = 0;
  }


  int Robot::MaxDistance() const {
    return maxDistance_;
  }
  
  void Robot::SetMaxDistance(const int &maxDistance) {
    maxDistance_ = maxDistance;
  }

  Point Robot::Origin() const {
    return origin_;
  }

  void Robot::SetOrigin(const Point &origin) {
    origin_ = origin;
  }

  std::vector<std::string> Robot::GeneratePaths(const Point &dest, Point curr,
                                         Point combo, std::string path) {
    //Keep this alive for the whole iteration
    static std::vector<std::string> paths;


    //Robot is on the point
    if(curr == dest) { 
      paths.push_back(path);
      return paths;
    }
    
    Point working(curr);
    Point difference;
    difference = curr - dest;
    Direction cardinal = NORTH;
    
    //Test each cardinal direction for progress

    //North : Positive Y
    if(abs((difference.y_ + 1)) < abs(difference.y_) && 
       combo.y_ < MaxDistance()) {
      
      if(!combo.IsInDirection(cardinal)) {
        combo.SetPoint(0,0);
      }
      
      curr.y_++;
      combo.y_++;
      GeneratePaths(dest, curr, combo, path + "N");
      combo.y_--;
      curr.y_--;
    }

    //East : Positive X
    cardinal = EAST;
    if(abs((difference.x_ + 1)) < abs(difference.x_) && 
       combo.x_ < MaxDistance()) {
      
      if(!combo.IsInDirection(cardinal)) {
        combo.SetPoint(0,0);
      }
      
      curr.x_++;
      combo.x_++;
      GeneratePaths(dest, curr, combo, path + "E");
      combo.x_--;
      curr.x_--;
    }

    //South : Negative Y
    cardinal = SOUTH;
    if(abs((difference.y_ - 1)) < abs(difference.y_) && 
       combo.y_ > -MaxDistance()) {
      
      if(!combo.IsInDirection(cardinal)) {
        combo.SetPoint(0,0);
      }
      
      curr.y_--;
      combo.y_--;
      GeneratePaths(dest, curr, combo, path + "S");
    }

    //West : Negative X
    cardinal = WEST;
    if(abs((difference.x_ - 1)) < abs(difference.x_) && 
       combo.x_ > -MaxDistance()) {
      
      if(!combo.IsInDirection(cardinal)) {
        combo.SetPoint(0,0);
      }
      
      curr.x_--;
      combo.x_--;
      GeneratePaths(dest, curr, combo, path + "W");
    }
    //Every direction is exhausted. Give up. Go back
    return paths;
  }

}
