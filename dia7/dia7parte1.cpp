#include <iostream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;

void get_input(vector<vector<int>> &entrada){
    string input;
    while(getline(cin, input)){
        vector<int> numeros;
        int num, pos = input.find(':');
        input.erase(pos, 1);
        stringstream sueltos(input);        
        while(sueltos >> num){
            numeros.push_back(num);
        }
        entrada.push_back(numeros);
    }

}



int main(){
    vector<vector<int>> entrada;
    get_input(entrada);

    for(int i = 0; i < entrada.size(); i++){
        for(int j = 0; j < entrada[i].size(); j++){
            cout << entrada[i][j] << " ";
        }
        cout << endl;
    }
}
