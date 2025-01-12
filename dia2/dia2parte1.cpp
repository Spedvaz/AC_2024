#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <algorithm>
#include "BSTree.h" 

// Función para verificar si una secuencia de números está ordenada (ascendente o descendente).
bool ordenado(std::stringstream &ss) {
    std::vector<int> orden; 
    int a;

    // Leer los números del stringstream y agregarlos al vector.
    while (ss >> a) {
        orden.push_back(a);
    }

    // Verificar si el vector está ordenado de forma ascendente o descendente.
    return std::is_sorted(orden.begin(), orden.end()) || 
           std::is_sorted(orden.begin(), orden.end(), std::greater<int>());
}

// Función para cargar los números de entrada en el árbol y verificar su validez inicial.
void load_input_tree(std::string input, BSTree<int> &bstree, bool &safe) {
    std::stringstream ss(input); 
    std::stringstream st(input); 
    int a;

    // Verificar si la secuencia de entrada está ordenada.
    if (ordenado(st) == false) {
        safe = false; // Marcar como "no seguro" si no está ordenada.
        return;
    }

    // Insertar los números en el árbol.
    while (ss >> a) {
        try {
            bstree.insert(a); // Intentar insertar cada número en el árbol.
        } 
        catch (const std::runtime_error &e) { 
            safe = false; // Marcar como "no seguro" si ocurre un error.
            return;
        }
    }
}

// Función para comparar los nodos del árbol y verificar una condición de seguridad.
void compare_tree(bool &safe, BSNode<int>* root) {
    // Si el árbol está vacío o ya se marcó como "no seguro", terminar.
    if (root == nullptr || !safe) {
        return;
    }

    // Verificar la relación entre el nodo actual y su hijo izquierdo.
    if (root->left != nullptr) {
        if (root->left->elem + 3 < root->elem) { 
            safe = false; // Marcar como "no seguro" si no se cumple.
            return;
        }
        compare_tree(safe, root->left); // Llamada recursiva al hijo izquierdo.
    }

    // Verificar la relación entre el nodo actual y su hijo derecho.
    if (root->right != nullptr) {
        if (root->elem + 3 < root->right->elem) {
            safe = false; // Marcar como "no seguro" si no se cumple.
            return;
        }
        compare_tree(safe, root->right); // Llamada recursiva al hijo derecho.
    }
}

// Función principal.
int main() {
    int count = 0; // Contador para rastrear cuántas entradas son "seguras".
    std::string input; // Variable para almacenar cada línea de entrada.

    while (std::getline(std::cin, input)) {
        BSTree<int> bstree;
        bool safe = true; 
        load_input_tree(input, bstree, safe);
        compare_tree(safe, bstree.getRoot());
        if (safe) {
            std::cout << "safe" << std::endl;
            count++;
        } else {
            std::cout << "unsafe" << std::endl;
        }
    }
    std::cout << "El número de veces que es seguro es: " << count << std::endl;
    return 0;    
}
