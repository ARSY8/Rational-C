#include <stdio.h>
#include <gmp.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include <assert.h>
#include <stdlib.h>
#include "rational_numbers.h"


void run_all_tests(void) {
    test_arithmetic_and_create();
    test_to_int();
    test_to_float();
    test_to_str();
}

void test_arithmetic_and_create(void) {

    srand(time(NULL));

    int first_num = rand() % 201 - 100;
    int first_den = (rand() % 100) + 1;
    int second_num = rand() % 201 -100;
    int second_den = (rand() % 100) + 1;

    Rational first = create(first_num, first_den);
    Rational second = create(second_num, second_den);

    Rational addition = add(first, second);
    Rational subtraction = subtract(first, second);
    Rational multiplication = multiply(first, second);
    Rational division = divide(first, second);
    Rational exponentiation = power(first, 3);

    mpq_t first_gmp, second_gmp, addition_gmp, subtraction_gmp, multiplication_gmp, division_gmp, exponentiation_gmp;
    mpq_init(first_gmp);
    mpq_init(second_gmp);
    mpq_init(addition_gmp);
    mpq_init(subtraction_gmp);
    mpq_init(multiplication_gmp);
    mpq_init(division_gmp);
    mpq_init(exponentiation_gmp);

    mpq_set_si(first_gmp, first_num, first_den);
    mpq_set_si(second_gmp, second_num, second_den);

    mpq_add(addition_gmp, first_gmp, second_gmp);
    mpq_sub(subtraction_gmp, first_gmp, second_gmp);
    mpq_mul(multiplication_gmp, first_gmp, second_gmp);
    mpq_div(division_gmp, first_gmp, second_gmp);

    mpq_set(exponentiation_gmp, first_gmp);

    int random_degree = rand() % 3 - 3;
    int abs_random_degree;

    if (random_degree < 0) {
        abs_random_degree = -random_degree;
        mpz_t num, den;
        mpz_init(num);
        mpz_init(den);

        mpq_get_num(num, exponentiation_gmp);
        mpq_get_den(den, exponentiation_gmp);

        mpz_swap(num, den);

        mpq_set_num(exponentiation_gmp, den);
        mpq_set_den(exponentiation_gmp, num);

        mpz_clear(num);
        mpz_clear(den);
    } else {
        abs_random_degree = random_degree;
    }
    for (int i = 1; i < 3; ++i) {
        mpq_mul(exponentiation_gmp, exponentiation_gmp, first_gmp);
    }

    mpq_t my_addition_gmp, my_subtraction_gmp, my_multiplication_gmp, my_division_gmp, my_exponentiation_gmp;
    mpq_init(my_addition_gmp);
    mpq_init(my_subtraction_gmp);
    mpq_init(my_multiplication_gmp);
    mpq_init(my_division_gmp);
    mpq_init(my_exponentiation_gmp);

    mpq_set_si(my_addition_gmp, addition.numerator, addition.denominator);
    mpq_set_si(my_subtraction_gmp, subtraction.numerator, subtraction.denominator);
    mpq_set_si(my_multiplication_gmp, multiplication.numerator, multiplication.denominator);
    mpq_set_si(my_division_gmp, division.numerator, division.denominator);
    mpq_set_si(my_exponentiation_gmp, exponentiation.numerator, exponentiation.denominator);

    assert(mpq_cmp(my_addition_gmp, addition_gmp) < 1e-6);
    assert(mpq_cmp(my_subtraction_gmp, subtraction_gmp) < 1e-6);
    assert(mpq_cmp(my_multiplication_gmp, multiplication_gmp) < 1e-6);
    assert(mpq_cmp(my_division_gmp, division_gmp) < 1e-6);
    assert(mpq_cmp(my_exponentiation_gmp, exponentiation_gmp) < 1e-3);

    mpq_clears(first_gmp, second_gmp, addition_gmp, subtraction_gmp, multiplication_gmp, division_gmp, exponentiation_gmp, NULL);
    mpq_clears(my_addition_gmp, my_subtraction_gmp, my_multiplication_gmp, my_division_gmp, my_exponentiation_gmp, NULL);
}


void test_to_int(void) {
    srand(time(NULL));

    int num = rand() % 201 - 100;
    int den = (rand() % 100) + 1;

    Rational r = create(num, den);

    int my_result = to_int(r);

    mpq_t int_gmp;
    mpq_init(int_gmp);
    mpq_set_si(int_gmp, num, den);

    int gmp_result = mpz_get_si(mpq_numref(int_gmp)) / mpz_get_si(mpq_denref(int_gmp));

    assert(my_result == gmp_result);

    mpq_clear(int_gmp);
}


void test_to_float(void){

    srand(time(NULL));

    int num = rand() % 201 - 100;
    int den = (rand() % 100) + 1;

    Rational r = create(num, den);

    float my_result = to_float(r);

    mpq_t float_gmp;
    mpq_init(float_gmp);
    mpq_set_si(float_gmp, num, den);

    assert(fabs(my_result - mpq_get_d(float_gmp)) < 1e-6);

    mpq_clear(float_gmp);
}


void test_to_str(void) {
    srand(time(NULL));

    int num = rand() % 201 - 100;
    int den = (rand() % 100) + 1;

    Rational r = create(num, den);

    char my_result[50];
    snprintf(my_result, sizeof(my_result), "%d/%d", r.numerator, r.denominator);

    mpq_t str_gmp;
    mpq_init(str_gmp);
    mpq_set_si(str_gmp, num, den);

    char gmp_result[50];
    gmp_snprintf(gmp_result, sizeof(gmp_result), "%Zd/%Zd", mpq_numref(str_gmp), mpq_denref(str_gmp));

    assert(strcmp(my_result, gmp_result) < 1e-6);

    mpq_clear(str_gmp);
}





    