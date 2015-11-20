#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>
#include "Stack.h"
#include "ErrorList.h"


#define $ ,

const int max_nmb_strings = 100;

int Read(char* initial_text, char** text);
int Preprocess(char *input_name, int *codeflow, size_t max_size);

enum Commands
{
    PUSH,
    POP,
    ADD,
    SUB,
    MUL,
    DIV,
    REM,
    END,
    COMMANDS_NUMBER

};


int main()
{


    char input_name[] = "/home/anastasia/git/iLab/Asm/Comm.txt";
    printf("Here");
    fflush(stdout);


    size_t const max_size = 30;
    int codeflow[max_size] = {0};
    int res = Preprocess(input_name, codeflow, max_size);
    printf("Here");
    fflush(stdout);
    for (int i = 0; i <= max_size; i++)
    {
        printf("%d\n", codeflow[i]);
    }

    return 0;

}


int Preprocess(char *input_name, int *codeflow, size_t max_size)
{


    char* text = 0;
    Read(input_name, &text);

    //printf("\n%s", text);


    char* command[] = {"push", "pop", "add", "sub", "mul", "div", "rem", "end"};

    size_t cur_size = 0;

    for (char* line = strtok(text,"\n"); line!= NULL ; line = strtok(NULL, "\n"))
    {
        printf("\n%zu %s\n", cur_size, line);
        for (int i = 0; i < COMMANDS_NUMBER; i++)
        {
            if(strstr(line, command[i]))
            {
                printf("%d\n", codeflow);
                fflush(stdout);
                if (cur_size > max_size)
                    LOG_ERROR(ARRAY_IS_FULL, "Array of commands is full");
                codeflow[cur_size] = i;
                cur_size++;

                if (i == 0)
                    if (cur_size > max_size)
                    LOG_ERROR(ARRAY_IS_FULL, "Array of commands is full");
                    codeflow[cur_size] = atoi(line + 5);
                    cur_size++;
            }
        }
    }

    return 0;
}


int Read(char*initial_file, char** text) {

    assert(initial_file);
    assert(text);

    FILE *infile = fopen(initial_file, "r");
    if (!infile)
        LOG_ERROR(NULL_POINTER, "NULL opened file pointer");

    long lSize = 0;

    int res = fseek(infile , 0L , SEEK_END);
    if (res)
        LOG_ERROR(res, "Fseek failed\n");

    lSize = ftell(infile); //значение указателя текущего положения потока

    res = fseek(infile , 0L , SEEK_SET); //  внутренний указатель положения файла в начальное положение
    if (res)
        LOG_ERROR(res, "Fseek failed\n" );


    *text = (char*)calloc( 1, lSize + 1 ); // EOL end of line
    if(!(*text))
    {
        fclose(infile);
        LOG_ERROR(CALLOC_ERROR, "NULL pointer in calloc");
    }

    if(fread( *text , lSize, 1 , infile) != 1)
    {
        fclose(infile);
        free(*text);
        LOG_ERROR(READ_ERROR, "Entire read fails");
    }

    fclose(infile);

    return 0;
}






