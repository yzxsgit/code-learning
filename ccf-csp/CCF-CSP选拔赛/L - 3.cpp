#include <iostream>

using namespace std;

int num[26];
int main()
{
    char a;

    for (int i = 0; i < 3; i++)
        a = getchar(), num[a - 'a']++;
    int res = 0;
    for (int i = 0; i < 26; i++)
        if(num[i] != 0)
            res = max(res, num[i]);

    cout << 3 - res;

    return 0;
}