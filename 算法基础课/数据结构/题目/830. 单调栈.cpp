#include <bits/stdc++.h>

using namespace std;
const int N = 1e6 + 10;
int sta[N];
int tt, n, a;
int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a);
        while (tt > 0 && sta[tt] >= a)
            tt--;
        if (tt)
            printf("%d ", sta[tt]);
        else
            printf("-1 ");
        sta[++tt] = a;
    }
    return 0;
}