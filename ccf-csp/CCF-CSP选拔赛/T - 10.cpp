#include <iostream>

using namespace std;
const int N = 1e5 + 10;
bool count[N],flag[N];
int n;
int a[N];
int main()
{
    int res = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
        if(a[i] <= n && !count[a[i]])
        {
            count[a[i]] = true;
            flag[i] = true;
            res++;
        }
    }
    cout << n - res << endl;
    int idx = 1;
    for (int i = 1; i <= n; i++)
        if (!flag[i])
        {
            while (count[idx])
                idx++;
            count[idx] = true;
            printf("%d %d\n", i, idx);
        }

    return 0;
}