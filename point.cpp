//// Stub header: Point implementation

#include "point.h"

namespace GreedyRobot {
  
  Point::Point() {
    x_ = 0;
    y_ = 0;
  }

  Point::Point(const int &x, const int &y) {
    x_ = x;
    y_ = y;
  }

  Point::Point(const Point &rhs) {
    x_ = rhs.x_;
    y_ = rhs.y_;
  }

  Point::~Point() {
    this.Point();
  }

  void SetPoint(const int &x, const int &y) {
    x_ = x;
    y_ = y;
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
    setPoint(x_, y_);
  }

  void Point::operator-=(const Point &rhs) {
    *this = *this - rhs;
  }

  void Point::operator+=(const Point &rhs) {
    *this = *this + rhs;
  }
  
}
