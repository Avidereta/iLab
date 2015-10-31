#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>






int MakeBinary()
{
    enum Commands
    {
        push = 1,
        pop = 2,
        add = 3,
        sub = 4,
        end = 5,

    };
}

// Obligatory free buffer!!!
int* Read(char* initial_text)
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
    if( !buffer ) fclose(infile),fputs("memory alloc fails",stderr),exit(1);

    /* copy the file into the buffer */
    if( fread( buffer , lSize, 1 , infile) != 1)
        fclose(infile),free(buffer),fputs("entire read fails",stderr),exit(1);


    fclose(infile);

    return (buffer);
}


int Write_to_file(char* name_file)
{
    assert(name_file);


    FILE *outfile = fopen(name_file, "w");

    if (outfile == NULL)
    {
        printf("Error opening file!\n");
        exit(1);
    }



    for (int i = 0; i < nmb_pointers; i++)
    {
        assert(i < nmb_pointers);
        fprintf(outfile, "%s\n", str_pointers[i]);
        printed_strings++;
    }

    fclose(outfile);

    return printed_strings;

}


