#include <iostream>
#include <deque>
#include <cstring>

using namespace std;

int main(int argc, char ** argv){

    deque<int64_t> dq;
    string command;
    int64_t amount = 0;
    dq.clear();

    while (true){
        cin >> command;
        if (command == "exit"){
            cout << "bye" << endl;
            break;
        }
        else if (command == "clear"){
            dq.clear();
            amount = 0;
            cout << "ok" << endl;
        }
        else if (command == "pop_front"){
            if (amount == 0){
                cout << "error" << endl;
            }
            else{
                auto it = dq.begin();
                cout << *it << endl;
                dq.pop_front();
                amount--;
            }
        }
        else if (command == "pop_back")
            if (amount == 0){
                cout << "error" << endl;
            }
            else{
                auto it = dq.end() - 1;
                cout << *it << endl;
                dq.pop_back();
                amount--;
            }
        else if (command == "push_back"){
            amount++;
            int64_t number;
            cin >> number;
            dq.push_back(number);
            cout << "ok" << endl;
        }
        else if (command == "push_front"){
            amount++;
            int64_t number;
            cin >> number;
            dq.push_front(number);
            cout << "ok" << endl;
        }
        else if (command == "size"){
            cout << amount << endl;
        }
        else if (command == "back"){
            if (amount == 0){
                cout << "error" << endl;
            }
            else{
                auto it = dq.end() - 1;
                cout << *it << endl;
            }
        }
        else if (command == "front"){
            if (amount == 0){
                cout << "error" << endl;
            }
            else{
                cout << *dq.begin() << endl;
            }
        }
    }

    return 0;
}