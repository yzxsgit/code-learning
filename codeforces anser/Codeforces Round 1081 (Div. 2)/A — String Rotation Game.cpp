#include <bits/stdc++.h>
using namespace std;
 
#define ll long long int
 
void solve(){
    ll n;
    cin >> n;
 
    string s;
    cin >> s;
 
    ll ans = 1;
 
    for (ll i = 1; i < n; i++)
    {
        if (s[i - 1] != s[i]){
            ans++;
        }
    }
 
    if (ans != n && s[0] != s[n - 1]){
        ans++;
    }
 
    cout << ans << "\n";
}
 
int main() { 
 
    ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
    
    ll T = 1;
    
    cin >> T;
    
    while (T--)
    {
        solve();
    }
    
    return 0;
 
}