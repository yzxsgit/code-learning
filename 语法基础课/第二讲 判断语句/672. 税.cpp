#include <iostream>
using namespace std;
int main() {
	float salary;
	cin>>salary;
	if (salary <= 2000) printf("Isento");
	else if (salary <= 3000) printf("R$ %.2f",(salary-2000)*0.08);
	else if (salary <= 4500) printf("R$ %.2f",(salary-3000)*0.18+80);
	else printf("R$ %.2f",(salary-4500)*0.28+350);
	return 0;
}
