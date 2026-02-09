#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

const int N = 100010;
const int M = 200010;

vector<pair<int, int>> adj[N];

int din[N], dout[N];

int cur[N];

bool used[M];

vector<int> path;

int t, n, m;

void dfs(int u) {
    for (int &i = cur[u]; i < adj[u].size(); ) 
    {
        int v = adj[u][i].first;
        int id = adj[u][i].second;
        
        i++;

        if (used[abs(id)]) continue;

        used[abs(id)] = true;

        dfs(v);

        path.push_back(id);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> t >> n >> m;

    for (int i = 1; i <= m; i++) 
    {
        int u, v;
        cin >> u >> v;
        if (t == 1) 
        {
            adj[u].push_back({v, i});
            adj[v].push_back({u, -i}); 
            din[u]++;
            din[v]++;
        } 
        else 
        {
            adj[u].push_back({v, i});
            dout[u]++; 
            din[v]++; 
        }
    }

    if (t == 1) 
    {
        for (int i = 1; i <= n; i++) 
        {
            if (din[i] % 2 != 0) 
            {
                cout << "NO" << "\n";
                return 0;
            }
        }
    } 
    else 
    {
        for (int i = 1; i <= n; i++) 
        {
            if (din[i] != dout[i]) 
            {
                cout << "NO" << "\n";
                return 0;
            }
        }
    }

    int start_node = 1;
    for (int i = 1; i <= n; i++) 
    {
        if (t == 1) 
        {
            if (din[i] > 0) { start_node = i; break; }
        } 
        else 
        {
            if (dout[i] > 0) { start_node = i; break; }
        }
    }

    dfs(start_node);

    if (path.size() != m) 
    {
        cout << "NO" << "\n";
    } 
    else 
    {
        cout << "YES" << "\n";
        reverse(path.begin(), path.end());
        
        for (int i = 0; i < path.size(); i++) 
        {
            cout << path[i] << (i == path.size() - 1 ? "" : " ");
        }
        cout << "\n";
    }

    return 0;
}