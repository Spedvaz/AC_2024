#include <iostream>
#include <unordered_map>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

// Función para construir el grafo desde la entrada estándar.
void hacer_grafo(unordered_map<string, vector<string>> &grafo) {
    string primero, segundo; // Variables para almacenar los nodos de cada conexión.
    string input; // Variable para almacenar cada línea de entrada.
    
    // Leer la entrada línea por línea.
    while (getline(cin, input)) {
        // Extraer los dos nodos de la línea de entrada.
        primero = input.substr(0, 2); // Los primeros dos caracteres.
        segundo = input.substr(3, 2); // Los dos caracteres después del espacio.
        
        // Añadir la conexión en ambas direcciones, ya que el grafo es no dirigido.
        grafo[primero].push_back(segundo);
        grafo[segundo].push_back(primero);
    }
}

// Función para comprobar ciclos de tamaño 3 (triángulos) en el grafo.
void comprobar_vecinos(const unordered_map<string, vector<string>>& grafo, int& total) {
    // Mapa anidado para registrar los ciclos que ya se han contado y evitar duplicados.
    unordered_map<string, unordered_map<string, unordered_map<string, bool>>> ciclosContados;

    // Iterar sobre cada nodo y sus vecinos.
    for (const auto& [nodo, vecinos] : grafo) {
        for (const auto& vecino : vecinos) {
            // Iterar sobre los vecinos del vecino actual.
            for (const auto& vecino2 : grafo.at(vecino)) {
                // Verificar si el nodo original está conectado con el vecino2, cerrando un ciclo.
                if (find(grafo.at(vecino2).begin(), grafo.at(vecino2).end(), nodo) != grafo.at(vecino2).end()) {
                    // Crear un vector que representa el ciclo y ordenarlo para evitar duplicados.
                    vector<string> ciclo = {nodo, vecino, vecino2};
                    sort(ciclo.begin(), ciclo.end());
                    
                    // Si el ciclo ya fue contado, se omite.
                    if (ciclosContados[ciclo[0]][ciclo[1]][ciclo[2]]) continue;

                    // Marcar el ciclo como contado.
                    ciclosContados[ciclo[0]][ciclo[1]][ciclo[2]] = true;

                    // Verificar si algún nodo del ciclo comienza con la letra 't'.
                    bool tieneT = (nodo[0] == 't' || vecino[0] == 't' || vecino2[0] == 't');
                    
                    // Si existe al menos un nodo con 't', incrementar el contador total.
                    if (tieneT) {
                        total++;
                    }
                }
            }
        }
    }
}

int main() {
    unordered_map<string, vector<string>> grafo; // Representación del grafo como lista de adyacencia.
    int total = 0; // Contador de ciclos que contienen al menos un nodo con la letra 't'.
    
    hacer_grafo(grafo);
    comprobar_vecinos(grafo, total);
    cout << total << endl;
}
