#include <iostream>

using namespace std;

const int dx[4] = {0, -1, 0, 1}, dy[4] = {1, 0, -1, 0};
int r, h, c, w;
int main()
{
    cin >> h >> w >> r >> c;

    int ans = 0;
    for (int i = 0; i < 4; i++)
    {
        int x = dx[i] + r, y = dy[i] + c;
        if (x >= 1 && x <= h && y >= 1 && y <= w)
            ans++;
    }

    cout << ans;

    return 0;
}