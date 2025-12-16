#include <iostream>

using namespace std;

string s;
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n, k;
        scanf("%d%d", &n, &k);
        cin >> s;
        int flag = -1,i = 0;
        int res = 0;
        while (i < n)
        {
            if(s[i] == '1' && i - flag >= k || s[i] == '1' && flag == -1)
            {
                res++;
                flag = i;
            }
            else if(s[i] == '1' && i - flag < k)
                flag = i;
            i++;
        }
        printf("%d\n", res);
    }
    return 0;
}