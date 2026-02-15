#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <cstring>

using namespace std;
using i64 = long long;
using PII = pair<int,int>;

const int N = 1e5 + 10;

struct Node
{
    int l, r;
    int cnt;
} tr[N * 21];

int root[N], idx;
vector<int> nums;
int a[N];

int find(int x)
{
    return lower_bound(nums.begin(), nums.end(), x) - nums.begin();
}

int build(int l, int r)
{
    int p = ++idx;
    if (l == r) return p;
    int mid = l + r >> 1;
    tr[p].l = build(l, mid);
    tr[p].r = build(mid + 1, r);
    return p;
}

int insert(int p, int l, int r, int x)
{
    int q = ++idx;
    tr[q] = tr[p];
    if (l == r)
    {
        tr[q].cnt++;
        return q;
    }
    int mid = l + r >> 1;
    if (x <= mid)
        tr[q].l = insert(tr[p].l, l, mid, x);
    else
        tr[q].r = insert(tr[p].r, mid + 1, r, x);
    tr[q].cnt = tr[tr[q].l].cnt + tr[tr[q].r].cnt;
    return q;
}

int query(int q, int p, int l, int r, int k)
{
    if (l == r) return r;
    int cnt = tr[tr[q].l].cnt - tr[tr[p].l].cnt;
    int mid = l + r >> 1;
    if (k <= cnt)
        return query(tr[q].l, tr[p].l, l, mid, k);
    else
        return query(tr[q].r, tr[p].r, mid + 1, r, k - cnt);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int n, m;

    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {    
        cin >> a[i];
        nums.push_back(a[i]);
    }

    sort(nums.begin(), nums.end());
    nums.erase(unique(nums.begin(), nums.end()), nums.end());

    root[0] = build(0, nums.size() - 1);

    for (int i = 1; i <= n; i++)
    {
        root[i] = insert(root[i - 1], 0, nums.size() - 1, find(a[i]));
    }

    while (m--)
    {
        int l, r, k;
        cin >> l >> r >> k;
        int res = query(root[r], root[l - 1], 0, nums.size() - 1, k);
        cout << nums[res] << '\n';
    }

    return 0;
}