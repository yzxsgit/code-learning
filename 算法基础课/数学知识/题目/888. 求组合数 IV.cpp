#include <bits/stdc++.h>
using namespace std;
const int N = 5e3 + 10;
int n;
int primes[N], sum[N];
bool st[N];

int get_primes(int x)
{
    int cnt = 0;

    for (int i = 2; i <= x; i++)
    {
        if(!st[i])
            primes[cnt++] = i;
        for (int j = 0; primes[j] <= x / i; j++)
        {
            st[primes[j] * i] = true;
            if (i % primes[j] == 0)
                break;
        }
    }

    return cnt;
}

int get(int x,int p)
{
    int res = 0;
    while (x)
    {
        res += x / p;
        x /= p;
    }

    return res;
}

vector<int> mul(vector<int> a,int b)
{
    vector<int> c;

    for (int i = 0, t = 0; i < a.size() || t; i++)
    {
        if(i < a.size())
            t += a[i] * b;
        c.push_back(t % 10);
        t /= 10;
    }

    while (c.size() > 1 && c.back() == 0)
        c.pop_back();

    return c;
}

int main()
{
    int a, b;
    cin >> a >> b;

    int cnt = get_primes(a);
    for (int i = 0; i < cnt; i++)
    {
        int p = primes[i];
        sum[i] = get(a, p) - get(a - b, p) - get(b, p);
    }

    vector<int> ans;
    ans.push_back(1);

    for (int i = 0; i < cnt; i++)
        for (int j = 0; j < sum[i]; j++)
            ans = mul(ans, primes[i]);

    for (int i = ans.size() - 1;i >= 0; i--)
        printf("%d", ans[i]);

    return 0;
}