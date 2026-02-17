#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <cstring>

using namespace std;
using i64 = long long;
using PII = pair<int,int>;

const int N = 1e5 + 10, inf = 1e8;

struct Node
{
    int l, r;
    int key, val;
    int cnt, size;
} tr[N];

int root, idx = 0;

void pushup(int p)
{
    int l = tr[p].l, r = tr[p].r;
    tr[p].size = tr[l].size + tr[r].size + tr[p].cnt;
}

int get_node(int key)
{
    tr[++idx].key = key;
    tr[idx].val = rand();
    tr[idx].cnt = tr[idx].size = 1;
    return idx;
}

void zig(int &p) //右旋
{
    int q = tr[p].l;
    tr[p].l = tr[q].r;
    tr[q].r = p;
    p = q;
    pushup(tr[p].r), pushup(p);
}

void zag(int &p) //左旋
{
    int q = tr[p].r;
    tr[p].r = tr[q].l;
    tr[q].l = p;
    p = q;
    pushup(tr[p].l), pushup(p);
}

void build()
{
    get_node(-inf), get_node(inf);
    root = 1;
    tr[1].r = 2;
    pushup(root);

    if (tr[1].val < tr[2].val)
        zag(root);
}

void insert(int &p, int key)
{
    if(!p) p = get_node(key);
    else if(tr[p].key == key)
        tr[p].cnt++;
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
    pushup(p);
}

void remove(int &p, int key)
{
    if (!p) return;
    else if (tr[p].key == key)
    {
        if (tr[p].cnt > 1)
            tr[p].cnt--;
        else if (tr[p].l || tr[p].r)
        {
            if (!tr[p].r || tr[tr[p].l].val > tr[tr[p].r].val)
            {
                zig(p);
                remove(tr[p].r, key);
            }
            else 
            {
                zag(p);
                remove(tr[p].l, key);
            }
        }
        else
            p = 0;
    }
    else if(tr[p].key > key)
        remove(tr[p].l, key);
    else
        remove(tr[p].r, key);
    pushup(p);
}

int get_rank_from_key(int p, int key)
{
    if (!p) return 0;
    if (tr[p].key == key) return tr[tr[p].l].size +1;
    if (tr[p].key > key) return get_rank_from_key(tr[p].l, key);
    else return tr[tr[p].l].size + tr[p].cnt + get_rank_from_key(tr[p].r, key);
}

int get_key_from_rank(int p,int rank)
{
    if (!p) return inf;
    if (tr[tr[p].l].size >= rank) return get_key_from_rank(tr[p].l,rank);
    if (tr[tr[p].l].size + tr[p].cnt >= rank) return tr[p].key;
    else return get_key_from_rank(tr[p].r, rank - tr[tr[p].l].size - tr[p].cnt);
}

int get_prev(int p, int key)
{
    if (!p) return -inf;
    if (tr[p].key >= key) return get_prev(tr[p].l, key);
    else return max(tr[p].key, get_prev(tr[p].r, key));
}

int get_next(int p, int key)
{
    if (!p) return inf;
    if (tr[p].key <= key) return get_next(tr[p].r, key);
    else return min(tr[p].key,get_next(tr[p].l, key));
}

int n;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    build();
    cin >> n;

    while (n--)
    {
        int t, x;
        cin >> t >> x;
        switch (t)
        {
            case 1:
                insert(root, x);
                break;
            case 2:
                remove(root, x);
                break;
            case 3:
                cout << get_rank_from_key(root, x) - 1<< '\n';
                break;
            case 4:
                cout << get_key_from_rank(root, x + 1) << '\n';
                break;
            case 5:
                cout << get_prev(root, x) << '\n';
                break;
            case 6:
                cout << get_next(root, x) << '\n';
                break;
            default:
                break;
        }
    }

    return 0;
}