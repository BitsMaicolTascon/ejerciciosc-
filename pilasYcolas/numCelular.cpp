#include <iostream>
#include <stack>
#include <queue>

void mostrarNumeros(const std::stack<int>& numeros) {
    std::stack<int> numerosCopia = numeros;
    std::cout << "Números de celular ingresados:" << std::endl;
    while (!numerosCopia.empty()) {
        std::cout << numerosCopia.top() << std::endl;
        numerosCopia.pop();
    }
}

void eliminarUltimo(std::stack<int>& numeros) {
    if (!numeros.empty()) {
        numeros.pop();
        std::cout << "Último número eliminado correctamente." << std::endl;
    } else {
        std::cout << "La lista de números está vacía. No se puede eliminar nada." << std::endl;
    }
}

int main() {
    std::stack<int> numeros;
    int numero;

    std::cout << "Ingrese números de celular. Ingrese 0 para finalizar." << std::endl;

    do {
        std::cout << "Ingrese un número de celular (o 0 para finalizar): ";
        std::cin >> numero;

        if (numero != 0) {
            numeros.push(numero);
        }

    } while (numero != 0);

    mostrarNumeros(numeros);

    // Agregamos la opción de eliminar el último número
    char opcion;
    std::cout << "¿Desea eliminar el último número ingresado? (S/N): ";
    std::cin >> opcion;

    if (opcion == 'S' || opcion == 's') {
        eliminarUltimo(numeros);
        mostrarNumeros(numeros); // Mostramos la lista actualizada después de la eliminación
    }

    return 0;
}
