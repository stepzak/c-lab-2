#include <stdio.h>
#include <math.h>
#include "dichometry.h"
#include "newton.h"
#include "my_math.h"
#include "types.h"
#include "iteration.h"

#define EPS 1e-10

double f24(double x) {
    return cos(2.0/x)-2*sin(1.0/x)+1.0/x;
}

double f24_x_equals(double x) {
    return -1.0 / (cos(2.0/x) - 2.0*sin(1.0/x));
}

double f23(double x) {
    return 3*x-4*log(x)-5;
}

double f23_x_equals(double x) {
    return (4*log(x)+5)/3;
}


void run_methods(func f, func f_x_equals, double a, double b, char displayable_name_dich[], char displayable_name_iter[], double dx) {
    printf("%s \n", displayable_name_dich);
    printf("Dichometry:\n");
    result_t res = dichometry(f, a, b);

    if (res.correct) {
        printf("Result = %lf, number of iterations = %d\n", res.result, res.count);
    }
    printf("%s \n", displayable_name_iter);
    printf("Iterations:\n");
    bool iter_flag = true;
    for (double x = a; x <= b; x += dx) {
        double deriv = differentiate(f_x_equals, x, 1, dx);
        if (fabs(deriv) >= 1) {
            printf("f'(%lf) = %lf, cannot apply iteration method\n", x, deriv);
            iter_flag = false;
            break;
        }
    }
    if (iter_flag) {
        result_t res_iter = iteration_method(f_x_equals, a, b);
        if (res_iter.correct) {
            printf("Result = %lf, number of iterations = %d\n", res_iter.result, res_iter.count);
        }
    }

    printf("Newton:\n");
    bool newton_flag = true;
    for (double x = a; x <= b; x += dx) {
        double deriv = differentiate(f, x, 1, dx);
        double deriv2 = differentiate(f, x, 2, dx);
        double fx = f(x);
        if (fabs(fx*deriv2) >= pow(deriv, 2)) {
            printf("F''(%lf) = %lf\n", x, deriv2);
            printf("F'(%lf) = %lf\n", x, deriv);
            printf("F(%lf) = %lf; cannot apply Newton method\n", x, fx);
            newton_flag = false;
            break;
        }
    }
    if (newton_flag) {
        result_t res_newton = newton(f, a, b);
        if (res_newton.correct) {
            printf("Result = %lf, number of iterations = %d\n", res_newton.result, res_newton.count);
        }
    }

}

int main(void) {
    run_methods(f24, f24_x_equals, 1, 2, "F(x) = cos(2/x)-2*sin(1/x)+1/x", "x = -1 / (cos(2/x) - 2*sin(1/x))", 1e-6);
    printf("-----------------------------------------------------------------------------\n");
    run_methods(f23, f23_x_equals, 3, 4, "F(x) =  3*x-4*log(x)-5", "x = (4*log(x)+5)/3", 1e-6); //отрезок сужен для сходимости

    return 0;
}

