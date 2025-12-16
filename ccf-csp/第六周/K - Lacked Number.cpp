#include <iostream>

using namespace std;

bool flag[10];
int main()
{
    char a;
    for (int i = 0; i < 9;i++)
    {
        a = getchar();
        flag[a - '0'] = true;
    }

    int ans;
    for (int i = 0; i < 10; i++)
        if(!flag[i])
            ans = i;

    cout << ans;
    return 0;   
}