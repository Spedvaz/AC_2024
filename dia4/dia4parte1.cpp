#include <iostream>
#include <vector>
#include <string>
#include <regex>

std::string agregarEspacios(const std::string& diagonal, int longitudObjetivo) {
    std::string resultado = diagonal;
    int faltantes = longitudObjetivo - diagonal.size();
    if (faltantes > 0) {
        resultado.append(faltantes, '.');  // Añadir los espacios necesarios
    }
    return resultado; 
}


std::vector<std::string> obtenerDiagonales_inversas(const std::vector<std::string>& lineas) {
    std::vector<std::string> diagonales;
	int filas = lineas.size();
	int columnas = lineas[0].size();
    // Diagonales que empiezan en la primera columna
    for (int i = 0; i < columnas; i++) {
        std::string diagonal;
        for (int x = filas - 1, y = i; x >= 0 && y < columnas; x--, ++y) {
            diagonal += lineas[x][y];
        }
        diagonales.push_back(agregarEspacios(diagonal, filas));
    }

    // Diagonales que empiezan en la primera fila (omitimos la diagonal principal repetida)
    for (int i = filas - 2; i >= 0; i--) {
        std::string diagonal;
        for (int x = i, y = 0; x >= 0 && y < columnas ; x--, ++y) {
            diagonal += lineas[x][y];
        }
        diagonales.push_back(agregarEspacios(diagonal, filas));
    }

    return diagonales;
}

std::vector<std::string> obtenerDiagonales(const std::vector<std::string>& lineas) {
    std::vector<std::string> diagonales;
	int filas = lineas.size();
	int columnas = lineas[0].size();
    // Diagonales que empiezan en la primera columna
    for (int i = 0; i < filas; ++i) {
        std::string diagonal;
        for (int x = i, y = 0; x < filas && y < columnas; ++x, ++y) {
            diagonal += lineas[x][y];
        }
        diagonales.push_back(agregarEspacios(diagonal, filas));
    }

    // Diagonales que empiezan en la primera fila (omitimos la diagonal principal repetida)
    for (int i = 1; i < columnas; ++i) {
        std::string diagonal;
        for (int x = 0, y = i; x < filas && y < columnas; ++x, ++y) {
            diagonal += lineas[x][y];
        }
        diagonales.push_back(agregarEspacios(diagonal, filas));
    }

    return diagonales;
}

std::vector<std::string> trasponer(std::vector<std::string> lineas){
    std::vector<std::string> traspuesta;
    //traspone la matriz para buscar en las columnas como si fuesen lineas
    for(int i = 0; i < lineas[0].size(); i++){
        std::string linea;
        for(const auto& j : lineas){
            linea += j[i];
        }
        traspuesta.push_back(linea);
    }
    return traspuesta;
}


void busqueda_linea(std::vector<std::string> lineas, int &contador){
     // Expresión regular para "XMAS" y "SAMX"
    std::regex patron("(XMAS)");
    std::regex patron_inverso("(SAMX)");

    for (int i = 0; i < lineas.size(); i++) {
        // Buscar todas las instancias de "XMAS" en la línea
        auto it = std::sregex_iterator(lineas[i].begin(), lineas[i].end(), patron);
        auto end = std::sregex_iterator();

        // Contar todas las coincidencias de "XMAS"
        while (it != end) {
            contador++;
            ++it;
        }

        // Buscar todas las instancias de "SAMX" en la línea
        it = std::sregex_iterator(lineas[i].begin(), lineas[i].end(), patron_inverso);

        // Contar todas las coincidencias de "SAMX"
        while (it != end) {
            contador++;
            ++it;
        }  
    }
}


int main(){
    //variables
    int contador = 0;
    std::vector<std::string> lineas, traspuesta, diagonal, diagonal_traspuesta;
    std::string input;
    
    //input
	while(std::getline(std::cin, input)){
        lineas.push_back(input);          
    }
    // contador nos dice cuánto XMAS tenemos en líneas
    busqueda_linea(lineas, contador); 
    //contador nos dice cuántos XMAS tenemos en columnas
    traspuesta = trasponer(lineas);
    busqueda_linea(traspuesta, contador);
    //contador nos dice cuántos XMAS tenemos en diagonales   
    diagonal = obtenerDiagonales(lineas);
    busqueda_linea(diagonal, contador);
    diagonal_traspuesta = obtenerDiagonales_inversas(lineas);
    busqueda_linea(diagonal_traspuesta, contador);
    
	for(int i = 0; i < diagonal.size(); i++){
		std::cout << diagonal[i] << std::endl;
	}
	std::cout << std::endl;
	for(int i = 0; i < diagonal_traspuesta.size(); i++){
		std::cout << diagonal_traspuesta[i] << std::endl;
	}
    std::cout << contador << std::endl;
}

