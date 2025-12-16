    #include <iostream>

    using namespace std;
    const int N = 40;
    int path[N];
    bool col[N], dg[N], udg[N];
    int n, cnt;
    void dfs(int u)
    {
        if(u == n)
        {
            if(++cnt <= 3)
            {
                for (int i = 0; i < n; i++)
                    printf("%d ", path[i]);
                printf("\n");
            }
            return;
        }

        for (int i = 0; i < n; i++)
        {
            if (!col[i] && !dg[u + i] && !udg[i + n - u])
            {
                path[u] = i + 1;
                col[i] = dg[u + i] = udg[i + n - u] = true;
                dfs(u + 1);
                col[i] = dg[u + i] = udg[i + n - u] = false;
            }
        }
    }

    int main()
    {
        cin>>n;
        
        dfs(0);

        cout << cnt << endl;
        
        return 0;
    }