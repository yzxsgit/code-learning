#include <iostream>
#include <vector>

using namespace std;
const int N = 15;
int f[N][N];

void init()
{
    for (int i = 0; i < N; i++)
        f[1][i] = 1;

    for (int i = 2; i < N; i++)
        for (int j = 0; j <= 9; j++)
            for (int k = j; k <= 9; k++)
                f[i][j] += f[i - 1][k];
}

int dp(int n)
{
    if(!n)
        return 1;

    vector<int> nums;
    while (n)
    {
        nums.push_back(n % 10);
        n /= 10;
    }

    int res = 0;
    int last = 0;
    for (int i = nums.size() - 1; i >= 0; i--)
    {
        int x = nums[i];
        for (int j = last; j < x; j++)
            res += f[i + 1][j];

        if (x < last)
            break;
        last = x;

        if(!i)
            res++;
    }

    return res;
}

int main()
{
    init();

    int a, b;
    while (~scanf("%d %d",&a ,&b))
        cout << dp(b) - dp(a - 1) << endl;

    return 0;
}