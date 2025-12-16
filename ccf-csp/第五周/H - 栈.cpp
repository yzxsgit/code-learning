#include <iostream>

using namespace std;

const int N = 1e6 + 10;
long long stack[N];

int main()
{
    int t, n;
    unsigned long long x;
    string op;
    scanf("%d", &t);
    while (t--)
    {
        int top = 0;
        scanf("%d", &n);
        while (n--)
        {
            cin >> op;
            if (op == "push")
            {
                scanf("%lld", &x);
                stack[top++] = x;
            }
            else if (op == "query")
            {
                if (top > 0)
                    printf("%lld\n", stack[top - 1]);
                else
                    printf("Anguei!\n");
            }
            else if (op == "pop")
            {
                if (top > 0)
                    top--;
                else
                    printf("Empty\n");
            }
            else if(op == "size")
            {
                printf("%d\n", top);
            }
        }
    }
    return 0;
}