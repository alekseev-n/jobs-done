#ifndef FILES_H
#define FILES_H

typedef struct Voter{
	char *fname;
	char *number;
	char *age;
} Voter;

int file_read(char *f_name, Voter **ptr, int *len);

#endif
