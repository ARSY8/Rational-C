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

	int numerator;
	int denominator;

	if (a.denominator == b.denominator) {
		numerator = a.numerator + b.numerator;
		denominator = a.denominator;
	}
	else {
		numerator = a.numerator * b.denominator + b.numerator * a.denominator;
		denominator = a.denominator * b.denominator;
	}

	return create(numerator, denominator);
}

Rational subtract(Rational a, Rational b) {
	int numerator;
	int denominator;

	if (a.denominator == b.denominator) {
		numerator = a.numerator - b.numerator;
		denominator = a.denominator;
	}
	else {
		numerator = a.numerator * b.denominator - b.numerator * a.denominator;
		denominator = a.denominator * b.denominator;
	}

	return create(numerator, denominator);
}

Rational multiply(Rational a, Rational b) {
	int numerator;
	int denominator;

	numerator = a.numerator * b.numerator;
	denominator = a.denominator * b.denominator;

	return create(numerator, denominator);
}

Rational divide(Rational a, Rational b) {
	int numerator;
	int denominator;

	numerator = a.numerator * b.denominator;
	denominator = a.denominator * b.numerator;

	return create(numerator, denominator);
}

Rational power(Rational r, int power) {
	int numerator = 1;
	int denominator = 1;

	if (r.denominator == 0) {
		printf("Деление на ноль не допустимо.");
		abort();
	}

	if (power != 0) {
		int numer = r.numerator;
		int denom = r.denominator;

		int abs_power = power < 0 ? -power : power;

		for (int i = 0; i < abs_power; i++) {
			numerator *= numer;
			denominator *= denom;
		}
		if (power < 0) {
			int temp = denominator;
			denominator = numerator;
			numerator = temp;
		}
	}
	return create(numerator, denominator);
}
//Конец арифметики

Rational create(int numer, int denom) {

	if (denom == 0) {
    	printf("Ошибка: знаменатель не может быть равен нулю.\n");
    	abort();
	}
	
	Rational result;
	result.numerator = numer;
	result.denominator = denom;

	int gcd = greatest_common_divisor(result.numerator, result.denominator);

	result.numerator = result.numerator / gcd;
	result.denominator = result.denominator / gcd;

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

