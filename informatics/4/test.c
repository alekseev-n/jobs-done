#include <stdio.h>
#include <stdlib.h>
#include "my_string.h"
#include <readline/readline.h>

#define PROMPT "input a string, please: "
#define DELIM " \t"

int main() {
    char *a = readline (PROMPT);
    char *word = my_strtok(a, DELIM);
    while (word) {
    	int w_len = my_strlen(word);
    	printf("len: %d\n%s\n", w_len, word);
    	word = my_strtok(NULL, DELIM);
    }
    return 0;
}
