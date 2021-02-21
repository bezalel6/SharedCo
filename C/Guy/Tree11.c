#include <stdio.h>
#include <malloc.h>
#define null NULL

typedef struct BinNode
{
    int data;

    struct BinNode *left;

    struct BinNode *right;

} BinNode;
BinNode *newnode(int data)
{
    BinNode *n = (BinNode *)malloc(sizeof(BinNode));
    n->data = data;

    n->left = NULL;

    n->right = NULL;
    return n;
}
int CountLeaves(BinNode *node)
{

    if (node == NULL)

        return 0;

    if (node->left == NULL && node->right == NULL)

        return 1;

    return CountLeaves(node->left) + CountLeaves(node->right);
}
int Height(BinNode *node)
{
    if (node == NULL)
        return -1;

    int l = Height(node->left), r = Height(node->right);

    return l > r?l+1:r+1;
}
int Sum(BinNode *node)
{
    if (node == null)
        return 0;
    return node->data + Sum(node->left) + Sum(node->right);
}
int Max(BinNode *node)
{
    int max = node->data;
    BinNode *innerNode = node, *leftNode = node;
    while (innerNode != null && leftNode != null)
    {
        if (max < innerNode->data)
            max = innerNode->data;
        int x = max, y = max;
        if (innerNode->left != null)
            x = Max(innerNode->left);
        if (innerNode->right != null)
            y = Max(innerNode->right);
        if (x >= y && max < x)
            max = x;
        else if (max < y)
            max = y;
        innerNode = innerNode->right;
        leftNode = leftNode->left;
    }
    return max;
}
int countX(BinNode *node, int x)
{
    int num = 0;
    if (node == null)
        return 0;
    if (node->data == x)
    {
        num++;
    }
    return num + countX(node->left, x) + countX(node->right, x);
}
int xExists(BinNode *node, int x)
{
    if (node == null)
        return 0;
    if (node->data == x)
        return 1;
    if (!xExists(node->right, x))
        xExists(node->left, x);
}
int treeExists(BinNode *node1, BinNode *node2)
{
    if (node2 == null)
        return 1;

    if (!xExists(node1, node2->data))
        return 0;
    if (!treeExists(node1, node2->left) || !treeExists(node1, node2->right))
        return 0;

    return 1;
}
int LessThenTree(BinNode *root, int x) 
{
    if (root == null)
        return 1;
    if (root->data > x)
    {
        LessThenTree(root->left, x);
        LessThenTree(root->right, x);
    }
    else
        return 0;
}
int TreeLessThenTree(BinNode *t1, BinNode *t2)
{
    if (t2 == null)
        return 1;

    if (!LessThenTree(t1, t2->data))
        return 0;
    if (!TreeLessThenTree(t1, t2->left) || !TreeLessThenTree(t1, t2->right))
        return 0;

    return 1;
}
int howManyRightSons(BinNode *root)
{
    int ret = 0;
    if (root == null)
        return 0;
    if (root->right != null)
        ret++;
    return ret + howManyRightSons(root->right) + howManyRightSons(root->left);
}

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

int ListNodeHeight(listNode *root)
{
    if (root == NULL)
        return -1;
    int height1 = ListNodeHeight(root->children)+1,height2=ListNodeHeight(root->next)+1;
    return height1>height2?height1:height2;
}

int maxGrade(listNode *root)
{
    int count = 0;

    listNode *node = root->children;
    while (node != null)
    {
        count++;
        node = node->children;
    }
    node=root->children;
    int max = count;
    while (node != null)
    {
        count = maxGrade(node);
        if(max<count)
        max=count;

        node = node->next;
    }
    return max;
}

int lMax(listNode *root)
{

    int max = root->key;

    listNode *node = root;

    while (node != NULL)

    {

        if (max < node->key)

            max = node->key;

        int x = max;

        if (node->children != NULL)

            x = lMax((*node).children);

        if (max < x)
            max = x;

        node = node->next;
    }

    return max;
}

int main()
{
    BinNode *binTree1 =newnode(5);
    binTree1->left=newnode(2);
    binTree1->right=newnode(4);
    binTree1->right->left = newnode(12);
    binTree1->right->left->left=newnode(2);

    BinNode *binTree2 =newnode(5);
    binTree2->left=newnode(2);
    binTree2->right=newnode(4);
    binTree2->right->left = newNode(12);
    binTree2->right->left->left=newnode(2);

    //שאלה 1
    printf("height = %d",Height(binTree1));

    //שאלה 2
    printf("sum = %d",Sum(binTree1));

    //שאלה 3
    printf("max = %d",Max(binTree1));

    //שאלה 4
    printf("times x is in bin tree = %d",countX(binTree1,2));

    //שאלה 5 א
    printf("is there x in bin tree = %d",xExists(binTree1,12));

    //שאלה 5 ב
    printf("does every number exist in tree 2 = %d",treeExists(binTree1,binTree2));

    //שאלה 6 א
    printf("is x smaller than tree = %d",LessThenTree(binTree1,1));

    //שאלה 6 ב
    printf("is every numbers in tree 1 smaller than tree 2 = %d",TreeLessThenTree(binTree1,binTree2));

    //שאלה 7
    printf("how many right sons in tree = %d",howManyRightSons(binTree1));

    listNode *listnode = newListNode(2);
    listnode->children=newListNode(12);
    listnode->children->next=newListNode(9);

    //שאלה 8
    printf("max grade = %d", maxGrade(listnode));

    //שאלה 9
    printf("list node height = %d", ListNodeHeight(listnode));
    return 0;
}
