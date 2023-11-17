#include <iostream>
#include <vector>

class AlgoritmoDeBusquedaBinaria {
private:
    std::vector<int> buscarBin;
    int left;
    int rigth;
    int elemento;

public:
    AlgoritmoDeBusquedaBinaria() : left(0), rigth(4) {
        buscarBin.resize(5);
    }

    void ingresarValores() {
        std::cout << "Ingresa los valores del vector " << std::endl;
        for (int i = 0; i < buscarBin.size(); i++) {
            std::cout << "Valor " << (i + 1) << ": ";
            std::cin >> buscarBin[i];
        }

        std::cout << "Ingrese el valor a buscar" << std::endl;
        std::cin >> elemento;
    }

    // Algoritmo de ordenamiento burbuja
    void ordenarB() {
        for (int i = 0; i < 5 - 1; i++) {
            for (int j = 0; j < 5 - i - 1; j++) {
                if (buscarBin[j] > buscarBin[j + 1]) {
                    // Intercambiamos los elementos
                    int temp = buscarBin[j];
                    buscarBin[j] = buscarBin[j + 1];
                    buscarBin[j + 1] = temp;
                }
            }
        }

        // Restablecer los límites después de ordenar
        left = 0;
        rigth = 4;
    }

    void imprimir() {
        for (int i = 0; i < 5; i++) {
            std::cout <<"\n" << buscarBin[i] << " ";
        }
        std::cout << std::endl;
    }

    void busquedaBinaria() {
        int medio;
        while (left <= rigth) {
            medio = (left + rigth) / 2;

            if (buscarBin[medio] < elemento) {
                left = medio + 1;
            } else if (buscarBin[medio] > elemento) {
                rigth = medio - 1;
            } else {
                std::cout << "\nElemento encontrado en la posición " << medio << std::endl;
                return;
            }
        }

        std::cout << "\nElemento no encontrado" << std::endl;
    }
};

int main() {
    AlgoritmoDeBusquedaBinaria bb;
    bb.ingresarValores();
    bb.ordenarB();
    bb.imprimir();
    bb.busquedaBinaria();

    return 0;
}