#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <cstring>

using namespace std;
using i64 = long long;
using PII = pair<int,int>;

const int N = (1 << 16) + 10, inf = 1e7;

struct Node
{
    int l, r;
    int val, key;
} tr[N];

int n;
int root, idx = 0;

int get_node(int key)
{
    tr[++idx].key = key;
    tr[idx].val = rand();
    return idx;
}

void build()
{
    get_node(-inf), get_node(inf);
    root = 1;
    tr[1].r = 2;
}

void zig(int &p) //右旋
{
    int q = tr[p].l;
    tr[p].l = tr[q].r;
    tr[q].r = p;
    p = q;
}

void zag(int &p) //左旋
{
    int q = tr[p].r;
    tr[p].r = tr[q].l;
    tr[q].l = p;
    p = q;
}

void insert(int &p, int key)
{
    if (!p) p = get_node(key);
    else if (tr[p].key == key) return;
    else if (tr[p].key > key)
    {
        insert(tr[p].l, key);
        if (tr[tr[p].l].val > tr[p].val)
            zig(p);
    }
    else 
    {
        insert(tr[p].r, key);
        if (tr[tr[p].r].val > tr[p].val)
            zag(p);
    }
}

int get_prev(int p, int key)
{
    if (!p) return -inf;
    if (tr[p].key > key) return get_prev(tr[p].l, key);
    else return max(tr[p].key, get_prev(tr[p].r, key));
}

int get_next(int p, int key)
{
    if (!p) return inf;
    if (tr[p].key < key) return get_next(tr[p].r, key);
    else return min(tr[p].key, get_next(tr[p].l, key));
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n;
    build();

    i64 res = 0;

    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        if (i == 1) res += x;
        else
        {
            res += min(x - get_prev(root, x), get_next(root, x) - x);
        }
        insert(root, x);
    }

    cout << res << '\n';

    return 0;
}