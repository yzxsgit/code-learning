#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

vector<int> alls;
int n;
int a[N];

int find(int x)
{
    int l = 0, r = alls.size() - 1;
    while(l < r)
    {
        int mid = l + r >> 1;
        if(alls[mid] >= x)
            r = mid;
        else
            l = mid + 1;
    }

    return l;
}

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        alls.clear();

        for (int i = 0; i < n; i++)
        {
            scanf("%d", &a[i]);
            alls.push_back(a[i]);
        }

        sort(alls.begin(), alls.end());
        alls.erase(unique(alls.begin(), alls.end()), alls.end());

        for (int i = 0; i < n; i++)
        {
            printf("%d ", find(a[i]) + 1);
        }
        puts("");
    }

    return 0;
}