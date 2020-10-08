
#include <stdio.h>
int ultimaL;
int wzip(char *fileName);
int final(int contador, char comp);



int main(int argc, char *argv[]){ 

   if (argc == 1){
       printf("wzip: file1 [file2 ...]\n");
       return 1;}   
   int cont = 0;
   if (argc > 1){
       for (int i = 1; i < argc; i++)
       {cont = cont+ wzip(argv[i]);}
       final(cont, ultimaL);}
}


int wzip(char *fileName){
   FILE *fp = fopen(fileName, "r");
   int contletras = 1; 
   char caracterpos;                 
   char primeraL;                   
                

   if (fp == NULL){
       printf("wzip: cannot open file\n");
       return 1;
   }
   caracterpos = fgetc(fp);

  do{  primeraL = caracterpos;
       caracterpos = fgetc(fp);
       if (caracterpos == EOF){
           break;
       }
       if (caracterpos == primeraL){
           contletras++;
       }
       else{fwrite(&contletras, 1, sizeof(contletras), stdout);
            printf("%c", primeraL);
            contletras = 1;
       }
   } while (1);

   ultimaL = primeraL;
   fclose(fp);
   return contletras;
}

int final(int contador, char comp){
   fwrite(&contador, 1, sizeof(contador), stdout);
   printf("%c", comp);
   return 0;
} 

