#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <utility>

using namespace std;

void insertar(vector<pair<int, int>> &lectura, vector<vector<int>> &orden) {
    bool espacio = false;
    string input, input1_x, input1_y, input2;

    // Comprobamos si hay un espacio entre medias para separar un input del otro 
    while (getline(cin, input)) {
        if (input.empty()) {
            espacio = true;
            continue;
        }

        // Si es verdadero, tomamos cada valor del input y lo metemos a un vector y luego ese vector a otro vector
        if (espacio) {
            vector<int> num;
            stringstream entrada(input);
            while (getline(entrada, input2, ',')) {
                num.push_back(stoi(input2));
            }
            orden.push_back(num);
        } else {
            // Tomamos la línea hasta el '|' y luego lo que falta y lo introducimos al final del vector
            stringstream entrada(input);
            getline(entrada, input1_x, '|');
            getline(entrada, input1_y);
            lectura.emplace_back(stoi(input1_x), stoi(input1_y));
        }
    }
}

int medio(vector<int> &orden) {
    return orden[orden.size() / 2];
}

bool verificar(vector<pair<int, int>> &lectura, vector<int> &orden) {
    int x, y, pos_x, pos_y;

    // Recorrer los pares de lectura
    for (int i = 0; i < lectura.size(); i++) {
        x = lectura[i].first;
        y = lectura[i].second;

        pos_x = pos_y = -1;

        // Buscar las posiciones de x y y en el vector orden
        for (int j = 0; j < orden.size(); j++) {
            if (x == orden[j]) {
                pos_x = j;
            }
            if (y == orden[j]) {
                pos_y = j;
            }
        }

        // Si ambos están presentes y no se cumple la regla, devolver falso
        if (pos_x != -1 && pos_y != -1 && pos_x > pos_y) {
            return false;
        }
    }

    return true;
}

int main() {
    vector<pair<int, int>> lectura;
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
