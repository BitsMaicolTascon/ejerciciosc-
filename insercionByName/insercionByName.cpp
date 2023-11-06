#include <iostream>
#include <vector>
#include <string>

void SolicitarDatos(std::vector<std::vector<std::string> >& table) {
    int numRows;
    std::cout << "Ingrese el número de filas: ";
    std::cin >> numRows;

    table.resize(numRows, std::vector<std::string>(3));

    for (int i = 0; i < numRows; i++) {
        std::cout << "Ingrese el ID del estudiante: ";
        std::cin >> table[i][0];
        std::cin.ignore(); // Limpiar el buffer del teclado
        std::cout << "Ingrese el nombre del estudiante: ";
        std::getline(std::cin, table[i][1]);
        std::cout << "Ingrese la nota del estudiante: ";
        std::cin >> table[i][2];
    }
}

void OrdenarPorNombreAscendente(std::vector<std::vector<std::string> >& table) {
    int n = table.size();
    for (int i = 1; i < n; i++) {
        std::vector<std::string> key = table[i];
        int j = i - 1;

        while (j >= 0 && table[j][1] > key[1]) {
            table[j + 1] = table[j];
            j = j - 1;
        }
        table[j + 1] = key;
    }
}

int main() {
    std::vector<std::vector<std::string> > table;

    SolicitarDatos(table);
    OrdenarPorNombreAscendente(table);

    // Mostrar la tabla ordenada
    std::cout << "\nTabla de estudiantes ordenada por Nombre (ascendente):\n";
    std::cout << "ID\tNombre\tNota\n";
    for (const std::vector<std::string>& row : table) {
        for (const std::string& cell : row) {
            std::cout << cell << "\t";
        }
        std::cout << std::endl;
    }

    return 0;
}
