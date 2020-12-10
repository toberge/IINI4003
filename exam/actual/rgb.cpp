#include <algorithm>
#include <iostream>

using namespace std;

// Thanks to C++'s templating system, we do not need more than these two type-specific functions

/// Clamps an RGB integer value
int clamp_rgb(int value) {
  if (value > 255) return 255;
  if (value < 0) return 0;
  return value;
}

/// Clamps an RGB floating point value
double clamp_rgb(double value) {
  if (value > 1.0) return 1.0;
  if (value < 0.0) return 0.0;
  return value;
}

/// General class for RGB colors
/// Either double or int -> generics FTW!
template<typename number>
class RGB {
private:
  number red;
  number green;
  number blue;

public:
  /// Initialize all values as argument value (and clamp them)
  RGB(number value)
    : red(clamp_rgb(value)),
      green(clamp_rgb(value)),
      blue(clamp_rgb(value)) {}

  /// Initialize each value specifically (and clamp them)
  RGB(number red, number green, number blue)
    : red(clamp_rgb(red)),
      green(clamp_rgb(green)),
      blue(clamp_rgb(blue)) {}

  /// Add <value> to all components of this color, return a new RGB instance
  RGB operator+(number value) const {
    return RGB(red + value, green + value, blue + value);
  }

  /// Add two RGB colors together, return the combined color
  RGB operator+(const RGB &other) const {
    return RGB(red + other.red, green + other.green, blue + other.blue);
  }

  /// Overload for printing a color
  friend ostream &operator<<(ostream &os, const RGB &rgb) {
    return os << "(" << rgb.red   << ", "
                     << rgb.green << ", "
                     << rgb.blue  << ")";
  }
};


/*
 * Should match
 * (0.5, 0.5, 0.5)
 * (0.8, 0.8, 0.8)
 * (1, 0.9, 0.9)
 * (130, 130, 130)
 * (190, 190, 190)
 * (255, 220, 220)
 * ...and it *does* match up, yay
 */
int main() {
  {
    // Double version
    RGB<double> rgb(0.5);
    std::cout << rgb << std::endl;
    // Add singular number
    std::cout << rgb + 0.3 << std::endl;
    // Add another color!
    std::cout << rgb + 0.3 + RGB<double>(0.5, 0.1, 0.1) << std::endl;
  }
  {
    // Integer version
    RGB<int> rgb(130);
    std::cout << rgb << std::endl;
    // Add singular number
    std::cout << rgb + 60 << std::endl;
    // Add another color!
    std::cout << rgb + 60 + RGB<int>(100, 30, 30) << std::endl;
  }
}

// vim:softtabstop=2:shiftwidth=2
