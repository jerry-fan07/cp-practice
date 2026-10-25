#include <bits/stdc++.h>
using namespace std;

void solve(){
    int min_val = INT_MAX;
    int n; cin >> n;
    for (int i = 0; i < n; i++){
        int a; cin >> a;
        min_val = min(min_val, a);
    }
    if (min_val < n) cout << n << '\n';
    else cout << 0 << '\n';
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

