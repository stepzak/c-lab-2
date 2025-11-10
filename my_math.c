//
// Created by zakatinstepan on 10.11.2025.
//

#include "my_math.h"
#include "types.h"

double differentiate(func f, double x, int n, double dx) {
    if (n == 0) {
        return f(x);
    }
    if (n == 1) {
        return (f(x + dx) - f(x - dx)) / (2 * dx);
    }

    return (differentiate(f, x + dx, n - 1, dx) - differentiate(f, x - dx, n - 1, dx)) / (2 * dx);
}