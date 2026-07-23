/*
Question 17
Write a program to find the roots of a quadratic equation and categorize them.
*/

#include <stdio.h>
#include <math.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int show_roots = argc == 2 && strcmp(argv[1], "--roots") == 0;
    if (argc > 1 && !show_roots) return 1;
    double a, b, c;
    if (scanf("%lf%lf%lf", &a, &b, &c) != 3) {
        return 1;
    }
    if (a == 0) {
        if (b != 0) {
            printf("Linear root: %.12g\n", -c / b);
        } else {
            puts(c == 0 ? "Infinitely many solutions" : "No solution");
        }
        return 0;
    }
    double discriminant = b * b - 4 * a * c;
    if (discriminant < 0) {
        puts("Roots are complex");
        if (show_roots) {
            double real = -b / (2 * a), imaginary = sqrt(-discriminant) / fabs(2 * a);
            printf("%.12g + %.12gi, %.12g - %.12gi\n", real + 0.0, imaginary, real + 0.0, imaginary);
        }
    } else if (discriminant == 0) {
        double root = -b / (2 * a);
        printf("Roots are real and same: %.12g\n", root == 0 ? 0 : root);
    } else {
        /* The larger-magnitude numerator avoids subtracting nearly equal numbers. */
        double q = -0.5 * (b + copysign(sqrt(discriminant), b));
        double first = q / a, second = c / q;
        printf("Roots are real and different: %.12g, %.12g\n",
               fmax(first, second) + 0.0, fmin(first, second) + 0.0);
    }
    return 0;
}
