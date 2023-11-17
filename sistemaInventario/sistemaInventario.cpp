#include <iostream>
#include <vector>

using namespace std;

// Estructura para representar un producto
struct Producto {
    string nombre;
    int codigoBarras;
    int cantidad;
};


// Función para agregar un producto en el inventario
int buscarProducto(const vector<Producto>& inventario, int codigoBarras) {
    for (int i = 0; i < inventario.size(); ++i) {
        if (inventario[i].codigoBarras == codigoBarras) {
            return i;  // Devolver la posición del producto en el inventario
        }
    }
    return -1;  // Si no se encuentra el producto
}

int main() {
    vector<Producto> inventario;

    while (true) {
        // Menú de opciones
        cout << "1. Agregar producto\n";
        cout << "2. Buscar producto\n";
        cout << "3. Salir\n";
        cout << "Ingrese su opción: ";

        int opcion;
        cin >> opcion;

        switch (opcion) {
            case 1: {
                // Agregar un producto al inventario
                Producto nuevoProducto;
                cout << "Ingrese el nombre del producto: ";
                cin >> nuevoProducto.nombre;
                cout << "Ingrese el código de barras del producto: ";
                cin >> nuevoProducto.codigoBarras;
                cout << "Ingrese la cantidad en inventario: ";
                cin >> nuevoProducto.cantidad;

                inventario.push_back(nuevoProducto);
                cout << "Producto agregado al inventario.\n";
                break;
            }
            case 2: {
                // Buscar un producto en el inventario
                int codigoBarras;
                cout << "Ingrese el código de barras del producto a buscar: ";
                cin >> codigoBarras;

                int posicion = buscarProducto(inventario, codigoBarras);
                if (posicion != -1) {
                    cout << "Producto encontrado:\n";
                    cout << "Nombre: " << inventario[posicion].nombre << "\n";
                    cout << "Cantidad en inventario: " << inventario[posicion].cantidad << "\n";
                } else {
                    cout << "Producto no encontrado en el inventario.\n";
                }
                break;
            }
            case 3:
                // Salir del programa
                cout << "Saliendo del programa.\n";
                return 0;
            default:
                cout << "Opción no válida. Por favor, ingrese una opción válida.\n";
        }
    }

    return 0;
}
