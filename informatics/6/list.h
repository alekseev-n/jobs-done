#ifndef LIST_H
#define LIST_H


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Item {
        char data;
        struct Item *next;
        struct Item *prev;
} Item;

typedef struct List {
        Item *head;
        Item *tail;
} List;

int push_back(List *list, char data);
int list_input(List *list);
int print_list(List *list);
int free_list(List *list);
List *list_new();
int del_item(List *list, Item *item);


#endif
