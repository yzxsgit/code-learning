#include <bits/stdc++.h>
using namespace std;

vector<int> get_p(const string &s, const string &t, int k, int n)
{
    vector<int> p(n, -1);

    int prev_p = 0;

    for (int j = 0; j < n; ++j)
    {
        int min_p = max(0, j - k);
        min_p = max(min_p, prev_p);
        int max_p = j;

        if (min_p > max_p)
        {
            return {};
        }

        bool found = false;
        for (int pj = min_p; pj <= max_p; ++pj)
        {
            if (s[pj] == t[j])
            {
                p[j] = pj;
                prev_p = pj;
                found = true;
                break;
            }
        }

        if (!found)
        {
            return {};
        }
    }

    for (int j = 0; j < n; ++j)
    {
        if (s[p[j]] != t[j])
        {
            return {};
        }
    }

    return p;
}

vector<string> construct_operations(int k, const string &s, vector<int> p)
{
    vector<string> ops;
    int n = s.size();
    vector<vector<int>> steps(k + 1);
    steps[k] = p;

    for (int step = k - 1; step >= 0; --step)
    {
        vector<int> prev_p(n);
        prev_p[0] = steps[step + 1][0];

        for (int j = 1; j < n; ++j)
        {
            if (steps[step + 1][j] == steps[step + 1][j - 1])
            {
                prev_p[j] = steps[step + 1][j];
            }
            else
            {
                prev_p[j] = steps[step + 1][j];
            }
            prev_p[j] = max(prev_p[j], max(0, j - step));
            prev_p[j] = min(prev_p[j], j);
        }
        steps[step] = prev_p;
    }

    for (int step = 1; step <= k; ++step)
    {
        string current(n, ' ');
        for (int j = 0; j < n; ++j)
        {
            current[j] = s[steps[step][j]];
        }
        ops.push_back(current);
    }

    return ops;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
    {
        int n, k_max;
        cin >> n >> k_max;
        string s, t;
        cin >> s >> t;

        if (s == t)
        {
            cout << "0\n";
            continue;
        }

        int ans_k = -1;
        vector<int> ans_p;

        for (int k = 0; k <= k_max; ++k)
        {
            vector<int> p = get_p(s, t, k, n);
            if (!p.empty())
            {
                ans_k = k;
                ans_p = p;
                break;
            }
        }

        if (ans_k == -1)
        {
            cout << "-1\n";
        }
        else
        {
            vector<string> ops = construct_operations(ans_k, s, ans_p);
            cout << ans_k << "\n";
            for (const string &op : ops)
            {
                cout << op << "\n";
            }
        }
    }

    return 0;
}