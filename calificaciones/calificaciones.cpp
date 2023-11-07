#include <iostream>
#include <string>

using namespace std;

int main() {
    int numEstudiantes;
    cout << "Ingrese el número de estudiantes: ";
    cin >> numEstudiantes;

    if (numEstudiantes <= 0) {
        cout << "El número de estudiantes debe ser mayor que cero." << endl;
        return 1;
    }

    double sumaCalificaciones = 0.0;
    double calificacionMaxima, calificacionMinima;

    for (int i = 0; i < numEstudiantes; i++) {
        string nombre;
        double calificacion;

        cout << "Ingrese el nombre del estudiante " << i + 1 << ": ";
        cin >> nombre;

        cout << "Ingrese la calificación para " << nombre << ": ";
        cin >> calificacion;

        // Actualizar el acumulado de calificaciones
        sumaCalificaciones += calificacion;

        // Si es la primera iteración, asignar el valor a ambas calificaciones máxima y mínima
        if (i == 0) {
            calificacionMaxima = calificacion;
            calificacionMinima = calificacion;
        } else {
            // Actualizar la calificación máxima y mínima si es necesario
            if (calificacion > calificacionMaxima) {
                calificacionMaxima = calificacion;
            }
            if (calificacion < calificacionMinima) {
                calificacionMinima = calificacion;
            }
        }
    }

    // Calcular el promedio de calificaciones
    double promedio = sumaCalificaciones / numEstudiantes;

    // Mostrar los resultados
    cout << "\nResultados:\n";
    cout << "Promedio de calificaciones: " << promedio << endl;
    cout << "Calificación más alta: " << calificacionMaxima << endl;
    cout << "Calificación más baja: " << calificacionMinima << endl;

    return 0;
}
