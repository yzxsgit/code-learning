
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int n;
vector<vector<int>> adj;
vector<int> out_degree;
vector<int> path;
vector<bool> visited;
bool found;

void dfs(int u, int count) {
    if (found) return;
    
    path[count - 1] = u; 
    visited[u] = true;

    if (count == n) {
        found = true;
        return;
    }

    vector<int> neighbors;
    neighbors.reserve(adj[u].size());
    for (int v : adj[u]) {
        if (!visited[v]) {
            neighbors.push_back(v);
        }
    }

    sort(neighbors.begin(), neighbors.end(), [&](int a, int b) {
        return out_degree[a] < out_degree[b];
    });

    for (int v : neighbors) {
        dfs(v, count + 1);
        if (found) return;
    }

    visited[u] = false;
}

void solve() {
    if (!(cin >> n)) return;

    adj.assign(n, vector<int>());
    out_degree.assign(n, 0);
    path.assign(n, 0);
    visited.assign(n, false);
    found = false;

    // Read Input
    for (int i = 0; i < n; ++i) {
        string row;
        cin >> row;
        for (int j = 0; j < n; ++j) {
            if (row[j] == '1') {
                adj[i].push_back(j);
                out_degree[i]++;
            }
        }
    }

    int min_deg = n + 1;
    for (int i = 0; i < n; ++i) {
        if (out_degree[i] < min_deg) {
            min_deg = out_degree[i];
        }
    }

    vector<int> start_nodes;
    for (int i = 0; i < n; ++i) {
        if (out_degree[i] == min_deg) {
            start_nodes.push_back(i);
        }
    }

    for (int start_node : start_nodes) {
        fill(visited.begin(), visited.end(), false);
        dfs(start_node, 1);
        if (found) break;
    }

    vector<int> q(n);
    for (int i = 0; i < n; ++i) {
        q[path[i]] = i + 1;
    }

    for (int i = 0; i < n; ++i) {
        cout << q[i] << (i == n - 1 ? "" : " ");
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}