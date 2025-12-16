#include <bits/stdc++.h>
using namespace std;
string ans;
int k;
void tto(string s, int d)
{
    if (k == 0)
        return;
    if (!d)
    {
        // printf("%d ", k);
        k--;
        if (k == 0)
            if(s.size() == 1)
                cout << (char)(s[0] + 1) << endl;
            else cout << s << endl;
        return;
    }
    else
    {
        int maxx = 10;
        if (s.size())
            maxx = s[s.size() - 1] - 48;
        for (int i = d - 1; i < maxx; i++)
        {
            tto(s + (char)(i + 48), d - 1);
        }
    }
}
int main()
{
    int a[100] = {0, 9, 45, 120, 210, 252, 210, 120, 45, 10, 1};
    cin >> k;
    int t = 1;
    while (k > a[t])
    {
        k -= a[t];
        t++;
    }
    tto("", t);
    cout << ans << endl;
    return 0;
}
// 0,9,45,120,210,252,210,120,45,10,1
// 9,129,339,591,801,921,966,976,977