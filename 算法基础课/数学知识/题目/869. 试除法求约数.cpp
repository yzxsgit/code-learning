#include <bits/stdc++.h>
using namespace std;
vector<int> divide(int x)
{
    vector<int> tmp;
    for (int i = 1; i <= x / i; i++)
    {
        if (x % i == 0)
        {
            tmp.push_back(i);
            if (i != x / i)
                tmp.push_back(x / i);
        }
    }
    sort(tmp.begin(), tmp.end());

    return tmp;
}
int main()
{
    int n;
    scanf("%d", &n);
    while (n--)
    {
        int a;
        scanf("%d", &a);
        auto b = divide(a);
        for (auto i : b)
            printf("%d ", i);
        printf("\n");
    }

    return 0;
}