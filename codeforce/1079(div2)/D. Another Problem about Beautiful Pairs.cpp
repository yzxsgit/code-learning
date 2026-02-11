#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <cstring>
#include <cmath>

using namespace std;
using i64 = long long;
using PII = pair<int,int>;

const int N = 2e5 + 10;
int a[N];

void solve()
{
    int n;
    cin >> n;
    int limit = sqrt(n);
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    i64 res = 0;
    for (int x = 1; x <= limit; x++)
    {
        for (int j = 1; j <= n; ++j) 
        {
            if (a[j] < x) continue; 
            
            i64 dist = (i64)a[j] * x;
            i64 i_long = j - dist;
            
            if (i_long >= 1 && i_long <= n) 
            {
                if (a[(int)i_long] == x) 
                {
                    res++;
                }
            }
        }

        for (int i = 1; i <= n; ++i) 
        {
            if (a[i] <= x) continue;

            i64 dist = (i64)a[i] * x;
            i64 j_long = i + dist;
            
            if (j_long >= 1 && j_long <= n) 
            {
                if (a[(int)j_long] == x) 
                {
                    res++;
                }
            }
        }
    }

    cout << res << '\n';
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