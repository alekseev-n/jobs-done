#include <stdio.h>
#include <math.h>

int getint(int *n);
float getfloat(float *x);

float row1(float x, int n);


float main() {
	int n = 0;
	float x = 0.0;
	
	printf("We need to count value of (1 + x) * e ^ (- x) expression.\n");
	printf("First, we need to input n. Press Enter to continue.");
	int check_n = getint(&n);
    if (check_n == -1) {
    	printf("Critical error of n input.\n");
    	return 0;
    }

	printf("Input x value(should be float, no more than 9 as far as we deal with float numbers).\n");
	float check_x = getfloat(&x);
	if(check_x == -1.0) {
		printf("Critical error of x variable input.\n");
		return 0.0;
	}
	
	printf("My result: %.6f\n", row1(x, n));
	float res_comp = (x + 1) * expf(- x);
	printf("Computer result: %6f\n", res_comp);
	return 0;
}


float row1(float x, int n) {
	float prev = - x * x / 2;
	float s = prev;
	for(int i = 3; i <= n; ++i) {
		prev = prev * x * (1 - i) / (i * i - 2 * i);  
		s += prev;                            
	}
	return s + 1;
}


int getint(int *n) {
    int res = 0;
    do {
    	if (res == -1){
    		return -1;
    	}
    	
    	scanf("%*[^\n]");
    	scanf("%*c");
    	printf("Input integer number, please: ");
    	res = scanf("%d", n);	
    } while (res != 1);

    return res;
}


float getfloat(float *x) {
    int res = 0;
    do{
        if(res == -1) {
            return res;
        }
        
        scanf("%*[^\n]");
        scanf("%*c");
        printf("Input float number, please: ");
        res = scanf("%f", x);
    } while (res != 1);

    return res;
}
