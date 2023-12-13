#include <iostream>

// Función que calcula el cuadrado de un número usando punteros
void calcularCuadrado(int *numero) {
    *numero = (*numero) * (*numero);
}

int main() {
    // Declarar una variable para almacenar el número
    int numero;

    // Solicitar al usuario que ingrese un número
    std::cout << "Ingrese un número entero: ";
    std::cin >> numero;

    // Llamar a la función y pasar la dirección de memoria del número
    calcularCuadrado(&numero);

    // Mostrar el resultado
    std::cout << "El cuadrado del número ingresado es: " << numero << std::endl;

    return 0;
}
