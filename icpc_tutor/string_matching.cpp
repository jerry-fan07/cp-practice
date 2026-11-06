#include <bits/stdc++.h>
using namespace std;

string t, p;
vector<int> pi;

// KMP Algorithm Implementation (Knuth-Morris-Pratt)
// Rabin-Karp Algorithm Implementation (rolling hash)

void build(){
    int k = 0, i = 1;
    while (i < p.size()){
        while (i < p.size() && p[i] == p[k]){
            pi[i] = k+1;
            k++;
            i++;
            if (i == p.size()) break;
            while (p[i] != p[k] && k > 0){
                k = pi[k-1];
            }
        }
        if (i == p.size()) break;
        pi[i++] = 0;
    }
}

void match(){
    int k = 0, ans = 0;
    for (char c: t){
        while (k > 0 && c != p[k]) k = pi[k-1];
        if (c == p[k]) k++;
        if (k == p.size()){
            ans++; 
            k = pi[k-1];
        }
    }
    cout << ans;
}

void solve(){
    build();
    match();
}

void RK(){
    int ans = 0;
    int T = t.size(), P = p.size();
    const int prime = 31;
    const int MOD = 1e9 + 9;
    vector<long long> p_pow(max(T, P), 1);
    for (int i = 1; i < p_pow.size(); i++){
        p_pow[i] = (p_pow[i-1]*prime) % MOD;
    }
    long long phash = 0;
    for (int i = 0; i < p.size(); i++){
        phash += ((p[i] - 'a' + 1)*p_pow[i]) % MOD;
    }
    vector<long long> thash(t.size()+1, 0);
    for (int i = 0; i < t.size(); i++){
        thash[i+1] = (thash[i] + ((t[i] - 'a' + 1)*p_pow[i])) % MOD;
    }

    for (int i = 0; i + P - 1 < t.size(); i++){
        long long sh = (thash[i+P] - thash[i] + MOD) % MOD;
        if (sh == (phash*p_pow[i]) % MOD) ans++;
    }
    cout << ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t >> p;
    pi.assign(p.size(), 0);
    //solve();
    RK();
    return 0;
}