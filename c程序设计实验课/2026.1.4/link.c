#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
    int data;          // 数据域
    struct Node *next; // 指针域
} Node;
typedef struct List
{
    Node *head; // 头节点指针
    int length; // 链表长度
} List;
// 创建节点
Node *createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (!newNode)
    {
        printf("内存分配失败\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
// 初始化链表
List *initList()
{
    List *list = (List *)malloc(sizeof(List));
    list->head = NULL;
    list->length = 0;
    return list;
}
// 头插法插入节点
void insertNode(List *list, int data)
{
    Node *newNode = createNode(data);
    newNode->next = list->head;
    list->head = newNode;
    list->length++;
}
// 删除指定值节点
void deleteNode(List *list, int data)
{
    Node *cur = list->head, *prev = NULL;
    while (cur && cur->data != data)
    {
        prev = cur;
        cur = cur->next;
    }
    if (!cur)
        return;
    if (!prev)
        list->head = cur->next;
    else
        prev->next = cur->next;
    free(cur);
    list->length--;
}
// 遍历链表
void traverseList(List *list)
{
    Node *cur = list->head;
    while (cur)
    {
        printf("%d -> ", cur->data);
        cur = cur->next;
    }
    printf("NULL\n");
}
int main()
{
    List *list = initList();
    insertNode(list, 1);
    insertNode(list, 2);
    insertNode(list, 3);
    traverseList(list);
    deleteNode(list, 2);
    traverseList(list);
}