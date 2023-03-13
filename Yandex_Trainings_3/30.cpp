#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    int64_t len1, len2;
    vector<int64_t> seq1, seq2;
    seq1.clear();
    seq2.clear();
    cin >> len1;
    for (int64_t i = 0; i < len1; i++){
        int64_t temp;
        cin >> temp;
        seq1.push_back(temp);
    }
    cin >> len2;
    for (int64_t i = 0; i < len2; i++){
        int64_t temp;
        cin >> temp;
        seq2.push_back(temp);
    }

    len2++;
    len1++;
    vector<vector<int64_t>> dp;
    vector<int64_t> empty;
    empty.clear();
    empty.resize(len2);
    dp.clear();

    for (int64_t i = 0; i < len2; i++){
        empty[i] = 0;
    }
    for (int64_t i = 0; i < len1; i++){
        dp.push_back(empty);
    }

    for (int64_t i = 1; i < len1; i++){
        for (int64_t j = 1; j < len2; j++){
            if (seq1[i - 1] == seq2[j - 1]){
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    int64_t i_orig, j_orig;
    vector<int64_t> union_seq;
    union_seq.clear();
    i_orig = len1 - 1;
    j_orig = len2 - 1;
    while(i_orig != 0 && j_orig != 0){
        //cout << i_orig << j_orig << endl;
        if (dp[i_orig][j_orig] == dp[i_orig - 1][j_orig]){
            i_orig--;
        }
        else if (dp[i_orig][j_orig] == dp[i_orig][j_orig - 1]){
            j_orig--;
        }
        else{
            union_seq.push_back(seq1[i_orig - 1]);
            i_orig--;
            j_orig--;
        }
    }

    if (union_seq.size() > 0){
        reverse(union_seq.begin(), union_seq.end());
        for (auto & it : union_seq){
            cout << it << ' ';
        }
        cout << endl;
    }

    return 0;
}