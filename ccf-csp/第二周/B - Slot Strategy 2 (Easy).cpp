#include <bits/stdc++.h>
using namespace std;
int n;
string s[3];
vector<int> find(char c, int l)
{
    vector<int> a;
    for (int i = 0; i < n; i++)
        if (c == s[l][i])
        {
            a.push_back(i);
            a.push_back(i + n);
            a.push_back(i + n * 2);
        }
    return a;
}
int main()
{
    cin >> n;
    for (int i = 0; i < 3; i++)
        cin >> s[i];

    int minn = 0x3f3f3f3f;

    for (int t = 0; t < 10; t++)
    {
        vector<int> x1 = find(t + 48, 0);
        vector<int> x2 = find(t + 48, 1);
        vector<int> x3 = find(t + 48, 2);
        for (auto i : x1)
            for (auto j : x2)
                for (auto k : x3)
                    if (i != j && k != j && i != k)
                    {
                        minn = min(minn, max(i, max(j, k)));
                    }
    }
    if (minn == 0x3f3f3f3f)
        printf("-1");
    else
        printf("%d", minn);
    return 0;
}