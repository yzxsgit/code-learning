#include <iostream>

using namespace std;
const int N = 210;
int ans, n, k;

void dfs(int d,int sum, int num)
{
    if(d >= k)
    {
        if(sum == n)
            ans++;
        return;
    }

    for (int i = num; sum + i * (k - d) <= n; i++)
        dfs(d + 1, sum + i, i);
}
int main()
{
    cin >> n >> k;
    dfs(0, 0, 1);
    cout << ans << endl;
    return 0;
}