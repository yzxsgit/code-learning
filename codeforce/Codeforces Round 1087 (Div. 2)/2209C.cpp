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
    if (!(cin >> n))
        return;

    auto query = [&](int u, int v)
    {
        cout << "? " << u << " " << v << endl; 
        int res;
        cin >> res;
        if (res == -1)
            exit(0); 
        return res;
    };

    if (query(1, 2) == 1)
    {
        cout << "! 1" << endl;
        return;
    }
    if (query(2, 3) == 1)
    {
        cout << "! 2" << endl;
        return;
    }
    if (query(3, 1) == 1)
    {
        cout << "! 3" << endl;
        return;
    }

    for (int i = 4; i <= 2 * n - 1; i += 2)
    {
        if (query(i, i + 1) == 1)
        {
            cout << "! " << i << endl;
            return;
        }
    }

    cout << "! " << 2 * n << endl;
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}