#include <iostream>

using namespace std;

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int a, b;
        bool flag = true;
        scanf("%d", &a);
        for (int i = 1; i <= 3; i++)
        {
            scanf("%d", &b);
            if (a != b)
                flag = false;
        }
        cout << (flag ? "YES" : "NO") << "\n";
    }

    return 0;
}