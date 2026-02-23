#include <bits/stdc++.h>
using namespace std;

#define ll long long int

void solve(){

    ll n, h, k;
    cin >> n >> h >> k;

    vector<ll> a (n);
    vector<ll> prefixSumA (n);

    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
        prefixSumA[i] = a[i];
        if(i - 1 >= 0){
            prefixSumA[i] += prefixSumA[i - 1];
        }
    }

    ll sum = prefixSumA[n - 1];

    ll numberOfMagsWithoutLastMag = (h - 1) / sum;
    ll timeWithoutLastMag = n * numberOfMagsWithoutLastMag + k * numberOfMagsWithoutLastMag;

    h -= numberOfMagsWithoutLastMag * sum;

    if (h <= 0){
        cout << timeWithoutLastMag << "\n";
        return;
    }

    vector<ll> maxFromRight (n);
    maxFromRight[n - 1] = a[n - 1];

    for (ll i = n - 2; i >= 0; i--)
    {
        maxFromRight[i] = max(maxFromRight[i + 1], a[i]);
    }

    ll minFromLeft = a[0];
    
    for (ll i = 0; i < n; i++)
    {
        minFromLeft = min(minFromLeft, a[i]);
        ll currSum = prefixSumA[i] - minFromLeft + maxFromRight[i + 1];

        if(h <= currSum || h <= prefixSumA[i]){
            cout << timeWithoutLastMag + i + 1 << "\n";
            return;
        }
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