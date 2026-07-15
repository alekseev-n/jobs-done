#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <time.h>
#include <readline/readline.h>


#include "../../lib/getters.h"


#define DELIM " \t"
#define PROMPT "Input a string, please: "

char *del_by_length(const char *string, int min, int max);

int main() {    
    char *string = readline(PROMPT);
    int min = 0, max = 0;
    printf("Input min length: ");
    int check = getint(&min, 0, INT_MAX);
    if (check == EOF) {free(string); return EOF;}

    printf("Input max length: ");
    check = getint(&max, min, INT_MAX);
    if (check == EOF) {free(string); return EOF;}

    
    while (string != NULL) {
    	printf("Input: %s\n", string);
    	clock_t start = clock();
    	char *result = del_by_length(string, min, max);
    	clock_t end = clock();
    	printf("Result: %s\n", result);
    	printf("Time: %d\n", (int) (end - start));
    	free(string);
    	free(result);
    	string = readline(PROMPT);
    }
    return 0;
}

char *del_by_length(const char *string, int min, int max) {
    char *str = strdup(string);
    int s_len = strlen(str);
	char *res = calloc((s_len + 1), sizeof(char));
	char *word = strtok(str, DELIM);
	int len = 0, w_len = 0;
    
	while (word != NULL) {
		w_len = strlen(word);
		if ((w_len >= min) && (w_len <= max)) {
			memcpy(res + len, word, w_len * sizeof(char));
			len += w_len;
			res[len] = ' ';
			len += 1;
		}
		word = strtok(NULL, DELIM);
	}
	free(str);
	len = (len > 0) ? len - 1 : len;
	res[len] = '\0';
	res = realloc(res, (len + 1) * sizeof(char));
	return res;
}
