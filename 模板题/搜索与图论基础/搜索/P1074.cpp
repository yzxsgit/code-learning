#include <iostream>
#include <algorithm>

using namespace std;

int g[10][10], score[10][10];
int row[10], col[10], cell[10]; // 位运算标记：1表示可用，0表示已用
int ones[1 << 9], map[1 << 9];  // ones存位数，map存2的幂次对应的数字
int cnt, max_ans = -1;

// 预处理每个位置的分值权重
void init_score() {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            int r = i + 1, c = j + 1;
            score[i][j] = min({r, c, 10 - r, 10 - c}) + 5;
        }
    }
    for (int i = 0; i < 9; i++) map[1 << i] = i + 1;
    for (int i = 0; i < (1 << 9); i++) {
        for (int j = 0; j < 9; j++) if (i >> j & 1) ones[i]++;
    }
}

// 获取(x, y)可填数字的并集状态
inline int get(int x, int y) {
    return row[x] & col[y] & cell[x / 3 * 3 + y / 3];
}

void dfs(int total_score, int k) {
    if (k == 0) {
        max_ans = max(max_ans, total_score);
        return;
    }

    // 策略：找到当前可填选项最少的格子 (Heuristic Search)
    int min_choices = 10;
    int x, y;
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (!g[i][j]) {
                int state = get(i, j);
                if (ones[state] < min_choices) {
                    min_choices = ones[state];
                    x = i, y = j;
                }
            }
        }
    }

    if (min_choices == 0) return; // 无路可走

    int state = get(x, y);
    for (int i = state; i; i -= i & -i) {
        int t = i & -i;
        int num = map[t];
        
        // 修改状态
        g[x][y] = num;
        row[x] ^= t; col[y] ^= t; cell[x / 3 * 3 + y / 3] ^= t;
        
        dfs(total_score + num * score[x][y], k - 1);
        
        // 回溯
        g[x][y] = 0;
        row[x] ^= t; col[y] ^= t; cell[x / 3 * 3 + y / 3] ^= t;
    }
}

int main() {
    init_score();
    for (int i = 0; i < 9; i++) row[i] = col[i] = cell[i] = (1 << 9) - 1;

    int initial_score = 0;
    cnt = 0;
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            int x; cin >> x;
            if (x != 0) {
                int t = 1 << (x - 1);
                g[i][j] = x;
                row[i] ^= t; col[j] ^= t; cell[i / 3 * 3 + j / 3] ^= t;
                initial_score += x * score[i][j];
            } else {
                cnt++; // 记录空格子数量
            }
        }
    }

    dfs(initial_score, cnt);
    cout << max_ans << endl;

    return 0;
}