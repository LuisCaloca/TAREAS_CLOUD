// Programación de una solución paralela.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <omp.h>

#define N 1000        // Cantidad de elementos en los arreglos
#define chunk 100     // Tamaño de los pedazos que se asignan a cada hilo
#define mostrar 10    // Cantidad de datos a imprimir de cada arreglo

// Prototipo de la función para imprimir arreglos
void imprimeArreglo(float* d);

int main()
{
    std::cout << "Sumando Arreglos en Paralelo!\n";

    // Declaración de arreglos
    float a[N], b[N], c[N];
    int i;

    // Inicialización de los arreglos a y b con valores calculados
    for (i = 0; i < N; i++) {
        a[i] = i * 10;
        b[i] = (i + 3) * 3.7;
    }

    // Variable para definir el tamaño de los pedazos
    int pedazos = chunk;

    // Suma de arreglos utilizando un for paralelo con OpenMP
#pragma omp parallel for \
    shared(a, b, c, pedazos) private(i) \
    schedule(static, pedazos)
    for (i = 0; i < N; i++) {
        c[i] = a[i] + b[i];
    }

    // Impresión de los resultados
    std::cout << "Imprimiendo los primeros " << mostrar << " valores del arreglo a: " << std::endl;
    imprimeArreglo(a);

    std::cout << "Imprimiendo los primeros " << mostrar << " valores del arreglo b: " << std::endl;
    imprimeArreglo(b);

    std::cout << "Imprimiendo los primeros " << mostrar << " valores del arreglo c (resultado): " << std::endl;
    imprimeArreglo(c);

    return 0;
}

// Función para imprimir los primeros elementos de un arreglo
void imprimeArreglo(float* d) {
    for (int x = 0; x < mostrar; x++) {
        std::cout << d[x] << " - ";
    }
    std::cout << std::endl;
}