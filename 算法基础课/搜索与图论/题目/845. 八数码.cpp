#include <bits/stdc++.h>
using namespace std;

int bfs(string start)
{
    int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
    string end = "12345678x";
    queue<string> q;
    q.push(start);
    unordered_map<string, int> d;
    d[start] = 0;

    while (q.size())
    {
        string t = q.front();
        q.pop();

        int distance = d[t];
        if(t == end)
            return distance;

        for (int i = 0; i < 4; i++) 
        {
            int k = t.find('x');
            int x = k / 3 + dx[i], y = k % 3 + dy[i];
            if (x >= 0 && x < 3 && y >= 0 && y < 3)
            {
                swap(t[k], t[x * 3 + y]);
                if(!d.count(t))
                {
                    d[t] = distance + 1;
                    q.push(t);
                }
                swap(t[k], t[x * 3 + y]);
            }
        }
    }

    return -1;
}
int main()
{
    string str = "";
    for (int i = 0; i < 9;i++)
    {
        char a;
        cin >> a;
        str = str + a;
    }

    printf("%d", bfs(str));

    return 0;
}