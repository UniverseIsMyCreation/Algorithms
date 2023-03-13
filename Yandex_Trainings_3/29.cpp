#include <iostream>
#include <vector>

using namespace std;

int64_t sum(vector<int64_t> arr){
    int64_t sm = 0;
    for (auto & it : arr){
        sm += it;
    }
    return sm;
}

int main(){

    int64_t n;
    cin >> n;
    vector<int64_t> prices;
    int64_t tickets_amount = 0;
    prices.clear();
    for (int64_t i = 0; i < n; i++){
        int64_t temp;
        cin >> temp;
        prices.push_back(temp);
        if (temp > 100){
            tickets_amount++;
        }
    }
    
    if (tickets_amount == 0){
        cout << sum(prices) << endl;
        cout << 0 << ' ' << 0 << endl;
        return 0;
    }

    tickets_amount++;
    vector<vector<int64_t>> dp;
    dp.clear();
    vector<int64_t> empty;
    empty.clear();
    dp.push_back(empty);
    int64_t min_ans = prices[0];
    int64_t i_orig, j_orig;
    if (prices[0] <= 100){
        dp[0].push_back(prices[0]);
        dp[0].push_back(30001);
        i_orig = 0;
        j_orig = 0;
    }
    else{
        dp[0].push_back(30001);
        dp[0].push_back(prices[0]);
        i_orig = 0;
        j_orig = 1;
    }
    for (int64_t i = 2; i <= tickets_amount; i++){
        dp[0].push_back(30001);
    }

    for (int64_t i = 1; i < prices.size(); i++){
        min_ans = 30001;
        dp.push_back(empty);
        for (int64_t j = 0; j < tickets_amount; j++){
            if (j == 0){
                dp[i].push_back(min(dp[i-1][j] + prices[i], dp[i-1][j+1]));
            }
            else{
                if (prices[i] <= 100){
                    dp[i].push_back(min(dp[i-1][j+1], dp[i-1][j] + prices[i]));
                }
                else{
                    dp[i].push_back(min(dp[i-1][j+1], dp[i-1][j-1] + prices[i]));
                }
                
            }
            if (dp[i][j] >= 30001){
                dp[i][j] = 30001;
            }
            if (dp[i][j] <= min_ans){
                min_ans = dp[i][j];
                i_orig = i;
                j_orig = j;
            }
        }
        dp[i].push_back(30001);
    }

    /*for (int64_t i = 0; i < prices.size(); i++){
        for (int64_t j = 0; j <= tickets_amount; j++){
            cout << dp[i][j] << ' ';
        }
        cout << endl;
    }*/

    cout << min_ans << endl;
    vector<int64_t> way;
    int64_t spent_tickets = 0;
    int64_t saved_tickets = j_orig;

    while(i_orig > 0){
        if (j_orig == 0){
            if (dp[i_orig-1][j_orig] + prices[i_orig] < dp[i_orig-1][j_orig+1]){
                i_orig--;
            }
            else{
                way.push_back(i_orig + 1);
                i_orig--;
                j_orig++;
            }
        }
        else{
            if (prices[i_orig] <= 100){
                if (dp[i_orig-1][j_orig] + prices[i_orig] < dp[i_orig-1][j_orig+1]){
                    i_orig--;
                }
                else{
                    way.push_back(i_orig + 1);
                    i_orig--;
                    j_orig++;
                }
            }
            else{
                if (dp[i_orig-1][j_orig-1] + prices[i_orig] < dp[i_orig-1][j_orig+1]){
                    i_orig--;
                    j_orig--;
                }
                else{
                    way.push_back(i_orig + 1);
                    i_orig--;
                    j_orig++;
                }
            }
        }
    }
    cout << saved_tickets << ' ' << way.size() << endl;

    if (way.size() > 0){
        for (auto it = way.end() - 1; it != way.begin(); it--){
            cout << *it << endl;
        }
        cout << *way.begin() << endl;
    }

    return 0;
}