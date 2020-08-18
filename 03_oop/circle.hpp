#ifndef CIRCLE_H
#define CIRCLE_H

class Circle {
  public:
    Circle(double radius_); // not the constructor name
    int get_area() const;
    double get_circumference() const;
  private: // no :
    double radius;
}; // missing semicolon

#endif // CIRCLE_H
