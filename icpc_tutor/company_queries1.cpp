#include <bits/stdc++.h>
using namespace std;

// BROKEN

const int LOG = 18;
int up[LOG][200'001];

void solve(){
    int n, q;
    cin >> n >> q;
    up[0][0] = 0;
    for (int i = 1; i < n; i++){
        int x; cin >> x;
        up[0][i] = x-1;
    }
    for (int x = 1; x < n; x++){
        for (int i = 1; i < LOG; i++){
            // if ((1 << i-1) >= n) break;
            up[i][x] = up[i-1][up[i-1][x]];
        }
    }
    while(q--){
        int x, k;
        cin >> x >> k;
        for (int j = 0; j < k && x && k >> j; j++){
            if ((k >> j) & 1) x = up[j][x];
        }
        if (x == 0) cout << -1 << '\n';
        else cout << x << '\n';
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}