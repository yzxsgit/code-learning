#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

const int N = 1e5 + 10;

struct Range
{
    int l, r;
} range[N];

bool cmp(Range a, Range b)
{
    return a.l < b.l;
}

int n;

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d%d", &range[i].l, &range[i].r);

    sort(range, range + n, cmp);

    priority_queue<int, vector<int>, greater<int>> heap;
    heap.push(range[0].r);

    for (int i = 1; i < n; i++)
    {
        Range r = range[i];
        if (heap.top() < r.l)
            heap.pop();
        heap.push(r.r);
    }

    printf("%d\n", heap.size());

    return 0;
}