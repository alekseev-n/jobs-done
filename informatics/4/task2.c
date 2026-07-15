#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>
#include "./my_string.h"
#include "../../lib/readline.h"

#include "../../lib/getters.h"


#define DELIM " \t"
#define PROMPT "Input a string, please: "

char *del_by_length(const char *string, int min, int max);

int main() {    
    int min = 0, max = 0;
    printf("Input min length: ");
    int check = getint(&min, 0, INT_MAX);
    if (check == EOF) {return EOF;}

    printf("Input max length: ");
    check = getint(&max, min, INT_MAX);
    if (check == EOF) {return EOF;}
    scanf("%*c");

    char *string = my_readline(PROMPT);
    if (string == NULL) {free(string); return EOF;}
    while (string != NULL) {
        if(!string) {continue;}

        printf("Input: %s\n", string);
        clock_t start = clock();
    	char *result = del_by_length(string, min, max);
    	clock_t end = clock();
    	
    	printf("Result: %s\n", result);
        printf("Time: %F\n\n\n", (double) (end - start));
    	free(string);
    	free(result);
    	
    	string = my_readline(PROMPT);
    }
    return 0;
}

char *del_by_length(const char *string, int min, int max) {
    char *str = my_strdup(string);
    int s_len = my_strlen(str);
	char *res = calloc((s_len + 1), sizeof(char));
	char *word = my_strtok(str, DELIM);
	int len = 0, w_len = 0;

	while (word != NULL) {
		w_len = my_strlen(word);
		if ((w_len >= min) && (w_len <= max)) {
			my_memcpy(res + len, word, w_len * sizeof(char));
			len += w_len;
			res[len] = ' ';
			len += 1;
		}
		word = my_strtok(NULL, DELIM);
	}
	
	free(str);
	len = (len > 0) ? len - 1 : len;
	res[len] = '\0';
	res = realloc(res, (len + 1) * sizeof(char));
	return res;
}
