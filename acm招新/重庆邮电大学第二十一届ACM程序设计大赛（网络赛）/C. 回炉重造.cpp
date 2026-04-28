#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <cstring>
#include <map>
#include <set>
#include <iomanip>

using namespace std;
using i64 = long long;
using PII = pair<int, int>;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    double a, b, c, d, e, f, g, x, y, z;
    cin >> a >> b >> c >> d >> e >> f >> g >> x >> y >> z;

    double cost = min({x / a, y / b, z / c});
    double num = 1 / g;
    double re = a * d + b * e + c * f;

    double res = cost * (1 - re) * num;

    cout << fixed << setprecision(2) << res << '\n';

    return 0;
}