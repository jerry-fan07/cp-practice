#include <bits/stdc++.h>
using namespace std;

vector<int> arr;
vector<vector<int>> segment;

void update(int k, int u){
    segment[0][k] = u;
    for (int i = 1; i < 19; i++){
        k /= 2;
        if (k >= segment[i].size()) break;
        int prev = segment[i][k];
        segment[i][k] = min(segment[i-1][k*2], segment[i-1][k*2 + 1]);
        if (prev == segment[i][k]) break;
    }
}

void mrq(int a, int b){
    int ans = segment[0][a];
    int i = 0;
    while (b - a > 0){
        if ((a % 2) != 0){
            ans = min(ans, segment[i][a]);
            a++;
        }
        if ((b % 2) == 0){
            ans = min(ans, segment[i][b]);
            b--;
        }
        if (b-a <= 0) break;
        a /= 2;
        b /= 2;
        i++;
    }
    ans = min(ans, segment[i][a]);
    cout << ans << '\n';
}

void solve(){
    int k, x, y; 
    cin >> k >> x >> y;
    if (k == 1) update(x-1, y);
    else mrq(x-1, y-1);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q; cin >> n >> q;
    segment.assign(19, vector<int>());
    segment[0].assign(n, 0);
    for (int& x: segment[0]) cin >> x;
    for (int i = 1; i < 19; i++){
        for (int j = 0; (j+1) < segment[i-1].size(); j += 2){
            segment[i].push_back(min(segment[i-1][j], segment[i-1][j+1]));
        }
    }
    while(q--) solve();
    return 0;
}