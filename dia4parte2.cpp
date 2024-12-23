#include <iostream>
#include <vector>
#include <string>
using namespace std;

#define N 140

int main(){
    //variables
    int contador = 0;
    vector<string> lineas;
    string input;
    
    //input
while(getline(cin, input)){
        lineas.push_back(input);          
    }
    
    for(int i = 0; i < lineas.size(); i++){
        for(int j = 0; j < lineas[i].size(); j++){
            if(i+2 < N && j+2 < N){
                if(lineas[i][j] == 'S' && lineas[i+1][j+1] == 'A' && lineas[i+2][j+2] == 'M'){
                    if((lineas[i+2][j] == 'M' && lineas[i][j+2] == 'S') || (lineas[i+2][j] == 'S' && lineas[i][j+2] == 'M')){
                        contador++;
                    }
                }
                else if(lineas[i][j] == 'M' && lineas[i+1][j+1] == 'A' && lineas[i+2][j+2] == 'S'){
                    if((lineas[i+2][j] == 'M' && lineas[i][j+2] == 'S') || (lineas[i+2][j] == 'S' && lineas[i][j+2] == 'M')){
                        contador++;
                    }
                }
            }
        }
    }
    cout << contador << endl;
}
