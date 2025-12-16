#include <bits/stdc++.h>
using namespace std;
int A[110];
int main()
{
    int N, X;
    cin >> N >> X;
    for (int i = 0; i < N - 1; i++)
        cin >> A[i];
    sort(A, A + N - 1);
    int tmp = 0;
    for (int i = 1; i < N - 2; i++)
        tmp += A[i];
    int ans = X - tmp;
    if (ans > A[N - 2])
        printf("-1\n");
    else if(ans <= A[0])
        printf("0\n");
    else 
        printf("%d\n", max(0, ans));
    return 0;
}