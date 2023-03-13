#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char ** argv){

    int64_t n, m;
    cin >> m >> n;
    vector<vector<int64_t>> arr;
    arr.clear();
    int64_t ans = 0;
    int64_t cnt;
    for (int i = 0; i < n; i++){
        int64_t b1, b2;
        cin >> b1 >> b2;
        vector<int64_t> temp = {b1, b2, 1};
        ans++;
        cnt = i;
        while (cnt > 0){
            if (arr[cnt-1][2] == 1){
                if (!(temp[0] > arr[cnt-1][1] || temp[1] < arr[cnt-1][0])){
                    arr[cnt-1][2] = 0;
                    ans--;
                }
            }
            cnt--;
        }
        arr.push_back(temp);
    }

    cout << ans << endl;

    return 0;
}