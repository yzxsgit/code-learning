#include <iostream>

using namespace std;

const int N = 1e6 + 10;

int link[N][2];

int main()
{
    int n;
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
    {
        int a;
        scanf("%d", &a);
        link[i][1] = a;
    }

    int head, idx = 1;
    scanf("%d", &head);

    printf("%d ", head);
    for (int i = head; link[i][1] != 0; i = link[i][1])
    {
        printf("%d ", link[i][1]);
    }

    return 0;
}