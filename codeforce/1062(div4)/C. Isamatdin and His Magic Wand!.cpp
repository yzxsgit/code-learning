#include <iostream>
#include <algorithm>

using namespace std;
const int N = 2e5 + 10;

int a[N];
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n;
        scanf("%d", &n);
        bool has_odd = false, has_even = false;
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &a[i]);
            if(a[i] % 2)
                has_odd = true;
            else
                has_even = true;
        }

        if(has_odd && has_even)
            sort(a, a + n);
            
        for (int i = 0; i < n; i++)
            printf("%d ", a[i]);

        puts("");
    }

    return 0;
}