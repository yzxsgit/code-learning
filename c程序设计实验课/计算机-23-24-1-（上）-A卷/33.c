#include <stdio.h>
#include <string.h>

void Count(int vote[], int count[], int n)
{
    for (int i = 0; i < n; i++)
        count[vote[i]]++;
    return;
}

void Swap(int *a, int *b, int *c, int *d)
{
    int tmp = *b;
    *b = *a;
    *a = tmp;
    tmp = *c;
    *c = *d;
    *d = tmp;
    return;
}

void Sort(int count[], int id[], int n)
{
    for (int i = 1; i <= n; i++)
        for (int j = i + 1; j <= n; j++)
            if(count[i] < count[j])
                Swap(&count[i], &count[j], &id[i], &id[j]);

    return;
}
int main()
{
    printf("请输入150张选票结果：");
    int vote[150];
    int count[11];
    memset(vote, 0, sizeof vote);
    memset(count, 0, sizeof count);
    for (int i = 0; i < 150; i++)
    {
        scanf("%d", &vote[i]);
    }
    
    Count(vote, count, 150);
    int id[11];
    for (int i = 1; i <= 10; i++)
        id[i] = i;

    Sort(count, id, 10);

    printf("前三位的候选人编号及相应票数为： \n");

    for (int i = 1; i <= 3; i++)
        printf("%d 号：%d票\n", id[i], count[i]);

    return 0;
}