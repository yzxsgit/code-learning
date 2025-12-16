#include <iostream>

using namespace std;
int n, r, x, d;
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        string div;
        scanf("%d%d%d%d", &r, &x, &d, &n);
        cin >> div;
        int res = 0;
        int i = 0;
        while (i < n)
        {
            if(r < x)
            {
                res += n - i;
                break;
            }
            else if(div[i] == '2')
                i++;
            else 
            {
                r = max(r - d, 0);
                res++;
                i++;
            }
        } 
        printf("%d\n", res);
    }

    return 0;
}