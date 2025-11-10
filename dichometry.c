#include <stdio.h>
#include "types.h"
#define EPS 1e-10
//
// Created by zakatinstepan on 04.11.2025.
//
result_t dichometry(func f, double a, double b) {
    result_t res;
    res.count = 0;
    while ((b-a)>EPS) {
        res.count++;
        double mid = (a+b)/2;
        double f_b = f(b);
        double f_c = f(mid);
        printf("Iteration %d, %lf\n", res.count, mid);
        if (f_c*f_b<0) {
            a = mid;
        }
        else {
            b = mid;
        }
    }
    res.result = (a+b)/2;
    res.correct = true;

    return res;
}
#include "dichometry.h"
