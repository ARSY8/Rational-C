#include <math.h>
#include "rational_numbers.h"


int greatest_common_divisor(int a, int b) {
	while (b != 0) {
		int temp = b;
		b = a % b;
		a = temp;
	}
	return a;
}

//Начало арифметики
Rational add(Rational a, Rational b) {
	Rational result;

	if (a.denominator == b.denominator) {
		result.numerator = a.numerator + b.numerator;
		result.denominator = a.denominator;
	}
	else {
		result.numerator = a.numerator * b.denominator + b.numerator * a.denominator;
		result.denominator = a.denominator * b.denominator;
	}

	int gcd = greatest_common_divisor(result.numerator, result.denominator);

	result.numerator = result.numerator / gcd;
	result.denominator = result.denominator / gcd;

	return result;
}

Rational subtract(Rational a, Rational b) {
	Rational result;

	if (a.denominator == b.denominator) {
		result.numerator = a.numerator - b.numerator;
		result.denominator = a.denominator;
	}
	else {
		result.numerator = a.numerator * b.denominator - b.numerator * a.denominator;
		result.denominator = a.denominator * b.denominator;
	}

	int gcd = greatest_common_divisor(result.numerator, result.denominator);

	result.numerator = result.numerator / gcd;
	result.denominator = result.denominator / gcd;

	return result;
}

Rational multiply(Rational a, Rational b) {
	Rational result;

	result.numerator = a.numerator * b.numerator;
	result.denominator = a.denominator * b.denominator;

	int gcd = greatest_common_divisor(result.numerator, result.denominator);

	result.numerator = result.numerator / gcd;
	result.denominator = result.denominator / gcd;

	return result;
}

Rational divide(Rational a, Rational b) {
	Rational result;

	result.numerator = a.numerator * b.denominator;
	result.denominator = a.denominator * b.numerator;

	int gcd = greatest_common_divisor(result.numerator, result.denominator);

	result.numerator = result.numerator / gcd;
	result.denominator = result.denominator / gcd;

	return result;
}

Rational power(Rational r, int power) {
	Rational result;

	result.numerator = 1;
	result.denominator = 1;

	if (power != 0) {
		int numer = r.numerator;
		int denom = r.denominator;

		int abs_power = power < 0 ? -power : power;

		for (int i = 0; i < abs_power; i++) {
			result.numerator *= numer;
			result.denominator *= denom;
		}
		if (power < 0) {
			int temp = result.denominator;
			result.denominator = result.numerator;
			result.numerator = temp;
		}
		int gcd = greatest_common_divisor(result.numerator, result.denominator);
		result.numerator = result.numerator / gcd;
		result.denominator = result.denominator / gcd;
	}
	return result;
}
//Конец арифметики

Rational create(int numer, int denom) {
	Rational result;
	result.numerator = numer;
	result.denominator = denom;

	return result;
}

int compare(Rational a, Rational b) {
	if (a.denominator != b.denominator) {
		a.numerator *= b.denominator;
		b.numerator *= a.denominator;
	}
	if (a.numerator == b.numerator) {
		return 0;
	}
	else {
		return a.numerator < b.numerator ? -1 : 1;
	}
}

int to_int(Rational r) {
	if (r.denominator == 0) {
		printf("Ошибка: деление на ноль\n");
		return 1;
	}
	else {
		return r.numerator / r.denominator;
	}
}

float to_float(Rational r) {
	if (r.denominator == 0) {
		printf("Ошибка: деление на ноль\n");
		return 1;
	}
	else {
		return (float)r.numerator / (float)r.denominator;
	}
}

void to_str(Rational r) {
	printf("\n%d/%d\n", r.numerator, r.denominator);
}

