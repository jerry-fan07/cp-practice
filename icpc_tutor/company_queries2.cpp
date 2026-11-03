#include <bits/stdc++.h>
using namespace std;

const int LOG = 18;
int up[LOG][200'001];
vector<int> length;

void buildtree(int n){
    for(int i = 2; i <= n; i++){
        cin >> up[0][i];
    }
    for (int i = 1; i < LOG; i++){
        for (int j = 2; j <= n; j++){
            up[i][j] = up[i-1][up[i-1][j]];
        }
    }
    length.assign(n+1, 0);
    vector<vector<int>> adj(n+1, vector<int>());
    for (int i = 2; i <= n; i++){
        adj[up[0][i]].push_back(i);
    }
    deque<int> queue;
    queue.push_front(1);
    while (queue.size() > 0){
        int s = queue.size();
        while(s--){
            int q = queue.back();
            queue.pop_back();
            for (int &x: adj[q]){
                length[x] = length[q]+1;
                queue.push_front(x);
            }
        }
    }
}

int kAncestor(int a, int k){
    int i = 0;
    while ((k >> i) > 0 && a > 0){
        if (((k >> i) & 1) > 0){
            a = up[i][a];
        }
        i++;
    }
    return a;
}

void solve(){
    int a, b;
    cin >> a >> b;
    if (length[a] < length[b]){
        int t = b; b = a; a = t;
    }
    a = kAncestor(a, length[a] - length[b]);
    cout << lca(a, b) << '\n';
}

int lca(int a, int b){
    if (a == b) return a;
    int l = length[a];
    int i = 0;
    while((l >> i) > 0) i++;
    while (i >= 0 && up[i][a] == up[i][b]) i--;
    if (i == -1) return up[0][a];
    return lca(up[i][a], up[i][b]);
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    buildtree(n);
    while (q--){
        solve();
    }
    return 0;
}
