#include <iostream>
#include <map>

using namespace std;

typedef long long LL;
LL n, m, ans;
map<LL, int> cnt;
bool dfs(LL l)
{
    if(cnt.find(l) != cnt.end())
    {
        --cnt[l];
        if (cnt[l] < 1)
        {
            cnt.erase(l);
        }
        return true;
    }
    if(l < 2)
        return false;
    return dfs(l / 2) && dfs(l-l/2);
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        LL x;
        scanf("%lld", &x);
        cnt[x]++;
        ans += x;
    }

    if(ans ==n && dfs(n) && cnt.size() == 0)
        printf("misaka\n");
    else
        printf("ham\n");

    return 0;
}