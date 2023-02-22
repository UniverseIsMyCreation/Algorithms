#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main(int argc, char ** argv){
    
    int n, k;
    vector <int64_t> arr;
    arr.clear();
    cin >> n >> k;
    for (int i = 0; i < n; i++){
        int64_t temp;
        cin >> temp;
        arr.push_back(temp);
    }
    
    for (int i = 0; i < k; i++){
        int64_t request;
        cin >> request;
        int l,r,m;
        l = -1;
        r = n;
        int64_t ans;
        int64_t diff = 6000000001;
        while (r > l + 1){
            m = (l + r) / 2;
            if (arr[m] == request){
                ans = arr[m];
                break;
            }
            else if (arr[m] < request){
                if (abs(arr[m] - request) <= diff){
                    diff = abs(arr[m] - request);
                    ans = arr[m];
                }
                l = m;
            }
            else{
                if (abs(arr[m] - request) < diff){
                    diff = abs(arr[m] - request);
                    ans = arr[m];
                }
                r = m;
            }
        }
        cout << ans << endl;
    }

    return 0;
}
