#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <utility>
#include <unordered_map>
using namespace std;

void insertar(unordered_map<int, vector<int>> &lectura, vector<vector<int>> &orden) {
    bool espacio = false;
    string input, input1_x, input1_y, input2;
    int x,y;
    // Comprobamos si hay un espacio entre medias para separar un input del otro 
    while (getline(cin, input)) {
        if (input.empty()) {
            espacio = true;
            continue;
        }

        // Si es verdadero (segunda parte del input), tomamos cada valor del input y lo metemos a un vector y luego ese vector a otro vector
        if (espacio) {
            vector<int> num;
            stringstream entrada(input);
            while (getline(entrada, input2, ',')) {
                num.push_back(stoi(input2));
            }
            orden.push_back(num);
        } else {
            // Tomamos la línea hasta el '|' y luego lo que falta y lo introducimos en el mapa. En el caso de que el input1_x exista,
			// añade al final del vector el segundo valor. En el caso de que no exista, lo crea y añade el segundo valor al vector.
            stringstream entrada(input);
            getline(entrada, input1_x, '|');
            getline(entrada, input1_y);
            x = stoi(input1_x); y = stoi(input1_y);
			lectura[x].push_back(y);
        }
    }
}

int medio(vector<int> &orden) {
    return orden[orden.size() / 2];
}

bool verificar(unordered_map<int, vector<int>> &lectura, vector<int> &orden) {
    int norden = orden.size();
    for(int i = 0; i < orden.size(); i++){
        if(lectura.find(orden[i]) == lectura.end()){
            return false;
        }
        vector<int> &valores = lectura[orden[i]];
        for(int j = i+1; j < norden; j++){
            bool encontrado = false;
            for(int x = 0; x < valores.size(); x++){
                if(orden[j] == valores[x]){
                    encontrado = true;
                    break;
                }
            }
            if(!encontrado){
                return false;
            }
        }
    }
    return true;
}

int main() {
	unordered_map<int, vector<int>> lectura;
    vector<vector<int>> orden;
    int resultado = 0;

    insertar(lectura, orden);

    // Recorrer todos los vectores en "orden" y verificar
    for (int i = 0; i < orden.size(); i++) {
        if (verificar(lectura, orden[i])) {
            resultado += medio(orden[i]);
        }
    }

    cout << resultado << endl;

    return 0;
}
