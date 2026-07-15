#include <stdio.h>
#include <math.h>

int getfloat(float *x);
float row2(float x, float eps, int *n);
int count_acc(float eps);

int main() {
	float x = 0.0;
	float eps = 0.0;
	
	printf("Input x value(should be float, no more than 9). Press Enter to continue.");
	float check_x = getfloat(&x);
	if (check_x == -1) {
		printf("Critical error of x variable input.\n");
		return 0;
	}

	printf("Input accuracy.");
	int check_eps = getfloat(&eps);
	if (check_eps == -1) {
		printf("Critical error of accuracy input.\n");
	}

	int n = 0;
	float res = row2(x, eps, &n);
    float ch_res = (x + 1) *expf(- x);
    int acc = count_acc(eps);
    printf("My result: %.*f\nNumber of iterations: %d\nComputer result: %f\n", acc, res, n, ch_res);
    return 0;
}


float row2(float x, float eps, int *n) {
	int i = 4;
	float prev = - x * x / 2;
	float sum = prev;
	float cur = - prev * x * 2 / 3;
	while (fabs(cur - prev) > eps) {
	    sum += cur;
	    prev = cur;
		cur *= - x * (i - 1) / (i * i - 2 * i);
		i += 1;
	}
	*n = i;
	return sum + 1;
}


int getfloat(float *x) {
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

int count_acc(float eps) {
	int n = 0;
	while (eps <= 0.999999) {
		eps*= 10;
		n ++; 
	}
	return n;
}
