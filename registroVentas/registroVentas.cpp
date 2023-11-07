#include <iostream>
#include <iomanip>

using namespace std;

const int NUM_PRODUCTOS = 3;  // Cambia esto al número deseado de productos
const int NUM_MESES = 4;     // Cambia esto al número deseado de meses

int main() {
    double ventas[NUM_PRODUCTOS][NUM_MESES] = {0.0};
    
    // Ingresar las ventas mensuales
    for (int i = 0; i < NUM_PRODUCTOS; i++) {
        for (int j = 0; j < NUM_MESES; j++) {
            cout << "Ingrese las ventas para el producto " << i + 1 << " en el mes " << j + 1 << ": ";
            cin >> ventas[i][j];
        }
    }

    // Calcular los totales de ventas por producto
    double totalVentasPorProducto[NUM_PRODUCTOS] = {0.0};
    for (int i = 0; i < NUM_PRODUCTOS; i++) {
        for (int j = 0; j < NUM_MESES; j++) {
            totalVentasPorProducto[i] += ventas[i][j];
        }
    }

    // Calcular los totales de ventas por mes
    double totalVentasPorMes[NUM_MESES] = {0.0};
    for (int j = 0; j < NUM_MESES; j++) {
        for (int i = 0; i < NUM_PRODUCTOS; i++) {
            totalVentasPorMes[j] += ventas[i][j];
        }
    }

    // Encontrar los productos más vendidos
    double maxVentasPorProducto = -1.0;
    int productoMasVendido = -1;
    for (int i = 0; i < NUM_PRODUCTOS; i++) {
        if (totalVentasPorProducto[i] > maxVentasPorProducto) {
            maxVentasPorProducto = totalVentasPorProducto[i];
            productoMasVendido = i;
        }
    }

    // Encontrar los meses de mayor y menor ventas
    double maxVentasPorMes = -1.0;
    double minVentasPorMes = totalVentasPorMes[0];
    int mesMasVentas = 1;
    int mesMenosVentas = 1;
    for (int j = 0; j < NUM_MESES; j++) {
        if (totalVentasPorMes[j] > maxVentasPorMes) {
            maxVentasPorMes = totalVentasPorMes[j];
            mesMasVentas = j + 1;
        }
        if (totalVentasPorMes[j] < minVentasPorMes) {
            minVentasPorMes = totalVentasPorMes[j];
            mesMenosVentas = j + 1;
        }
    }

    // Mostrar el informe
    cout << "\nInforme de Ventas:\n";
    cout << "Productos más vendidos: Producto " << productoMasVendido + 1 << endl;
    cout << "Mes de mayor ventas: Mes " << mesMasVentas << endl;
    cout << "Mes de menor ventas: Mes " << mesMenosVentas << endl;

    cout << "\nVentas por producto:\n";
    for (int i = 0; i < NUM_PRODUCTOS; i++) {
        cout << "Producto " << i + 1 << ": " << totalVentasPorProducto[i] << endl;
    }

    cout << "\nVentas por mes:\n";
    for (int j = 0; j < NUM_MESES; j++) {
        cout << "Mes " << j + 1 << ": " << totalVentasPorMes[j] << endl;
    }

    return 0;
}
