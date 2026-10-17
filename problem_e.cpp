#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    unordered_map<int, bool> strings;

    int t; cin >> t;
    int tot;
    for (int x = 0; x < t; x++){
        for (int s = 0; s < 4; s++){
            strings[s] = false;
        }

        int n;
        cin >> n;

        for (int i = 0; i < n; i++){
            int p; cin >> p;
            if (p <= 10){
                strings[0] = true;
            }
            else if (p <= 20){
                strings[1] = true;
            }
            else if (p <= 30){
                strings[2] = true;
            }
            else {
                strings[3] = true;
            }
        }
        tot = 0;
        for (int i = 0; i < 4; i++){
            if (strings[i]){
                tot++;
            }
        }
        cout << tot << '\n';
    }

    return 0;
}
