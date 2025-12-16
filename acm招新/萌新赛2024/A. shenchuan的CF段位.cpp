#include <iostream>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    while (n--)
    {
        int rating;
        scanf("%d", &rating);
        if(rating >= 4000)
            printf("Tourist ");
        else if (rating >= 3000)
            printf("Legendary Grandmaster ");
        else if (rating >= 2600)
            printf("International Grandmaster ");
        else if (rating >= 2400)
            printf("Grandmaster ");
        else if (rating >= 2300)
            printf("International Master ");
        else if (rating >= 2100)
            printf("Master ");
        else if (rating >= 1900)
            printf("Candidate Master ");
        else if (rating >= 1600)
            printf("Expert ");
        else if (rating >= 1400)
            printf("Specialist ");
        else if (rating >= 1200)
            printf("Pupil ");
        else
            printf("Newbie ");
        
        if(rating >= 1700)
            printf("Yes\n");
        else
            printf("No\n");
    }

    return 0;
}