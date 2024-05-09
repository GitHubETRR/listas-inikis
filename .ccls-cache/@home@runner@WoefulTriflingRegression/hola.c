#include<stdio.h>
// Ingresar caracteres en un archivo hasta [Enter]
//verificar el archivo con el bloc de notas
int main(){
    FILE *archivo;
    char ch;
    char* nombre="texto.txt";// nombre fisico del archivo
    if((archivo=fopen(nombre,"w"))==NULL)
           printf("\n\n***El archivo %s no pudo abrirse ***\n",nombre);
    else{
           printf("\n\n Ingrese caracteres hasta [Enter]");
           while((ch=getchar())!='\n'){
               putc(ch,archivo); // almacena en el archivo hasta [ENTER]

           }
           fclose(archivo)    ;
   }
}