#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<int> a;
    int n, t;
    scanf("%d", &n);
    while (n--)
        scanf("%d", &t), a.push_back(t);

    sort(a.begin(), a.end());

    a.erase(unique(a.begin(), a.end()), a.end());

    for (int i : a)
        printf("%d ", i);

    return 0;
}