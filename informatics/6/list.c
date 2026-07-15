#include "list.h"


List *list_new() {
	List *list = (List *) calloc(1, sizeof(List));
	if (!list) {return NULL;}
	list -> head = NULL;
	list -> tail = NULL;
	return list;
}

int push_back(List *list, char data) {
	Item *new = (Item *) malloc (sizeof(Item));
	if (!new) {return 0;}
	
	new -> data = data;
	new -> next = NULL;
	new -> prev = NULL;
	
	if (!list -> head) {
		list -> head = new;
		list -> tail = new;
	}
	else{
		list -> tail -> next = new;
		new -> prev = list -> tail;
		list -> tail = new;
	}
	
	return 0;
}

int list_input(List *list) {
    printf("Введите, пожалуйста, строку: ");

	char sym = getchar();
	while (sym != '\n' && sym != EOF){
		push_back(list, sym);
		sym = getchar();
	};
	return sym;
}

int print_list(List *list) {
	Item *sym = list -> head;
	if (!sym) {printf("||Пустая строка||");}
	while (sym) {
		printf("%c", sym -> data);
		sym = sym -> next;
	}
	printf("\n");
	return 0;
}

int free_list(List *list) {
	Item *sym = list -> head, *prev;
	while(sym) {
		prev = sym;
		sym = sym -> next;
		free(prev);
    }
	free(list);
}

int del_item(List *list, Item *item) {
    if (list -> head == list -> tail) {list -> head = NULL; list -> tail = NULL; free(item);}
    
	else if (item == list -> head) {
		list -> head = item -> next;
		list -> head -> prev = NULL;
		free(item);
	}
	else if (item == list -> tail) {
		list -> tail = item -> prev;
		list -> tail -> next = NULL;
		free(item);
	}
	else {
		item -> next -> prev = item -> prev;
		item -> prev -> next = item -> next;
		free(item);
	}
	return 0;
}

// int main() {
// 	List *list = list_new();
// 	list_input(list);
// 	
// 	Item *item = list -> head -> next;
// 	del_item(list, item);
// 	print_list(list);
// 	free_list(list);
// 	return 0;
// }
