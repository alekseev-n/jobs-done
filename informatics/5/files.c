#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "files.h"

#define DELIM " \t"


int file_read(char *f_name, Voter **ptr, int *len) {
	FILE *file = fopen(f_name, "r");
	if (!file) {exit(1);}
	
    *len = 0;
	char str[80];
	int a = fscanf(file, "%80[^\n]s", str);
	while (a != EOF){
		Voter *new = (Voter *) calloc(1, sizeof(Voter));
		new -> fname = strtok(str, DELIM);
		new -> number = strtok(NULL, DELIM);
		new -> age = strtok(NULL, DELIM);
		*len += 1;
		*ptr = (Voter *) realloc(*ptr, *len * sizeof(Voter));
		(*ptr)[*len - 1] = *new;
		fscanf(file, "%*c");
		a = fscanf(file, "%[^\n]s", str);
	}
	return 0;
}


int stream_print(Voter *ptr, int len) {
	for (int i = 0; i < len; ++i) {
	    Voter voter = ptr[i];
		printf("Name: %s\tElectoral presinct number:%s\tAge:%s\n", voter.fname, voter.number, voter.age);
	}
	return 0;
}


int main() {
	Voter *ptr = (Voter *) malloc(sizeof(Voter));
	int len = 0;
	file_read("file.txt", &ptr, &len);
	stream_print(ptr, len);
	return 0;
}
