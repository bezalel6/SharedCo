#include <stdio.h>
#include <malloc.h>
#include "Headers/heap.h"
#define null NULL

int main()
{
    int insertNums1[] = {6, 4, 18, 11, 85}, insertNums2[] = {20, 7, 22, 10, 15, 1, 40, 100};//סתם הכנסתי את המספרים למערכים כדי שיהיה לי נוח להכניס את כולם. במקום להכניס אחד אחד.
    Heap *h;
    initHeap(h);
    int i;
    for (i = 0; i < 5; i++)
    {
        heapInsertWithoutSorting(h,insertNums1[i]);
    }
    printf("b4 build heap:");
    printHeap(h);
    buildHeap(h);
    printf("after build heap:");
    printHeap(h);
    for (i = 0; i < 8; i++)
    {
        heapInsertWithoutSorting(h,insertNums2[i]);
    }
    printf("with insert nums 2: ");
    printHeap(h);
    heapSort(h);
    printf("after heap sort: ");
    printHeap(h);
    
    
    return 0;
}