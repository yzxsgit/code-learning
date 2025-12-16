 #include <iostream>

using namespace std;
const int N = 110;
int t;
int a[N];
int main()
{
    scanf("%d", &t);
    while (t--)
    {
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
            scanf("%d", &a[i]);

        int target;
        scanf("%d", &target);
        bool low = false, high = false;

        for (int i = 0; i < n; i++)
        {
            if(a[i] <= target)
                low = true;
            if(a[i] >= target)
                high = true;
        }
        cout << (low && high ? "YES" : "NO") << "\n";
    }
    return 0;
}