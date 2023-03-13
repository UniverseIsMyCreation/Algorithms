#include <iostream>

using namespace std;

int main(int argc, char ** argv){

    int64_t n, cnt;
    cin >> n;
    cin >> cnt;
    int64_t ans = 0;
    for (int64_t i = 1; i < n; i++){
        int64_t temp;
        cin >> temp;
        ans += min(cnt, temp);
        cnt = temp;
    }

    cout << ans << endl;

    return 0;
}