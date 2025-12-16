#include <iostream>

using namespace std;
const int N = 2e5 + 10;
long long s[N];
void insert(long long x,int l,int r)
{
    s[l] += x;
    s[r + 1] -= x;
}

int main()
{
    int n;
    long long p, q;
    cin >> n >> p >> q;
    for (int i = 1; i <= n; i++)
    {
        long long score;
        scanf("%lld", &score);
        insert(score, i, i);
    }

    int t;
    cin >> t;
    while (t--)
    {
        int l, r;
        long long val;
        scanf("%d%d%lld", &l, &r, &val);
        insert(val, l, r);
    }
    for (int i = 1; i <= n; i++)
    {
        s[i] += s[i - 1];
        p = max(p, s[i]);
    }

    cout << (p >= q ? "3G win win!" : "3G wanna win win") << endl;

    return 0;
}