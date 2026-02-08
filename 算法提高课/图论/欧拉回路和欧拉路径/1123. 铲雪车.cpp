#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <cstring>
#include <cmath>

using namespace std;
using i64 = long long;
using PII = pair<int,int>;

int main()
{

    double x1, x2, y1, y2;
    cin >> x1 >> y1;

    double sum = 0;
    while (cin >> x1 >> y1 >> x2 >> y2)
    {
        double dx = x1 - x2;
        double dy = y1 - y2;
        sum += sqrt(dx * dx + dy * dy) * 2;
    }
    int minutes = round(sum / 1000 / 20 * 60);
    int hours = minutes / 60;
    minutes %= 60;

    printf("%d:%02d\n", hours, minutes);
    
    return 0;
}