#pragma once
#include <stdio.h>
#include <malloc.h>
typedef struct BinNode
{
    int data;

    struct BinNode *left;

    struct BinNode *right;

} BinNode;
BinNode *newnode(int data)
{ //allocates a new node with the given data
    //BinNode * n = (BinNode *)malloc(sizeof(BinNode));
    BinNode *n = (BinNode *)malloc(sizeof(BinNode));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}
void insert(BinNode *root, int key)
{
    if (root == NULL)
    {
        root = newnode(key);
        return;
    }
    BinNode *parent = NULL;
    BinNode *x = root;
    while (x != NULL)
    {
        parent = x;
        if (key <= x->data)
            x = x->left;
        else
            x = x->right;
    }
    if (key <= parent->data) //put in left
        parent->left = newnode(key);
    else
        parent->right = newnode(key);
}
