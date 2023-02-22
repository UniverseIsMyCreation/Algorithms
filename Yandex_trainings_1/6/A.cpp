#include <iostream>
#include <vector>
#include <cstring>

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
        string found = "NO";
        l = -1;
        r = n;
        while (r > l + 1){
            m = (r + l) / 2;
            if (arr[m] == request){
                found = "YES";
                break;
            }
            if (arr[m] > request){
                r = m;
            }
            else{
                l = m;
            }
        }
        cout << found << endl;
    }
    
    return 0;
}
