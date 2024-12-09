#include <math.h>
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "rational_numbers.h"


int greatest_common_divisor(int a, int b) {
	while (b != 0) {
		int temp = b;
		b = a % b;
		a = temp;
	}
	return abs(a);
}

//Начало арифметики
Rational add(Rational a, Rational b) {

	int numerator = a.numerator * b.denominator + b.numerator * a.denominator;
	int denominator = a.denominator * b.denominator;

	return create(numerator, denominator);
}

Rational subtract(Rational a, Rational b) {

	int numerator = a.numerator * b.denominator - b.numerator * a.denominator;
	int denominator  = a.denominator * b.denominator;

	return create(numerator, denominator);
}

Rational multiply(Rational a, Rational b) {

	int numerator = a.numerator * b.numerator;
	int denominator = a.denominator * b.denominator;

	return create(numerator, denominator);
}

Rational divide(Rational a, Rational b) {

	int numerator = a.numerator * b.denominator;
	int denominator = a.denominator * b.numerator;

	return create(numerator, denominator);
}

Rational power(Rational r, int power) {

	int abs_power = abs(power);

	int numer = r.numerator;
	int denom = r.denominator;

	int numerator = pow(numer, abs_power);
	int denominator = pow(denom, abs_power);

	if (power < 0) {
		int temp = denominator;
		denominator = numerator;
		numerator = temp;
	}

	return create(numerator, denominator);
}
//Конец арифметики

Rational create(int numer, int denom) {

	Rational result;
	result.numerator = numer;
	result.denominator = denom;

	int gcd = greatest_common_divisor(result.numerator, result.denominator);

	result.numerator = result.numerator / gcd;
	result.denominator = result.denominator / gcd;

	return result;
}

int compare(Rational a, Rational b) {

	int first_numerator = a.numerator * b.denominator;
	int second_numerator = b.numerator * a.denominator;

	if ( first_numerator == second_numerator) {
		return 0;
	}
	else {
		return first_numerator < second_numerator ? -1 : 1;
	}
}

int to_int(Rational r) {
	return r.numerator / r.denominator;
}

float to_float(Rational r) {
	return (float)r.numerator / r.denominator;
}

void to_str(Rational r) {
	printf("\n%d/%d\n", r.numerator, r.denominator);
}

