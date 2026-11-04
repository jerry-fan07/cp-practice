#include <bits/stdc++.h>
using namespace std;

vector<int> indegree;
vector<vector<int>> adj;
vector<int> dist;
vector<int> par;

void solve(){
    deque<int> queue;
    queue.push_front(0);
    dist[0] = 1;
    for (int i = 1; i < (int) indegree.size(); i++){
        if (indegree[i] == 0) queue.push_front(i);
    }
    while(!queue.empty()){
        int s = queue.size();
        while(s--){
            int q = queue.back();
            queue.pop_back();
            for (int &x: adj[q]) {
                if (dist[q] != 0 && dist[q]+1 > dist[x]) {
                    dist[x] = dist[q]+1;
                    par[x] = q;
                }
                indegree[x]--;
                if (indegree[x] == 0) queue.push_front(x);
            }
        }
    }
    if (dist.back() > 0) {
        cout << dist.back() << '\n';
        int n = (int) indegree.size()-1;
        vector<int> ans; ans.reserve(n);
        while (n != -1){
            ans.push_back(n);
            n = par[n];
        }
        reverse(ans.begin(), ans.end());
        for (int& x: ans) cout << x+1 << ' ';
    }
    else cout << "IMPOSSIBLE" << '\n';
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m; cin >> n >> m;
    adj.assign(n, vector<int>());
    indegree.assign(n, 0);
    dist.assign(n, 0);
    par.assign(n, -1);
    while (m--){
        int a, b;
        cin >> a >> b; b--; a--;
        adj[a].push_back(b);
        indegree[b]++;
    }
    solve();

    return 0;
}