#include <iostream>
#include <vector>

using namespace std;

int main (){

    int64_t n;
    cin >> n;
    vector<pair<int64_t, int64_t>> dp;
    dp.clear();
    dp.push_back(pair<int64_t, int64_t>(0, -1));

    for (int i = 2; i <= n; i++){
        if (i % 2 == 0 && i % 3 == 0){
            int64_t res_fin = min(dp[i / 3 - 1].first, min(dp[i - 2].first, dp[i / 2 - 1].first));
            int64_t res_i;
            if (res_fin == dp[i - 2].first){
                res_i = i - 1;
            }
            else if (res_fin == dp[i / 2 - 1].first){
                res_i = i / 2;
            }
            else{
                res_i = i / 3;
            }
            dp.push_back(pair<int64_t, int64_t>(res_fin + 1, res_i));
        }
        else if (i % 2 == 0 && i % 3 != 0){
            int64_t res_fin = min(dp[i - 2].first, dp[i / 2 - 1].first);
            int64_t res_i;
            if (res_fin == dp[i - 2].first){
                res_i = i - 1;
            }
            else{
                res_i = i / 2;
            }
            dp.push_back(pair<int64_t, int64_t>(res_fin + 1, res_i));
        }
        else if (i % 2 != 0 && i % 3 == 0){
            int64_t res_fin = min(dp[i - 2].first, dp[i / 3 - 1].first);
            int64_t res_i;
            if (res_fin == dp[i - 2].first){
                res_i = i - 1;
            }
            else{
                res_i = i / 3;
            }
            dp.push_back(pair<int64_t, int64_t>(res_fin + 1, res_i));
        }
        else{
            dp.push_back(pair<int64_t, int64_t>(dp[i - 2].first + 1, i - 1));
        }
    }

    cout << dp[n - 1].first << endl;

    vector<int64_t> res_way;
    res_way.clear();
    int64_t pointer = dp[n - 1].second;
    res_way.push_back(n);
    while (true){
        if (pointer == -1){
            break;
        }
        res_way.push_back(pointer);
        pointer = dp[pointer - 1].second;
    }

    for (auto it = res_way.end() - 1; it != res_way.begin(); it--){
        cout << *it << ' ';
    }
    cout << *res_way.begin() << endl;

    return 0;
}