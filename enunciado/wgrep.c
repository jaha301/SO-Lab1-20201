#include <stdio.h>
#include <string.h>


int main(char * p, int argc, char **argv)
{

int c=1;
int len = strlen(P);

char caracter;
FILE *pf;
while (c<argc){

   if ((pf=fopen(argv[c],"r"))==NULL){
       printf("wcat: cannot open file");

    } 
    else {
   while(!feof(pf)){
    {
        fscanf(pf,"%c",&caracter);
        
        if (strstr(caracter,P))
        {
            if (*(caracter-1) == ' ' && *(caracter+len+1) == ' ')
            {
                return 1;
            }
        }
   
   printf("%c", caracter);
   }
   fclose(pf); 
  }
c++;
}
return 0;
}
