//// Stub header: Point implementation

#include <stdlib.h>

#include <cstdlib>
#include <iostream>

#include "point.h"

namespace GreedyRobot {
  
  Point::Point() {
    x_ = 0;
    y_ = 0;
  }

  Point::Point(const int &x, const int &y) {
    SetPoint(x, y);
  }

  Point::Point(const Point &rhs) {
    SetPoint(rhs.x_, rhs.y_);
  }

  Point::~Point() {
    SetPoint(0,0);
  }

  void Point::SetPoint(const int &x, const int &y) {
    
    x_ = x;
    y_ = y;
    
    //Bail if past artificial limits
    if(ExceededLimit()) {
      std::cout << "POINT OVERFLOW/UNDERFLOW" << std::endl;
      exit(1);
    }
  }

  bool Point::operator==(const Point &rhs) const {
    return ((x_ == rhs.x_) && (y_ == rhs.y_));
  }

  bool Point::operator!=(const Point &rhs) const {
    return !(*this == rhs);
  }

  Point Point::operator-() const {
    return Point(-x_, -y_);
  }
  
  Point Point::operator+(const Point &rhs) const {
    return Point(x_ + rhs.x_, y_ + rhs.y_);
  }

  Point Point::operator-(const Point &rhs) const {
   return *this + -rhs;
  }

  void Point::operator=(const Point &rhs) {
    SetPoint(rhs.x_, rhs.y_);
  }

  void Point::operator-=(const Point &rhs) {
    *this = *this - rhs;
  }

  void Point::operator+=(const Point &rhs) {
    *this = *this + rhs;
  }

  //  Checks the direction from 0,0 with the specified args
  // 
  //  Example:
  //    Point with (2,3) would return true when `entry` is NORTH or EAST
  bool Point::IsInDirection(Direction entry) const{
    switch(entry) {
    case NORTH:
      return y_ > 0;
    case EAST:
      return x_ > 0;
    case SOUTH:
      return y_ < 0;
    case WEST:
      return x_ < 0;
    default:
      return false;
    }
  }
  
  //If beyond 1 billion in any direction, return true.
  bool Point::ExceededLimit() const {
    return abs(x_) > 1000000000 || abs(y_) > 1000000000;
  }
}
