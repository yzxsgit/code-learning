#include <iostream>
#include <string>
using namespace std;

int main() {
	int n;
	string str1,str2;
	cin>>n;
	while (n--) {
		cin>>str1>>str2;
//		cout<<str1<<" "<<str2<<endl;
		if (str1 == "Hunter") {
			if (str2 == "Gun")
				printf("Player1\n");
			else if (str2 == "Bear")
				printf("Player2\n");
			else
				printf("Tie\n");
			}
		else if (str1 == "Gun") {
			if (str2 == "Gun")
				printf("Tie\n");
			else if (str2 == "Bear")
				printf("Player1\n");
			else
				printf("Player2\n");
			}
		else
			{
			if (str2 == "Gun")
				printf("Player2\n");
			else if (str2 == "Bear")
				printf("Tie\n");
			else
				printf("Player1\n");
			}
	}
	return 0;
} 
