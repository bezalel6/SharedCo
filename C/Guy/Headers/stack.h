#pragma once
#include <stdio.h>
#include <malloc.h>
#include "BinNode.h"
#define null NULL
int const N = 10;
typedef struct Stack
{
    binNode *arr[N];
    int size;
}Stack;
void stackInit(Stack &S)
{
    S.size = 0;
}
int empty(Stack &S)
{
    return S.size == 0;
}
void push(Stack &S, binNode *node)
{
    if (S.size == N)
    {
        printf("Stack Full! \n");
    }
    else
    {
        S.arr[S.size] = node;
        S.size++;
    }
}

binNode *stackTop(Stack &S)
{
    if (empty(S))
    {
        printf("Cant return stack top. stack is empty");
        return null;
    }
    return S.arr[S.size];
}
binNode *pop(Stack &S)
{
    if (empty(S))
    {
        printf("Cant return pop. stack is empty");
        return null;
    }
    S.size--;
    return S.arr[S.size];
}
void printStack(Stack &S)
{
    for (int i = 0; i < S.size; i++)
    {
        printf("%i\n", S.arr[i]->data);
    }
}
binNode *Delete(Stack &S, binNode *deleteBin)
{
    Stack D;
    stackInit(D);
    while (stackTop(S) != deleteBin)
    {
        push(D, pop(S));
    }
    binNode *ret = pop(S);
    while (!empty(D))
    {
        push(S, pop(D));
    }
    return ret;
}
int Search(Stack &S, binNode *find)
{
    Stack D;
    stackInit(D);

    int didFind = 0;

    while (!empty(S))
    {
        push(D, pop(S));
    }
    while (!empty(D))
    {
        if (stackTop(D) == find)
            didFind = 1;
        push(S, pop(D));
    }

    return didFind;
}
int searchXRec(binNode *root, int x)
{
    /*זמן ריצה: n/(2^x)=> Ω(logn) במקרה הטוב
    במקרה הרע: O(n) מאחר שיכול להיות לך מצב שהעץ כולו ימין\שמאל ככה שאתה בכל מקרה עובר על כולו*/
    if (root == null)
        return -1;

    int num = 0;
    if (root->data == x)
    {
        return 1;
    }
    if (root->data > x)
        num += searchXRec(root->left, x);
    else
        num += searchXRec(root->right, x);
    if (num > 0)
        num++;
    return num;
}