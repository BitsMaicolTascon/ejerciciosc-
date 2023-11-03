#include <iostream>
#include <vector>

class Matriz {

    private:
        std::vector<std::vector<int> > matrices;

        public:
            void cargar() {
                 std::cout<<"Digite las filas de la matrz: ";
                 int filas, columnas;
                 std::cin>>filas;
                 std::cout<<"Digite las columnas de la matrz: ";
                 std::cin>>columnas;

                matrices.resize(filas, std::vector<int>(columnas));

                for(int f=0; f<filas; f++) {
                    for (int c = 0; c < columnas; c++){
                        std::cout<<"Ingrese el componente de la matriz: ";
                        std::cin>> matrices[f][c];
                    }                
                }
            }

            void imprimirMayor() {
                int mayor = matrices[0][0];
                int filaMayor = 0;
                int columnaMayor = 0;
                for(int f = 0; f < matrices.size(); f++){
                    for(int c = 0; c < matrices[f].size(); c++) {
                        if(matrices[f][c] > mayor) {
                            mayor = matrices[f][c];
                            filaMayor = f;
                            columnaMayor = c;
                        }
                    }
                }
                std::cout<<"El elemento mayor es: "<<mayor<<std::endl;
                std::cout<<"Se encuentra en la fila: "<<filaMayor<<" y en la columna "<<columnaMayor<<std::endl;
            }
};

int main() {
    Matriz ma;
    ma.cargar();
    ma.imprimirMayor();
    return 0;
}