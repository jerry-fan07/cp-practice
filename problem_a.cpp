#include <bits/stdc++.h>
using namespace std;
const int MOD = 998'244'353;
void solve() {
    long long n;
    cin >> n;
    
    int a = n;
    if 

    long long t1 = n % MOD;
    long long t2 = n % MOD + 1;
    long long t3 = n % MOD + 2;

    long long ans = ((t1 * t2) * t3) /= 6;
    ans %= MOD;
    cout << ans;
}

    

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
