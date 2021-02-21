#include <stdio.h>

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
int main()
{
    listNode *root = newListNode(7);

    root->children = newListNode(5);

    root->children->next = newListNode(9);

    root->children->next->next = newListNode(10);

    root->children->children = newListNode(-4);

    root->children->children->next = newListNode(-7);

    root->children->children->next->next = newListNode(-5);

    root->children->next->children = newListNode(3);

    root->children->next->children->next = newListNode(7);

    root->children->next->children->next->next = newListNode(2);

    root->children->next->next->children = newListNode(19);

    root->children->next->next->children->next = newListNode(14);
    printf("%d + 123456",Max(root));
    return 0;
}