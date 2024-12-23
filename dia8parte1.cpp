#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#define N 10

using namespace std;

void get_input(vector<vector<char>> &mapa){
	string input;
	while(getline(cin, input)){
		vector<char> caracteres;
		char c;
		stringstream entrada(input);
		while(entrada >> c){
			caracteres.push_back(c);
		}
		mapa.push_back(caracteres);
	}
}

int main(){
	vector<vector<char>> mapa;
	get_input(mapa);
	for(int i = 0; i < mapa.size(); i++){
		for(int j = 0; j < mapa[i].size(); j++){	
				cout<<mapa[i][j];
		}
		cout<<endl;
	}
	
}
 
