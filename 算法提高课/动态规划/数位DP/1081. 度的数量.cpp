#include <iostream>
#include <vector>
#include <cstring>

using namespace std;
const int N = 35;
int f[N][N];

void init()
{
    for (int i = 0; i < N; i++)
        f[i][0] = 1;

    for (int i = 1; i < N; i++)
        for (int j = 1; j <= i; j++)
            f[i][j] = f[i - 1][j] + f[i - 1][j - 1];
}

int x, y, k, b;
int dp(int n)
{
    if(!n)
        return 0;

    vector<int> nums;
    while (n)
    {
        nums.push_back(n % b);
        n /= b;
    }

    int res = 0;
    int last = 0;
    for (int i = nums.size() - 1; i >= 0; i--)
    {
        int x = nums[i];
        if(x)
        {
            res += f[i][k - last];
            if(x > 1)
            {
                if (k - last - 1 >= 0)
                    res += f[i][k - last - 1];
                break;
            }
            else 
            {
                last++;
                if(last > k)
                    break;
            }
        }
        if (!i &&k == last)
            res++;
    }

    return res;
}

int main()
{
    init();

    cin >> x >> y >> k >> b;

    cout << dp(y) - dp(x - 1) << endl;

    return 0;
}