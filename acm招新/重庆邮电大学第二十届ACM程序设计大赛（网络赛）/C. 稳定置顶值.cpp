#include <iostream>
#include <set>

using namespace std;

struct MMS{
    multiset<int> data;
    multiset<int>::iterator mid;

    void add(int x)
    {
        data.insert(x);
    
        if (data.size() == 1)
        {
            mid = data.begin();
            return;
        }
        if (x < *mid)
        {
            if (data.size() % 2 == 0)
                mid--;    
        }
        else
        {
            if (data.size() % 2 == 1)
                mid++;
        }
    }

    int get_res()
    {
        return *mid;
    }
}q;

int main()
{
    int n;
    scanf("%d", &n);
    while (n--)
    {
        char op[5];
        scanf("%s", op);
        if(op[0] == '+')
        {
            int x;
            scanf("%d", &x);
            q.add(x);
        }
        else
            printf("%d\n", q.get_res());
    }

    return 0;
}