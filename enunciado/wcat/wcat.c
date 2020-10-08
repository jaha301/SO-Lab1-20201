#include <stdio.h>
#include <string.h>

int main(int argc, char **argv)
{
int c=1;
char caracter;
FILE *pf;
pf=fopen(argv[c],"rb");
while (c<argc){
   if ((pf=fopen(argv[c],"rb"))==NULL){
       printf("wcat: cannot open file\n");
       return 1;
    } 
    else {
   while(!feof(pf)){
   fscanf(pf,"%c",&caracter);
   if(!feof(pf)){
   printf("%c",caracter);}
   }
  }
c++;
fclose(pf);
}
return(0);
}
