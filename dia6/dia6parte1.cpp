#include <iostream>
#include <string>
#include <sstream>
#define N  130 // Define el tamaño del mapa como una constante global.
using namespace std;

// Función para obtener el input y llenar la matriz "mapa".
// Además, localiza la posición inicial del cursor (indicado por '^').
void get_input(char (&mapa)[N][N], int &posX, int &posY) {
    string linea;
    int i = 0; 
    while (getline(cin, linea)) { // Leer línea por línea desde la entrada estándar.
        for (int j = 0; j < N; ++j) { // Recorrer cada carácter de la línea.
            mapa[i][j] = linea[j]; // Almacenar el carácter en la matriz.
            if (linea[j] == '^') { // Verificar si este carácter es el punto inicial ('^').
                posX = i; // Almacenar la fila del punto inicial.
                posY = j; // Almacenar la columna del punto inicial.
            }
        }
        i++; // Pasar a la siguiente fila.
    }
}

// Función para mover en la dirección vertical (arriba o abajo).
void movimientoX(char (&mapa)[N][N], int &posX, int &posY, int &contador, bool positivo_negativo) {
    if (positivo_negativo == true) { // Movimiento hacia abajo (incremento en posX).
        while ((posX >= 0 && posX <= N - 1) && mapa[posX + 1][posY] != '#') { // Mientras no salga de los límites y no haya obstáculos.
            posX++; // Avanzar hacia abajo.
            cout << posX << " " << posY << " " << contador << endl; 
            if (mapa[posX][posY] != 'X' && posX >= 0 && posX <= N - 1) { // Si la celda no ha sido visitada.
                contador++; // Incrementar el contador.
                mapa[posX][posY] = 'X'; // Marcar la celda como visitada.
            }
        }
    } else { // Movimiento hacia arriba (decremento en posX).
        while ((posX >= 0 && posX <= N - 1) && mapa[posX - 1][posY] != '#') { // Mientras no salga de los límites y no haya obstáculos.
            posX--; // Avanzar hacia arriba.
            cout << posX << " " << posY << " " << contador << endl; 
            if (mapa[posX][posY] != 'X' && posX >= 0 && posX <= N - 1) { // Si la celda no ha sido visitada.
                contador++; // Incrementar el contador.
                mapa[posX][posY] = 'X'; // Marcar la celda como visitada.
            }
        }
    }
}

// Función para mover en la dirección horizontal (derecha o izquierda).
void movimientoY(char (&mapa)[N][N], int &posX, int &posY, int &contador, bool positivo_negativo) {
    if (positivo_negativo == true) { // Movimiento hacia la derecha (incremento en posY).
        while ((posY >= 0 && posY <= N - 1) && mapa[posX][posY + 1] != '#') { // Mientras no salga de los límites y no haya obstáculos.
            posY++; // Avanzar hacia la derecha.
            cout << posX << " " << posY << " " << contador << endl; 
            if (mapa[posX][posY] != 'X' && posY >= 0 && posY <= N - 1) { // Si la celda no ha sido visitada.
                contador++; // Incrementar el contador.
                mapa[posX][posY] = 'X'; // Marcar la celda como visitada.
            }
        }
    } else { // Movimiento hacia la izquierda (decremento en posY).
        while ((posY >= 0 && posY <= N - 1) && mapa[posX][posY - 1] != '#') { // Mientras no salga de los límites y no haya obstáculos.
            posY--; // Avanzar hacia la izquierda.
            cout << posX << " " << posY << " " << contador << endl; 
            if (mapa[posX][posY] != 'X' && posY >= 0 && posY <= N - 1) { // Si la celda no ha sido visitada.
                contador++; // Incrementar el contador.
                mapa[posX][posY] = 'X'; // Marcar la celda como visitada.
            }
        }
    }
}

// Función recursiva para moverse en diferentes direcciones de manera controlada.
void mover_delante(char (&mapa)[N][N], int &posX, int &posY, int &contador, int &prueba) {
    bool positivo_negativo = false; // Determina si el movimiento es positivo (hacia abajo/derecha) o negativo (hacia arriba/izquierda).
    
    // Movimiento hacia arriba.
    movimientoX(mapa, posX, posY, contador, positivo_negativo);
    if (mapa[posX][posY + 1] == '#' || posY + 1 >= N || posX < 0) {
        return;
    }

    // Movimiento hacia la derecha.
    positivo_negativo = true;
    movimientoY(mapa, posX, posY, contador, positivo_negativo);
    if (mapa[posX + 1][posY] == '#' || posX + 1 >= N || posY < 0) {
        return;
    }

    // Movimiento hacia abajo.
    movimientoX(mapa, posX, posY, contador, positivo_negativo);
    if (mapa[posX][posY - 1] == '#' || posY - 1 < 0 || posX >= N) {
        return;
    }

    // Movimiento hacia la izquierda.
    positivo_negativo = false;
    movimientoY(mapa, posX, posY, contador, positivo_negativo);
    if (mapa[posX - 1][posY] == '#' || posX - 1 < 0 || posY >= N) {
        return;
    }

    // Verificar los límites para evitar desbordamientos y realizar una llamada recursiva si es necesario.
    if (posX + 1 >= N || posY + 1 >= N || posX - 1 < 0 || posY - 1 < 0) {
        return;
    } else {
        mover_delante(mapa, posX, posY, contador, prueba); // Llamada recursiva.
    }
}

int main() {
    char mapa[N][N]; // Matriz que representa el mapa.
    int posX, posY; // Posición inicial del cursor.
    int contador = 1; // Contador de celdas visitadas.

    get_input(mapa, posX, posY);
    cout << posX << " " << posY << endl;
    mover_delante(mapa, posX, posY, contador, prueba);
    cout << contador << endl;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << mapa[i][j];
        }
        cout << endl;
    }

    return 0;
}
