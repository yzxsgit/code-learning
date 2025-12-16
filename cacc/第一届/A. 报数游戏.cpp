#include <iostream>

using namespace std;

struct LINK
{
    int val;
    LINK *next;
} *head;

int main()
{
    int n, m;
    cin >> n >> m;

    head = new LINK();
    head->val = 1;
    LINK *last = head;

    for (int i = 2; i <= n; i++)
    {
        LINK *p = new LINK();
        p->val = i;
        last->next = p;
        last = p;
    }
    last->next = head;

    LINK *current = head;
    LINK *prev = last;

    while (current->next != current)
    { 
        for (int i = 1; i < m; i++)
        {
            prev = current;
            current = current->next;
        }

        prev->next = current->next;
        LINK *toDelete = current;
        current = current->next;
        delete toDelete;
    }

    cout << current->val << endl;

    delete current;
    return 0;
}