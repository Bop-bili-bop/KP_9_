#ifndef PRINT_CIRCUIT_H
#define PRINT_CIRCUIT_H
#include <stdio.h>
#include <windows.h>

#define CIRCUIT_RLC '1'
#define CIRCUIT_RCL '2'
#define CIRCUIT_R2CLR1 '3'
#define CIRCUIT_R1R2LC '4'

void print_chosen_circuit(char choice) {
    switch(choice) {
        case CIRCUIT_RLC:
            printf("Circuit 1\n");
            printf("●─┬────────▆▆▆──────◠◠◠◠────┬─●\n"
                   "  │         R         L     │\n"
                   "  │                         │\n"
                   "  │               C         │\n"
                   "  └───────────────││────────┘\n");
            break;
        case CIRCUIT_RCL:
            printf("Circuit 2\n");
            printf("●─┬────────▆▆▆──────││──────┬─●\n"
                   "  │         R       C       │\n"
                   "  │                         │\n"
                   "  │      L                  │\n"
                   "  └────◠◠◠◠─────────────────┘\n");
            break;
        case CIRCUIT_R2CLR1:
            printf("Circuit 3\n");
            printf("●─┬─────────▆▆▆──────││─────┓\n"
                   "  │         R2         C    │\n"
                   "  │                         │\n"
                   "  █ R1     L                │\n"
                   "●─┴──────◠◠◠◠──────────────┘\n");
            break;
        case CIRCUIT_R1R2LC:
            printf("Circuit 4\n");
            printf("●─┬────────▆▆▆──────────────┓\n"
                   "  █ R1     R2               │\n"
                   "  ┴                         │\n"
                   "  ┬ C       L               │\n"
                   "●─┴───────◠◠◠◠──────────────┚\n");
            break;
        default:
            printf("Error\n");
            break;
    }
}
void print_all_circuits()
{
    printf("Circuit 1\n");
    printf("●─┬────────▆▆▆──────◠◠◠◠────┬─●\n"
        "  │         R         L     │\n"
        "  │                         │\n"
        "  │               C         │\n"
        "  └───────────────││────────┘\n");

    printf("Circuit 2\n");
    printf("●─┬────────▆▆▆──────││──────┬─●\n"
        "  │         R       C       │\n"
        "  │                         │\n"
        "  │      L                  │\n"
        "  └────◠◠◠◠─────────────────┘\n");

    printf("Circuit 3\n");
    printf("●─┬─────────▆▆▆──────││─────┓\n"
           "  │         R2         C    │\n"
           "  │                         │\n"
           "  █ R1     L                │\n"
           "●─┴──────◠◠◠◠───────────────┘\n");

    printf("Circuit 4\n");
    printf("●─┬────────▆▆▆──────────────┓\n"
       "  █ R1     R2               │\n"
       "  ┴                         │\n"
       "  ┬ C       L               │\n"
       "●─┴───────◠◠◠◠──────────────┚\n");
}
#endif
