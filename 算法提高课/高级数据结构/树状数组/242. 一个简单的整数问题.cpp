#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <cstring>

using namespace std;
using i64 = long long;
using PII = pair<int,int>;

const int N = 1e5 + 10;

int tr[N];
int n, m;

int lowbit(i64 x)
{
    return x & -x;
}

void add(int x, int c)
{
    for (int i = x; i <= n; i += lowbit(i)) tr[i] += c;
}

i64 sum(int x)
{
    i64 res = 0;
    for (int i = x; i; i -= lowbit(i))
        res += tr[i];
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        add(i, x);
        add(i + 1, -x);
    }

    while (m--)
    {
        char op[2];
        cin >> op;
        if (*op == 'Q')
        {
            int target;
            cin >> target;
            cout << sum(target) << '\n';
        }
        else 
        {
            int l, r, d;
            cin >> l >> r >> d;
            add(l, d);
            add(r + 1, -d);
        }
    }

    return 0;
}