#include <iostream>
#include <algorithm>
#include <set>
#include <vector>

using namespace std;

int main(int argc, char ** argv){

    int n, k;
    set<int64_t> st;
    st.clear();
    vector<int64_t> arr;
    arr.clear();
    cin >> n;
    for (int i = 0; i < n; i++){
        int64_t temp;
        cin >> temp;
        if (st.find(temp) == st.end()){
            st.insert(temp);
            arr.push_back(temp);
        }
    }

    sort(arr.begin(), arr.end());

    cin >> k;
    int64_t length = arr.size();
    for (int i = 0; i < k; i++){
        int64_t temp, b, e, m;
        cin >> temp;
        b = -1;
        e = length;
        while (e > b + 1){
            m = (b + e) / 2;
            if (arr[m] >= temp){
                e = m;
            }
            else{
                b = m;
            }
        }
        if (e == length){
            cout << length;
        }
        else if (b == -1){
            cout << 0;
        }
        else if (arr[e] < temp){
            cout << e + 1;
        }
        else{
            cout << b + 1;
        }
        if (i != k - 1){
            cout << endl;
        }
    }

    return 0;
}