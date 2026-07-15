#include <stdio.h>

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
    
    int check = scanf("%*c");
    if (check != 0) {
        return -1.0;
    }
    return check;
}

void main() {
    int a = 0;
    char ch;
	int b = scanf("%c", &ch);
	int d = ch != '\n';
	printf("%d\n%d\n", b, d);
}
