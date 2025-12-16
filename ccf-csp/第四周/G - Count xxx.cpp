#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;
char s[N];
int num[26];
int n;

int main()
{
    cin >> n >> s;

    int res = 1;
    for (int i = 1; i < n; i++)
    {
        if(s[i] == s[i-1])
            res++;
        else
        {
            num[s[i - 1] - 'a'] = max(num[s[i - 1] - 'a'], res);
            res = 1;
        }
    }
    num[s[n - 1] - 'a'] = max(num[s[n - 1] - 'a'], res);

    int ans = 0;
    for (int i = 0; i <= 25; i++)
    {
        ans += num[i];
    }

    printf("%d\n", ans);

    return 0;
}