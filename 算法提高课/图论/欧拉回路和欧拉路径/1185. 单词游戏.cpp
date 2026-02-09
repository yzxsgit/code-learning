#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <cstring>

using namespace std;
using i64 = long long;
using PII = pair<int,int>;

const int N = 30;

int p[N];
int find(int x)
{
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}

void solve()
{
    int n;
    cin >> n;
    for (int i = 0; i < 26; i++)
        p[i] = i;
    char str[1010];
    vector<int> din(26, 0), dout(26, 0);
    vector<bool> st(26, false);

    for (int i = 0; i < n; i++)
    {
        cin >> str;
        int len = strlen(str);
        int a = *str - 'a', b = *(str + len - 1) - 'a';
        st[a] = st[b] = true;
        dout[a]++, din[b]++;
        p[find(a)] = find(b);
    }
    int start = 0, ed = 0;
    bool has_ans = true;
    for (int i = 0; i < 26; i++)
        if (din[i] != dout[i])
        {
            if (din[i] == dout[i] + 1)
                ed++;
            else if(din[i] + 1 == dout[i])
                start++;
            else 
            {
                has_ans = false;
                break;
            }
        }
    
    if (has_ans && !(!start && !ed || start == 1 && ed == 1))
        has_ans = false;

    int rep = -1;
    for (int i = 0; i < 26; i++)
    {
        if (st[i])
        {
            if (rep == -1) rep = find(i);
            else if (rep != find(i))
            {
                has_ans = false;
                break;
            }
        }
    }

    cout << (has_ans ? "Ordering is possible.\n" : "The door cannot be opened.\n");
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}