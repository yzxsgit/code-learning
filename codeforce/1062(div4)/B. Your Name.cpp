#include <iostream>
#include <cstring>

using namespace std;

int a[27],b[27];
int t, n;
int main()
{
    scanf("%d", &t);
    while (t--)
    {
        memset(a, 0, sizeof a);
        memset(b, 0, sizeof b);
        scanf("%d", &n);
        string s1, s2;
        cin >> s1 >> s2;
        for (auto i : s1)
            a[i - 'a']++;
        for (auto i : s2)
            b[i - 'a']++;

        bool flag = true;
        for (int i = 0; i < 26; i++)    
            if(a[i]!=b[i])
                flag = false;

        cout << (flag ? "YES" : "NO") << "\n";
    }

    return 0;
}