#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

deque<int> fuck;

int main()
{
    int n, m ,x;
    scanf("%d%d", &n, &m);
    while (m--)
    {
        int op;
        scanf("%d",&op);
        if(op == 1)
        {
            scanf("%d", &x);
            fuck.push_front(x);
        }
        if(op == 2)
            fuck.pop_front();
        if(op == 3)
        {
            scanf("%d", &x);
            fuck.push_back(x);
        }
        if(op == 4)
            fuck.pop_back();
        if(op == 5)
        {
            reverse(fuck.begin(), fuck.end());
        }
        if(op == 6)
        {
            printf("%d\n", fuck.size());
            for (auto i:fuck)
                printf("%d ", i);
            puts("");
        }
        if(op == 7)
            sort(fuck.begin(), fuck.end());
    }

    return 0;
}