#include <iostream>
#include <vector>

using namespace std;

int main(){

    int64_t n, m;
    cin >> n >> m;
    vector<vector<int64_t>> arr;
    arr.clear();
    for (int64_t i = 0; i < n; i++){
        arr.push_back(vector<int64_t>());
        for (int64_t j = 0; j < m; j++){
            int64_t temp;
            cin >> temp;
            arr[i].push_back(temp);
        }
    }

    vector<vector<int64_t>> dp;
    for (int64_t i = 0; i < n; i++){
        dp.push_back(vector<int64_t>());
        for (int64_t j = 0; j < m; j++){
            if (i == 0){
                if (j == 0){
                    dp[0].push_back(arr[0][0]);
                }
                else{
                    dp[0].push_back(arr[0][j] + dp[0][j - 1]);
                }
            }
            else if (j == 0){
                dp[i].push_back(arr[i][0] + dp[i - 1][0]);
            }
            else{
                dp[i].push_back(min(dp[i][j - 1], dp[i - 1][j]) + arr[i][j]);
            }
        }
    }

    cout << dp[n - 1][m - 1] << endl;

    return 0;
}