    #include <iostream>
    #include <cstring>
    #include <stack>
    #include <utility>
    using namespace std;
    const int N = 2e5 + 10;
    bool visited[N];
    int h[N * 2], e[N * 2], ne[N * 2], idx;

    void add(int a,int b)
    {
        e[idx] = b, ne[idx] = h[a], h[a] = idx++;
    }
    int k;

    int iterative_dfs()
    {
        int count = 1;
        if (count >= 1000000)
            return count;

        stack<pair<int, int>> st;
        st.push({1, h[1]});
        visited[1] = true;

        while (!st.empty() && count < 1000000)
        {
            auto [u, i] = st.top();
            st.pop();

            for (; i != -1 && count < 1000000; i = ne[i])
            {
                int v = e[i];
                if (!visited[v])
                {
                    visited[v] = true;
                    count++;
                    if (count >= 1000000)
                        break;

                    st.push({u, ne[i]});
                    st.push({v, h[v]});
                    break;
                }
            }

            if (i == -1)
            {
                visited[u] = false;
            }
        }

        return count;
    }
    int main()
    {
        memset(h, -1, sizeof h);
        int n, m;
        scanf("%d%d", &n, &m);
        for (int i = 0; i < m; i++)
        {
            int a, b;
            scanf("%d%d", &a, &b);
            add(a, b);
            add(b, a);
        }
        cout << iterative_dfs();
        return 0;
    }