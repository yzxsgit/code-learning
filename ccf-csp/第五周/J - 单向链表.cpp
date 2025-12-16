#include <iostream>
using namespace std;

struct Node
{
    int val;
    Node *next;
} *head;

// 在x后面插入y
void add(int x, int y)
{
    Node *p = head;
    while (p != nullptr && p->val != x)
    {
        p = p->next;
    }
    if (p != nullptr)
    {
        Node *q = new Node();
        q->val = y;
        q->next = p->next;
        p->next = q;
    }
}

// 查询x后面的元素
int query(int x)
{
    Node *p = head;
    while (p != nullptr && p->val != x)
    {
        p = p->next;
    }
    if (p != nullptr && p->next != nullptr)
    {
        return p->next->val;
    }
    return 0;
}

// 删除x后面的元素
void cancel(int x)
{
    Node *p = head;
    while (p != nullptr && p->val != x)
    {
        p = p->next;
    }
    if (p != nullptr && p->next != nullptr)
    {
        Node *temp = p->next;
        p->next = temp->next;
        delete temp;
    }
}

int main()
{
    int n;
    scanf("%d", &n);

    // 正确初始化
    head = new Node();
    head->val = 1;
    head->next = nullptr;

    while (n--)
    {
        int op;
        cin >> op;
        if (op == 1)
        {
            int x, y;
            cin >> x >> y;
            add(x, y);
        }
        else if (op == 2)
        {
            int x;
            cin >> x;
            printf("%d\n", query(x));
        }
        else
        {
            int x;
            cin >> x;
            cancel(x);
        }
    }
    return 0;
}