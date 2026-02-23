#include <bits/stdc++.h>
using namespace std;
 
#define ll long long int
 
//<ans, ansWithOperationUsed, sum, maxDepth>
array<ll, 4> func(ll par, ll child, vector<vector<ll>> &a, vector<ll> &v, vector<array<ll, 4>> &ans){
    array<ll, 4> currAns = {0, 0, v[child], 0};
 
    ll maxDepth = 0;
    ll secondMaxDepth = 0;
 
    ll maxAnsIncreaseWithOperationUsed = 0;
 
    for (auto i:a[child])
    {
        if(i != par){
            array<ll, 4> sa = func(child, i, a, v, ans);
 
            if (sa[3] + 1 >= maxDepth) {
                secondMaxDepth = maxDepth;
                maxDepth = sa[3] + 1;
            }
            else if (sa[3] + 1 > secondMaxDepth) {
                secondMaxDepth = sa[3] + 1;
            }
 
            maxAnsIncreaseWithOperationUsed = max(maxAnsIncreaseWithOperationUsed, sa[1] - sa[0]);
 
            currAns[0] += sa[0] + sa[2];
            currAns[1] += sa[0] + sa[2];
            currAns[2] += sa[2];
        }
    }
 
    currAns[1] += maxAnsIncreaseWithOperationUsed;
    currAns[3] = maxDepth;
 
    for (auto i:a[child])
    {
        if(i != par){
            ll cAns = ans[i][0];
            ll cSum = ans[i][2];
            ll cd = ans[i][3] + 1;
 
            ll maxDepthFromOtherSubtrees = maxDepth;
 
            if (cd == maxDepth) {
                maxDepthFromOtherSubtrees = secondMaxDepth;
            }
 
            currAns[1] = max(currAns[1], currAns[0] + maxDepthFromOtherSubtrees * cSum);
        }
    }
 
    ans[child] = currAns;
 
    return currAns;
}
 
void solve(){
 
    ll n, e;
    cin >> n;
    e = n-1; // For Tree
 
    // For Graph;
    // cin >> e; 
 
    vector<ll> v (n+1);
 
    for (ll i = 1; i <= n; i++)
    {
        cin >> v[i];
    }
 
    vector<vector<ll>> a (n+1);
 
    for (ll i = 0; i < e; i++)
    {
        ll u, v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
 
    vector<array<ll, 4>> ans (n+1);
    
    func(1, 1, a, v, ans);
 
    for (ll i = 1; i <= n; i++)
    {
        cout << ans[i][1] << " ";
    }
    cout << "\n";
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