#include <bits/stdc++.h>
using namespace std;
 
#define ll long long int
 
void solve(){
    ll n;
    cin >> n;
 
    string a;
    cin >> a;
 
    ll c0 = 0;
 
    for (ll i = 0; i < n; i++)
    {
        if (a[i] == '0'){
            c0++;
        }
    }
 
    ll c1 = n - c0;
 
    if (c0 % 2) {
        cout << c0 << "\n";
        for (ll i = 0; i < n; i++)
        {
            if (a[i] == '0'){
                cout << i + 1 << " ";
            }
        }
        cout << "\n";
    }
    else if ((c1 % 2) == 0) {
        cout << c1 << "\n";
        if (c1 != 0) {
            for (ll i = 0; i < n; i++)
            {
                if (a[i] == '1'){
                    cout << i + 1 << " ";
                }
            }
            cout << "\n";
        }
    }
    else{
        cout << -1 << "\n";
    }
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