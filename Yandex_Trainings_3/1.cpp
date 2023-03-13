#include <map>
#include <iostream>
#include <fstream>
#include <vector>
#include <set>

using namespace std;

int main(int argc, char ** argv){

    ifstream file ("input.txt");
    map<char, int64_t> dct;
    vector<int64_t> buff;
    buff.clear();
    char symbol;
    
    for (;file;){
        file.get(symbol);
        if (file.eof()){
            break;
        }
        if (symbol != ' ' && symbol != '\n'){
            if (dct.find(symbol) == dct.end()){
                dct[symbol] = 1;
            }
            else{
                dct[symbol] += 1;
            }
        }
    }
    int64_t mx = -1;
    for (auto& i : dct) {
        if (i.second > mx){
            mx = i.second;
        }
        buff.push_back(i.second);
    }
    while (mx != 0){
        for (int i = 0; i < buff.size(); i++){
            if (buff[i] == mx){
                cout << '#';
                buff[i]--;
            }
            else{
                cout << ' ';
            }
        }
        cout << endl;
        mx--;
    }
    for (auto& i : dct){
        cout << i.first;
    }
    
    return 0;
}
