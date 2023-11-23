#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Contacto
{
    int id;
    std::string nombre;
    std::string numeroTel;
};

class ListaContactos {
    private:
    std::vector<Contacto> contactos;

    public:

    bool idExistente(int id) {
        for (const Contacto& cont : contactos) {
            if (cont.id == id) {
                return true;
            }
        }
        return false;
    }

    void agregaContacto(const std::string nombre, const std::string numeroTel, int id){
       if (idExistente(id)) {
            std::cout << "El ID ya existe. Ingrese un ID único.\n";
        } else {
            contactos.push_back({id, nombre, numeroTel});
            std::cout << "Contacto agregado con éxito.\n";
        }
    }

    void ordenarPorId() {
       int n = contactos.size();
        for (int i = 1; i < n; ++i) {
            Contacto key = contactos[i];
            int j = i - 1;

            while (j >= 0 && contactos[j].id > key.id) {
                contactos[j + 1] = contactos[j];
                j = j - 1;
            }
            contactos[j + 1] = key;
        }
    }

    void ordenarPorNombre() {
        int n = contactos.size();
        for (int i = 1; i < n; ++i) {
            Contacto key = contactos[i];
            int j = i - 1;

            while (j >= 0 && contactos[j].nombre > key.nombre) {
                contactos[j + 1] = contactos[j];
                j = j - 1;
            }
            contactos[j + 1] = key;
        }
    }

    void ordenarPorNumeroTel() {
        int n = contactos.size();
        for (int i = 1; i < n; ++i) {
            Contacto key = contactos[i];
            int j = i - 1;

            while (j >= 0 && contactos[j].numeroTel > key.numeroTel) {
                contactos[j + 1] = contactos[j];
                j = j - 1;
            }
            contactos[j + 1] = key;
        }
    }


    void buscarPorNombre(const std::string& nombre) {
        ordenarPorNombre(); 

        int inicio = 0, fin = contactos.size() - 1;

        while (inicio <= fin) {
            int medio = inicio + (fin - inicio) / 2;

            if (contactos[medio].nombre == nombre) {
                std::cout << "Contacto encontrado:\n";
                std::cout << "Nombre: " << contactos[medio].nombre << "  Teléfono: " << contactos[medio].numeroTel << " Identificador: " << contactos[medio].id << "\n";
                return;
            }

            if (contactos[medio].nombre < nombre) {
                inicio = medio + 1;
            } else {
                fin = medio - 1;
            }
        }

        std::cout << "Contacto no encontrado.\n";
    }

    void buscarPorNumeroTel(const std::string numeroTel){
        ordenarPorNumeroTel();

        int inicio = 0, fin = contactos.size() - 1;

        while (inicio <= fin) {
            int medio = inicio + (fin - inicio) / 2;

            if (contactos[medio].numeroTel == numeroTel) {
                std::cout << "Contacto encontrado:\n";
                std::cout << "Nombre: " << contactos[medio].nombre << "  Teléfono: " << contactos[medio].numeroTel << " Identificador: " << contactos[medio].id << "\n";
                return;
            }

            if (contactos[medio].numeroTel < numeroTel) {
                inicio = medio + 1;
            } else {
                fin = medio - 1;
            }
        }

        std::cout << "Contacto no encontrado.\n";
        
    }

    void mostrarContactos(){
        std::cout << "Contactos: " << std::endl;
        for (const Contacto cont : contactos)
        {
            std::cout << "Nombre: " << cont.nombre << "  Telefono: " << cont.numeroTel << " Identificador: " << cont.id << " \n";
        }
    }


    void menuContactos(){
        int op;
        do
        {
            std::cout << "Menu \n";
            std::cout << "1. Agregar contacto \n";
            std::cout << "2. Buscar por nombre \n";
            std::cout << "3. Buscar por numero de telefono\n";
            std::cout << "4. Mostrar contactos\n";
            std::cout << "5. Salir \n";
            std::cout << "Opcion: ";
            std::cin >> op;

            switch (op) {

                case 1:
                {
                    std::string nombre, numeroTel;
                    int id;
                    std::cout << "Ingrese el nombre del contacto: ";
                    std::cin.ignore();
                    std::getline(std::cin, nombre);
                    std::cout << "Ingrese el numero de telefono del contacto: ";
                    std::getline(std::cin, numeroTel);
                    std::cout << "Ingrese el id del contacto: ";
                    std::cin >> id;
                    agregaContacto(nombre, numeroTel, id);
                    break;
                }
                case 2: {
                    std::string nombre;
                    std::cout << "Ingrese el nombre del contacto: ";
                    std::cin.ignore();
                    std::getline(std::cin, nombre);
                    buscarPorNombre(nombre);
                    break;
                }
                case 3: {
                    std::string numeroTel;
                    std::cout << "Ingrese el numero de telefono del contacto: ";
                    std::cin.ignore();
                    std::getline(std::cin, numeroTel);
                    buscarPorNumeroTel(numeroTel);
                    break;
                }
                case 4: {
                    mostrarContactos();
                    break;
                }
                case 5: {
                     std::cout << "Saliendo de la aplicacion. \n";
                    break;
                }
                default: {
                     std::cout << "Opcion invalida. \n";
                }
            }


        } while (op != 5);

    }


};

int main()
{
    ListaContactos listaContactos;
    listaContactos.menuContactos();
    return 0;
}