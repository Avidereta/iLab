#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>
#include "Stack.h"
#include "ErrorList.h

const int max_nmb_strings = 100;

char* Read(char* initial_text);
int MakeBinary(char* input_file);
int Write_to_file(char* name_file, char* str_pointers[], const int nmb_pointers);

enum Commands
{
    PUSH = 1,
    POP = 2,
    ADD = 3,
    SUB = 4,
    END = 5,

};


int main()
{
    char input_name[] = "/home/anastasia/iLab/Asm/Comm.txt";
    assert(input_name);

    char* text = Read(input_name);
    assert(text);
    int i = 0;

    printf("\n%s", text);

    for (char* line = strtok(text,"\n"); line!= NULL ; line = strtok(NULL, "\n"))
    {
        char* comm = strtok(line," " );

        printf("\n %d %s", i,line);
        i++;
    }


    //printf("Hello");
    return 0;

}


int MakeBinary(char* input_file)
{
    char* text = Read(input_file);
    assert(text);



    char* lines[max_nmb_strings] = {0};

    for (char* line = strtok(text,"\n"); line != NULL; line = strtok(NULL, "\n"))
    {
        char* comm = strtok(line," " );
    }

    return 0;
}

// Obligatory free buffer!!!
char* Read(char* initial_text)
{
    assert(initial_text);

    FILE *infile = fopen(initial_text, "r");
    assert(infile);

    long lSize = 0;
    char *buffer = 0;

    fseek( infile , 0L , SEEK_END);
    lSize = ftell( infile ); //значение указателя текущего положения потока
    rewind( infile ); //  внутренний указатель положения файла в начальное положение


    buffer = (char*)calloc( 1, lSize + 1 );
    if( !buffer )
    {
        fclose(infile);
        fputs("memory alloc fails", stderr);
    }


    if( fread( buffer , lSize, 1 , infile) != 1)
    {
        fclose(infile), free(buffer), fputs("entire read fails", stderr), exit(1);
    }


    fclose(infile);

    return buffer;
}





int Write_to_file(char* name_file, char* str_pointers[], const int nmb_pointers)
{
    assert(name_file);
    assert(str_pointers);

    FILE *outfile = fopen(name_file, "w");

    if (outfile == NULL)
    {
        printf("Error opening file!\n");
        exit(1);
    }

    int printed_strings = 0;


    for (int i = 0; i < nmb_pointers; i++)
    {
        assert(i < nmb_pointers);
        fprintf(outfile, "%s\n", str_pointers[i]);
        printed_strings++;
    }

    fclose(outfile);

    return printed_strings;

}



