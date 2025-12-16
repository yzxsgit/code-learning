#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;   
    string a;
    cin >> a;
    bool flag = false;
    for (auto i : a)
    {
        if(i == '|')
            flag = 1-flag;
        
        if(flag && i == '*')
        {
            printf("in");
            return 0;
        }
    }

    printf("out");
    return 0;
}