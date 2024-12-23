#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>
using namespace std;



void get_input(vector<vector<int>> &levels){
string input;
while(getline(cin, input)){
int num;
vector<int> insertar;
stringstream entrada(input);
while(entrada >> num){
insertar.push_back(num);
}
levels.push_back(insertar);
}
}

bool comp(int a, int b) {
    return a > b;
}


bool comprobar(vector<int> copias){
for(int i = 0; i < copias.size()-1; i++){
if(abs(copias[i] - copias[i+1]) > 3 || abs(copias[i] - copias[i+1]) < 1){
return false;
}
}
if(is_sorted(copias.begin(), copias.end()) || is_sorted(copias.begin(), copias.end(), comp)){
return true;
}
return false;
}



int main(){
vector<vector<int>> levels;
get_input(levels);
int total = 0;

for(int i = 0; i < levels.size(); i++){
bool repetido = false; 
for(int j = 0; j < levels[i].size(); j++){
vector<int> copias = levels[i];
copias.erase(copias.begin() + j);
if(comprobar(copias) && repetido == false){
total++;
repetido = true;
}
}
}
cout << total << endl;
}

