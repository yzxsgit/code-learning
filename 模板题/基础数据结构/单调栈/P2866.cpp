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
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    stack<int> stk;

    i64 res = 0;
    for (int i = 1; i <= n; i++)
    {
        while (stk.size() && a[i] >= a[stk.top()])
        {
            res += i - stk.top() - 1;
            stk.pop();
        }

        stk.push(i);
    }

    while (stk.size())
    {
        res += n - stk.top();
        stk.pop();
    }

    cout << res << '\n';

    return 0;
}