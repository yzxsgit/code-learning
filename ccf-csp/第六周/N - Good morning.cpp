#include <iostream>

using namespace std;

int main()
{
    int A, B, C, D;
    cin >> A >> B >> C >> D;

    if(A != C)
        cout << (A < C ? "Takahashi" : "Aoki");
    else{
        cout << (B <= D ? "Takahashi" : "Aoki");
    }

    return 0;
}