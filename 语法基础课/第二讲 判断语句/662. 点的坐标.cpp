#include <iostream>
using namespace std;
int main() {
    float x,y;
    cin>>x>>y;
    if (x == 0 && y == 0)
    	printf("Origem");
    else 
		if (x>0)
    		if (y == 0)
    			printf("Eixo X");
    		else if(y<0)
    			printf("Q4");
    		else
    			printf("Q1");
    	else if (x == 0)
    		printf("Eixo Y");
    	else
    		if (y == 0)
    			printf("Eixo X");
    		else if (y>0)
    			printf("Q2");
    		else 
    			printf("Q3");
    return 0;
}
