#include "student.h"
typedef struct BinNode
{
    student *data;

    struct BinNode *left;

    struct BinNode *right;

} BinNode;
BinNode *newnode(student *s)
{
    BinNode *n = (BinNode *)malloc(sizeof(BinNode));
    n->data = s;
    n->left = NULL;
    n->right = NULL;
    return n;
}
BinNode *insert(BinNode *root, student *s)
{
    if (root == NULL)
    {
        root = newnode(s);

        return root;
    }
    BinNode *parent = NULL;
    BinNode *x = root;

    while (x != NULL)
    {
        parent = x;
        if (s->id <= x->data->id)
            x = x->left;
        else
            x = x->right;
    }
    if (s->id <= parent->data->id)
        parent->left = newnode(s);
    else
        parent->right = newnode(s);
    return root;
}
student *search(BinNode *node, ulong id)
{
    if (node == null)
    {
        ERROR("STUDENT NOT FOUND");
        return null;
    }
    ulong nId = node->data->id;
    if (nId == id)
    {
        return node->data;
    }
    return nId < id ? search(node->right, id) : search(node->left, id);
}
int idExists(ulong *arr, ulong id)
{
    for (size_t i = 0; i < 5; i++)
        if (arr[i] == id)
            return 1;
    return 0;
}
void findMilgaStudents(BinNode *node, ulong *arr, int *index, int isCheckExists)
{
    if (!node)
    {
        return;
    }
    if (node->data->index == -1)
    {
        if (isCheckExists && !idExists(arr, node->data->id))// במקרה שזו הפעם השנייה שאנחנו מחפשים סטודנטים למילגה, זה אומר שצריך לוודא שהמספר לא קיים במערך. ואם הוא לא קיים, ז"א שהוא מהמלגה החדשה. ולכן צריך להדפיס אותו
        {
            PID(node->data->id);
        }
        else if(!isCheckExists)
        {
            PID(node->data->id);
            arr[*index] = node->data->id;
            (*index)++;
        }
    }
    if (node->left)
        findMilgaStudents(node->left, arr, index, isCheckExists);
    if (node->right)
        findMilgaStudents(node->right, arr, index, isCheckExists);
}
void printAllSons(BinNode *node)
{
    if (!node)
        return;
    BinNode *tNode = node;
    if (tNode->left != null)
    {
        printAllSons(node->left);
    }
    if (tNode->right != null)
    {
        printAllSons(node->right);
    }
    printStudent(node->data);
}
