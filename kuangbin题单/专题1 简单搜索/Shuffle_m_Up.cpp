#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <cstring>
#include <map>
#include <set>

using namespace std;
using i64 = long long;
using PII = pair<int, int>;

int C;

string merge(string s1, string s2)
{
    string res = "";
    for (int i = 0; i < C; i++)
    {
        res += s2[i];
        res += s1[i];
    }
    return res;
}

int bfs(string bg, string target)
{
    queue<string> q;
    set<string> st;
    st.insert(bg);
    q.push(bg);

    int res = 1;

    while (q.size())
    {
        string u = q.front();
        q.pop();
        if (u == target)
            return res;

        string v1 = u.substr(0, C), v2 = u.substr(C);

        string v = merge(v1, v2);
        if (!st.count(v))
        {
            st.insert(v);
            q.push(v);
        }
        res++;
    }

    return -1;
}

int solve()
{
    cin >> C;

    string s1, s2;

    cin >> s1 >> s2;

    string targat;

    cin >> targat;

    int res = bfs(merge(s1, s2), targat);

    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    for (int i = 1; i <= T; i++)
    {
        cout << i << ' ' << solve() << '\n';
    }
    return 0;
}