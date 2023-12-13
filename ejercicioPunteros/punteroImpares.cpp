#include <iostream>

// Función que determina si un número es par o impar usando punteros
void determinarParImpar(int *numero) {
    if (*numero % 2 == 0) {
        std::cout << "El número " << *numero << " es par." << std::endl;
    } else {
        std::cout << "El número " << *numero << " es impar." << std::endl;
    }
}

int main() {
    // Declarar dos variables para almacenar los números
    int num1, num2;

    // Solicitar al usuario que ingrese dos números
    std::cout << "Ingrese el primer número: ";
    std::cin >> num1;

    std::cout << "Ingrese el segundo número: ";
    std::cin >> num2;

    // Determinar y mostrar si el primer número es par o impar usando punteros
    determinarParImpar(&num1);

    // Determinar y mostrar si el segundo número es par o impar usando punteros
    determinarParImpar(&num2);

    return 0;
}
