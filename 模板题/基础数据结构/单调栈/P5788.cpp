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

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;

    cin >> n;

    vector<int> a(n + 1);

    stack<int> stk;

    for (int i = 1; i <= n; i++)
        cin >> a[i];

    vector<int> res(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        while (stk.size() && a[i] > a[stk.top()])
        {
            res[stk.top()] = i;
            stk.pop();
        }

        stk.push(i);
    }

    for (int i = 1; i <= n; i++)
        cout << res[i] << ' ';

    return 0;
}