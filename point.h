//// 
//  File: Point 
//  
//  Author: June
//  
//  Class: 342
//
//  Description: Basic point class with primatives.
////

#ifndef POINT_H_
#define POINT_H_

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

    bool IsInDirection(Direction entry);

    int x_;
    int y_;
  };
}

#endif //POINT_H_
