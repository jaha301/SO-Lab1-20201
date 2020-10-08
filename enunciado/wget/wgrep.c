
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define n 1000
int wgrepEntrada(char caracter[]);
int Wgrep(char caracter[], char *fileName);


int main(int argc, char *argv[])
{
    if (argc == 1)
    {printf("wgrep: searchterm [file ...]\n");
        return 1;
    }
    if (argc == 2)
    {
        if (wgrepEntrada(argv[1]) == 1)
        {return 1;}
    }
    if (argc > 2)
    {
        for (int i = 2; i < argc; i++)
        {
            if (Wgrep(argv[1], argv[i]) == 1)
            {return 1;}
        }
    }
    return 0;
}
int wgrepEntrada(char caracter[])
{   char str[n];
    while (fgets(str, n, stdin))
    {  if (strstr(str, caracter) != NULL)
        {printf("%s", str);}
    }
    return 0;
}

int Wgrep(char caracter[], char *fileName)
{   FILE *fp = fopen(fileName, "r");
    size_t tam = 0;
    int cont = 0;
    char *linea = NULL;
    ssize_t conLinea;
    if (fp == NULL)
    {printf("wgrep: cannot open file\n");
        return 1;
    }

    conLinea = getline(&linea, &tam, fp);
    while (conLinea >= 0)
    {   cont++;
        if (strstr(linea, caracter) != NULL)
        {printf("%s", linea);
        }
        conLinea = getline(&linea, &tam, fp);
    }
    free(linea);
    linea = NULL;
    fclose(fp);

    return 0;
}
