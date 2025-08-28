/***********************0*******************************************************
 * Fecha: 26 de agosto 2025
 * Autor: David Santiago Calderon Idarraga
 * Materia: Sistemas Operativos
*******************************************************************************/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
 int n, i, *ptr, sum = 0;
 printf("Enter number of elements: ");
 scanf("%d", &n);
 
 ptr = (int*) calloc(n, sizeof(int));
 if(ptr == NULL) {
    printf("Error! memory not allocated.");
    exit(0);
 }
 
 
 for(i = 0; i < n; ++i) {
    printf("Enter elements: ");
    scanf("%d", ptr + i);
    sum += *(ptr + i);
 }
 
 printf("Sum = %d", sum);
 free(ptr);
 return 0;
 return 0;
}