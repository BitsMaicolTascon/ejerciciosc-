#include <iostream>
#include <stdio.h>


using namespace std;

class AlturaJugadores {
    public:
        float altura[5];
        float promedio;

        void cargarAlturas() {
            for(int i = 0; i < 5; i++){
                cout<<"Ingrese la altura del jugador"<< (i +1) << ": ";
                cin>>altura[i];
            }
        }

        void promedioAltura() {
            float suma = 0;
            for(int i = 0; i < 5; i++) {
                suma  += altura[i];
            }
            promedio = suma / 5;
            cout<<"El promedio de la altura es: "<<promedio<<endl;
        }

        void mayorYmenor() {
            int mayor = 0;
            int menor = 0;
            for (int i = 0; i < 5; i++) {
                if(altura[i] > promedio ) {
                    mayor++;

                } else if (altura[i] < 5) {
                    menor++;
                }

        
            }
            cout<<"La cantidad de personas mayores al promedio son: "<<mayor<<endl;
            cout<<"La cantidad de personas menores al promedio son: "<<menor<<endl;
        }
};

int main( int argc, char *argv[ ] ){

    AlturaJugadores altura;
    altura.cargarAlturas();
    altura.promedioAltura();
    altura.mayorYmenor();

    return 0;

};

