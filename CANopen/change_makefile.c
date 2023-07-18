/**
 * C program to replace a specific line with another in a file.
 */

#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 1000


int main()
{
    /* File pointer to hold reference of input file */
    FILE * fPtr;
    FILE * fTemp;
    char path[100] = "../../controller_ert_rtw/controller.mk";
    
    char buffer[BUFFER_SIZE];
    char newline[BUFFER_SIZE] = "TOOLCHAIN_LIBS = -lm -lm -lstdc++ -lsocketcan -lcanopen -lmotor \n";

    int line = 53;
    int count;

    /*  Open all required files */
    fPtr  = fopen(path, "r");
    fTemp = fopen("replace.tmp", "w"); 

    /* fopen() return NULL if unable to open file in given mode. */
    if (fPtr == NULL || fTemp == NULL)
    {
        /* Unable to open file hence exit */
        printf("\nUnable to open file.\n");
        printf("Please check whether file exists and you have read/write privilege.\n");
        exit(EXIT_SUCCESS);
    }


    /*
     * Read line from source file and write to destination 
     * file after replacing given line.
     */
    count = 0;
    while ((fgets(buffer, BUFFER_SIZE, fPtr)) != NULL)
    {
        count++;

        /* If current line is line to replace */
        if (count == line)
            fputs(newline, fTemp);
        else
            fputs(buffer, fTemp);
    }


    /* Close all files to release resource */
    fclose(fPtr);
    fclose(fTemp);


    /* Delete original source file */
    remove(path);

    /* Rename temporary file as original file */
    rename("replace.tmp", path);

    printf("\nSuccessfully replaced '%d' line with '%s'.", line, newline);

    return 0;
}