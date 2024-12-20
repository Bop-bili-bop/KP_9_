#ifndef CALCULATION_H
#define CALCULATION_H
#define M_PI 3.14159265358979323846
double calculate_resonant_frequency(double L, double C)
{
    return 1.0 / (2.0 * M_PI * sqrt(L* C));
}

#endif
