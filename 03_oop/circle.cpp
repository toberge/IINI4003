#include "circle.hpp"
// see circle.hpp for the class declaration

const double pi = 3.141592;

// ==> Implementasjon av klassen Circle

Circle::Circle(double radius_) : radius(radius_) {} // no need for public
// the radius attribute is initialized, was swapped with radius_ on RHS

int Circle::get_area() const { // missing const
  return pi * radius * radius;
}

double Circle::get_circumference() const { // no return type
  /* double circumference = 2.0 * pi * radius; // undeclared... */
  /* return circumference; */
    return 2.0 * pi * radius; // I do prefer this
}
