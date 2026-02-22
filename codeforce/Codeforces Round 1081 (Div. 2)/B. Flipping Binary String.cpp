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
    cin >> n;
    string s;
    cin >> s;

    int cnt_0 = 0, cnt_1 = 0;
    for (char c : s) 
    {
        if (c == '1') cnt_0++;
        else cnt_1++;
    }

    bool can_cnt_0 = (cnt_0 % 2 == 0);
    bool can_cnt_1 = (cnt_1 % 2 != 0);


    if (!can_cnt_0 && !can_cnt_1) 
    {
        cout << -1 << "\n";
        return;
    }

    
    bool use_cnt_0 = false;
    if (can_cnt_0 && can_cnt_1) 
    {
        use_cnt_0 = (cnt_0 < cnt_1);
    } 
    else 
    {
        use_cnt_0 = can_cnt_0;
    }

    if (use_cnt_0) 
    {
        cout << cnt_0 << "\n";
        if (cnt_0 > 0) 
        {
            for (int i = 0; i < n; i++) 
            {
                if (s[i] == '1') cout << i + 1 << " ";
            }
            cout << "\n";
        }
    } 
    else 
    {
        cout << cnt_1 << "\n";
        if (cnt_1 > 0) 
        {
            for (int i = 0; i < n; i++) 
            {
                if (s[i] == '0') cout << i + 1 << " ";
            }
            cout << "\n";
        }
    }
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