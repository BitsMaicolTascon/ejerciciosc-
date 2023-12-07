#include <iostream>

class Nodo {
    public:
        int valor;
        Nodo* left;
        Nodo* right;

        Nodo(int val) : valor(val), left(nullptr), right(nullptr) {}
};

class ArbolBinario {
    private:
        Nodo* raiz;

    public:
        ArbolBinario() : raiz(nullptr){}

        void insertarValor(int val) {
            raiz = insertarAux(raiz, val);  
        }

        Nodo* insertarAux(Nodo* nodo, int val) {
            if(nodo == nullptr) {
                return new Nodo(val);
            } 

            if(val < nodo->valor) {
                nodo->left = insertarAux(nodo->left, val);
            } else if (val > nodo->valor) {
                nodo->right = insertarAux(nodo->right, val);
            }

            return nodo;
        }

        //método para realizar el recorrido inorden del arbol
        void inOrden() {
            inOrdenRec(raiz);   
            std::cout << std::endl;
        }

        //método recursivo para realizar el recorrido inorden
        void inOrdenRec(Nodo* nodo) {
            if(nodo != nullptr) {
                inOrdenRec(nodo->left);
                std::cout << nodo->valor << " ";
                inOrdenRec(nodo->right);
            }
        }

        //método para realizar el recorrido preorden del arbol
        void preOrden() {
            preOrdenRec(raiz);   
            std::cout << std::endl;
        }

        void preOrdenRec(Nodo* nodo) {
            if(nodo != nullptr) {
                std::cout << nodo->valor << " ";
                preOrdenRec(nodo->left);
                preOrdenRec(nodo->right);
            }
        }

        //método para realizar el recorrido postorden del arbol
        void postOrden() {
            postOrdenRec(raiz);   
            std::cout << std::endl;
        }

        void postOrdenRec(Nodo* nodo) {
            if(nodo != nullptr) {
                postOrdenRec(nodo->left);
                postOrdenRec(nodo->right);
                std::cout << nodo->valor << " ";
            }
        }
};

int main () {
    ArbolBinario arbol;

    // insertar valores en el arbol
    arbol.insertarValor(50);
    arbol.insertarValor(30);
    arbol.insertarValor(70);
    arbol.insertarValor(20);
    arbol.insertarValor(40);

    // realizar el recorrido inorden
    std::cout << "Recorrido inorden: ";
    arbol.inOrden();

    // realizar el recorrido preorden
    std::cout << "Recorrido preorden: ";
    arbol.preOrden();

    // realizar el recorrido postorden
    std::cout << "Recorrido postorden: ";
    arbol.postOrden();

    return 0;
};

