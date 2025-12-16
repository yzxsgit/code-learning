#include <iostream>

using namespace std;

int n, m;
char s[1010];

int main()
{
    cin >> n >> m >> s;
    
    int plain, logo, ans;
    
    for (int i = 0; i <= 1000; i++)
    {
        plain = m;
        logo = i;
        bool flag = true;
        for (int j = 0; j < n; j++)
        {
            if (s[j] == '0')
            {
                plain = m;
                logo = i;
            }
            else if (s[j] == '2')
            {
                logo--;
            }
            else
            {
                if (plain > 0)
                    plain--;
                else
                    logo--;
            }
            
            if (logo < 0)
            {
                flag = false;
                break;
            }
        }
        if (flag)
        {
            ans = i;
            break;
        }
    }

    printf("%d\n", ans);

    return 0;
}