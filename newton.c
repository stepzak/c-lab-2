//
// Created by zakatinstepan on 04.11.2025.
//

#include "newton.h"
#include <math.h>
#include <stdio.h>

#include "my_math.h"

#define EPS 1e-6

result_t newton(func f, double a, double b) {
    result_t r;
    r.count = 0;
    double x_curr = (a+b)/2;

    double x_prev = x_curr;
    double deriv = differentiate(f, x_prev, 1, EPS);
    x_curr = x_prev - f(x_prev)/deriv;

    while(fabs(x_curr - x_prev) > EPS) {
        x_prev = x_curr;
        double deriv = differentiate(f, x_prev, 1, EPS);
        x_curr = x_prev - f(x_prev)/deriv;
        r.count++;

        printf("Iteration %d, %lf\n", r.count, x_curr);
    }
    r.result = x_curr;
    r.correct = true;
    return r;
}
