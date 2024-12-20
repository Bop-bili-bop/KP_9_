#ifndef VALIDATION_H
#define VALIDATION_H
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX_FILE_NAME_LEN 27


char validFileName(const char *string) {
    for (unsigned i = 0; i < strlen(string); i++) {
        if (!isalnum((unsigned char)string[i]) && string[i] != '_') {
            return 0;
        }
    }
    return 1; 
}

void validateFileNameInput(char *prompt, char *stringPointer) {
    do {
        printf("%s", prompt);
        fgets(stringPointer, MAX_FILE_NAME_LEN, stdin);
        if (string[strcspn(stringPointer, "\n")] != '\n' && validFileName(stringPointer) != 0) 
        {
            string[strcspn(stringPointer, "\n")] = '\0';
        } 
        else 
        {
            printf("Invalid input. The filename must be up to %d characters long and contain only letters, digits or underscores (_).\n", MAX_FILE_NAME_LEN);
            strcpy(string, "\n");
        }
        fflush(stdin);
    } while (string[strcspn(string, "\n")] != '\0');
}


#endif