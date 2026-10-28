#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q; cin >> n >> q;
    vector<vector<int>> minima;
    vector<int> temps(n);
    for (int& x: temps) cin >> x;
    
    int k = 1; int mv;
    while ((1 << k) <= temps.size()){
        minima.emplace_back(vector<int>());
        for (int i = 0; i + (1 << k) <= temps.size(); i += (1 << k)){
            mv = INT_MAX;
            for (int j = i; j < i + (1 << k); j++){
                mv = min(mv, temps[j]);
            }
            minima.back().push_back(mv);
        }
        k++;
    }
    
    while (q--){
        int l, r; cin >> l >> r;
        l--; r--;
        mv = temps[l];
        if ((l % 2) == 1) mv = min(mv, temps[l++]);
        if ((r % 2) == 0) mv = min(mv, temps[r--]);
        int i = 0;
        while (l <= r){
            l /= 2; r /= 2;
            if ((l % 2) == 1) mv = min(mv, minima[i][l++]);
            if ((r % 2) == 0) mv = min(mv, minima[i][r--]);
            i++;
        }
        cout << mv << '\n';
    }
    
    return 0;
}
