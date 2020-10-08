#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    if (argc == 1)
    {printf("wunzip: file1 [file2 ...]\n");
      exit(1);}
    for (int i = 1; i < argc; i++)
    {   int cont = 1;
    	 char bin[4];
        char caracter;
        FILE *fp = fopen(argv[i], "r");
        if (fp == NULL)
        {  printf("wunzip: cannot open file\n");
            exit(1);}
        caracter = fgetc(fp);
        while (caracter!= EOF)
        {if (cont == 5)
            {   int x = (bin[3] << 24) | (bin[2] << 16) | (bin[1] << 8) | bin[0];
                for (int a = 0; a < x; a++)
                {printf("%c", caracter);}
                cont=0;
            }
            else
            {bin[cont - 1] = caracter;}
            caracter= fgetc(fp);
            cont = cont +1;
        }
        fclose(fp);
    }
    return 0;
} 
