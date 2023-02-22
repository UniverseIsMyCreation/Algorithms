#include <iostream>
#include <cmath>

using namespace std;

int main(int argc, char ** argv){

    int64_t a, b, c;
    cin >> a >> b >> c;
    int64_t left = 0;
    int64_t right = a + b + c;
    int64_t middle;

    while (right > left + 1){
        middle = floor((left + right) / 2);
        if ((a * 2 + b * 3 + c * 4 + middle * 5) * 2 > 7 * (a + b + c + middle)){
            right = middle;
        }
        else if ((a * 2 + b * 3 + c * 4 + middle * 5) * 2 <= 7 * (a + b + c + middle)){
            left = middle;
        }
    }

    while (true){
        if ((a * 2 + b * 3 + c * 4 + right * 5) * 2 >= 7 * (a + b + c + right)){
            if (right == 0){
                break;
            }
            right--;
        }
        else{
            right++;
            break;
        }
    }

    cout << right << endl;

    return 0;
}
