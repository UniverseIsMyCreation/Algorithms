#include <iostream>

using namespace std;

int main(int argc, char ** argv){

    int n, m, k;
    cin >> n >> m >> k;
    int64_t arr[n][m];

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            int64_t temp;
            cin >> temp;
            if (i == 0 && j == 0){
                arr[i][j] = temp;
            }
            else if (i == 0 && j != 0){
                arr[i][j] = arr[i][j-1] + temp;
            }
            else if (i != 0 && j == 0){
                arr[i][j] = arr[i-1][j] + temp;
            }
            else{
                arr[i][j] = temp + arr[i][j-1] + arr[i-1][j] - arr[i-1][j-1];
            }
        }
    }

    int x1,y1,x2,y2;
    for (int i = 0; i < k; i++){
        cin >> x1 >> y1 >> x2 >> y2;
        x1--;
        x2--;
        y1--;
        y2--;
        if (y1 == 0)
            if (x1 == 0)
                cout << arr[x2][y2] << endl;
            else
                cout << arr[x2][y2] - arr[x1-1][y2] << endl;
        else if (x1 == 0)
            cout << arr[x2][y2] - arr[x2][y1-1] << endl;
        else
            cout << arr[x2][y2] - arr[x2][y1-1] - arr[x1-1][y2] + arr[x1-1][y1-1] << endl;
    }

    return 0;
}