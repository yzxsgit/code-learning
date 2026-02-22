#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <cstring>

using namespace std;
using i64 = long long;
using PII = pair<int,int>;

void solve() 
{
    int n;
    i64 h, k;
    cin >> n >> h >> k;
    vector<i64> a(n);
    i64 sum = 0;
    for (int i = 0; i < n; i++) 
    {
        cin >> a[i];
        sum += a[i];
    }
    
    i64 full = h / sum;      
    
    i64 rem = h % sum;       
    
    
    if (rem == 0) 
    {
        cout << full * (n + k) - k << '\n';
        return;
    }
    
    vector<i64> pre(n), minL(n), maxR(n + 1);
    
    pre[0] = a[0];
    minL[0] = a[0];
    for (int i = 1; i < n; i++) 
    {
        pre[i] = pre[i-1] + a[i];
        minL[i] = min(minL[i-1], a[i]);
    }
    
    maxR[n] = 0; 
    for (int i = n-1; i >= 0; i--) 
    {
        maxR[i] = max(maxR[i+1], a[i]);
    }
    
    i64 ans = full * (n + k) + n; 
    
    for (int i = 0; i < n; i++) 
    {
        i64 curSum = pre[i];
        i64 gain = 0;
        if (i + 1 < n) 
        {
            i64 maxRight = maxR[i+1];
            i64 minLeft = minL[i];
            if (maxRight > minLeft) 
            {
                gain = maxRight - minLeft;
            }
        }
        if (curSum + gain >= rem) 
        {
            ans = full * (n + k) + i + 1;
            break;
        }
    }
    
    cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}