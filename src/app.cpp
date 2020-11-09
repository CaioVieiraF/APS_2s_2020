#include <stdio.h>
#include "sortingAlgorithms.h"

void printList(int list[], int size);
void testeMerge();

int main(){
    testeMerge();

    return(0);
}

void testeMerge(){
    int array[] = {1, 3, 6, 2, 45, 65, 9};

    printList(array, 7);
    mergeSort(array, 0, 7);
    printList(array, 7);
}

void printList(int list[], int size){
    for (int i = 0; i < size; ++i)  {
        printf("list[%i] = %i\n", i, list[i]);
    }
    printf("\n\n");
}
