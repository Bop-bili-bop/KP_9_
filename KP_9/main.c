#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#include "validation.h"
#define DESCRIPTOR "YWhhbGFkemVuaWdnZXJkb250YnJlYWtteXByb2dyYW0=" 
#define MAX_FILE_NAME 32
#define MAX_REGION_LEN 3

FILE *file;

typedef struct Record
{
    char regionName[MAX_REGION_LEN];
    float squareArea;
    float population;
}record;

void createUserFile()
{
    char fileName[MAX_FILE_NAME];
    
    validateFileNameInput("Enter name of file you want to create:\n", &fileName);
    strcat(fileName, ".dat");
    do  
    {
        file = fopen(fileName, "w");
        if (file == NULL)
        {
            printf("Error! File wasn't created");
        }
        else
        {
            printf("File created succesfully with name %s", fileName);
            fprintf(file ,"%s\n", DESCRIPTOR);
        }
    } while (file == NULL);
    fclose(file); 
}
int main()
{
    

    //descryptor yeeeeeeeessssirr
    //checksum
    createUserFile();
    return 0;
}