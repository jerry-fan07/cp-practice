// An array of n integers is given. Process q operations of two kinds, in order:

// 1 k u: set ak to u;
// 2 a b: print aa + aa+1 + ... + ab.
// input
// The first line has n and q (1 ≤ n, q ≤ 2·105).

// The second line has a1, ..., an (1 ≤ ai ≤ 109).

// Each of the next q lines is an operation 1 k u (1 ≤ k ≤ n, 1 ≤ u ≤ 109) or 2 a b (1 ≤ a ≤ b ≤ n).

// output
// For each operation of the second kind, print the sum on its own line.

#include <bits/stdc++.h>
using namespace std;

vector<long long> fenwick;

long long val(int x){
    int k = 0; long long a = 0;
    while ((x >> k) > 0){
        if (((x>>k) & 1) > 0) a += fenwick[(x>>k)<<k];
        k++;
    }
    return a;
}

void solve(){
    int b, x, y; cin >> b >> x >> y;
    if (b == 1){
        int k = 0;
        long long diff = y-(val(x)-val(x-1));
        while ((x>>k) > 0 && ((x >> k) & 1) == 0) k++;
        while (x < fenwick.size()){
            fenwick[x] += diff;
            int k=0;
            while (((x >> k) & 1) == 0) k++;
            x += 1 << k;
        }
    }
    else {
        x--;
        long long a = 0, c = 0;
        c = val(y);
        a = val(x);
        cout << c - a << '\n';
    }
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q; cin >> n >> q;
    fenwick.reserve(n+1); fenwick.push_back(0);
    vector<long long> sum(n+1);
    int i = 1; sum[0] = 0;
    while(i <= n){
        long long a; cin >> a;
        sum[i] = sum[i-1]+a;
        int k = 0;
        while (((i >> k) & 1) == 0){
            k++;
        }
        fenwick.push_back(sum[i] - sum[i-(1 << k)]);
        i++;
    }
    while (q--){
        solve();
    }
    return 0;
}