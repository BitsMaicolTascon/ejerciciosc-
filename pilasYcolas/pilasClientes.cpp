#include <iostream>
#include <queue>
#include <string>

struct Cliente {
    std::string nombre;
    int edad;
    // Agrega más campos según sea necesario
};

void mostrarClientes(const std::queue<Cliente>& clientes) {
    std::queue<Cliente> clientesCopia = clientes;
    std::cout << "Clientes en la taquilla (sin los dos últimos):" << std::endl;
    int clientesMostrados = 0;
    while (!clientesCopia.empty() && clientesMostrados < clientes.size() - 2) {
        Cliente cliente = clientesCopia.front();
        std::cout << "Nombre: " << cliente.nombre << ", Edad: " << cliente.edad << std::endl;
        clientesCopia.pop();
        clientesMostrados++;
    }
}

void eliminarUltimo(std::queue<Cliente>& clientes) {
    if (!clientes.empty()) {
        // Elimina el último elemento
        std::queue<Cliente> colaTemporal;
        while (clientes.size() > 1) {
            colaTemporal.push(clientes.front());
            clientes.pop();
        }
        clientes = colaTemporal;
        std::cout << "Último cliente eliminado correctamente." << std::endl;
    } else {
        std::cout << "La cola de clientes está vacía. No se puede eliminar nada." << std::endl;
    }
}

int main() {
    std::queue<Cliente> clientes;
    Cliente cliente;

    std::cout << "Ingrese datos de clientes en la taquilla. Ingrese 'fin' para finalizar." << std::endl;

    do {
        std::cout << "Nombre del cliente (o 'fin' para finalizar): ";
        std::cin >> cliente.nombre;

        if (cliente.nombre != "fin") {
            std::cout << "Edad del cliente: ";
            std::cin >> cliente.edad;
            clientes.push(cliente);
        }

    } while (cliente.nombre != "fin");

    mostrarClientes(clientes);

    // Agregamos la opción de eliminar el último cliente
    char opcion;
    std::cout << "¿Desea eliminar al último cliente ingresado? (S/N): ";
    std::cin >> opcion;

    if (opcion == 'S' || opcion == 's') {
        eliminarUltimo(clientes);
        mostrarClientes(clientes); // Mostramos la cola actualizada después de la eliminación
    }

    return 0;
}
