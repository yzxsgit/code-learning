#include <iostream>
#include <cstring>

using namespace std;
bool num[200];
int main()
{
    int t;
    cin >> t;
    string a = "Baidu";
    int b[10];
    for (int i = 0; i <= 4; i++)
        b[i] = a[i];

    while (t--)
    {
        memset(num, false, sizeof num);
        cin >> a;
        if (a.size() == 5)
        {
            bool flag = true;
            for (auto i : a)
                num[i] = true;
            for (int i = 0; i <= 4; i++)
                if (!num[b[i]])
                    flag = false;
            cout << (flag ? "Yes" : "No") << "\n";
        }
        else
            printf("No");
    }

    return 0;
}