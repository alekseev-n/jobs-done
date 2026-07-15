#include "main.h"
#include "files.h"
#include "../../lib/getters.h"
#include <readline/readline.h>


int dialogs(Voter **people, int *len) {
	menu(1);
	int key = getint(&key, 1, 3);
	switch (key) {
		case 1:
			break;
		case 2:
		    char *f_name = readline("Input file name, please: ");
		    file_read(f_name, people, *len);
			break;
	}
}
