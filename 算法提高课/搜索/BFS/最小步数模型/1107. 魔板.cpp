#include <iostream>
#include <unordered_map>
#include <queue>

using namespace std;

unordered_map<string, string> res;
string start, ed;

string change(string str,int j)
{
    int dx[4][9] = {{7, 6, 5, 4, 3, 2, 1, 0}, {3, 0, 1, 2, 5, 6, 7, 4}, {0, 6, 1, 3, 4, 2, 5, 7}};
    string tmp = "";
    for (int i = 0; i < 8; i++)
        tmp += str[dx[j][i]];
    return tmp;
}

void bfs()
{
    if(start == ed)
        return;

    queue<string> q;
    q.push(start);
    res[start] = "";

    while (q.size())
    {
        auto t = q.front();
        q.pop();
        // cout << t << endl;
        string new_str = "";
        for (int i = 0; i < 3; i++)
        {
            new_str = change(t, i);
            if(!res.count(new_str))
            {
                res[new_str] = res[t] + char('A' + i);
                q.push(new_str);
                if (new_str == ed) return;
            }
        }
    }
}
int main()
{
    int x;
    for (int i = 0; i < 8; i++)
    {
        cin >> x;
        ed += char(x + '0');
    }

    for (int i = 0; i < 8; i++)
        start += char(i + '1');

    bfs();
    if (res.count(ed))
    {
        cout << res[ed].size() << "\n";
        cout << res[ed] << "\n";
    }
    else
        cout << "0\n";
    return 0;
}