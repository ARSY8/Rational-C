#include <stdio.h>
#include "rational_numbers.h"


int main(void) {
	Rational first = { 8, 12 };
	Rational second = { 8, 24 };

	Rational addition = add(first, second);
	Rational subtraction = subtract(first, second);
	Rational multiplication = multiply(first, second);
	Rational division = divide(first, second);
	Rational exponentiation = power(first, 2);
	Rational created_rational = create(8, 12);
	int comparison = compare(first, second);

	printf("\nСложение:\nЧислитель: %d \nЗнаменатель: %d\n", addition.numerator, addition.denominator);
	printf("\nВычитание:\nЧислитель: %d \nЗнаменатель: %d\n", subtraction.numerator, subtraction.denominator);
	printf("\nУмножение:\nЧислитель: %d \nЗнаменатель: %d\n", multiplication.numerator, multiplication.denominator);
	printf("\nДеление:\nЧислитель: %d \nЗнаменатель: %d\n", division.numerator, division.denominator);
	printf("\nВозведение в степень:\nЧислитель: %d \nЗнаменатель: %d\n", exponentiation.numerator, exponentiation.denominator);

	if (comparison == 0) {
		printf("\nfirst = second\n");
	}
	else if (comparison == 1) {
		printf("\nfirst > second\n");
	}
	else if (comparison == -1) {
		printf("\nfirst < second\n");
	}

	printf("\n%d\n", to_int(created_rational));
	printf("\n%.2f\n", to_float(created_rational));

	to_str(created_rational);

	return 0;
}