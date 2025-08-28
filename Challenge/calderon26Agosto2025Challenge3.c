/***********************0***************************************************************
 * Fecha: 26 de agosto 2025
 * Autor: David Santiago Calderon Idarraga
 * Materia: Sistemas Operativos
*******************************************************************************/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
 int *ptr;
 ptr = malloc(15 * sizeof(*ptr)); /* a block of 15 integers */

 if (ptr != NULL) {
 *(ptr + 5) = 480; /* assign 480 to sixth integer */
 printf("Value of 6th integer is %d\n", *(ptr+5));
 }
 
 return 0;
}
 
 
 
 
 
 
 
 
 