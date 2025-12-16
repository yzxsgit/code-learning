#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1e9 + 7;

void solve() {
    int p;
    cin >> p;

    int ans = 0;
    
    for (int l = 1, r; l <= p; l = r + 1) 
    {
        int val = N / l;
        
        if (val == 0) { 
             r = p; 
        } 
        else 
        {
             r = N / val;
        }

        if (r > p) r = p;
        
        int count = r - l + 1;
        
        ans ^= count;
    }

    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}