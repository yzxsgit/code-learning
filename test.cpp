#include <iostream>
#include <ctime>

using namespace std;


int main()
{
    srand(time(nullptr));
    for (int i = 0; i < 25; i++)
    {
        cout << (char)(rand() % 4 + 'A');
    }
    return 0;
}