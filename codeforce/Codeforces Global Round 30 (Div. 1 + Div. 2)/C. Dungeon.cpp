#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>

using namespace std;

struct Monster
{
    int b, c;
};

int main()
{
    int t;
    scanf("%d", &t);

    while (t--)
    {
        int n, m;
        scanf("%d%d", &n, &m);

        vector<int> swords(n);
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &swords[i]);
        }

        vector<Monster> monsters(m);
        for (int i = 0; i < m; i++)
        {
            scanf("%d", &monsters[i].b);
        }
        for (int i = 0; i < m; i++)
        {
            scanf("%d", &monsters[i].c);
        }

        // 按剑的伤害排序
        sort(swords.begin(), swords.end());

        // 按怪物生命值排序
        sort(monsters.begin(), monsters.end(), [](const Monster &x, const Monster &y)
             { return x.b < y.b; });

        // 使用multiset维护可用剑
        multiset<int> available_swords(swords.begin(), swords.end());

        // 优先队列：存储能获得更好剑的怪物（按c_i降序）
        auto cmp = [](const Monster &a, const Monster &b)
        {
            return a.c < b.c;
        };
        priority_queue<Monster, vector<Monster>, decltype(cmp)> pq(cmp);

        int killed = 0;
        int j = 0; // 指向当前考虑的最小生命值怪物

        // 处理所有怪物
        while (!available_swords.empty())
        {
            // 将所有能被当前最小剑杀死的怪物加入优先队列
            while (j < m && monsters[j].b <= *available_swords.rbegin())
            {
                pq.push(monsters[j]);
                j++;
            }

            if (pq.empty())
                break;

            // 选择能获得最好剑的怪物
            Monster best = pq.top();
            pq.pop();

            // 找到能杀死这个怪物的最小伤害的剑
            auto it = available_swords.lower_bound(best.b);
            if (it != available_swords.end())
            {
                int used_sword = *it;
                available_swords.erase(it);
                killed++;

                // 如果获得新剑，加入可用剑集合
                if (best.c > 0)
                {
                    available_swords.insert(max(used_sword, best.c));
                }
            }
        }

        printf("%d\n", killed);
    }

    return 0;
}