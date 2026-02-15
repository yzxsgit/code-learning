#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <cstring>

using namespace std;
using i64 = long long;
using PII = pair<int,int>;

struct Node
{
    int ch[2];
    int max_id;
    Node()
    {
        ch[0] = ch[1] = 0;
        max_id = -1;
    }
};

vector<Node> tr;
vector<int> s;
vector<int> root;

void insert(int i, int k, int p, int q)
{
    if (k < 0)
    {
        tr[q].max_id = i;
        return;
    }

    int v = (s[i] >> k) & 1;
    if (p)
    {
        tr[q].ch[v ^ 1] = tr[p].ch[v ^ 1];
    }

    tr[q].ch[v] = tr.size();
    tr.push_back(Node());

    insert(i, k - 1, tr[p].ch[v], tr[q].ch[v]);

    tr[q].max_id = -1;
    if (tr[q].ch[0]) tr[q].max_id = max(tr[q].max_id, tr[tr[q].ch[0]].max_id);
    if (tr[q].ch[1]) tr[q].max_id = max(tr[q].max_id, tr[tr[q].ch[1]].max_id);
}

int query(int root_idx, int C, int L)
{
    int p = root_idx;

    for (int i = 23; i >= 0; i--)
    {
        int v = (C >> i) & 1;
        if (tr[p].ch[v ^ 1] && tr[tr[p].ch[v ^ 1]].max_id >= L) 
        {
            p = tr[p].ch[v ^ 1];
        } 
        else 
        {
            p = tr[p].ch[v]; 
        }
    }

    return C ^ s[tr[p].max_id];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    
    tr.push_back(Node()); 

    int n, m;
    cin >> n >> m;

    s.resize(n + m + 1);
    root.resize(n + m + 1);

    s[0] = 0;
    root[0] = tr.size();
    tr.push_back(Node());
    insert(0, 23, 0, root[0]);

    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        s[i] = s[i - 1] ^ x;
        root[i] = tr.size();
        tr.push_back(Node());
        insert(i, 23, root[i - 1], root[i]);
    }

    while (m--)
    {
        char op[2];
        int l, r, x;
        cin >> op;
        if (*op == 'Q')
        {
            cin >> l >> r >> x;
            cout << query(root[r - 1], s[n] ^ x, l - 1) << '\n';
        }
        else 
        {
            cin >> x;
            n++;
            s[n] = s[n - 1] ^ x;
            root[n] = tr.size();
            tr.push_back(Node());
            insert(n, 23, root[n - 1], root[n]);
        }
    }

    return 0;
}