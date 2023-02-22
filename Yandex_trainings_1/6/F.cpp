#include <iostream>

using namespace std;

int main(int argc, char ** argv){

    int64_t n, x, y;
    cin >> n >> x >> y;

    n--;
    int64_t left = 0;
    int64_t right = max(x, y) * n;
    int64_t middle;
    int64_t x_count, y_count;
    while (right > left + 1){
        // cout << left << ' ' << right << endl;
        middle = (right + left) / 2;
        x_count = (middle / x);
        y_count = (middle / y);
        if (x_count + y_count > n){
            right = middle;
        }
        else if (x_count + y_count == n){
            right = middle;
            while (true){
                if ((right / x) + (right / y) >= n){
                    right--;
                }
                else{
                    right++;
                    break;
                }
            }
            break;
        }
        else{
            left = middle;
        }
    }

    cout << right + min(x, y) << endl;

    return 0;
}
