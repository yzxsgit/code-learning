#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <cstring>

using namespace std;
using i64 = long long;
using PII = pair<int,int>;

int primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23};
int n;
int maxd, number;

void dfs(int u, int last, int p, int s)
{
    if (s > maxd || s == maxd && p < number)
    {
        maxd = s;
        number = p;
    }

    if (u == 9)
        return;

    for (int i = 1; i <= last; i++)
    {
        if ((i64) p * primes[u] > n)
            break;
        p *= primes[u];
        dfs(u + 1, i, p, s * (i + 1));
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n;

    dfs(0, 30, 1, 1);

    cout << number << '\n';

    return 0;
}