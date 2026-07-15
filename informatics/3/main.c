#include <stdio.h>
#include <stdlib.h>
#include "../../lib/getters.h"
#include "../../lib/arr.h"
#include "dialogs.h"

int main() {
    
	int *arr;
	int len = 0, capacity = 0;

	menu();
	int p = 0, p_check = 0;
	do {

	    printf("\n\n");

	    printf("Введите пункт меню: ");
	    p_check = getint(&p, 1, 8);
	    if (p_check == EOF) {
	    	continue;
	    }

    	switch (p) {
    		case 1:
    		    InputArrD(&arr, &len, &capacity);
    		    break;
    	    case 2: 
    	        InsertD(&arr, &len, capacity);
    	        break;
    	    case 3:
    	        DelD(&arr, &len);
    	        break;
    	    case 4:
    	        ChangeCapacity(&arr, &capacity, &len);
    	        break;
    	    case 5:
    	        NewArrBySum(&arr, &len);
    	        break;
    	    case 6:
    	        break;
    	    case 7:
    	        menu();
    	        break;
    	    case 8:
    	        break;
    	    default:
    	        printf("Нет такого варианта.\n");
    	        

    	        
    	}
        printf("\nArray:");
    	print_int_arr(arr, len);
    	printf("Length: %d; capacity: %d\n", len, capacity);
	} while (p_check != EOF && p != 8);


	
	if(capacity > 0) {
	free(arr);
	}
}
