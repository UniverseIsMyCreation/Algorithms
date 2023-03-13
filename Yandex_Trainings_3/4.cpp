#include <iostream>

using namespace std;

int main(int argc, char ** argv){
    
    int64_t n, k;
    int64_t row, pos;
    cin >> n >> k >> row >> pos;

    int64_t Petya_pos = pos == 1 ? row * 2 - 1 : row * 2;
    int64_t ans_row_front, ans_pos_front, ans_row_back, ans_pos_back;
    int64_t Petya_variant = Petya_pos % k == 0 ? k : Petya_pos % k;
    ans_row_front = -1;
    ans_pos_front = -1;
    ans_row_back = -1;
    ans_pos_back = -1;
    
    //cout << Petya_pos << ' ' << Petya_variant << endl;
    if (Petya_variant != Petya_pos){
        // have front
        int64_t front_pos = Petya_pos - k;
        ans_row_front = front_pos % 2 ? front_pos / 2 + 1 : front_pos / 2;
        ans_pos_front = front_pos % 2 ? 1 : 2;
    }
    if (n - Petya_pos >= k){
        // have back
        int64_t back_pos = Petya_pos + k;
        ans_row_back = back_pos % 2 ? back_pos / 2 + 1 : back_pos / 2;
        ans_pos_back = back_pos % 2 ? 1 : 2;
    }

    //cout << ans_row_back << ' ' << ans_pos_front << endl;
    if (ans_row_back != -1 && ans_row_front != -1){
        if ((row - ans_row_front) >= (ans_row_back - row)){
            cout << ans_row_back << ' ' << ans_pos_back << endl;
        }
        else{
            cout << ans_row_front << ' ' << ans_pos_front << endl;
        }
    }
    else if (ans_row_back == -1 && ans_row_front != -1){
        cout << ans_row_front << ' ' << ans_pos_front << endl;
    }
    else if (ans_row_front == -1 && ans_row_back != -1){
        cout << ans_row_back << ' ' << ans_pos_back << endl;
    }
    else{
        cout << -1 << endl;
    }

    return 0;
}