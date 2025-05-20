#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define BUFF_SIZE 1024

int main(int argc, char** argv) {
    if(argc != 2) {
        printf("You must pass in at least one argument\n");
        printf("Example: %s file_name\n", argv[0]);  // Added semicolon
        return 1;
    }
    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL)
    {
        printf("Error opening file\n");
        exit(1);
    }   
    char* line = malloc(BUFF_SIZE * sizeof(char));
    while (fgets(line, BUFF_SIZE, fp) != NULL)
    {
        printf("%s", line);
    }
    free(line);
    fclose(fp);
    return 0;
}