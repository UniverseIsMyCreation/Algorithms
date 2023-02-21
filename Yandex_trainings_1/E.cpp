#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main(int argc, char ** argv){

    int64_t n, k;
    cin >> n >> k;
    vector<int64_t> arr;
    map<int64_t, int64_t> dct;
    arr.clear();
    for (int i = 0; i < n; i++){
        int64_t plant;
        cin >> plant;
        arr.push_back(plant);
    }

    int64_t left, right;
    left = 0;
    right = 0;
    int64_t length = arr.size();
    int64_t best_length = 250001;
    int64_t founded_copies = 1;
    int64_t cur_length = 1;
    int64_t x, y;
    dct[arr[right]] = 1;
    while (left < length && right < length){
        if (founded_copies < k){
            if (right < length - 1){
                right++;
            }
            else{
                break;
            }
            cur_length++;
            if (dct.find(arr[right]) == dct.end()){
                founded_copies++;
                dct[arr[right]] = 1;
            }
            else if (dct[arr[right]] == 0){
                founded_copies++;
                dct[arr[right]] += 1;
            }
            else{
                dct[arr[right]] += 1;
            }
        }
        else{
            if (cur_length < best_length){
                best_length = cur_length;
                x = left;
                y = right;
            }
            dct[arr[left]] -= 1;
            if (dct[arr[left]] == 0){
                founded_copies--;
            }
            cur_length--;
            left++;
        }
    }

    cout << x + 1 << ' ' << y + 1 << endl;

    return 0;
}
