#include <iostream>

using namespace std;
const int N = 1e6 + 10;

bool st[N];
int primes[N];
int find_primes(int x)
{
    int cnt = 0;
    for (int i = 2; i <= x; i++)
    {
        if(!st[i])
            primes[cnt++] = i;
        for (int j = 0; primes[j] <= x / i; j++)
        {
            st[primes[j] * i] = true;
            if(i%primes[j] == 0)
                break;
        }
    }
    return cnt;
}

int main()
{
    int len = find_primes(1e6);
    st[1] = true;
    int n;
    scanf("%d", &n);
    while (n--)
    {
        int a;
        bool flag = true;
        scanf("%d", &a);
        while (a)
        {
            if(st[a])
                flag = false;
            a /= 10;
        }
        cout << (flag? "YES" : "NO") << "\n";
    }

    return 0;
}