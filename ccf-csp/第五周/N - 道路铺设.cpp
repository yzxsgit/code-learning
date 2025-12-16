#include <iostream>

using namespace std;

const int N = 1e6 + 10;

int a[N], stack[N];
int top, ans;
int n;

int main()
{
    scanf("%d",&n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    for (int i = 0; i < n; i++)
    {
        int res = 0;
        if (top == 0)
            ans += a[i];
        else if (a[i] > a[stack[top - 1]])
        {
            ans += a[i] - a[stack[top - 1]];
            while (top != 0 && a[i] > a[stack[top - 1]])
                top--;
        }
        stack[top++] = i;
    }

    printf("%d\n", ans);

    return 0;
}