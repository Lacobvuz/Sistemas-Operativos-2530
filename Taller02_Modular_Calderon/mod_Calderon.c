/***********************0***************************************************************
 * Fecha: 24 de Septiembre 2025
 * Autor: David Santiago Calderon Idarraga
 * Materia: Sistemas Operativos
 * Tema: generacion de programa principal para la Multiplicacion de Matrices.
 * Objetivo: Hacer una metodología para la implementación de la multiplicación de matrices.
 * La idea principal, es construir paso a paso la implementación para hacer uso de la
 * biblioteca PTHREAD. Se implementa el Algoritmo Clásico de multiplicación de matrices, para
 * matrices cuadradas, es decir, la dimensión de filas es igual a la de columnas.
 * Incialmente se genera el progrma o código de forma general.
 * Posteriormente, se toma como enfoque la programación modular
 * A continuación se describen los paso
 *  - Reserva de memoria
 *      - Creación de punteros para matrices del tipo doble
 *      - Asignación de memoria
 *      - Ingreso de argumentos de entrada (Dimensión matriz, número de hilos)
 *      - Validación argumentos de entrada
 *      - Inicializar las matrices
 *      - Imprimir las matrices
 *      - Función para inicializar las matrices
 *      - Función para imprimir las matrices
 *      - Algoritmo clásico de multiplicación matrices
 *  - Se verifica el resultado
 *      - Función para multiplicación las matrices
 *      - Declaración vector de hilos
 *      - Creación de hilos según tamaño de vector de hilos
 *      - Crear estructura de datos que encapsule los argumentos de entrada de la función MM
 * Implementación de paralelismo: resolución de la multiplicación de matrices
 *  - Se crea el vector de hilos
 *  - Se tiene pendiente la exclusión de los hilos
 *  - Se pasa a globales las matrices
 *  - Encapsular los datos para enviarlos a la función MxM
 *  - Se desencapsulan los datos dentro de la función MxM (descomprimen)
*************************************************************************************/



// Se incluyen las  interfaces necesarias
#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>   
#include "modulo.h"


// Se declaran las variables de manera global
double *mA, *mB, *mC;

int main(int argc, char *argv[]) {
    // Valida que se reciba al menos 1 argumento que sera la dimension de las matrices cuadradas a mulitplicar
    if(argc<2){
    	printf("Numero argumentos incorrectos\n");
    	printf("\n\t $ejecutable.exe DIM \n");
    	return -1; // Termina en caso de recibir 0 o mas de 1 argumento
    }
    // Convierte el argumento recibido de entero a flotante
    int N = (int) atof(argv[1]);
    if(N<=0){
        printf("\n Valores deben ser mayor que cero\n");
        return -1;
    };
    // Reserva memoria para tres matris 
    // Matriz A y B se llena con valores aleotrios con malloc
    mA = (double *) malloc(N*N*sizeof(double));
    mB = (double *) malloc(N*N*sizeof(double));
    mC = (double *) calloc(N*N,sizeof(double));// Matriz C donde se guardaran el resultado, se incializa en 0 con el uso de calloc

	// Se inicializan las matrices A y B
    iniMatriz(N, mA,mB);
    
    // Imprimir matrices iniciales con la condición de que el tamaño sea menor a 7
    imprMatrices(N, mA);
    imprMatrices(N, mB);


    // Algoritmo de Multiplicación de matrices
    // Recorre fila de A y columna de B, va sumando y almacenando en un acumulador
     for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            double sumaTemp, *pA, *pB;
            sumaTemp = 0.0;// Acumulador
            pA = mA + i*N;// Puntero recorriendo filas de A
            pB = mB + j;// Puntero recorriendo columnas de B

            // Multuiplicaciones
            for(int k=0; k<N; k++, pA++, pB+=N){
                sumaTemp += *pA * *pB;
            }
            mC[j+i*N] = sumaTemp;// Guardar el valor resultante de cada posicione en la matriz reulstado C
        }
    }

    // Imprimir la matriz resultante 
	imprMatrices(N, mC);

    printf("\n\tFin del programa.............!\n");
    //IMPORTANTE: Libera la memoria reservada por el programa
    free(mA);
    free(mB);
    free(mC);
    return 0;
}
