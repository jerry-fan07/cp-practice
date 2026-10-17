#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dp;
vector<unordered_map<int, int>> adj;
int n;
int MOD = 1000'000'007;

void mask(int pos, int visited){
    if (visited == (1 << (n-2)) - 1){
        dp[pos][visited] = adj[pos-1][n] % MOD;
        return;
    }
    dp[pos][visited] = 0;
    for (int i = 2; i < n; i++){
        if ((visited >> (i-2)) & 1) continue;
        int next = visited | (1 << (i-2));
        if (dp[i][next] == -1){
            mask(i, next);
        }
        dp[pos][visited] += (int) (((long long) adj[pos-1][i] * dp[i][next]) % MOD);
        dp[pos][visited] %= MOD;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int m;
    cin >> n >> m;
    adj = vector<unordered_map<int, int>>(n, unordered_map<int, int>());
    while (m--){
        int i, j;
        cin >> i >> j;
        adj[i-1][j]++;
    }
    dp.assign(n+1, vector<int>(1 << (n-2), -1));
    mask(1, 0);
    cout << dp[1][0] << '\n';

    return 0;
}
