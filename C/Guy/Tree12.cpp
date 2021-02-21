#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define null NULL

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

int const N = 10;
typedef struct Stack
{
    BinNode *arr[N];
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
void push(Stack &S, BinNode *node)
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
BinNode *stackTop(Stack &S)
{
    if (empty(S))
    {
        printf("Cant return stack top. stack is empty");
        return null;
    }
    return S.arr[S.size];
}
BinNode *pop(Stack &S)
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
BinNode *Delete(Stack &S, BinNode *deleteBin)
{
    Stack D;
    stackInit(D);
    while (stackTop(S) != deleteBin)
    {
        push(D, pop(S));
    }
    BinNode *ret = pop(S);
    while (!empty(D))
    {
        push(S, pop(D));
    }
    return ret;
}
int Search(Stack &S, BinNode *find)
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

int searchX(BinNode *root, int x)
{
    /*זמן ריצה: n/(2^x)=> Ω(logn) במקרה הטוב
    במקרה הרע: O(n) מאחר שיכול להיות לך מצב שהעץ כולו ימין\שמאל ככה שאתה בכל מקרה עובר על כולו
    זמן הריצה הוא אותו דבר גם ברקורסיה. מאחר שבסופו של דבר, 2 הפונקציות עושות את אותה "הדרך" בדרך למספר*/
    int rank = -1;
    BinNode *parent = NULL;
    BinNode *node = root;
    while (node != NULL)
    {
        parent = node;
        if (x <= node->data)
            node = node->left;
        else
            node = node->right;
        rank++;
    }
    if (x == parent->data)
        return rank;
    return -1;
}
int searchXRec(BinNode *root, int x)
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
int sumWithoutRec(BinNode *root)
{
    Stack S;
    stackInit(S);
    BinNode *temp = null;
    if (root == null)
        return 0;

    int sum = 0;

    push(S, root);
    while (!empty(S))
    {
        temp = pop(S);
        sum += temp->data;
        if (temp->left != null)
            push(S, temp->left);
        if (temp->right != null)
            push(S, temp->right);
    }
    return sum;
}
int sumSmallerThanX(BinNode *root, int x)
{
    int sum = 0;
    BinNode *node = root;
    while (node != null)
    {
        while (node != null && node->data <= x)
        {
            if (node->data <= x)
                sum += node->data;

            sum += sumWithoutRec(root->left);
            node = node->right;
        }

        while (root != null && node->data > x)
            node = node->left;
    }
    return sum;
}

int isSearchTree(struct BinNode *node)
{
    //אם זו אופציה, אני מעדיף שהבונוס ילך למגן
    if (node == null)
        return 1;

    if (node->left != null && node->left->data > node->data)
        return 0;

    if (node->right != null && node->right->data < node->data)
        return 0;

    if (!isSearchTree(node->left) || !isSearchTree(node->right))
        return 0;

    return 1;
}

int main()
{
    BinNode *root = newnode(5);
    insert(root, 4);
    insert(root, 14);
    insert(root, 145);
    insert(root, -4);
    printf("%d", searchX(root, 145));
    return 0;
}
