#include <iostream>
#include <queue>

using namespace std;

int main()
{
    queue<int> q;
    int n;
    cin >> n;
    int op, x;
    while(n--)
    {
        cin >> op;
        if(op == 1)
        {
            cin >> x;
            q.push(x);
        }
        else if(op == 2)
        {
            if(q.size())
                q.pop();
            else{
                printf("ERR_CANNOT_POP\n");
            }
        }
        else if(op == 3)
        {
            if(q.size())
                printf("%d\n", q.front());
            else
                printf("ERR_CANNOT_QUERY\n");
        }
        else
        {
            printf("%d\n", q.size());
        }
    }
    return 0;
}