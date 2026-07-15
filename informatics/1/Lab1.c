#include <stdio.h>

int oct(int a){
	int res, coun, coef;
	res = 0;
	coun = 1
	koef = 1;
	if(a < 0) {
		a *= -1;
		koef *= -1;
	}
	while(a > 0) {
		int ost = (a % 8) * coun;
		res = ost + res;
		coun *= 10;
		a /= 8;
	}
	return res * koef;
}

int main() {
	int a;
	printf("Input a decimal number you want to make octal: ");
	scanf(" %d", &a);
	a = oct(a);
	printf("Octal variant: %d\n", a);
	return 0;
}
