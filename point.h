//// 
//  File: Point 
//  
//  Author: June
//  
//  Class: 342
//
//  Description: Basic point class with primatives. Supports up to 1 billion in
//  Any cardinal direction. Defines cardinal directions within GreedyRobot 
//  namespace
////

#ifndef POINT_H_
#define POINT_H_

#include <stdlib.h>

#include <cstdlib>
#include <iostream>

namespace GreedyRobot {

  enum Direction {
    NORTH,
    EAST,
    SOUTH,
    WEST
  };

  class Point {
  public:
    
    Point();
    Point(const int &x, const int &y);
    Point(const Point &rhs);
    ~Point();
    
    void SetPoint(const int &x, const int &y);

    bool operator==(const Point &rhs) const;
    bool operator!=(const Point &rhs) const;

    Point operator-() const;

    Point operator+(const Point &rhs) const;
    Point operator-(const Point &rhs) const;

    void operator=(const Point &rhs);
    void operator-=(const Point &rhs);
    void operator+=(const Point &rhs);

    bool IsInDirection(const Direction entry) const;
    //Checked every SetPoint call
    bool ExceededLimit() const;

    //Kept public due to being essentially an overgrown struct
    int x_;
    int y_;
  };
}

#endif //POINT_H_
