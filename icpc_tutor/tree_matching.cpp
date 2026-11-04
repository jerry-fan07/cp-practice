#include <bits/stdc++.h>
using namespace std;

vector<unordered_set<int>> adj;
vector<bool> matched;

void solve(){
    deque<int> queue;
    for (int i = 0; i < adj.size(); i++){
        if (adj[i].size() == 1) queue.push_front(i);
    }
    int ans = 0;
    int s;
    while (queue.size() > 0){
        for (int i = 0; i < 2 && queue.size() > 0; i++){
            s = queue.size();
            for (int k = 0; k < s; k++){
                int q = queue.back();
                queue.pop_back();
                if (adj[q].empty()) continue;
                int b = *adj[q].begin();
                adj[q].clear();
                adj[b].erase(q);
                matched[b] = true;
                matched[q] = true;
                ans++;
                for (int x: adj[b]){
                    adj[x].erase(b);
                    if (adj[x].size() == 1 && !matched[x]) queue.push_front(x);
                }
                adj[b].clear();
            }
        }
    }
    cout << ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    matched.assign(n, false);
    adj.assign(n, unordered_set<int>());
    for (int i = 0; i < n-1; i++){
        int a, b; cin >> a >> b;
        adj[a-1].insert(b-1);
        adj[b-1].insert(a-1);
    }
    solve();
    return 0;
}