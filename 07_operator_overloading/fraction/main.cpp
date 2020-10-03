#include "fraction.hpp"
#include <iostream>
#include <string>

using namespace std;

void print(const string &text, const Fraction &broek) {
  cout << text << broek.numerator << " / " << broek.denominator << endl;
}

int main() {
  Fraction a(10, 20);
  Fraction b(3, 4);
  Fraction c;
  c.set(5);
  Fraction d = a / b;
  int x;

  print("a = ", a);
  print("b = ", b);
  print("c = ", c);
  print("d = ", d);

  b += a;
  ++c;
  d *= d;

  print("b = ", b);
  print("c = ", c);
  print("d = ", d);

  c = a + b - d * a;
  c = -c;

  print("c = ", c);

  if (a + b != c + d)
    cout << "a + b != c + d" << endl;
  else
    cout << " a + b == c + d" << endl;
  while (b > a)
    b -= a;
  print("b = ", b);

  x = 9;

  print("a + x = ", a + x);
  print("x + a = ", x + a);

  print("a - x = ", a - x);
  print("x - a = ", x - a);

  a += x;
  print("a = ", a);

  a -= x;
  print("a = ", a);
}
