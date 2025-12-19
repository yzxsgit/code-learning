#include <iostream>
#include <queue>
#include <cstring>
#include <unordered_map>
#include <algorithm>

using namespace std;
const char op[] = {'u', 'd', 'l', 'r'};
const int dx[] = {-1, 1, 0, 0},
          dy[] = {0, 0, -1, 1};
typedef pair<int, string> PIS;

int f(string state)
{
    int res = 0;
    for (int i = 0; i < 9; i++)
        if(state[i] != 'x')
        {
            int t = state[i] - '1';
            res += abs(i / 3 - t / 3) + abs(i % 3 - t % 3);
        }

    return res;
}

string bfs(string start)
{
    string ed = "12345678x";

    unordered_map<string, int> dist;
    unordered_map<string, pair<string,char>> prev;
    priority_queue<PIS, vector<PIS>, greater<PIS>> heap;

    heap.push({f(start), start});
    dist[start] = 0;

    while (!heap.empty())
    {
        auto t = heap.top();
        heap.pop();

        string state = t.second;
        if(state == ed)
            break;

        int x, y;
        for (int i = 0; i < 9; i++)
            if (state[i] == 'x')
            {
                x = i / 3;
                y = i % 3;
                break;
            }
        
        string source = state;
        int d = dist[source];
       
        for (int i = 0; i < 4; i++)
        {
            int a = x + dx[i], b = y + dy[i];
            if (a < 0 || a > 2 || b < 0 || b > 2)
                continue;
            swap(state[x * 3 + y], state[a * 3 + b]);

            if(!dist.count(state) || dist[state] > d + 1)
            {
                dist[state] = d + 1;
                prev[state] = {source,op[i]};
                heap.push({f(state) + d + 1, state});
            }
            
            swap(state[x * 3 + y], state[a * 3 + b]);
        }
    }

    string res;
    while (ed != start)
    {
        res += prev[ed].second;
        ed = prev[ed].first;
    }

    reverse(res.begin(), res.end());

    return res;
}

int main()
{
    string start, seq;
    char c;
    while (cin >> c)
    {
        start += c;
        if(c != 'x')
            seq += c;
    }

    int cnt = 0;
    for (int i = 0; i < 8; i++)
        for (int j = i + 1; j < 8;j++)
            if(seq[i] > seq[j])
                cnt++;

    if (cnt & 1)
        cout << "unsolvable\n";
    else
        cout << bfs(start) << "\n";

    return 0;
}