#include <iostream>
#include <cstring>
#include <map>
#include <set>
#include <vector>

using namespace std;

int main(int argc, char ** argv){

    string input;
    map<char, int64_t> dct;
    char symbol = ' ';
    while (true){
        cin.get(symbol);
        if (symbol == '\n'){
            break;
        }
        if (symbol != ' '){
            input += symbol;
        }
    }

    int64_t len_input = input.length();
    set<char> used;
    for (int64_t i = 0; i <= len_input - 1; i++){
        if (used.find(input[i]) == used.end()){
            dct[input[i]] = (i + 1) * (len_input - i);
            used.insert(input[i]);
        }
        else{
            dct[input[i]] += (i + 1) * (len_input - i);
        }
    }

    for (auto & i : dct){
        cout << i.first << ": " << i.second << endl;
    }

    return 0;
}