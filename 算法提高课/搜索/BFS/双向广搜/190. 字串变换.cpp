#include <iostream>
#include <queue>
#include <unordered_map>
#include <cstring>

using namespace std;

const int N = 6;
string A, B;
int n;

int extend(queue<string> &q,
           unordered_map<string, int> &da,
           unordered_map<string, int> &db, 
           string a[N], string b[N])
{
    int d = da[q.front()];
    while (q.size() && d == da[q.front()])
    {
        auto t = q.front();
        q.pop();

        for (int i = 0; i < n; i++)
            for (int j = 0; j < t.size(); j++)
                if(t.substr(j , a[i].size()) == a[i])
                {
                    string r = t.substr(0, j) + b[i] + t.substr(j + a[i].size());
                    if(db.count(r))
                        return db[r] + da[t] + 1;
                    if(da.count(r))
                        continue;
                    da[r] = da[t] + 1;
                    q.push(r);
                }
    }

    return 11;
}

string a[N], b[N];

int bfs()
{
    if(A == B)
        return 0;
    queue<string> qa, qb;
    unordered_map<string, int> da, db;

    qa.push(A), qb.push(B);
    da[A] = db[B] = 0;

    int step = 0;
    while (qa.size() && qb.size())
    {
        int t;

        if (qa.size() < qb.size())
            t = extend(qa, da, db, a, b);
        else
            t = extend(qb, db, da, b, a);
        if (t <= 10)
            return t;
        if(++step >= 10)
            return -1;
    }

    return -1;
}

int main()
{
    cin >> A >> B;
    while (cin >> a[n] >> b[n])
        n++;

    int t = bfs();
    if (~t)
        cout << t << "\n";
    else
        cout << "NO ANSWER!\n";

    return 0;
}