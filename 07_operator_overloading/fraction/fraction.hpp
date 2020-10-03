#pragma once

class Fraction {
public:
  int numerator;
  int denominator;

  Fraction();
  Fraction(int numerator, int denominator);
  void set(int numerator_, int denominator_ = 1);
  Fraction operator+(const Fraction &other) const;
  Fraction operator+(const int number) const;
  Fraction operator-(const Fraction &other) const;
  Fraction operator-(const int number) const;
  Fraction operator*(const Fraction &other) const;
  Fraction operator/(const Fraction &other) const;
  Fraction operator-() const;
  Fraction &operator++(); // Preinkrement
  Fraction &operator--(); // Predekrement
  Fraction &operator+=(const Fraction &other);
  Fraction &operator+=(const int number);
  Fraction &operator-=(const Fraction &other);
  Fraction &operator-=(const int number);
  Fraction &operator*=(const Fraction &other);
  Fraction &operator/=(const Fraction &other);
  Fraction &operator=(const Fraction &other);
  bool operator==(const Fraction &other) const;
  bool operator!=(const Fraction &other) const;
  bool operator<=(const Fraction &other) const;
  bool operator>=(const Fraction &other) const;
  bool operator<(const Fraction &other) const;
  bool operator>(const Fraction &other) const;

private:
  void reduce();
  int compare(const Fraction &other) const;
};

Fraction operator+(int integer, const Fraction &other);
Fraction operator-(int integer, const Fraction &other);
