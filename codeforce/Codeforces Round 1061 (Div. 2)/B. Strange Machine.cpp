#include <iostream>

using namespace std;

int res[20];
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n, q;
        scanf("%d%d", &n, &q);
        string mathine;
        cin >> mathine;
        int cnt = 0, count = 0;
        bool flag = true;
        for (int i = 0; i < n; i++)
        {
            if(mathine[i] == 'B')
            {
                if(count != 0)
                    res[cnt++] = count, count = 0;
                res[cnt++] = -1;
                flag = false;
            }
            else
            {
                count++;
            }
        }
        if (count != 0)
            res[cnt++] = count;
        while (q--)
        {
            int a;
            scanf("%d", &a);

            if (flag)
                printf("%d\n", a);
            else
            {
                int t = 0, out = 0;
                while (a)
                {
                    if(res[t%cnt] == -1)
                    {
                        a /= 2;
                        out++;
                    }
                    else
                    {
                        if(res[t%cnt] < a)
                        {
                            a -= res[t % cnt];
                            out += res[t % cnt];
                        }
                        else
                        {
                            out += a;
                            a = 0;
                        }
                    }
                    t++;
                }
                printf("%d\n", out);
            }
        }
    }
    return 0;
}