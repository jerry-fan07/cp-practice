#include <bits/stdc++.h>
using namespace std;

vector<unordered_set<int>> adj;


// 0-INDEXING

void solve(){
    deque<int> queue;
    for (int i = 0; i < adj.size(); i++){
        if (adj[i].size() == 1) queue.push_front(i);
    }
    int diam = 0;
    int s;
    while (queue.size() > 0){
        diam++;
        s = queue.size();
        for (int i = 0; i < s; i++){
            int leaf = queue.back();
            queue.pop_back();
            if (adj[leaf].size() < 1) continue;
            int branch = *adj[leaf].begin();
            adj[leaf].clear();
            adj[branch].erase(leaf);
            if (adj[branch].size() == 1){
                queue.push_front(branch);
            }
        }
    }
    if (s==2) cout << max(0, (diam)*2-1);
    else cout << max(0, (diam-1)*2);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    adj.assign(n, unordered_set<int>());
    for (int i=0; i < n-1; i++){
        int a, b; cin >> a >> b;
        adj[a-1].insert(b-1);
        adj[b-1].insert(a-1);
    }
    solve();
    return 0;
}
