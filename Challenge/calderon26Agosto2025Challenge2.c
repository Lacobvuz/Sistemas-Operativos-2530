/***********************0***************************************************************
 * Fecha: 26 de agosto 2025
 * Autor: David Santiago Calderon Idarraga
 * Materia: Sistemas Operativos

*******************************************************************************/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
 char *q = NULL;
 printf("Requesting space for \"Goodbye\" \n");
 q = (char *)malloc(strlen("Goodbye")+1);
 if (!q) {
    perror("Failed to allocate space because");
    exit(1);
 }
 printf("About to copy \"Goodbye\" to q at address %s \n", q);
 strcpy(q, "Goodbye");
 printf("String copied\n");
 printf("%s \n", q);
 return 0;
}