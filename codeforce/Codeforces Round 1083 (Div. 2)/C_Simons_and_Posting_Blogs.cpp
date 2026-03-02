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

void solve()
{
    int n;
    cin >> n;

    vector<vector<int>> blogs(n);
    vector<int> allUsers; 
    for (int i = 0; i < n; i++)
    {
        int l;
        cin >> l;
        vector<int> a(l);
        for (int j = 0; j < l; j++)
            cin >> a[j];

        set<int> seen;
        for (int j = l - 1; j >= 0; j--)
        {
            if (!seen.count(a[j]))
            {
                blogs[i].push_back(a[j]);
                seen.insert(a[j]);
                allUsers.push_back(a[j]);
            }
        }
    }

    vector<bool> picked(n, false);
    vector<bool> used(1e6 + 1, false);
    for (int step = 0; step < n; step++)
    {
        int best = -1;

        for (int i = 0; i < n; i++)
        {
            if (picked[i])
                continue;
            if (best == -1)
            {
                best = i;
                continue;
            }
            int pi = 0, pb = 0;
            while (true)
            {
                while (pi < (int)blogs[i].size() && used[blogs[i][pi]])
                    pi++;
                while (pb < (int)blogs[best].size() && used[blogs[best][pb]])
                    pb++;

                bool i_done = (pi >= (int)blogs[i].size());
                bool b_done = (pb >= (int)blogs[best].size());

                if (i_done && b_done)
                    break;
                if (i_done)
                {
                    best = i;
                    break;
                }
                if (b_done)
                    break; 

                if (blogs[i][pi] < blogs[best][pb])
                {
                    best = i;
                    break;
                }
                if (blogs[i][pi] > blogs[best][pb])
                    break;
                pi++;
                pb++;
            }
        }

        if (best == -1)
            break;
        picked[best] = true;
        for (auto j : blogs[best])
        {
            if (!used[j])
            {
                cout << j << ' ';
                used[j] = true;
            }
        }
    }
    cout << '\n';
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