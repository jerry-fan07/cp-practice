#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n, m; cin >> n >> m;
    vector<vector<int>> adj(n, vector<int>());
    for (int i = 0; i < n-1; i++){
        int a, b; cin >> a >> b;
        adj[a-1].push_back(b-1);
        adj[b-1].push_back(a-1);
    }
    deque<int> queue;
    vector<int> par(n, 0);
    queue.push_front(0);
    unordered_set<int> visited;
    while (!queue.empty()){
        int q = queue.back();
        queue.pop_back();
        visited.insert(q);
        if (q == n-1) break;
        for (int& x: adj[q]) {
            if (visited.count(x) == 0) {
                queue.push_front(x);
                par[x] = q;
            }
        }
    }
    vector<int> path; path.reserve(n);
    int x = n-1;
    while (x != 0){
        path.push_back(x);
        x = par[x];
    }
    path.push_back(0); 
    reverse(path.begin(), path.end());
    visited.clear();
    for (int &x: path) visited.insert(x);
    unordered_map<int, int> increases;
    for (int i = 1; i < path.size(); i++){
        deque<int> queue;
        for (int &x: adj[path[i]]){
            if (visited.count(x) == 0) queue.push_front(x);
        }
        int c = 1;
        while (!queue.empty()){
            int s = queue.size();
            while(s--){
                int q = queue.back(); 
                queue.pop_back();
                visited.insert(q);
                if (c-i+1 > 0) increases[q] = c - i + 1;
                for (int& x: adj[q]) {
                    if (visited.count(x) == 0) queue.push_front(x);
                }
            }
            c++;
        }
    }
    int max_val = 0;
    while (m--){
        int a; cin >> a;
        if (increases[a-1] > 0) max_val = max(max_val, increases[a-1]);
    }
    cerr << max_val << "mv" << '\n';
    cout << max_val + path.size()-1 << '\n';
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--){
        solve();
    }
    return 0;
}

