#include <iostream>

using namespace std;

int main()
{
    int A,B,C,D,E,F,X;
    cin >> A >> B >> C >> D >> E >> F >> X;

    int num1 = 0, num2 = 0;
    int sum1 = A + C, sum2 = D + F;

    for (int i = 0; i < X; i++)
    {
        if (i % sum1 < A)
            num1 += B;
        if (i % sum2 < D)
            num2 += E;
    }

    if(num1 == num2)
        cout << "Draw";
    else
        cout << (num1 > num2 ? "Takahashi" : "Aoki");

    return 0;
}