#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>
#include <regex>

int extraer_numeros(std::string input){
    std::size_t coma = input.find(',');
    int num1 = std::stoi(input.substr(0, coma));
    int num2 = std::stoi(input.substr(coma + 1));
    std::cout << num1 << " " << num2 << std::endl;
    return num1*num2;
}


int main(){
    std::vector<std::string> v;
    std::string input;
    int total = 0;

    while(std::getline(std::cin, input)){
        v.push_back(input);
    }

    std::regex patron(R"(mul((-?\d+),(-?\d+)))");
    std::vector<std::string> result;
    std::string sin_filtrar, filtrada;

    for(const auto& line : v){
        auto words_begin = std::sregex_iterator(line.begin(), line.end(), patron);
        auto words_end = std::sregex_iterator();
        for (std::sregex_iterator j = words_begin; j != words_end; ++j) {
            sin_filtrar = j->str();
            filtrada = sin_filtrar.substr(4, sin_filtrar.size());
            filtrada.pop_back();
            std::cout << filtrada << std::endl;
            result.push_back(filtrada);
        }
    }

    for(int i = 0; i < result.size(); i++){
        total += extraer_numeros(result[i]);
    }
    std::cout<<"La suma de multiplicaciones es: "<<total<< std::endl;
}
