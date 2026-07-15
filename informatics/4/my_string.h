#ifndef MY_STRING_H
#define MY_STRING_H


int my_strlen(const char *string);
char *my_strdup(const char *string);
char *my_strtok(char *str, const char *sep);
void *my_memcpy(void *dest, const void *src, size_t len);
char *my_strpbrk(const char *str, const char *sym);
void my_strcat(char *string, const char *addition);

#endif
