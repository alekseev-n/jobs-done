#ifndef DIALOGS_H
#define DIALOGS_H

int InputArrD(int **arr, int *len, int *capacity);  
int InsertD(int **arr, int *len, int capacity);
int DelD(int **arr, int *len);                                                       
int ChangeCapacity(int **arr, int *capacity, int *len);
int NewArrBySum(int **arr, int *len);
int menu();

#endif
