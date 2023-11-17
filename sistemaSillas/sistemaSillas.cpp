#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Función para verificar la disponibilidad de un asiento utilizando búsqueda binaria
bool verificarDisponibilidad(const vector<int>& asientos, int numeroAsiento) {
    return binary_search(asientos.begin(), asientos.end(), numeroAsiento);
}

// Función para ordenar un vector utilizando el algoritmo de inserción
void ordenarAsientos(vector<int>& asientos) {
    int n = asientos.size();
    for (int i = 1; i < n; ++i) {
        int key = asientos[i];
        int j = i - 1;

        while (j >= 0 && asientos[j] > key) {
            asientos[j + 1] = asientos[j];
            j = j - 1;
        }

        asientos[j + 1] = key;
    }
}

int main() {
    vector<int> asientosDisponibles = {5, 2, 8, 1, 10, 4, 7}; // Asientos en orden aleatorio
    vector<int> asientosSeleccionados;

    // Mostrar asientos disponibles
    cout << "Asientos disponibles (orden aleatorio): ";
    for (int asiento : asientosDisponibles) {
        cout << asiento << " ";
    }
    cout << "\n";

    // Ordenar asientos utilizando el algoritmo de inserción
    ordenarAsientos(asientosDisponibles);

    // Solicitar al usuario el número de asientos a seleccionar
    int numAsientosASeleccionar;
    cout << "¿Cuantos asientos desea seleccionar?: ";
    cin >> numAsientosASeleccionar;

    // Menú para seleccionar asientos
    for (int i = 0; i < numAsientosASeleccionar; ++i) {
        int numeroAsiento;
        cout << "Ingrese el número del asiento: ";
        cin >> numeroAsiento;

        // Verificar disponibilidad utilizando búsqueda binaria
        if (verificarDisponibilidad(asientosDisponibles, numeroAsiento)) {
            cout << "¡Asiento disponible! Reserva realizada.\n";
            asientosSeleccionados.push_back(numeroAsiento);
        } else {
            cout << "Lo siento, el asiento no está disponible. Por favor, seleccione otro.\n";
            --i; // Decrementar el índice para repetir la selección del asiento
        }
    }

    // Mostrar la lista ordenada de asientos al final
    cout << "Números de asientos: ";
    for (int asiento : asientosDisponibles) {
        cout << asiento << " ";
    }
    cout << "\n";

    // Mostrar los asientos seleccionados por el usuario
    cout << "Asientos seleccionados: ";
    for (int asiento : asientosSeleccionados) {
        cout << asiento << " ";
    }
    cout << "\n";

    return 0;
}
