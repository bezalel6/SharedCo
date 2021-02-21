#pragma once
#include <stdio.h>
#include <malloc.h>
#define null NULL
typedef struct Heap
{
    int size, capacity, *data;
} Heap;

int getParent(int i) { return (i - 1) / 2; }
int getLeft(int parent) { return parent * 2 + 1; }
int getRight(int parent) { return parent * 2 + 2; }

void initHeap(Heap *h)
{
    h->size = h->capacity = 0;
    h->data = (int *)malloc(sizeof(int) * 20);
}
void swap(int *arr, int index1, int index2)
{
    int temp = arr[index1];
    arr[index1] = arr[index2];
    arr[index2] = temp;
}
void heapInsertWithoutSorting(Heap *h, int key)
{
    if (h->size == h->capacity)
    {
        h->capacity += 10;
        h->data = (int *)realloc(h->data, sizeof(int) * h->capacity);
    }
    h->data[h->size] = key;
    h->size++;
}
void heapInsert(Heap *h, int key)
{
    if (h->size == h->capacity)
    {
        h->capacity += 10;
        h->data = (int *)realloc(h->data, sizeof(int) * h->capacity);
    }
    int i = h->size;
    while (i >= 1 & h->data[getParent(i)] < key)
    {
        h->data[i] = h->data[getParent(i)];
        i = getParent(i);
    }
    h->data[i] = key;
    h->size++;
}

void heapifyUp(Heap *h, int i)
{
    while (i && h->data[getParent(i)] < h->data[i])
    {
        swap(h->data, i, getParent(i));
        i = getParent(i);
    }
}
void heapifyDown(Heap *h, int i)
{
    int right = getRight(i), left = getLeft(i), largest = i;
    if (left < h->size && h->data[left] > h->data[largest])
    {
        largest = left;
    }
    if (right < h->size && h->data[right] > h->data[largest])
    {
        largest = right;
    }
    if (largest != i)
    {
        swap(h->data, largest, i);
        heapifyDown(h, largest);
    }
}
void heapifyDownWithoutRec(Heap *h, int i)
{
    int right, left, largest = i;
    do
    {
        right = getRight(i), left = getLeft(i), largest = i;
        if (left < h->size && h->data[right] > h->data[largest])
            largest = left;
        if (right < h->size && h->data[right] > h->data[largest])
            largest = right;
        if (largest != i)
        {
            swap(h->data, largest, i);
        }
    } while (largest != i);
}
void buildHeap(Heap *h)
{
    for (int i = (h->size - 1 - 1) / 2; i >= 0; i--)
        heapifyDown(h, i);
}
void heapSort(Heap *h)
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

void printHeap(Heap *h)
{
    int i;
    putchar('\n');
    for (i = 0; i < h->size; i++)
    {
        printf("%d ", h->data[i]);
    }
    putchar('\n');
}