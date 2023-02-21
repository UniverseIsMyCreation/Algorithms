#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char ** argv){

    int64_t n, r;
    cin >> n >> r;
    vector<int64_t> arr;
    arr.clear();
    for (int i = 0; i < n; i++){
        int64_t pos;
        cin >> pos;
        arr.push_back(pos);
    }

    int64_t left, right;
    left = 0;
    right = 0;
    int64_t cur_range = 0;
    int64_t ans = 0;
    int64_t length = arr.size();
    while (left < length && right < length){
        if (cur_range <= r){
            if (right < length - 1){
                right++;
            }
            else{
                break;
            }
            cur_range = arr[right] - arr[left];
        }
        else{
            ans += (length - right);
            left++;
            cur_range = arr[right] - arr[left];
        }
    }

    cout << ans << endl;

    return 0;
}