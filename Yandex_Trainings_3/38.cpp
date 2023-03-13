#include <iostream>
#include <map>
#include <queue>
#include <vector>
#include <cmath>

using namespace std;

int main(){
    int n, m, s, t, q;
    cin >> n >> m >> s >> t >> q;
    s--;
    t--;
    vector<vector<int>> visited;
    vector<int> null_vector;
    null_vector.clear();
    for (int i = 0; i < n; i++){
        visited.push_back(null_vector);
        for (int j = 0; j < m; j++){
            if (i == s && j == t)
                visited[i].push_back(0);
            else
                visited[i].push_back(-1);
        }
    }
    map<pair<int, int>, int> pos2obj;
    pos2obj.clear();
    for (int i = 0; i < q; i++){
        int temp1, temp2;
        cin >> temp1 >> temp2;
        pos2obj[pair<int, int>(temp1-1, temp2-1)] = -1;
    }
    int visited_amount = 0;
    int64_t jumps = 0;
    vector<int> jumps_add = {-2, -1, 1, 2};
    queue<vector<int>> que;
    vector<int> cur_pos_dist = {s, t, 0};
    que.push(cur_pos_dist);
    int length = 1;
    while (length > 0){
        cur_pos_dist = que.front();
        length--;
        que.pop();
        if (pos2obj.find(pair<int, int>(cur_pos_dist[0], cur_pos_dist[1])) != pos2obj.end()){
            if (pos2obj[pair<int, int>(cur_pos_dist[0], cur_pos_dist[1])] == -1){
                visited_amount++;
                jumps += cur_pos_dist[2];
            }
            if (visited_amount == q){
                cout << jumps << endl;
                return 0;
            }
        }
        for (auto it1 : jumps_add){
            for (auto it2 : jumps_add){
                if (abs(it1) != abs(it2)){
                    if (cur_pos_dist[0] + it1 >= 0 && cur_pos_dist[0] + it1 < n && cur_pos_dist[1] + it2 >= 0 && cur_pos_dist[1] + it2 < m){
                        if (visited[cur_pos_dist[0] + it1][cur_pos_dist[1] + it2] == -1){
                            visited[cur_pos_dist[0] + it1][cur_pos_dist[1] + it2] = cur_pos_dist[2] + 1;
                            vector<int> new_pos_dist = {cur_pos_dist[0] + it1, cur_pos_dist[1] + it2, cur_pos_dist[2] + 1};
                            que.push(new_pos_dist);
                            length++;
                        }
                    }
                }
            }
        }
    }
    cout << -1 << endl;
    return 0;
}