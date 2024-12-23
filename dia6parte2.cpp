#include <iostream>
#include <string>
#include <sstream>
#define N  130
using namespace std;

void get_input(char (&mapa)[N][N], int &posX, int &posY){
    string linea;
    int i = 0;
    while(getline(cin, linea)){
        for(int j = 0; j < N; ++j){
            mapa[i][j] = linea[j];
            if(linea[j] == '^'){ //depende de tu input
                posX = i; //filas
                posY = j; //columnas
            }
        }
        i++;
    }
}

void movimientoX(char (&mapa)[N][N], int &posX, int &posY, int &contador, bool positivo_negativo){
    if(positivo_negativo == true){
        while((posX >= 0 && posX <= N - 1) && mapa[posX+1][posY] != '#'){
            posX++;
            cout << posX << " " << posY << " " << contador<< endl;
            if(mapa[posX][posY] != 'X' && posX >= 0 && posX <= N - 1){
                contador++;
                mapa[posX][posY] = 'X';
            }
        }
    }else{
        while((posX >= 0 && posX <= N - 1) && mapa[posX-1][posY] != '#'){
            posX--;
            if(mapa[posX][posY] != 'X' && posX >= 0 && posX <= N - 1){
                contador++;
                mapa[posX][posY] = 'X';
            }
        }
    }
}

void movimientoY(char (&mapa)[N][N], int &posX, int &posY, int &contador, bool positivo_negativo){
    if(positivo_negativo == true){
        while((posY >= 0 && posY <= N - 1) && mapa[posX][posY+1] != '#'){
            posY++;
            if(mapa[posX][posY] != 'X' && posY >= 0 && posY <= N - 1){
                contador++;
                mapa[posX][posY] = 'X';
            }
        }
    }else{
        while((posY >= 0 && posY <= N - 1) && mapa[posX][posY-1] != '#'){
            posY--;
            if(mapa[posX][posY] != 'X' && posY >= 0 && posY <= N - 1){
                contador++;
                mapa[posX][posY] = 'X';
            }
        }
    }
}


void mover_delante(char (&mapa)[N][N], int &posX, int &posY, int &contador, int &prueba){
    //  subir posY++, bajar posY--, derecha posX++, izquierda posX-
    bool positivo_negativo = false; //depende de tu input
    movimientoX(mapa, posX, posY, contador, positivo_negativo);
    if(mapa[posX][posY+1] == '#' || posY+1 >= N){
        return;
    }
    positivo_negativo = true;
    movimientoY(mapa, posX, posY, contador, positivo_negativo);
    if(mapa[posX+1][posY] == '#' || posX+1 >= N){
        return;
    }

    movimientoX(mapa,posX, posY, contador, positivo_negativo);
    if(mapa[posX][posY-1] == '#' || posY-1 < 0 || posX >= N){
        return;
    }
    positivo_negativo = false;
    movimientoY(mapa, posX, posY, contador, positivo_negativo);
    if(mapa[posX-1][posY] == '#' || posX-1 < 0){
        return;
    }
    if(posX + 1 >= N || posY + 1 >= N || posX - 1 < 0 || posY - 1 < 0){
        return;
    }else{
        if (posX + 1 < N-1 && posY + 1 < N-1 && mapa[posX][posY+1] != '#' && mapa[posX-1][posY] != '#') {
            mover_delante(mapa, posX, posY, contador, prueba);
        }
    }
}

int main(){
    char mapa[N][N];
    int posX, posY, contador = 1, prueba = 0;
    get_input(mapa, posX, posY);
    cout << posX << " " << posY << endl;
    mover_delante(mapa, posX, posY, contador, prueba);
    cout << contador << endl;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cout << mapa[i][j];
        }
        cout <<endl;
    }
}
