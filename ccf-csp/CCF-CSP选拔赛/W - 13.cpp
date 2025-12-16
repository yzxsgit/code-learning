#include <iostream>
#include <math.h>
#define M_PI  3.14159265358979323846
using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;
    a += b;
    double res = double(a * a * M_PI);
    printf("%.10f", res);

    return 0;
}