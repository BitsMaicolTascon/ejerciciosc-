#include <iostream>
#include <vector>
#include <string>

struct Student {
    int id;
    std::string name;
    double grade;
};

void insertionSort(std::vector<Student>& students) {
    int n = students.size();
    for (int i = 1; i < n; i++) {
        Student key = students[i];
        int j = i - 1;

        while (j >= 0 && students[j].id < key.id) {
            students[j + 1] = students[j];
            j = j - 1;
        }
        students[j + 1] = key;
    }
}

int main() {
    int numRows;
    std::cout << "Ingrese el número de filas: ";
    std::cin >> numRows;

    std::vector<Student> students;

    for (int i = 0; i < numRows; i++) {
        Student student;
        std::cout << "Ingrese el ID del estudiante: ";
        std::cin >> student.id;
        std::cin.ignore(); // Limpiar el buffer del teclado
        std::cout << "Ingrese el nombre del estudiante: ";
        std::getline(std::cin, student.name);
        std::cout << "Ingrese la nota del estudiante: ";
        std::cin >> student.grade;

        students.push_back(student);
    }

    insertionSort(students);

    // Mostrar la tabla ordenada
    std::cout << "\nTabla de estudiantes ordenada por ID (descendente):\n";
    std::cout << "ID\tNombre\tNota\n";
    for (const Student& student : students) {
        std::cout << student.id << "\t" << student.name << "\t" << student.grade << "\n";
    }

    return 0;
}
