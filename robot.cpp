//// Stub header: Robot implementation

#include <stdlib.h>

#include <cstdlib>
#include <string>
#include <vector>
#include <iostream>

#include "robot.h"

namespace GreedyRobot {
  
  Robot::Robot() {
    origin_.SetPoint(0,0);
    maxDistance_ = 0;
  }

  Robot::Robot(const Point &origin, const int &maxDistance) {
    origin_ = origin;
    maxDistance_ = abs(maxDistance);
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
    maxDistance_ = abs(maxDistance);
  }

  Point Robot::Origin() const {
    return origin_;
  }

  void Robot::SetOrigin(const Point &origin) {
    origin_ = origin;
  }


  // Generates/returns a vector of strings containing each valid path to `dest`.
  // Keeps track of max distance when travelling from one "recurse" to the next
  // via `combo`. Adds iteration's copy of `path` to vector when `curr` matches
  // `combo` with a non-empty string. Uses a greedy algorithm that checks each
  // cardinal direction in the order of N, E, W, S for a decrease in distance.
  //
  // Args:
  // `curr` : current iteration's location
  // `combo`: current iteration's trajectory
  // `dest` : destination (passed by ref, not edited)
  // `path` : directions from robot's initial start value to `curr` in a string
  //          format where each char is a step in a cardinal direction
  // Returns:
  //  paths : list of sucessful `path`s. Static to allow all recurses to push
  //          valid paths to a single location.
  std::vector<std::string> Robot::GeneratePaths(const Point &dest, Point curr,
                                         Point combo, std::string path) {
     
    //Keep this alive for the whole process, so that no outside var is req'd.
    static std::vector<std::string> paths;

    //Robot is on the point? Appends the valid path
    if(curr == dest) {
      if(path != ""){
        paths.push_back(path);
      }
      return paths;
    }
    
    Point working;
    Point difference;
    difference = curr - dest;
    Direction cardinal = NORTH;
    
    //Test each cardinal direction for progress
    //Loop could be used, but would make this less understandable
    //Only the first iteration is annotated to keep this readable

    //North : Positive Y

    //Checks to see if moving North reduces the difference's magnitude and has
    //not been otherwise exhausted from max 
    if(abs((difference.y_ + 1)) < abs(difference.y_) && 
       combo.y_ < MaxDistance()) {
      
      working = combo;  //Save

      //Checks to see if trajectory is now different than last "recurse"
      if(!combo.IsInDirection(cardinal)) {
        combo.SetPoint(0,0);  //Reset for next recurse
      }
      
      //"Moves" to valid spot, gets spot and trajectory combo copied via pass by 
      //value into recurse. After which reloads/retreats to previous state
      curr.y_++;
      combo.y_++;
      GeneratePaths(dest, curr, combo, path + "N"); 
      combo = working;  //Reload
      curr.y_--;
    }

    //East : Positive X
    cardinal = EAST;
    if(abs((difference.x_ + 1)) < abs(difference.x_) && 
       combo.x_ < MaxDistance()) {
      
      working = combo;

      if(!combo.IsInDirection(cardinal)) {
        combo.SetPoint(0,0);
      }
      
      curr.x_++;
      combo.x_++;
      GeneratePaths(dest, curr, combo, path + "E");
      combo = working;
      curr.x_--;
    }

    //South : Negative Y
    cardinal = SOUTH;
    if(abs((difference.y_ - 1)) < abs(difference.y_) && 
       abs(combo.y_) < MaxDistance()) {
      
      working = combo;

      if(!combo.IsInDirection(cardinal)) {
        combo.SetPoint(0,0);
      }
      
      curr.y_--;
      combo.y_--;
      GeneratePaths(dest, curr, combo, path + "S");
      combo = working;
      curr.y_++;
    }

    //West : Negative X
    cardinal = WEST;
    if(abs((difference.x_ - 1)) < abs(difference.x_) && 
       abs(combo.x_) < MaxDistance()) {
      
      working = combo;

      if(!combo.IsInDirection(cardinal)) {
        combo.SetPoint(0,0);
      }
      
      curr.x_--;
      combo.x_--;
      GeneratePaths(dest, curr, combo, path + "W");
      combo = working;
      curr.x_++;
    }
    //Every direction is exhausted. Give up. Go back a level.
    return paths;
  }

}
