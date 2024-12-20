#pragma once


typedef struct {
	int numerator;
	int denominator;
} Rational;


Rational add(Rational a, Rational b);
Rational subtract(Rational a, Rational b);
Rational multiply(Rational a, Rational b);
Rational divide(Rational a, Rational b);
Rational power(Rational r, int power);
Rational create(int numer, int denom);
int compare(Rational a, Rational b);
int to_int(Rational r);
float to_float(Rational r);
void to_str(Rational r);

