#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char ** argv){

    int64_t n, k;
    cin >> n >> k;
    vector<int64_t> arr;
    arr.clear();
    for (int i = 0; i < n; i++){
        int64_t temp;
        cin >> temp;
        arr.push_back(temp);
    }

    int64_t ans = 0;
    int64_t left, right;
    left = 0;
    right = 0;
    int64_t length = arr.size();
    int64_t cur_k = arr[left];
    while (left < length && right < length){
        if (cur_k == k){
            ans++;
            if (right < length - 1){
                right++;
                cur_k += arr[right];
            }
            else{
                cur_k -= arr[left];
                left++;
            }
        }
        else if (cur_k > k){
            cur_k -= arr[left];
            left++;
        }
        else if (cur_k < k){
            if (right == length - 1){
                break;
            }
            right++;
            cur_k += arr[right];
        }
    }

    cout << ans << endl;

    return 0;
}
