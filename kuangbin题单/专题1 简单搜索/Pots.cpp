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

struct PIII
{
    int a, b, idx, pre, d, op;
};

const int N = 1e4 + 10, M = 110;

int A, B, C;

PIII q[N];
bool st[M][M];

int bfs()
{
    int head = 0, tail = -1;
    q[++tail] = {0, 0, 0, -1, 0, 0};

    st[0][0] = true;

    while (head <= tail)
    {
        PIII u = q[head++];

        if (u.a == C || u.b == C)
        {
            return u.idx;
        }

        PIII v = u;
        auto push = [&](int op)
        {
            if (!st[v.a][v.b])
            {
                v.idx = tail + 1;
                v.pre = u.idx;
                v.d = u.d + 1;
                v.op = op;
                q[++tail] = v;
                st[v.a][v.b] = true;
            }
        };
        {
            v = u;
            v.a = A;
            push(1);

            v = u;
            v.b = B;
            push(2);

            v = u;
            v.a = 0;
            push(3);

            v = u;
            v.b = 0;
            push(4);

            v = u;
            if (v.a + v.b <= B)
            {
                v.b += v.a;
                v.a = 0;
            }
            else
            {
                v.a = v.a + v.b - B;
                v.b = B;
            }
            push(5);

            v = u;
            if (v.a + v.b <= A)
            {
                v.a += v.b;
                v.b = 0;
            }
            else
            {
                v.b = v.a + v.b - A;
                v.a = A;
            }
            push(6);
        }
    }

    return -1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> A >> B >> C;

    int res = bfs();
    if (res == -1)
    {
        cout << "impossible\n";
    }
    else
    {
        cout << q[res].d << '\n';

        vector<int> path;
        while (res != 0)
        {
            path.push_back(q[res].op);
            res = q[res].pre;
        }
        reverse(path.begin(), path.end());

        for (int op : path)
        {
            if (op == 1)
                cout << "FILL(1)\n";
            else if (op == 2)
                cout << "FILL(2)\n";
            else if (op == 3)
                cout << "DROP(1)\n";
            else if (op == 4)
                cout << "DROP(2)\n";
            else if (op == 5)
                cout << "POUR(1,2)\n";
            else if (op == 6)
                cout << "POUR(2,1)\n";
        }
    }

    return 0;
}