#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
using namespace std;

void solve(){
    pair<int, int> origin;
    cin >> origin.first >> origin.second;
    vector<vector<long long>> points(2, vector<long long>(2));
    for (auto& p: points) {
        cin >> p[0] >> p[1];
        p[0] -= origin.first; p[1] -= origin.second;
    }
    long long c = points[0][0]*points[1][1] - points[0][1]*points[1][0];
    if (c==0) cout << "TOUCH\n";
    else if (c > 0) cout << "LEFT\n";
    else cout << "RIGHT\n";
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}