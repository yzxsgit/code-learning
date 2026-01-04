#include <iostream>
#include <cstring>
#include <queue>

using namespace std;
const int N = 5e4 + 10, M = 2e5 + 10;

int h[N], ne[M], e[M], w[M], idx;
void add(int a, int b, int c)
{
    e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx++;
}


int main()
{
    
}