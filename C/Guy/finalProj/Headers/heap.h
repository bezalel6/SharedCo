#pragma once
#include <stdio.h>
#include <malloc.h>
#include "student.h"
#define ulong unsigned long
#define null NULL
typedef struct
{
    stdAvg *data;
    int size, capacity;
} heapAvg;

int getParent(int i) { return (i - 1) / 2; }
int getLeft(int parent) { return parent * 2 + 1; }
int getRight(int parent) { return parent * 2 + 2; }

void initHeap(heapAvg *h)
{
    h->size = h->capacity = 0;
    h->data = (stdAvg *)malloc(sizeof(stdAvg) * 20);
}
int getIndex(heapAvg *h, stdAvg s)
{
    for (int i = 0; i < h->size; i++)
    {
        if(h->data[i].id==s.id)
        return i;
    }
    ERROR("DIDNT FIND INDEX IN HEAP");
    return -1;
}
void swap(stdAvg *arr, int index1, int index2)
{
    stdAvg temp = arr[index1];
    arr[index1] = arr[index2];
    arr[index2] = temp;
}
int heapInsert(heapAvg *h, stdAvg key)
{
    if (h->size == h->capacity)
    {
        h->capacity += 10;
        h->data = (stdAvg *)realloc(h->data, sizeof(stdAvg) * h->capacity);
    }
    int i = h->size;
    while (i >= 1 & h->data[getParent(i)].avg < key.avg)
    {
        h->data[i] = h->data[getParent(i)];
        i = getParent(i);
    }
    h->data[i] = key;
    h->size++;
    return i;
}

int heapifyUp(heapAvg *h, int i)
{
    while (i && h->data[getParent(i)].avg < h->data[i].avg)
    {
        swap(h->data, i, getParent(i));
        if (i && h->data[getParent(i)].avg < h->data[i].avg)
            i = getParent(i);
        else
            return i;
    }
    return i;
}
int heapifyDown(heapAvg *h, int i)
{
    int right = getRight(i), left = getLeft(i), largest = i;
    if (left < h->size && h->data[left].avg > h->data[largest].avg)
    {
        largest = left;
    }
    if (right < h->size && h->data[right].avg > h->data[largest].avg)
    {
        largest = right;
    }
    if (largest != i)
    {
        swap(h->data, largest, i);
        heapifyDown(h, largest);
    }
    return i;
}
void buildHeap(heapAvg *h)
{
    for (int i = (h->size - 1 - 1) / 2; i >= 0; i--)
        heapifyDown(h, i);
}
void heapSort(heapAvg *h)
{
    buildHeap(h);
    int i, size = h->size;
    for (i = h->size - 1; i >= 1; i--)
    {
        swap(h->data, 0, i);
        h->size--;
        heapifyDown(h, 0);
    }
    h->size = size;
}


void printHeap(heapAvg *h)
{
    int i;
    putchar('\n');
    for (i = 0; i < h->size; i++)
    {
        printf("avg = %lf, id = %lu\n", h->data[i].avg, h->data[i].id);
    }
    putchar('\n');
}
void heapInsertWithoutSorting(heapAvg *h, stdAvg key)
{
    if (h->size == h->capacity)
    {
        h->capacity += 10;
        h->data = (stdAvg *)realloc(h->data, sizeof(int) * h->capacity);
    }
    h->data[h->size] = key;
    h->size++;
}