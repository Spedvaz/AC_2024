#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <utility>
#include <unordered_map>
using namespace std;

// Función para procesar la entrada y llenar las estructuras de datos.
void insertar(unordered_map<int, vector<int>> &lectura, vector<vector<int>> &orden) {
    bool espacio = false; // Bandera para identificar si hemos llegado a la segunda parte del input.
    string input, input1_x, input1_y, input2;
    int x, y;

    // Leer cada línea de la entrada estándar.
    while (getline(cin, input)) {
        if (input.empty()) { // Detectar una línea vacía que separa las dos partes de la entrada.
            espacio = true;
            continue;
        }

        // Si estamos en la segunda parte del input (vectores para "orden").
        if (espacio) {
            vector<int> num; 
            stringstream entrada(input);
            
            // Leer valores separados por comas y convertirlos a enteros.
            while (getline(entrada, input2, ',')) {
                num.push_back(stoi(input2));
            }
            
            // Agregar el vector procesado al vector "orden".
            orden.push_back(num);
        } else {
            // Procesar la primera parte del input (pares clave-valor para "lectura").
            stringstream entrada(input);
            
            // Separar el valor antes y después del '|' para obtener la clave y el valor.
            getline(entrada, input1_x, '|');
            getline(entrada, input1_y);
            
            x = stoi(input1_x); // Convertir la clave a entero.
            y = stoi(input1_y); // Convertir el valor a entero.
            
            // Si la clave ya existe, agregar el valor al vector correspondiente.
            // Si no existe, se crea automáticamente el vector y se agrega el valor.
            lectura[x].push_back(y);
        }
    }
}

// Función para obtener el elemento del medio de un vector.
int medio(vector<int> &orden) {
    return orden[orden.size() / 2]; 
}

// Función para verificar si el orden cumple con las relaciones definidas en "lectura".
bool verificar(unordered_map<int, vector<int>> &lectura, vector<int> &orden) {
    int norden = orden.size(); // Tamaño del vector "orden".

    // Iterar sobre cada elemento en el vector "orden".
    for (int i = 0; i < orden.size(); i++) {
        // Verificar si el elemento actual existe como clave en "lectura".
        if (lectura.find(orden[i]) == lectura.end()) {
            return false; // Si no existe, no cumple con las condiciones.
        }

        // Obtener los valores asociados al elemento actual.
        vector<int> &valores = lectura[orden[i]];

        // Verificar que los elementos siguientes en "orden" estén en los valores permitidos.
        for (int j = i + 1; j < norden; j++) {
            bool encontrado = false;

            // Buscar si el elemento en la posición `j` está en el vector de valores permitidos.
            for (int x = 0; x < valores.size(); x++) {
                if (orden[j] == valores[x]) {
                    encontrado = true; // Si se encuentra, marcar como "encontrado".
                    break;
                }
            }

            // Si no se encuentra el elemento, no cumple con las condiciones.
            if (!encontrado) {
                return false;
            }
        }
    }

    return true; // Si se cumplen todas las condiciones, retorna verdadero.
}

int main() {
    unordered_map<int, vector<int>> lectura; // Mapa que almacena las relaciones clave-valor.
    vector<vector<int>> orden; // Vector de vectores que representa las secuencias a verificar.
    int resultado = 0; // Variable para almacenar el resultado final.

    
    insertar(lectura, orden);

    for (int i = 0; i < orden.size(); i++) {
        if (verificar(lectura, orden[i])) {
            resultado += medio(orden[i]);
        }
    }
    cout << resultado << endl;

    return 0;
}
