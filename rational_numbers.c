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

	if (a.denominator == 0 || b.denominator == 0) {
		printf("Ошибка: деление на ноль\n");
		abort();
	}

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

	if (a.denominator == 0 || b.denominator == 0) {
		printf("Ошибка: деление на ноль\n");
		abort();
	}

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

	if (a.denominator == 0 || b.denominator == 0) {
		printf("Ошибка: деление на ноль\n");
		abort();
	}

	int numerator = a.numerator * b.numerator;
	int denominator = a.denominator * b.denominator;

	return create(numerator, denominator);
}

Rational divide(Rational a, Rational b) {

	if (a.denominator == 0 || b.denominator == 0) {
		printf("Ошибка: деление на ноль\n");
		abort();
	}
	
	int numerator = a.numerator * b.denominator;
	int denominator = a.denominator * b.numerator;

	return create(numerator, denominator);
}

Rational power(Rational r, int power) {
	int numerator = 1;
	int denominator = 1;

	if (r.denominator == 0) {
		printf("Деление на ноль не допустимо.");
		abort();
	}

	int abs_power = power < 0 ? -power : power;

	int numer = r.numerator;
	int denom = r.denominator;

	for (int i = 0; i < abs_power; i++) {
		numerator *= numer;
		denominator *= denom;
	}

	if (power < 0) {
		int temp = denominator;
		denominator = numerator;
		numerator = temp;
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

	if (a.denominator == 0 || b.denominator == 0) {
		printf("Ошибка: деление на ноль\n");
		abort();
	}

	float first = (float)a.numerator / a.denominator;
	float second = (float)b.numerator / b.denominator;

	if ( first == second) {
		return 0;
	}
	else {
		return first < second ? -1 : 1;
	}
}

int to_int(Rational r) {
	if (r.denominator == 0) {
		printf("Ошибка: деление на ноль\n");
		abort();
	}
	else {
		return r.numerator / r.denominator;
	}
}

float to_float(Rational r) {
	if (r.denominator == 0) {
		printf("Ошибка: деление на ноль\n");
		abort();
	}
	else {
		return (float)r.numerator / r.denominator;
	}
}

void to_str(Rational r) {

	if (r.denominator == 0) {
		printf("Ошибка: деление на ноль\n");
		abort();
	}

	printf("\n%d/%d\n", r.numerator, r.denominator);
}

