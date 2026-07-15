#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>


#define PROMPT "Input a string, please: "


int my_strlen(const char *string);
char *my_strdup(const char *string);
char *my_strtok(char *str, const char *sep);
void *my_memcpy(void *dest, const void *src, size_t len);
char *my_strpbrk(const char *str, const char *sym);
void my_strcat(char *string, const char *addition);

void my_strcat(char *string, const char *addition) {
	int s_len = my_strlen(string);
	int a_len = my_strlen(addition);
	
	for (int j = 0; j < a_len; ++j) {
		string[s_len + j] = addition[j];
	}
	string[s_len + a_len] = '\0';
}

int my_strlen(const char *string) {
        if(!string) {return 0;}
        int c = 0;
        while (string[c]) {
        	c += 1;
        }
        return c;
}


char *my_strdup(const char *string) {
    char *result = (char *)calloc(my_strlen(string) + 1, sizeof(char));
    if (!result) {
    	return NULL;
    }
    
	for (int i = 0; i < my_strlen(string) + 1; ++i) {
		result[i] = string[i];
	}
	return result;
}

char *my_strpbrk(const char *str, const char *sym) {
	if(!str || !sym) {return NULL;}
	int len = my_strlen(str);
	int sym_len = my_strlen(sym);
	for (int i = 0; i < len; i ++) {
		for (int j = 0; j < sym_len; j ++) {
			if (str[i] == sym[j]) {return &(((char *)str)[i]);}
		}
	}
	return NULL;
}
char *my_strtok(char *str, const char *sep) {
	if (!sep) {return NULL;}
	static char *prev = NULL;
	
	char *res = NULL; 
	if (str) {
		prev = str;
	}

	if (!prev) {return NULL;}
    while(prev == my_strpbrk(prev, sep)) {
    	prev ++;
    }
    if(prev) {res = prev;}
    else {return NULL;}
    
    prev = my_strpbrk(prev, sep);
    
    if(prev) {
        *prev = '\0';
        prev ++;
    }
    
	return res;
}

void *my_memcpy(void *dest, const void *src, size_t len){
    if(!dest) {return NULL;}
    if(!src) {return NULL;}

    char *a = dest;
    const char *b = src;
    for (size_t i = 0; i < len; ++i) {
    	a[i] = b[i];
    }
	return dest;
}


// int main() {
// 	char *src = readline(PROMPT);
// 	//char *a = my_strpbrk(src, " \t");
// 	//printf("%d\n", my_strlen(a));
//     char *a = my_strtok(src, " \t");
//     while (a != NULL) {
//     	printf("%s\n", a);
//     	a = my_strtok(NULL, " \t");
//     }
// 	free(src);
// 	
// 	return 0;
// }
