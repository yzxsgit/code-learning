#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

const int MAX_A = 200000; // a_i 的最大可能值

vector<int> min_prime; // 存储每个数的最小质因子
vector<int> primes;    // 存储所有质数

// 线性筛法预处理最小质因子
void linear_sieve(int n)
{
    min_prime.resize(n + 1, 0); // 初始化大小为n+1，所有元素初始为0

    for (int i = 2; i <= n; i++)
    {
        if (min_prime[i] == 0)
        {                        // i是质数
            min_prime[i] = i;    // 最小质因子就是自身
            primes.push_back(i); // 加入质数列表
        }

        // 用当前质数 primes[j] 去标记合数
        for (int j = 0; j < primes.size() && primes[j] <= min_prime[i] && i * primes[j] <= n; j++)
        {
            int num = i * primes[j];
            min_prime[num] = primes[j]; 
        }
    }
}

vector<int> get_prime_factors(int x)
{
    vector<int> factors;
    while (x > 1)
    {
        int p = min_prime[x]; 
        factors.push_back(p); 
        while (x % p == 0)
            x /= p;
    }
    return factors;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    linear_sieve(MAX_A);

    int t; 
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        vector<int> b(n); 
        for (int i = 0; i < n; i++)
            cin >> b[i];

        unordered_map<int, vector<int>> prime_to_indices; 
        bool found_pair = false;                         

        for (int i = 0; i < n; i++)
        {
            int x = a[i];
            vector<int> pf = get_prime_factors(x); 

            
            for (int p : pf)
            {
                if (!prime_to_indices[p].empty())
                {
                    found_pair = true; 
                    break;
                }
            }
            if (found_pair)
                break; 


            for (int p : pf)
            {
                prime_to_indices[p].push_back(i);
            }
        }

        if (found_pair)
        {
            cout << "0\n"; 
            continue;
        }

      
        bool has_even = false;
        for (int x : a)
        {
            if (x % 2 == 0)
            {
                has_even = true; 
                break;
            }
        }
        if (has_even)
        {
            cout << "1\n"; 
            continue;
        }

        int min_cost = 2; 
        for (int i = 0; i < n; i++)
        {
            vector<int> pf_plus1 = get_prime_factors(a[i] + 1); 

            for (int p : pf_plus1)
            {
                if (!prime_to_indices[p].empty())
                {
                    for (int idx : prime_to_indices[p])
                    {
                        if (idx != i)
                        {
                            min_cost = 1; 
                            break;
                        }
                    }
                    if (min_cost == 1)
                        break;
                }
            }
            if (min_cost == 1)
                break; 
        }
        cout << min_cost << "\n";
    }

    return 0;
}