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

	std::sort(lista1.begin(), lista1.end());
	std::sort(lista2.begin(), lista2.end());
    

    int distancia = 0;
    for(int i = 0; i < lista1.size(); i++){
		int diff = std::abs(lista1[i] - lista2[i]);
		std::cout << i << "  " <<lista1[i] << " - " << lista2[i] << " = " << diff << std::endl;
        distancia += diff;
    }

    std::cout << distancia << std::endl;
}
