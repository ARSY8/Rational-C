#include <stdio.h>
#include <gmp.h>
#include <time.h>
#include <assert.h>
#include <stdlib.h>
#include "rational_numbers.h"


void run_all_tests(void) {
    test_arithmetic_and_create();
}

void test_arithmetic_and_create(void) {

    srand(time(NULL));

    int first_num = rand() % 100 - 100;
    int first_den = rand() % 100;
    int second_num = rand() % 100 - 100;
    int second_den = rand() % 100;

    Rational first = create(first_num, first_den);
    Rational second = create(second_num, second_den);

    Rational addition = add(first, second);
    Rational subtraction = subtract(first, second);
    Rational multiplication = multiply(first, second);
    Rational division = divide(first, second);

    int random_degree = rand() % 3 - 3;

    Rational exponentiation = power(first, random_degree);

    mpq_t first_gmp, second_gmp;

    mpq_init(first_gmp);
    mpq_init(second_gmp);

    mpq_set_si(first_gmp, first_num, first_den);
    mpq_set_si(second_gmp, second_num, second_den);

    mpq_t my_first_to_gmp, my_second_to_gmp;

    mpq_init(my_first_to_gmp);
    mpq_init(my_second_to_gmp);

    mpq_set_si(my_first_to_gmp, first.numerator, first.denominator);
    mpq_set_si(my_second_to_gmp, second.numerator, second.denominator);


    mpq_t addition_gmp, subtraction_gmp, multiplication_gmp, division_gmp, exponentiation_gmp;
    mpq_init(addition_gmp);
    mpq_init(subtraction_gmp);
    mpq_init(multiplication_gmp);
    mpq_init(division_gmp);
    mpq_init(exponentiation_gmp);

    mpq_add(addition_gmp, first_gmp, second_gmp);
    mpq_sub(subtraction_gmp, first_gmp, second_gmp);
    mpq_mul(multiplication_gmp, first_gmp, second_gmp);
    mpq_div(division_gmp, first_gmp, second_gmp);

    mpq_set(exponentiation_gmp, first_gmp);

    int abs_random_degree;

    if (random_degree < 0) {
        abs_random_degree = -random_degree;
        mpz_t num, den;
        mpz_init(num);
        mpz_init(den);

        mpq_get_num(num, exponentiation_gmp);
        mpq_get_den(den, exponentiation_gmp);

        mpz_swap(num, den);

        mpq_set_num(exponentiation_gmp, num);
        mpq_set_den(exponentiation_gmp, den);

        mpz_clear(num);
        mpz_clear(den);
    }
    else {
        abs_random_degree = random_degree;
    }
    for (int i = 1; i < abs_random_degree; ++i) {
        mpq_mul(exponentiation_gmp, exponentiation_gmp, first_gmp);
    }


    mpq_t my_addition_to_gmp, my_subtraction_to_gmp, my_multiplication_to_gmp, my_division_to_gmp, my_exponentiation_to_gmp;
    mpq_init(my_addition_to_gmp);
    mpq_init(my_subtraction_to_gmp);
    mpq_init(my_multiplication_to_gmp);
    mpq_init(my_division_to_gmp);
    mpq_init(my_exponentiation_to_gmp);

    mpq_set_si(my_addition_to_gmp, addition.numerator, addition.denominator);
    mpq_set_si(my_subtraction_to_gmp, subtraction.numerator, subtraction.denominator);
    mpq_set_si(my_multiplication_to_gmp, multiplication.numerator, multiplication.denominator);
    mpq_set_si(my_division_to_gmp, division.numerator, division.denominator);
    mpq_set_si(my_exponentiation_to_gmp, exponentiation.numerator, exponentiation.denominator);

    assert(mpq_cmp(my_first_to_gmp, first_gmp) == 0);
    assert(mpq_cmp(my_second_to_gmp, second_gmp) == 0);
    assert(mpq_cmp(my_addition_to_gmp, addition_gmp) == 0);
    assert(mpq_cmp(my_subtraction_to_gmp, subtraction_gmp) == 0);
    assert(mpq_cmp(my_multiplication_to_gmp, multiplication_gmp) == 0);
    assert(mpq_cmp(my_division_to_gmp, division_gmp) == 0);
    assert(mpq_cmp(my_exponentiation_to_gmp, exponentiation_gmp) == 0);

    mpq_clear(first_gmp);
    mpq_clear(second_gmp);
    mpq_clear(my_first_to_gmp);
    mpq_clear(my_second_to_gmp);
    mpq_clear(addition_gmp);
    mpq_clear(subtraction_gmp);
    mpq_clear(multiplication_gmp);
    mpq_clear(division_gmp);
    mpq_clear(exponentiation_gmp);
    mpq_clear(my_addition_to_gmp);
    mpq_clear(my_subtraction_to_gmp);
    mpq_clear(my_multiplication_to_gmp);
    mpq_clear(my_division_to_gmp);
    mpq_clear(my_exponentiation_to_gmp);

}