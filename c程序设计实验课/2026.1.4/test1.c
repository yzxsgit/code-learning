#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct grade
{
    int score;
    char ID[6];
    struct grade *next;
};

struct grade *createList()
{
    struct grade *head = NULL, *tail = NULL, *newNode;
    int s;
    char id[6];

    printf("输入学生成绩和ID：\n");
    while (1)
    {

        if (scanf("%d", &s) == 1 && s < 0)
            break;
        scanf(",%s", id);

        newNode = (struct grade *)malloc(sizeof(struct grade));
        newNode->score = s;
        strcpy(newNode->ID, id);
        newNode->next = NULL;

        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }
    return head;
}

void printList(struct grade *head)
{
    struct grade *p = head;
    while (p != NULL)
    {
        printf("%d,%s\n", p->score, p->ID);
        p = p->next;
    }
}

struct grade *insertNode(struct grade *head, int n)
{
    int s;
    char id[6];
    printf("请输入要插入结点的成绩和ID:\n");
    scanf("%d,%s", &s, id);
    printf("请输入要插入结点的位置,在这个位置后面插入新结点：\n");
    int pos;
    scanf("%d", &pos);

    struct grade *p = head;
    int count = 1;

    while (p != NULL && count < pos)
    {
        p = p->next;
        count++;
    }

    if (pos < 0 || (pos > 0 && p == NULL))
    {
        printf("插入的节点不存在！");
    }
    else
    {
        struct grade *newNode = (struct grade *)malloc(sizeof(struct grade));
        newNode->score = s;
        strcpy(newNode->ID, id);

        if (pos == 0)
        { 
            newNode->next = head;
            head = newNode;
        }
        else
        { 
            newNode->next = p->next;
            p->next = newNode;
        }
    }

    printf("插入后的链表：\n");
    printList(head);
    return head;
}

void freeList(struct grade *head)
{
    struct grade *temp;
    while (head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main()
{
    struct grade *head = NULL;

    head = createList();
    printf("创建的链表：\n");
    printList(head);

    head = insertNode(head, 0);

    freeList(head);

    return 0;
}