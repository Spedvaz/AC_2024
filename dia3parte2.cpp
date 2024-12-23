#include <iostream>
#include <string>
#include <algorithm>
#include <regex>

using namespace std;

int extraer_numeros(smatch &m){
    int num1 = stoi(m[1].str());
    int num2 = stoi(m[2].str());
	return num1 * num2;
	
}

int main(){
    std::string input;
    int total = 0;
	bool enable = true;
    regex patron_mul(R"(mul\((\d{1,3}),(\d{1,3})\))");
	regex patron_do(R"(do\(\))");
	regex patron_dont(R"(don't\(\))");
	regex completo(R"(mul\((\d{1,3}),(\d{1,3})\)|do\(\)|don't\(\))");
	smatch m;
   	while(getline(cin, input)){
		//habilitar(input, enable, total);
		string line = input;
		while(regex_search(line, m, completo)){
			string coincide = m[0];
			if(regex_match(coincide, patron_mul)){
				if(enable){
					total += extraer_numeros(m);
				}
			}else if(regex_match(coincide, patron_do)){
				enable = true;
			}else if(regex_match(coincide, patron_dont)){
				enable = false;
			}
			line = m.suffix().str();
   		}
	}
    std::cout << "La suma de multiplicaciones es: " << total << std::endl;
}
