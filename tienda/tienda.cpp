#include <iostream>
#include <stdio.h>

using namespace std;



string nameDay(int index) {
    string dayWeekend[] = {"Lunes", "Martes", "Miercoles", "Juewves", "Viernes", "Sabado", "Domingo"};
    return dayWeekend[index];
}


int main(int argc, char **argv) {

    int dailySales[7];
    int totalSales = 0;
    int maxDay = 0;
    int minDay = 0;

    for (int i = 0; i < 7; i++)
    {
        cout<<"Ingrese las ventas del día: " << nameDay(i) << " :";
        cin >> dailySales[i];
        totalSales += dailySales[i];


        if(dailySales[i] > dailySales[maxDay]) {
            maxDay = i;
        }
        
        if(dailySales[i] < dailySales[minDay]) {
            minDay = i;
        }
    }
    

    cout<<"Ventas del día: ";
    for (int i = 0; i < 7; i++) {
        cout<< dailySales[i] << " ";
    }

    cout<<endl<<"Ventas total: "<<totalSales;
    cout<<endl<<"Días con mas ventas: "<<nameDay(maxDay);
    cout<<endl<<"Dias con menos ventas: "<<nameDay(minDay);

    return 0;
}