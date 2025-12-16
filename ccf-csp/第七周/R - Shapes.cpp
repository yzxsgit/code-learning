#include <iostream>
#include <vector>
#include <string>
using namespace std;

const int N = 210;
char a[N][N], b[N][N], c[N][N];
int n;

// 旋转函数
void rotate_grid(char grid[N][N])
{
    char temp[N][N];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            temp[j][n - 1 - i] = grid[i][j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            grid[i][j] = temp[i][j];
        }
    }
}

// 找到左上角的'#'
pair<int, int> find_left_top(char grid[N][N])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == '#')
            {
                return make_pair(i, j);
            }
        }
    }
    return make_pair(0, 0);
}

// 检查两个图形是否相同
bool check_same(char S[N][N], char T[N][N])
{
    pair<int, int> s_pos = find_left_top(S);
    pair<int, int> t_pos = find_left_top(T);

    int Si = s_pos.first, Sj = s_pos.second;
    int Ti = t_pos.first, Tj = t_pos.second;

    int offset_i = Ti - Si;
    int offset_j = Tj - Sj;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int ii = i + offset_i;
            int jj = j + offset_j;

            if (ii >= 0 && ii < n && jj >= 0 && jj < n)
            {
                if (S[i][j] != T[ii][jj])
                {
                    return false;
                }
            }
            else
            {
                if (S[i][j] == '#')
                {
                    return false;
                }
            }
        }
    }
    return true;
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%s", a[i]);
    }
    for (int i = 0; i < n; i++)
    {
        scanf("%s", c[i]);
    }

    int cntS = 0, cntT = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (a[i][j] == '#')
                cntS++;
            if (c[i][j] == '#')
                cntT++;
        }
    }

    if (cntS != cntT)
    {
        cout << "No" << endl;
        return 0;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            b[i][j] = c[i][j];
        }
    }

    for (int rot_count = 0; rot_count < 4; rot_count++)
    {
        if (check_same(b, a))
        {
            cout << "Yes" << endl;
            return 0;
        }
        rotate_grid(b);
    }

    cout << "No" << endl;
    return 0;
}