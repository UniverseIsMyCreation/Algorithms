#include <iostream>
#include <cmath>

using namespace std;

int main(int argc, char ** argv){

    int64_t min_x, min_y, max_x, max_y;
    int n;
    max_x = -1;
    max_y = -1;
    min_x = pow(10, 9) + 1;
    min_y = pow(10, 9) + 1;
    cin >> n;

    for (int i = 0; i < n; i++){
        int64_t temp1, temp2;
        cin >> temp1 >> temp2;
        if (temp1 > max_x){
            max_x = temp1;
        }
        if (temp1 < min_x){
            min_x = temp1;
        }
        if (temp2 > max_y){
            max_y = temp2;
        }
        if (temp2 < min_y){
            min_y = temp2;
        }
    }

    cout << min_x << ' ' << min_y << ' ' << max_x << ' ' << max_y << endl; 

    return 0;
}