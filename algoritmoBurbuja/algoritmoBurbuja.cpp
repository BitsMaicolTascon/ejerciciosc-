// algoritmo burbuja

#include <iostream>
using namespace std;

// Función para ordenar la lista usando el algoritmo de ordenamiento burbuja
void algoritmoBurbuja(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            // Si el elemento actual es mayor que el siguiente, intercámbialos
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]); // swap() -> intercambia los valores de dos variables
            }
        }
    }
}

// Función para imprimir una lista
void pintarLista(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}


int main() {
    // Lista desordenada de números enteros
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]); // sizeof() -> devuelve el tamaño de todo el array.

    cout << "Lista desordenada: ";
    pintarLista(arr, n);

    // Llama a la función de ordenamiento burbuja
    algoritmoBurbuja(arr, n);

    cout << "Lista ordenada: ";
    pintarLista(arr, n);

    return 0;
}
