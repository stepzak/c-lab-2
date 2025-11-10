//
// Created by zakatinstepan on 10.11.2025.
//

#include "iteration.h"
#include <stdio.h>
#include <math.h>
#include "my_math.h"
#include "types.h"

#define EPS 1e-6

result_t iteration_method(func f, double a, double b) {
  result_t r;
  r.count = 0;
  double x_curr = (a+b)/2;

  double x_prev = x_curr;
  x_curr = f(x_prev);
  while(fabs(x_curr - x_prev) > EPS) {
    x_prev = x_curr;
    x_curr = f(x_prev);
    r.count++;

    printf("Iteration %d, %lf\n", r.count, x_curr);
  }
  r.result = x_curr;
  r.correct = true;
  return r;
}