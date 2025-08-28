/***********************0***************************************************************
 * Fecha: 26 de agosto 2025
 * Autor: David Santiago Calderon Idarraga
 * Materia: Sistemas Operativos
*******************************************************************************/
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
int main() {
 char *p;
 char *q = NULL;
 printf("Address of p = %s\n", p);
 
 strcpy(p, "Hello, I'm the best in Operating Systems!!!");
 printf("%s\n", p);
 printf("About to copy \"Goodbye\" to q\n");
 printf("String copied\n");
 printf("%s\n", q);
 return 0;
}