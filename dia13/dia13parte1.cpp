#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

int ecuacion(int &a, int ax, int bx, int ay, int by, int tx, int ty){
	for(int b = 0; b <= 100; b++){
		// Verificar si se satisface la ecuación
		if(ax*a + bx*b == tx && ay*a + by*b == ty){
			return b;
		}
	}
	a++; // Incrementar a
	if(a > 100){
		return -1; // No se puede resolver dentro de los límites
	}
	return ecuacion(a, ax, bx, ay, by, tx, ty); // Llamada recursiva
}
void get_input(int &total){
    int modo = 0;
    string input;
    int ax, ay, bx, by, tx, ty;
    while (getline(cin, input)) {
        if (input.size() < 5) {  // Ignorar líneas vacías
            continue;
        }
        switch (modo) {
            case 0: {  // Procesar valores de Button A
                ax = stoi(input.substr(12, 2));
                ay = stoi(input.substr(18, 2));
                break;
            }
            case 1: {  // Procesar valores de Button B
                bx = stoi(input.substr(12, 2));
                by = stoi(input.substr(18, 2));
                break;
            }
            case 2: {  // Procesar valores del total
                int x_pos = input.find("X=");  // Encontrar "X="
                int y_pos = input.find("Y=");  // Encontrar "Y="
                if (x_pos != string::npos && y_pos != string::npos) {
                    x_pos += 2;  // Saltar "X="
                    y_pos += 2;  // Saltar "Y="
                    tx = stoi(input.substr(x_pos, input.find(",", x_pos) - x_pos));
                    ty = stoi(input.substr(y_pos));
                }
                break;
            }
        }
        modo++;
        if (modo == 3) {
            int a = 0, b;
            b = ecuacion(a, ax, bx, ay, by, tx, ty);
            if (b != -1) {
                total += a * 3 + b;  // Sumar al total
            }
            modo = 0;  // Reiniciar para la siguiente entrada
        }
    }
}

int main(){
	int total = 0;
	get_input(total);
	cout << total << endl;
}
