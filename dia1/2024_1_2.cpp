#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>

int main(){
    std::vector<int> lista1, lista2;
	std::string input;
	std::string a, b;

    while(std::getline(std::cin, input)){
		std::stringstream ss(input);
		ss >> a;
        lista1.push_back(std::stoi(a));
		ss >> b;
        lista2.push_back(std::stoi(b));
    }
	
	int total = 0;

	for(int i = 0; i < lista1.size(); i++){
		int numero_veces = 0;
		for(int j = 0; j < lista2.size(); j++){
			if(lista1[i] == lista2[j]){
				numero_veces++;				
			}
		}
		total += lista1[i] * numero_veces;
	}
	std::cout << total << std::endl;
}
