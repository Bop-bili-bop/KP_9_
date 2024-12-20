#ifndef VALIDATION_H
#define VALIDATION_H
#include <stdio.h>
#include <conio.h>
double validate_double_input(const char *prompt, double min, double max)
{
    double value = 0;
    int input = 0;
    do
    {
        printf("%s", prompt);
        input = scanf("%lf", &value);
        if (input != 1 || value <= 0 || value < min || value > max)
        {
            printf("Invalid input. Please enter a valid number.\n");
        }
        fflush(stdin);
    }
    while (input != 1 || value <= 0 || value < min || value > max);
    return value;
}
char validate_char_input(char *prompt, char choice_1, char choice_2, char choice_3, char choice_4)
{
    char user_choice = 0;
    do
    {
        printf("%s", prompt);
        user_choice = getch();
        if (user_choice != choice_1 && user_choice != choice_2 && user_choice != choice_3 && user_choice != choice_4)
        {
            printf("Invalid input.\n");
        }
        fflush(stdin);
    }
    while (user_choice != choice_1 && user_choice != choice_2 && user_choice != choice_3 && user_choice != choice_4);
    return user_choice;
}
#endif //VALIDATION_H
