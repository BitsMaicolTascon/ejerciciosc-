#include <iostream>

// Función que intercambia dos valores usando punteros
void intercambiarValores(int *valor1, int *valor2) {
    int temp = *valor1;
    *valor1 = *valor2;
    *valor2 = temp;
}

int main() {
    // Declarar dos variables para almacenar los valores
    int valorA, valorB;

    // Solicitar al usuario que ingrese dos valores
    std::cout << "Ingrese el valor A: ";
    std::cin >> valorA;

    std::cout << "Ingrese el valor B: ";
    std::cin >> valorB;

    // Mostrar los valores antes del intercambio
    std::cout << "Valores antes del intercambio: A = " << valorA << ", B = " << valorB << std::endl;

    // Llamar a la función y pasar las direcciones de memoria de las variables
    intercambiarValores(&valorA, &valorB);

    // Mostrar los valores después del intercambio
    std::cout << "Valores después del intercambio: A = " << valorA << ", B = " << valorB << std::endl;

    return 0;
}
