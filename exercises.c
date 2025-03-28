#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "arraylist.h"
#include "stack.h"

//#include "exercises.h"

//Funciones auxiliares que puedes utilizar para debuggear tus ejercicios
//NO MODIFICAR
void imprime_lista(List *L) {
   int *dato;
   dato = (int*)first(L);
   printf("[");
   while(dato != NULL) {
      printf("%d ", *dato);
      dato = (int*)next(L);
   }
   printf("]\n");

}

//Ojo que la pila se vacía al imprimir y se imprime en orden inverso
//NO MODIFICAR
void imprime_y_vacia_pila(Stack *P) {
   void *dato;
   printf("[");
   while((dato = pop(P)) != NULL) {
      printf("%d ", *(int*)dato);
   }
   printf("]\n");
}

/* 
Ejercicio 1.
Crea una Lista y agrega punteros a elementos del 1 al 10.
Recuerda que la lista almacena punteros, por lo que
debes reservar memoria para cada elemento que agregues.
Al finalizar retorna la lista creada.
*/

List* crea_lista() {
   List* L = create_list();

   for(int i = 1; i <=10; i++)
   {
      int* num = (int*) malloc(sizeof(int));
      *(num) = i;
      pushBack(L, num);

   }
   return L;
}

/*
Ejercicio 2.
Crea una función que reciba una lista de enteros (int*) y 
retorne la suma de sus elementos.
*/
int sumaLista(List *L) {
   int suma = 0;
   int total = get_size(L);
   int* dato = first(L);
   for(int k = 0; k < total; k++)
   {
      suma += *dato;
      dato = next(L);
   }
   return suma;
}

/*
Ejercicio 3.
Crea una función que reciba una lista de punteros a int (int*) y
un entero elem. La función debe eliminar todos los elementos 
de la lista que sean iguales a elem.
Asume que popCurrent luego de eliminar un elemento se
posiciona en el elemento anterior.
*/

void eliminaElementos(List*L, int elem){
   int total = get_size(L);
   int* dato = first(L);

   for(int k = 0; k < total; k++)
   {
      if (*dato == elem)
         popCurrent(L);
      dato = next(L);
   }

}

/*
Ejercicio 4.
La función copia los punteros de la pila P1 en la pila P2.
El orden de ambas pilas se debe mantener.
Puedes usar una pila auxiliar.
*/

void copia_pila(Stack* P1, Stack* P2) {
   Stack* aux = create_list();
   while(top(P1) != NULL)
   {
      void* elemento = top(P1);
      push(aux, elemento);
      pop(P1);
   }

   while(top(aux) != NULL)
   {
      void* elemento = top(aux);
      push(P1,elemento);
      push(P2,elemento);
      pop(aux);
   }
   free(aux);   
}

/*
Ejercicio 5.
La función verifica si la cadena de entrada tiene sus 
paraéntesis balanceados. Retorna 1 si están balanceados,
0 en caso contrario.
*/

int parentesisBalanceados(char *cadena) {
   int contador = 0;
   while(cadena[contador] != '\0')
   {
      contador ++;
   }

   if (contador % 2 == 1)
      return 0;

   Stack* pila = create_stack();
   for(int r = 0; r < contador; r++)
   {
      push(pila, (void *)(long)cadena[r]);
   }

   for(int r = 0; r < contador ; r++)
   {
      char elemTras =  (char) (long) top(pila);
      if (('}' == elemTras && cadena[r] == '{') ||(']' == elemTras && cadena[r] == '[' )||(')' == elemTras && cadena[r] == '(') ) return 1;

      pop(pila);
   }

   return 0;
}

