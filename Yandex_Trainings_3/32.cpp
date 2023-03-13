#include <map>
#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

int main(){

    int64_t n, m;
    cin >> n >> m;
    map<int64_t, vector<int64_t>> graph;
    vector<int64_t> empty;
    set<int64_t> points;
    points.clear();
    graph.clear();
    empty.clear();
    for (int64_t i = 0; i < n; i++){
        graph[i + 1] = empty;
        points.insert(i + 1);
    }
    for (int64_t i = 0; i < m; i++){
        int64_t n1, m1;
        cin >> n1 >> m1;
        if (n1 == m1)
            continue;
        graph[n1].push_back(m1);
        graph[m1].push_back(n1);
    } 

    set<int64_t> visited;
    visited.clear();
    vector<vector<int64_t>> all_graph;
    all_graph.clear();
    int64_t comp = 0;
    vector<int64_t> one_graph;
    stack<int64_t> st;
    for (auto & point : points){
        if (visited.find(point) == visited.end()){
            comp++;
            one_graph.clear();
            st.push(point);
            int64_t cur_stack;
            while (st.size() > 0){
                cur_stack = st.top();
                st.pop();
                if (visited.find(cur_stack) == visited.end()){
                    visited.insert(cur_stack);
                    one_graph.push_back(cur_stack);
                    for (auto & it : graph[cur_stack]){
                        if (visited.find(it) == visited.end()){
                            st.push(it);
                        }
                    }
                }
            }
            cout << endl;
            all_graph.push_back(one_graph);
        }
    }

    cout << comp << endl;
    for (auto & component : all_graph){
        cout << component.size() << endl;
        sort(component.begin(), component.end());
        for (auto & part : component){
            cout << part << ' ';
        }
        cout << endl;
    }

    return 0;
}