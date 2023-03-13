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
                dp[i].push_back(max(dp[i][j - 1], dp[i - 1][j]) + arr[i][j]);
            }
        }
    }

    cout << dp[n - 1][m - 1] << endl;

    vector<char> way;
    way.clear();
    int64_t i_orig = n - 1;
    int64_t j_orig = m - 1;
    if (i_orig != 0 || j_orig != 0){
        while(true){
            int64_t cur_value = dp[i_orig][j_orig] - arr[i_orig][j_orig];
            if (i_orig == 0 && j_orig == 0){
                break;
            }
            else if (i_orig == 0){
                j_orig--;
                way.push_back('R');
            }
            else if (j_orig == 0){
                i_orig--;
                way.push_back('D');
            }
            else if (cur_value == dp[i_orig - 1][j_orig]){
                i_orig--;
                way.push_back('D');
            }
            else{
                j_orig--;
                way.push_back('R');
            }
        }
        for (auto it = way.end() - 1; it != way.begin(); it--){
            cout << *it << ' ';
        }
        cout << *way.begin() << endl;
    }

    return 0;
}