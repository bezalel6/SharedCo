#pragma once
#include <stdio.h>
#include <malloc.h>
typedef struct listNode
{
    int key;

    struct listNode *children;

    struct listNode *next;

} listNode;

listNode *newListNode(int key)
{

    listNode *node = (listNode *)malloc(sizeof(listNode));

    node->key = key; //same as above

    node->children = NULL;

    node->next = NULL;

    return node;
}
int Max(listNode *root)
{

    int max = root->key;

    listNode *node = root;

    while (node != NULL)

    {

        if (max < node->key)

            max = node->key;

        int x = max;

        if (node->children != NULL)

            x = Max((*node).children);

        if (max < x)
            max = x;

        node = node->next;
    }

    return max;
}