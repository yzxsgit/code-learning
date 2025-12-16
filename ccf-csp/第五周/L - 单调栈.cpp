#include <iostream>

using namespace std;

const int N = 3e6 + 10;
int n;
int stack[N], top, a[N], ans[N];

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);

    for (int i = 1; i <= n; i++)
    {
        while (top > 0 && a[i] > a[stack[top - 1]])
        {    
            ans[stack[top - 1]] = i;
            top--;
        }
        stack[top++] = i;
    }

    for (int i = 1; i <= n; i++)
        printf("%d ", ans[i]);

    return 0;
}