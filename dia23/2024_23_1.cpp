#include <iostream>
#include <unordered_map>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

void hacer_grafo(unordered_map<string, vector<string>> &grafo){
	string primero, segundo;
	string input;
	while(getline(cin, input)){
		primero = input.substr(0,2);
		segundo = input.substr(3,2);
		grafo[primero].push_back(segundo);
		grafo[segundo].push_back(primero);
	}	 
}


void comprobar_vecinos(const unordered_map<string, vector<string>>& grafo, int& total) {
    unordered_map<string, unordered_map<string, unordered_map<string, bool>>> ciclosContados;
    for (const auto& [nodo, vecinos] : grafo) {
        for (const auto& vecino : vecinos) {
            for (const auto& vecino2 : grafo.at(vecino)) {
                if (find(grafo.at(vecino2).begin(), grafo.at(vecino2).end(), nodo) != grafo.at(vecino2).end()) {
                    vector<string> ciclo = {nodo, vecino, vecino2};
                    sort(ciclo.begin(), ciclo.end());
                    if (ciclosContados[ciclo[0]][ciclo[1]][ciclo[2]]) continue;
                    ciclosContados[ciclo[0]][ciclo[1]][ciclo[2]] = true;
                    bool tieneT = (nodo[0] == 't' || vecino[0] == 't' || vecino2[0] == 't');
                    if (tieneT) {
                        total++;
                    }
                }
            }
        }
    }
}

int main(){
	unordered_map<string, vector<string>> grafo;
	int total = 0;
	hacer_grafo(grafo);
	comprobar_vecinos(grafo, total);
	cout << total << endl;
}
