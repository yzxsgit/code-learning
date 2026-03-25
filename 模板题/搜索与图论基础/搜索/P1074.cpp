#include <iostream>
#include <algorithm>
#include <bitset>

using namespace std;

const int N = 9;
bitset<10> row[N], col[N], box[N];
int g[N][N];
int ans = -1;

inline int get_weight(int i, int j)
{
    return min({i, j, 8 - i, 8 - j}) + 6;
}

void PUT(int val, int i, int j, bool state)
{
    row[i][val] = state;
    col[j][val] = state;
    box[i / 3 * 3 + j / 3][val] = state;
}

void dfs(int score, int cnt)
{
    if (cnt == 0)
    {
        ans = max(ans, score);
        return;
    }

    int min_choices = 11, x = -1, y = -1;
    bitset<10> best_mask;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (g[i][j] == 0)
            {
                bitset<10> mask = row[i] | col[j] | box[i / 3 * 3 + j / 3];
                int choices = 0;
                for (int k = 1; k <= 9; k++)
                    if (!mask[k])
                        choices++;

                if (choices < min_choices)
                {
                    min_choices = choices;
                    x = i;
                    y = j;
                    best_mask = mask;
                    if (choices == 0)
                        return; 
                }
            }
        }
    }

    if (x == -1)
        return;

    for (int i = 1; i <= 9; i++)
    {
        if (!best_mask[i])
        {
            g[x][y] = i;
            PUT(i, x, y, 1);
            dfs(score + get_weight(x, y) * i, cnt - 1);
            PUT(i, x, y, 0);
            g[x][y] = 0;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int empty_cnt = 0, current_score = 0;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> g[i][j];
            if (g[i][j] != 0)
            {
                PUT(g[i][j], i, j, 1);
                current_score += g[i][j] * get_weight(i, j);
            }
            else
            {
                empty_cnt++;
            }
        }
    }

    dfs(current_score, empty_cnt);

    cout << ans << endl;

    return 0;
}