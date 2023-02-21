#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main(int argc, char ** argv){
    
    int64_t n,m;
    vector <int64_t> arr;
    arr.clear();

    cin >> n; 
    for (int i=0; i<n; i++){
        int64_t temp;
        cin >> temp;
        arr.push_back(temp);
    }

    cin >> m; 
    for (int i=0; i<m; i++){
        int64_t temp;
        cin >> temp;
        arr.push_back(temp);
    }
    
    int left1,left2;
    left1 = 0;
    left2 = n;
    int64_t best_result = 10000001;
    int64_t cur_result;
    int64_t ans1,ans2;
    while (true){
        // cout << arr[left1] << ' ' << arr[left2] << endl;
        cur_result = abs(arr[left1] - arr[left2]);
        if (cur_result == 0){
            ans1 = arr[left1];
            ans2 = arr[left2];
            break;
        }
        else if (cur_result < best_result){
            best_result = cur_result;
            ans1 = arr[left1];
            ans2 = arr[left2];
        }
        if (left1 == n - 1 && left2 == n + m - 1){
            break;
        }
        if (arr[left1] > arr[left2]){
            if (left2 == n + m - 1){
                left1++;
            }
            else{
                left2++;
            }
        }
        else{
            if (left1 == n - 1){
                left2++;
            }
            else{
                left1++;
            }
        }
    }
    cout << ans1 << ' ' << ans2 << endl;
    return 0;
}