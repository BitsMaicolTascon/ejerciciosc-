#include <iostream>
#include <vector>
#include <string>

struct Libro
{
    int id;
    std::string titulo;
    std::string autor;
};

class GestionarLibros
{
private:
    std::vector<Libro> libros;

public:
    void agregaLibro(const std::string titulo, const std::string autor, int id)
    {
        libros.push_back({id, titulo, autor});
        std::cout << "Libro agregado. \n " << std::endl;
    }

    void buscarPorTitulo(const std::string titulo)
    {
        for (const Libro lib : libros)
        {
            if (lib.titulo == titulo)
            {
                std::cout << "Libro encontrado. " << std::endl;
                std::cout << "Titulo: " << lib.titulo << "  Autor: " << lib.autor << " Identificador: " << lib.id << " \n";
            }
        }

        std::cout << "Libro no encontrado. \n";
    }

    void mostrarLibros()
    {
        std::cout << "Libros: " << std::endl;
        for (const Libro libr : libros)
        {
            std::cout << "Titulo: " << libr.titulo << "  Autor: " << libr.autor << " Identificador: " << libr.id << " \n";
        }
    }

    void menuLibros()
    {
        int op;
        do
        {
            std::cout << "Menu \n";
            std::cout << "1. Agregar libro \n";
            std::cout << "2. Buscar por titulo \n";
            std::cout << "3. Mostrar libros \n";
            std::cout << "4. Salir \n";
            std::cout << "Opcion: ";
            std::cin >> op;

            switch (op)
            {
                case 1:
                {
                    std::string titulo, autor;
                    int id;
                    std::cout << "Ingrese el titulo del libro: ";
                    std::cin.ignore();
                    std::getline(std::cin, titulo);
                    std::cout << "Ingrese el autor del libro: ";
                    std::getline(std::cin, autor);
                    std::cout << "Ingrese el id del libro: ";
                    std::cin >> id;
                    agregaLibro(titulo, autor, id);
                    break;
                }
                case 2:
                {
                    std::string tituloBuscar;
                    std::cout << "Ingrese el titulo del libro a buscar: ";
                    std::cin.ignore();
                    std::getline(std::cin, tituloBuscar);
                    buscarPorTitulo(tituloBuscar);
                    break;
                }
                case 3:
                {
                    mostrarLibros();
                    break;
                }
    
                case 4:
                {
                    std::cout << "Saliendo de la aplicacion. \n";
                    break;
                }
    
                default:
                {
                    std::cout << "Opcion invalida. \n";
                }
            }

        } while (op != 4);
    }
};

int main()
{
    GestionarLibros gestionarLibros;
    gestionarLibros.menuLibros();
    return 0;
}
