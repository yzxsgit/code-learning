#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <cstring>

using namespace std;
using i64 = long long;
using PII = pair<int,int>;

int exgcd(int a, int b, int &x, int &y)
{
    if (!b)
    {
        x = 1, y = 0;
        return a;
    }

    int d = exgcd(b, a % b, y, x);
    y = y - a / b * x;

    return d;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int a, b;
    cin >> a >> b;

    int x0, y0;
    exgcd(a, b, x0, y0);

    cout << (x0 % b + (i64)b) % b << '\n';

    return 0;
}