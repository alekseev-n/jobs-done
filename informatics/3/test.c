#include <stdio.h>
#include <stdlib.h>

int main(){
	int *a = malloc(sizeof(int));
	free(a);
	if (!a) {
		printf("Not a");
		return 0;
	}
	printf("a");
	return 1;
}
