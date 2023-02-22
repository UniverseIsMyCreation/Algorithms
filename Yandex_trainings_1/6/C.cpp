#include <iostream>

using namespace std;

int main(int argc, char ** argv){

    int64_t w, h, n;
    cin >> w >> h >> n;
    int64_t left = 0;
    int64_t right = max(w, h) * n;
    int64_t middle;
    int64_t ans;

    while (right > left + 1){
        middle = (left + right) / 2;
        if (((middle / w) * (middle / h)) > n){
            right = middle;
        }
        else{
            left = middle;
        }
    }

    while (true){
        if (((right / w) * (right / h)) >= n){
            right--;
        }
        else{
            cout << right + 1 << endl;
            break;
        }
    }

    return 0;
}
