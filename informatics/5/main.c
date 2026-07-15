#include <stdlib.h>
#include <readline/readline.h>
#include <stdio.h>
#include "../../lib/getters.h"
#include "main.h"
#include "dialogs.h"


int main() {
	int exit = 0;
	Voter *ppl = (Voter *) malloc(sizeof(Voter));
	int len = 1;
	if (!ppl) {return 0;}
	
	do {
		dialogs(&ppl, *len);
		for (int i = 0; i < len; ++i) {
			free(*ppl[i]);
		}
		free(ppl);
		
	} while (!exit);
	return 0;
}

int menu(int key) {
    switch (key) {
    	case 1:
    		printf("Каким образом вы хотите ввести массив?\n\
1) Из стандартного потока\n\
2) Из текстового файла\n\
3) Из бинарного файла\n\
Ваш выбор: ");
			break;
		case 3:
			printf("Какую сортировку вы выбираете?\n\
1) Быструю\n\
2) Гномью\n\
3) Выбором\n\
Ваш выбор: ");
			break;
		case 2:
			printf("Каким образом вы хотите вывести массив?\n\
1) На экран \n\
2) В текстовый файл\n\
3) В бинарный файл\n\
Ваш выбор: ");
    }
	return 0;
}
