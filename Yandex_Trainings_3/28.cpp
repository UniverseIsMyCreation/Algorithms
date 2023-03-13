#include <iostream>
#include <vector>

using namespace std;

int main(){

    int64_t n, m;
    cin >> n >> m;

    vector<vector<int64_t>> dp;
    for (int64_t i = 0; i < n; i++){
        dp.push_back(vector<int64_t>());
        for (int64_t j = 0; j < m; j++){
            if (i == 0 && j == 0){
                dp[0].push_back(1);
            }
            else{
                int64_t cur_value = 0;
                if (i - 2 >= 0 && j - 1 >= 0){
                    cur_value += dp[i - 2][j - 1];
                }
                if (i - 1 >= 0 && j - 2 >= 0){
                    cur_value += dp[i - 1][j - 2];
                }
                dp[i].push_back(cur_value);
            }
        }
    }

    cout << dp[n - 1][m - 1] << endl;

    return 0;
}