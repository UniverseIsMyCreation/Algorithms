#include <map>
#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

void dfs(map<int64_t, vector<int64_t>> graph, int64_t point, set<int64_t> & visited, vector<int64_t> & topological_sort, map<int64_t, int64_t> & colored){
    visited.insert(point);
    colored[point] = 1;
    for (auto & it : graph[point]){
        if (colored[it] == 1){
            cout << -1 << endl;
            exit(0);
        }
        if (visited.find(it) == visited.end()){
            dfs(graph, it, visited, topological_sort, colored);
        }
    }
    colored[point] = 2;
    topological_sort.push_back(point);
}

int main(){

    int64_t n, m;
    cin >> n >> m;
    map<int64_t, vector<int64_t>> graph;
    vector<int64_t> empty;
    vector<int64_t> points;
    map<int64_t, int64_t> colored;
    set<int64_t> visited;
    vector<int64_t> topological_sort;
    topological_sort.clear();
    visited.clear();
    colored.clear();
    points.clear();
    graph.clear();
    empty.clear();
    for (int64_t i = 0; i < n; i++){
        graph[i + 1] = empty;
        colored[i + 1] = 0;
        points.push_back(i + 1);
    }
    for (int64_t i = 0; i < m; i++){
        int64_t n1, m1;
        cin >> n1 >> m1;
        graph[n1].push_back(m1);
    } 

    for (auto & point : points){
        if (visited.find(point) == visited.end())
            dfs(graph, point, visited, topological_sort, colored);
    }

    reverse(topological_sort.begin(), topological_sort.end());
    for (auto & part : topological_sort){
        cout << part << ' ';
    }
    cout << endl;

    return 0;
}