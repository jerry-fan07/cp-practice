#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n, k;
    cin >> n >> k;
    vector<int> nums(101, 0);
    while (n--){
        int a; cin >> a;
        nums[a]++;
    }
    int i = 0; int curr = 0;
    while (i < nums.size()){
        curr += nums[i];
        if (curr < k || nums[i] == 0) {
            cout << i << '\n';
            break;
        }
        curr -= k;
        i++;
    }
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