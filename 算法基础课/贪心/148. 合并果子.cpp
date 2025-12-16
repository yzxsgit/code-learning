#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int n, a;

int main()
{
    scanf("%d", &n);

    priority_queue<int, vector<int>, greater<int>> heap;

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a);
        heap.push(a);
    }

    int ans = 0;
    while (heap.size() > 1)
    {
        int x = heap.top();
        heap.pop();
        int y = heap.top();
        heap.pop();

        ans += x + y;
        heap.push(x + y);
    }

    printf("%d\n", ans);

    return 0;
}