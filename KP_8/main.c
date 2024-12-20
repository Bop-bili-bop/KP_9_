#include <stdio.h>
#include <math.h>
#include "calculation.h"
#include "complex.h"
#include "validation.h"
#include "print_circuit.h"


#define MINIMUM_INPUT 1e-308
#define MAXIMUM_L 1e3
#define MAXIMUM_C 1e5
#define MAXIMUM_R 1e6
#define MAXIMUM_FREQUENCY 1e9
int main()
{
    SetConsoleOutputCP(CP_UTF8);
    char circuit_choice = 0;
    double R = 0, R1 = 0, R2 = 0, L = 0, C = 0, f_min =0, f_max = 0, df = 0;
    double omega = 0, f0 = 0, f = 0;
    complex Z = {0, 0}, numerator = {0, 0}, denominator = {0, 0};
    do
    {
        print_all_circuits();
        circuit_choice = validate_char_input("Choose circuit(1-4):\n",
                        CIRCUIT_RLC, CIRCUIT_RCL, CIRCUIT_R2CLR1, CIRCUIT_R1R2LC);
        printf("You chose circuit #%c\n", circuit_choice);
        print_chosen_circuit(circuit_choice);
        L = validate_double_input("Enter L(mHn):\n", MINIMUM_INPUT, MAXIMUM_L);
        C = validate_double_input("Enter C (mcF):\n", MINIMUM_INPUT, MAXIMUM_C);
        f_min = validate_double_input("Enter f_min:\n", MINIMUM_INPUT, MAXIMUM_FREQUENCY);
        f_max = validate_double_input("Enter f_max:\n", f_min, MAXIMUM_FREQUENCY);
        switch (circuit_choice) {
            case CIRCUIT_RLC:
            case CIRCUIT_RCL:
                R = validate_double_input("Enter R(Ohm):\n", MINIMUM_INPUT, MAXIMUM_R);
                break;
            case CIRCUIT_R2CLR1:
            case CIRCUIT_R1R2LC:
                R1 = validate_double_input("Enter R1(Ohm):\n", MINIMUM_INPUT, MAXIMUM_R);
                R2 = validate_double_input("Enter R2(Ohm):\n", MINIMUM_INPUT, MAXIMUM_R);
                break;
            default:
                printf("Invalid choice\n");
                break;
        }
        df = validate_double_input("Enter df:\n", MINIMUM_INPUT, MAXIMUM_FREQUENCY);
        int i = 0;
        f0 = calculate_resonant_frequency(L, C);
        printf("Resonant frequency = %g\n", f0);
        f = f_min;
        do {
            omega = 2.0 * M_PI * f;
            switch (circuit_choice) {
                case CIRCUIT_RLC:
                    numerator.real = L / C;
                    numerator.imaginary = -R / (omega * C);
                    denominator.real = R;
                    denominator.imaginary = omega * L - 1.0 / (omega * C);
                    Z = complex_division(numerator, denominator);
                    break;
                case CIRCUIT_RCL:
                    numerator.real = L / C;
                    numerator.imaginary = R / (omega * C);
                    denominator.real = R;
                    denominator.imaginary = omega * L - 1.0 / (omega * C);
                    Z = complex_division(numerator, denominator);
                    break;
                case CIRCUIT_R2CLR1:
                    numerator.real = R1 * R2;
                    numerator.imaginary = R1 * (omega * L - 1.0 / (omega * C));
                    denominator.real = R1 + R2;
                    denominator.imaginary = omega * L - 1.0 / (omega * C);
                    Z = complex_division(numerator, denominator);
                    break;
                case CIRCUIT_R1R2LC:
                    numerator.real = R1 * R2 + L / C;
                    numerator.imaginary = omega * L * R1 - R2*R2 / (omega * C);
                    denominator.real = R1 + R2;
                    denominator.imaginary = omega * L - 1.0 / (omega * C);
                    Z = complex_division(numerator, denominator);
                    break;
                default:
                    printf("Error");
                    break;
            }

            printf("f%d:%g\t", i+1, f);
            printf("df%d:%g\t", i+1, df);
            printf("Z[%d]: ", i+1);
            print_complex_number(Z);
            f+=df;
            i++;
        }while (f<=f_max);
        printf("Press 'q' to exit, any other key to continue\n");
    }while (getch() != 'q');
    return 0;
}