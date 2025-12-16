#include <iostream>
#include <vector>

using namespace std;
const int N = 5e5 + 10;
long long s[N];
long long a[N];
int n, q;

int main()
{
    cin >> n >> q;
    while (q--)
    {
        int op;
        scanf("%d", &op);
        if(!op)
        {
            int st, end, o, y;
            scanf("%d%d%d%lld", &st, &end, &o, &y);
            for (int i = st; i <= end; i++)
                if (a[i] % 2 == o)
                    a[i] += y;
            for (int i = 1; i <= n; i++)
                s[i] = s[i - 1] + a[i];
        }
        else 
        {
            int st, end;
            scanf("%d%d", &st, &end);
            printf("%lld\n", s[end] - s[st - 1]);
        }
    }

    return 0;
}