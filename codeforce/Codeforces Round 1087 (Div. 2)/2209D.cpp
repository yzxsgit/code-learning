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
using PII = pair<int, int>;
using PIC = pair<int, char>;

bool cmp(PIC a, PIC b)
{
    return a.first > b.first;
}
PIC c[3];

void solve()
{
    cin >> c[0].first >> c[1].first >> c[2].first;
    c[0].second = 'R';
    c[1].second = 'G';
    c[2].second = 'B';

    string res = "";
    int total = c[0].first + c[1].first + c[2].first;
    char last = ' '; 

    for (int i = 0; i < total; i++)
    {
        sort(c, c + 3, cmp);

        bool found = false;
        for (int j = 0; j < 3; j++)
        {
            if (c[j].first > 0 && c[j].second != last)
            {
                res += c[j].second;
                c[j].first--;
                last = c[j].second;
                found = true;
                break;
            }
        }

        if (!found)
        {
            break;
        }
    }

    cout << res << '\n';
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}