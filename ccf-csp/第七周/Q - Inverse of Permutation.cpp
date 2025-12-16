#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int out[n + 1];
    for (int i = 1; i <= n; i++)
    {
        int idx;
        scanf("%d", &idx);
        out[idx] = i;
    }

    for (int i = 1; i <= n; i++)
        printf("%d ", out[i]);

    return 0;
}
