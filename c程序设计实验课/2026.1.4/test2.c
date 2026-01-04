#include <stdio.h>
#include <string.h>

typedef struct book
{
    char title[50];
    char status[20];
} BOOK;

void Input(BOOK a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        scanf("%s", a[i].title);
        scanf("%s", a[i].status);
    }
}

void Find(BOOK a[], int n, char p[])
{
    int found = 0;
    for (int i = 0; i < n; i++)
    {
        if (strcmp(a[i].title, p) == 0)
        {
            printf("%s\n", a[i].status);
            found = 1;
            break;
        }
    }
    if (!found)
    {
        printf("不存在！\n");
    }
}

int main()
{
    int n;
    BOOK books[10]; 
    char searchName[50];

    printf("请输入图书数量：\n");
    if (scanf("%d", &n) != 1)
        return 0;

    printf("请输入图书名称和状态：\n");
    Input(books, n);

    printf("请输入待检索图书名称：\n");
    scanf("%s", searchName);

    Find(books, n, searchName);

    return 0;
}