#include <bits/stdc++.h>
using namespace std;

string t, p;
vector<int> pi;

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

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t >> p;
    pi.assign(p.size(), 0);
    solve();
    return 0;
}