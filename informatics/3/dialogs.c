#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "../../lib/arr.h"
#include "../../lib/getters.h"
#include "indiv_task.h"

enum Errors {
	INIT_ERROR = 0,
	MEMO_ERROR = 2,
	IND_ERROR = 3,
};

int menu() {
        printf("Меню: \n\
1. Проинициализировать массив.\n\
2. Вставить элемент в массив.\n\
3. Удалить элемент по индексу.\n\
4. Изменить длину массива.\n\
5. Сформировать новый массив из чисел с заданной суммой цифр, удалив их из старого.\n\
6. Вывести массив.\n\
7. Вывести меню.\n\
8. Завершить работу программы.\n");
}

int InputArrD(int **arr, int *len, int *capacity) {
    
    if (*capacity != 0) {
        printf("Массив уже проинициализирован.");
        return INIT_ERROR;
    }

    int_arr_input(arr, len);
    *len = (*len >= 0) ? *len : 0;
    *capacity = *len;
    return 1;
}

int InsertD(int **arr, int *len, int capacity) {
    if (capacity == *len) {
        printf("Недостаточно памяти. Выделите, пожалуйста, память.\n");
        return MEMO_ERROR;
    }
    
    int new_elem = 0, ind = 0;
    printf("Введите новый элемент: ");
    int check = getint(&new_elem, INT_MIN, INT_MAX);
    if (check == EOF) {
        printf("EOF element\n");
        return EOF;
    }
    
    printf("Введите индекс: ");
    check = getint(&ind, INT_MIN, INT_MAX);
    
    if (check == EOF) {
        printf ("EOF index.\n");
        return EOF;
    }

    ind = ind > *len - 1? *len : ind;
    check = insert(arr, *len, ind, new_elem);
    
    if (check == -1) {
        printf("Wrong index.");
        return IND_ERROR;
    }
    *len += 1;
    
    return 1;
}

int DelD(int **arr, int *len) {
        if (*len == 0) {
        printf("Массив не проинициализирован.\n");
            return INIT_ERROR;
        }
        
        printf("Введите индекс удаляемого элемента: ");
        int ind = 0;
        int check_ind = getint(&ind, 0, *len - 1);
        if (check_ind == EOF) {
            printf("EOF index\n");
            return EOF;
        }

        int check = del_elem(arr, len, ind);
        if (check == -1) {
                printf("Wrong index.");
                return IND_ERROR;
        }
        return 1;
}


int NewArrBySum(int **arr, int *len) {
    printf("Введите требуемую сумму цифр: ");
    int M = 0;
    int check = getint(&M, 0, INT_MAX);
    if (check == EOF) {
    	printf("EOF input. \n");
    	return EOF;
    }

    int *new_arr = (int *) malloc((*len) * sizeof(int));
    if(!new_arr) {
    	printf("Memory allocation error.\n");
    	return MEMO_ERROR;
    }
    
    int new_len = 0;
    check = by_sum(arr, len, &new_arr, &new_len, M);
    if (check != 1) {
    	printf("Memory error.\n");
    	free(new_arr);
    	return MEMO_ERROR;
    }

    if (new_len > 0) {
        new_arr = (int *) realloc(new_arr, new_len * sizeof(int));
    }
    else {
    	free(new_arr);
    	printf("Нет подходящих элементов\n");
    	return 1;
    }

    if (!new_arr) {
    	printf("Memory allocation error");
    	return MEMO_ERROR;
    }
    printf("Новый массив: ");
    print_int_arr(new_arr, new_len);
    printf("Длина нового массива: %d\n", new_len);
    free(new_arr);
    return 1;
}
