#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> a;
int n, t;

int main()
{
    scanf("%d", &t);

    while (t--)
    {
        int x;
        scanf("%d", &n);

        a.clear();
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &x);
            a.push_back(x);
        }

        sort(a.begin(), a.end());
        a.erase(unique(a.begin(), a.end()), a.end());

        printf("%d\n", a.size());
    }

    return 0;
}