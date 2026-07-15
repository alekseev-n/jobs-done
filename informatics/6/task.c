#include "list.h"
#include <stdio.h>

List *del_symb(List *list);
int cut_spaces(List *list);
int del_part(List *list, int reverse);
int main() {
	List *list = list_new();
	int check = list_input(list);

	while (check != EOF) {
	
		printf("Строка до обработки: ");
		print_list(list);
		
		cut_spaces(list);
        if (list -> head) { list = del_symb(list); cut_spaces(list); }
		printf("Строка после обработки: ");
		print_list(list);
		
		free_list(list);
		list = list_new();
		
		printf("\n\n");
		check = list_input(list);
	}

	free_list(list);
	return 0;
}


List *del_symb(List *list) {
	Item *symb = list -> head;

	do{
		if (symb -> data == '.' && symb != list -> head) {
			symb -> prev -> next = NULL;
			
			del_part(list, 0);
			list -> head = symb;
			symb -> prev = NULL;
			
			break;
		}
		symb = symb -> next;
	} while (symb);

	symb = list -> tail;
	while (symb) {
		if (symb -> data == ';' && symb != list -> tail) {
			symb -> next -> prev = NULL;
			
			del_part(list, 1);
			list ->tail = symb;
			symb -> next = NULL;
			
			break;
		}
		symb = symb -> prev;
	}
	return list;
}


int cut_spaces(List *list) {
    while (list -> head && (list -> head -> data == ' ' || list -> head -> data == '\t')) {
        del_item(list, list -> head);
    }
    while (list -> tail && (list -> tail -> data == ' ' || list -> tail -> data == '\t')) {
        del_item(list, list -> tail);
    }
    if (! list -> head) {return 0;}
    
    Item *symb = list -> head, *nxt = symb -> next;
    while (nxt) {
        if (nxt -> data == '\t') {nxt -> data = ' ';}
    	if (symb -> data == ' ' && nxt -> data == ' ') {
    		del_item(list, nxt); 
    		nxt = symb -> next; 
    		continue;
    	}
    	symb = symb -> next;
    	nxt = symb -> next;
    }
    return 0;
}

int del_part(List *list, int reverse) {
	if (reverse == 0) {
		Item *i = list -> head, *prev;
		while (i) {
			prev = i; 
			i = i -> next;
			free(prev);
		}
		return 0;
	}
	Item *i = list -> tail, *nxt;
	while (i) {
		nxt = i;
		i = i -> prev;
		free(nxt);
	}
	return 0;
}
