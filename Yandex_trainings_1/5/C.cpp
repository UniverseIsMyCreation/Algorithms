#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char ** argv){

    int64_t n, m;
    vector<int64_t> ascent_amount_forward;
    vector<int64_t> ascent_amount_backward;
    vector<pair<int64_t, int64_t>> path;
    cin >> n;
    ascent_amount_forward.clear();
    ascent_amount_backward.clear();
    path.clear();
    
    int64_t sm_ascent = 0;
    for (int i = 0; i < n; i++){
        int64_t x, y;
        cin >> x >> y;
        pair<int64_t, int64_t> coords (x, y);
        path.push_back(coords);
        if (i == 0){
            ascent_amount_forward.push_back(0);
        }
        else{
            if (y > path[i - 1].second){
                sm_ascent += (y - path[i - 1].second);
            }
            ascent_amount_forward.push_back(sm_ascent);
        }
    }

    sm_ascent = 0;
    for (int i = n - 1; i >= 0; i--){
        if (i == n - 1){
            ascent_amount_backward.push_back(0);
        }
        else{
            if (path[i].second > path[i + 1].second){
                sm_ascent += (path[i].second - path[i + 1].second);
            }
            ascent_amount_backward.push_back(sm_ascent);
        }
    }

    cin >> m;
    int64_t length = ascent_amount_backward.size() - 1;
    for (int i = 0; i < m; i++){
        int64_t s, f;
        cin >> s >> f;
        if (f >= s){
            cout << ascent_amount_forward[f - 1] - ascent_amount_forward[s - 1] << endl;
        }
        else{
            cout << ascent_amount_backward[length - f + 1] - ascent_amount_backward[length - s + 1] << endl;
        }
    }

    return 0;
}