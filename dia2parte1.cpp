#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <algorithm>
#include "BSTree.h"

bool ordenado(std::stringstream &ss){
	std::vector<int> orden;
	int a;
	while(ss >> a){
		orden.push_back(a);
	}
	return std::is_sorted(orden.begin(), orden.end()) || std::is_sorted(orden.begin(), orden.end(), std::greater<int>());
}


void load_input_tree(std::string input, BSTree<int> &bstree, bool &safe) {
    std::stringstream ss(input);
	std::stringstream st(input);
	int a;
	if(ordenado(st) == false){
		safe = false;
		return;
	}
    while (ss >> a) {
        try {
            bstree.insert(a);
        } 
        catch (const std::runtime_error &e) {
            safe = false;
            return;
        }	
	}
}

void compare_tree(bool &safe, BSNode<int>* root) {
    if (root == nullptr || !safe) {
        return;
    }

    if (root->left != nullptr){
        if (root->left->elem + 3 < root->elem) {
            safe = false;
            return;
        }
        compare_tree(safe, root->left);
    }

    if (root->right != nullptr) {
        if (root->elem + 3 < root->right->elem) {
            safe = false;
            return;
        }
        compare_tree(safe, root->right);
    }
}

int main() {
    int count = 0;
    std::string input;
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
