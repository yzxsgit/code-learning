#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <cstring>
#include <map>
#include <set>

using namespace std;
using i64 = long long;
using PII = pair<int,int>;

void solve()
{
    int n;
    cin >> n;
    string x;
    cin >> x;
    
    bool res = true;
    int start = 0;
    
    if (n % 2 != 0) 
    {
        if (x[0] == 'b') 
        {
            res = false;
        }
        start = 1;
    }
    
    for (int i = start; i < n; i += 2) 
    {
        if (x[i] == 'a' && x[i+1] == 'a') 
        {
            res = false;
            break;
        }
        if (x[i] == 'b' && x[i+1] == 'b') 
        {
            res = false;
            break;
        }
    }

    cout << (res ? "YES\n" : "NO\n");
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