#include <iostream>

using namespace std;

int main(int argc, char ** argv){

    int64_t n, a, b, w, h;
    cin >> n >> a >> b >> w >> h;
    int64_t left1, left2;
    int64_t d1, d2;
    int64_t right1, right2;
    right1 = max(w ,h);
    right2 = max(w, h);
    left1 = 0;
    left2 = 0;

    while (right1 > left1 + 1 || right2 > left2 + 1){
        // cout << left1 << ' ' << right1 << ' ' << left2 << ' ' << right2 << endl;
        if (right1 > left1 + 1){
            d1 = (left1 + right1) / 2;
            if (((w / (a + 2 * d1)) * (h / (b + 2 * d1))) < n){
                right1 = d1;
            }
            else if (((w / (a + 2 * d1)) * (h / (b + 2 * d1))) == n){
                left1 = d1;
            }
            else if (((w / (a + 2 * d1)) * (h / (b + 2 * d1))) == 0){
                right1 = d1;
            }
            else{
                left1 = d1;
            }
        }
        if (right2 > left2 + 1){
            d2 = (left2 + right2) / 2;
            if (((h / (a + 2 * d2)) * (w / (b + 2 * d2))) < n){
                right2 = d2;
            }
            else if (((h / (a + 2 * d2)) * (w / (b + 2 * d2))) == n){
                left2 = d2;
            }
            else if (((h / (a + 2 * d2)) * (w / (b + 2 * d2))) == 0){
                right2 = d2;
            }
            else{
                left2 = d2;
            }
        }
    }

    cout << max(left1, left2) << endl;

    return 0;
}
