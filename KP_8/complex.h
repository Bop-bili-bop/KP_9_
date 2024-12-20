#ifndef COMPLEX_H
#define COMPLEX_H
typedef struct complex{
    double real;
    double imaginary;
}complex;

complex complex_division(complex a, complex b) {
    complex result;
    double denominator = b.real * b.real + b.imaginary * b.imaginary;
    result.real = (a.real * b.real + a.imaginary * b.imaginary) / denominator;
    result.imaginary = (a.imaginary * b.real - a.real * b.imaginary) / denominator;
    return result;
}

void print_complex_number(complex number)
{
    printf("%e + i * %e\n", number.real, number.imaginary);
}
#endif //COMPLEX_H
