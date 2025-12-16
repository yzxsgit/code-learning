#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 2e5 + 10;
vector<LL> a, b, B;
LL n, m, p;
int main()
{
    LL x;
    scanf("%lld%lld%lld", &n, &m, &p);
    for (int i = 0; i < n; i++)
    {
        scanf("%lld", &x);
        a.push_back(x);
    }
    for (int i = 0; i < m; i++)
    {
        scanf("%lld", &x);
        b.push_back(x);
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    B.push_back(b.front());
    for (auto i = b.begin() + 1; i != b.end(); i++)
        B.push_back(B.back() + *i);

    // for (auto i = B.begin(); i != B.end();i++)
    //     cout<<*i<<endl;

    LL ans = 0;

    for (auto i = a.begin(); i != a.end(); i++)
    {
        auto j = upper_bound(b.begin(), b.end(), p - *i);
        // printf("j:%d\n", j-b.begin());
        if (j <= b.begin())
            ans += m * p;
        else
        {
            ans += (b.end() - j) * p + (*i) * (j - b.begin()) + B[j - b.begin()-1];
        }
        // puts("");
    }
    printf("%lld\n", ans);
    return 0;
}