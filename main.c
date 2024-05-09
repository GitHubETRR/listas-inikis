#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#define LEN 100

typedef struct productos {
  char *nombre;
  /*char *apellido;
  unsigned int edad;*/
  char *precio;
  char *cantidad;
  struct productos *siguiente;
} producto;

typedef unsigned char enterito;
typedef producto * puntero_lista;

void imprimir_todo(puntero_lista comienzo);
void borrar_lista(puntero_lista *comienzo);
void crear_producto(puntero_lista *comienzo);

FILE *txt;

int main() {
  enterito pepe;
  char carac;
  puntero_lista comienzo = NULL;

  txt=fopen("productos.txt","r+");

  /*fputs("PRODUCTOS MAXIKIOSCO:\n", txt);
  fputs("nada", txt);
  fflush(txt); //vuelca el contenido del buffer al archivo
  char var[LEN];
  rewind(txt);
  while(!feof(txt)){
    fgets(var, LEN, txt);
    for(int var2 = 0; var2 < LEN && var[var2 - 1] != '\n'; var2++){
      printf("%c", var[var2]);
    }
  }*/
  do {
    printf("presione \'c\' para agregar un producto \'l\' para listar todos y \'s\' para salir\n");
    do {
      carac = getchar();
    } while ((carac != 'c') && (carac != 'l') && (carac != 's'));
    if (carac == 'c')
      crear_producto(&comienzo);
    if (carac == 'l')
      imprimir_todo(comienzo);
  } while (carac != 's');
  borrar_lista(&comienzo);
  fclose(txt);
  return 0;
}

void crear_producto(puntero_lista *comienzo) {
  puntero_lista p = malloc(sizeof(producto));
  p->siguiente = NULL;
  
  printf("Ingrese el nombre del nuevo producto sin espacio o con guiones\n");
  char *nombre = (char *)malloc(10);
  scanf("%s", nombre);
  p->nombre = nombre;
  fseek(txt, 0, SEEK_END);
  fputs("\n", txt);
  fputs(nombre, txt);
  fputs("~", txt);
  
 /* printf("Ingrese el Apellido del nuevo alumno\n");
  char *apellido = (char *)malloc(10);
  scanf("%s", apellido);
  p->apellido = apellido;
  printf("Ingrese la edad del nuevo alumno\n");
  scanf("%d", &(p->edad));*/
  printf("Ingrese el precio del nuevo producto\n");
  char *precio = (char *)malloc(10);
  scanf("%s", precio);
  p->precio = precio;
  fputs(precio, txt);
  fputs("~", txt);
  printf("Ingrese el stock disponible del nuevo producto\n");
  char *cantidad = (char *)malloc(10);
  scanf("%s", cantidad);
  p->cantidad = cantidad;
  fputs(cantidad, txt);
  fflush(txt); //vuelca el contenido del buffer al archivo
}

void imprimir_todo(puntero_lista comienzo) {
  /*while (comienzo != NULL) {
    printf("Nombre del producto: %s \n", comienzo->nombre);
    printf("Precio del producto: %s \n", comienzo->precio);
    printf("Cant. del producto: %s \n", comienzo->cantidad);
    comienzo = comienzo->siguiente;
  }*/
  char var[LEN];
  char var2;
  fseek(txt, 22, SEEK_SET);
  while(!feof(txt)){
    for(int var3=0; var3<LEN; var3++){
      var[var3] = 0;
    }
    fgets(var, LEN, txt);
    printf("\nNombre: ");
    for(var2 = 0; var2 < LEN && var[var2 - 1] != '\n' && var[var2] != '~'; var2++){
      printf("%c", var[var2]);
    }
    printf("\nPrecio: ");
    for(var2++; var2 < LEN && var[var2] != '~'; var2++){
      printf("%c", var[var2]);
    }
    printf("\nCantidad: ");
    for(var2++; var2 < LEN && var[var2 - 1] != '\n'; var2++){
      printf("%c", var[var2]);
    }
    printf("\n\n");
  }
}

void borrar_lista(puntero_lista *comienzo) {
  puntero_lista actual;
  while (*comienzo != NULL) {
    actual = *comienzo;
    *comienzo = (*comienzo)->siguiente;
    free(actual->nombre);
    free(actual);
  }
}
