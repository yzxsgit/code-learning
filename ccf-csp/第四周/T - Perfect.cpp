#include<bits/stdc++.h>
using namespace std;

int num[11];
int main()
{
    vector<int> finish;
    int n,m,k;
    cin >> n >> m >> k;
    while (k--)
    {
        int a, b;
        cin>>a>>b;
        num[a]++;
        if(num[a] == m)
            finish.push_back(a);
    }

    for (auto i: finish)
        printf("%d ", i);

    return 0;
}