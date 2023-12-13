#include <iostream>

// Definición de la estructura del nodo del árbol
struct TreeNode
{
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

// Clase para representar el árbol binario de búsqueda
class BinarySearchTree
{
private:
    TreeNode *root;

    // Funciones auxiliares para insertar y buscar en el árbol
    TreeNode *insert(TreeNode *node, int value);
    bool search(TreeNode *node, int value);

    // Función auxiliar para visualizar el árbol (recorrido inorden)
    void display(TreeNode *node);

public:
    BinarySearchTree() : root(nullptr) {}

    // Funciones públicas para insertar, buscar y visualizar
    void insert(int value);
    bool search(int value);
    void display();
};

// Implementación de las funciones de la clase BinarySearchTree

TreeNode *BinarySearchTree::insert(TreeNode *node, int value)
{
    if (node == nullptr)
    {
        return new TreeNode(value);
    }

    if (value < node->data)
    {
        node->left = insert(node->left, value);
    }
    else if (value > node->data)
    {
        node->right = insert(node->right, value);
    }

    return node;
}

void BinarySearchTree::insert(int value)
{
    root = insert(root, value);
}

bool BinarySearchTree::search(TreeNode *node, int value)
{
    if (node == nullptr)
    {
        return false;
    }

    if (value == node->data)
    {
        return true;
    }
    else if (value < node->data)
    {
        return search(node->left, value);
    }
    else
    {
        return search(node->right, value);
    }
}

bool BinarySearchTree::search(int value)
{
    return search(root, value);
}

void BinarySearchTree::display(TreeNode *node)
{
    if (node != nullptr)
    {
        display(node->left);
        std::cout << node->data << " ";
        display(node->right);
    }
}

void BinarySearchTree::display()
{
    display(root);
    std::cout << std::endl;
}

// Función principal para el programa con menú
int main()
{
    BinarySearchTree bst;

    int option, value;
    do
    {
        std::cout << "1. Insertar dato en el arbol\n";
        std::cout << "2. Buscar dato en el arbol\n";
        std::cout << "3. Visualizar arbol\n";
        std::cout << "0. Salir\n";
        std::cout << "Ingrese la opción: ";
        std::cin >> option;

        switch (option)
        {
        case 1:
            std::cout << "Ingrese el valor a insertar: ";
            std::cin >> value;
            bst.insert(value);
            break;
        case 2:
            std::cout << "Ingrese el valor a buscar: ";
            std::cin >> value;
            if (bst.search(value))
            {
                std::cout << "El dato está en el árbol.\n";
            }
            else
            {
                std::cout << "El dato no está en el árbol.\n";
            }
            break;
        case 3:
            std::cout << "Árbol visualizado (recorrido inorden): ";
            bst.display();
            break;
        case 0:
            std::cout << "Saliendo del programa.\n";
            break;
        default:
            std::cout << "Opción no válida. Intente nuevamente.\n";
        }
    } while (option != 0);

    return 0;
}
