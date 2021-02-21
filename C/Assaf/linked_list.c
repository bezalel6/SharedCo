#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#define null NULL

typedef char string[255];

#define ERROR(str) printf("\nERROR %s. in File: %s, Line: %d, in Function: %s\n", str, __FILE__, __LINE__, __FUNCTION__);

#define Q12 // השאלה שאתה בודק עכשיו

#ifndef Q1 // בעיקרון, אלה פונקציות שמשתמשים בהם לאורך כל דף התרגילים. חוץ מבשאלה מספר אחת ו10, שבה הנוד מוגדרת בצורה שונה. (רוב הפונקציות היו תרגילים בעצמם)
#ifndef Q10
typedef int type;
struct LNode
{
    type data;
    struct LNode *next, *prev;
} typedef LNode;

typedef struct
{
    LNode *head;
} List;

LNode *newNode(type data)
{
    LNode *n = malloc(sizeof(LNode));
    n->data = data;
    n->next = n->prev = null;
    return n;
}
void insertNodeToEnd(List *l, type data)
{
    LNode *temp = l->head;
    while (temp->next)
        temp = temp->next;
    LNode *new = newNode(data);
    temp->next = new;
    new->prev = temp;
}

void printNodes(LNode *node)
{
    if (!node)
        return;
    printf("%d ", node->data);
    printNodes(node->next);
}
void freeLNode(LNode *node)
{
    if (node)
    {
        LNode *temp = node->next;
        //free(node);
        freeLNode(temp);
    }
}
void freeList(List *l)
{
    freeLNode(l->head);
    free(l);
}
void insertNodeAfter(List *l, type insertAfter, type data)
{
    LNode *temp = l->head;
    while (temp && temp->data != insertAfter)
        temp = temp->next;
    if (temp) //זה אומר שמצאנו את הערך שאחריו נ שים את הנוד
    {
        LNode *new = newNode(data);
        if (temp->next) //למקרה שהגענו לסוף הרשימה
        {
            new->next = temp->next;
            temp->next->prev = new;
        }
        new->prev = temp;
        temp->next = new;
        freeLNode(new);
    }
    else
    {
        ERROR("Didnt find the node to insert after");
    }
    freeLNode(temp);
}
#endif
#endif

#ifdef Q1
typedef string type;
struct LNode
{
    type data;
    struct LNode *next;
} typedef LNode;

typedef struct
{
    LNode *head;
} List;
void printList(List *ls)
{
    LNode *temp = ls->head;
    while (temp)
    {
        printf("%s(%d)\n", temp->data, strlen(temp->data));
        temp = temp->next;
    }
}
void Q1_main()
{
    List *l = malloc(sizeof(List));
    l->head = malloc(sizeof(LNode) * 3);
    LNode n1 = {"1", NULL}, n2 = {"12", null}, n3 = {"123", null};
    n1.next = &n2;
    n2.next = &n3;
    l->head = &n1;
    printList(l);
}
#endif

#ifdef Q2toQ8 /*מאחר ושאלות 2-8 היו +- שזורות אחת בשניה, הכנסתי את כולן יחד ל"קונטיינר" משלהן. לכל אחת מהשאלות יש מיין משלה, לצורגי בדיקה. כפי שמבוקש בתרגיל.*/
void printQ2(List *l)
{
    LNode *temp = l->head;
    while (temp->next)
    {
        temp = temp->next;
    }
    int a = 1;
    do
    {
        if (a++ % 2)
        {
            printf("%d ", temp->data);
        }
        temp = temp->prev;
    } while (temp);
    freeLNode(temp);
}
void Q4(LNode *node)
{
    if (!node)
        return;
    printf("%d ", node->data);
    Q4(node->next);
}
void Q5(LNode *node)
{
    if (!node)
        return;
    Q5(node->next);
    printf("%d ", node->data);
}
void freeLNode_Q6(LNode *node)
{
    if (node)
    {
        LNode *temp = node->next;
        //free(node);
        freeLNode(temp);
    }
}
void Q6(List *l)
{
    freeLNode_Q6(l->head);
    free(l);
}
void freeLNode_Q7(LNode *node)
{
    if (!node)
    {
        return;
    }
    if (node->next)
        freeLNode_Q7(node->next);
    free(node);
}
void Q7(List *l)
{
    freeLNode_Q7(l->head);
    free(l);
}
int LNodeLength_Q8(LNode *node)
{
    if (!node)
        return 0;
    return 1 + LNodeLength_Q8(node->next);
}
int Q8(List *l)
{
    return LNodeLength_Q8(l->head);
}
void insertNodeToEmptyList(List *l, type data)
{
    l->head = newNode(data);
}
void insertNodeAfter(List *l, type insertAfter, type data)
{
    LNode *temp = l->head;
    while (temp && temp->data != insertAfter)
        temp = temp->next;
    if (temp) //זה אומר שמצאנו את הערך שאחריו נ שים את הנוד
    {
        LNode *new = newNode(data);
        if (temp->next) //למקרה שהגענו לסוף הרשימה
        {
            new->next = temp->next;
            temp->next->prev = new;
        }
        new->prev = temp;
        temp->next = new;
        freeLNode(new);
    }
    else
    {
        ERROR("Didnt find the node to insert after");
    }
    freeLNode(temp);
}
List *testingList()
{
    List *l = malloc(sizeof(List));
    insertNodeToEmptyList(l, 1);
    insertNodeToEnd(l, 3);
    insertNodeAfter(l, 1, 2);
    return l;
}
void Q8_main()
{
    List *l = testingList;
    printf("%d", Q8(l));
}
void Q7_main()
{
    List *l = testingList;
    Q7(l);
}
void Q6_main()
{
    List *l = testingList;
    Q6(l);
}
void Q5_main()
{
    List *l = testingList;
    Q5(l->head);
}
void Q4_main()
{
    List *l = testingList;
    Q4(l->head);
}
void Q3_main()
{
    List *l = testingList;
    printNodes(l->head);
}
void Q2_main()
{
    List *l = malloc(sizeof(List));
    LNode *n1 = newNode(1), *n2 = newNode(2), *n3 = newNode(3);
    l->head = n1;
    n1->next = n2;
    n2->prev = n1;
    n2->next = n3;
    n3->prev = n2;
    printQ2(l);
}
int main()
{
    Q8_main();
    return 0;
}
#endif

#ifdef Q10
typedef int type;
struct node
{
    type data;
    struct node *next;
} typedef node;

typedef struct
{
    node *head;
} Stack;

node *newNode(type data)
{
    node *n = malloc(sizeof(node));
    n->data = data;
    n->next = null;
    return n;
}
int isEmpty(Stack *s)
{
    return s->head == null;
}
void push(Stack *s, type data)
{
    node *storeTop = s->head;
    s->head = newNode(data);
    s->head->next = storeTop;
}
type pop(Stack *s)
{
    if (isEmpty(s))
    {
        ERROR("cant pop. stack is empty.")
        return -1;
    }
    type ret = s->head->data;
    s->head = s->head->next;
    return ret;
}
type top(Stack *s)
{
    if (isEmpty(s))
    {
        ERROR("cant return top. stack is empty.")
        return -1;
    }
    return s->head->data;
}

int main()
{
    Stack *s = malloc(sizeof(Stack));
    s->head = newNode(1);
    push(s, 2);
    printf("top = %d. pop = %d. pop = %d", top(s), pop(s), pop(s));
    return 0;
}
#endif

#ifdef Q11

void deleteNode(LNode *n)
{
    if (n->prev && n->next)
    {
        n->prev->next = n->next;
        n->next->prev = n->prev;
    }
    else if (n->prev)
        n->prev->next = null;
    else
        n->next->prev = null;

    free(n);
}

void removeAllMatching(List *l, type data)
{
    LNode *temp = l->head;
    while (temp->next)
    {
        if (temp->data == data)
            deleteNode(temp);
        temp = temp->next;
    }
}
int main()
{
    List *l = malloc(sizeof(List));
    l->head = newNode(1);
    insertNodeToEnd(l, 3);
    insertNodeAfter(l, 1, 2);
    insertNodeToEnd(l, 1);
    printf("b4 removing:\n");
    printNodes(l->head);

    removeAllMatching(l, 1);
    printf("\nafter removing:\n");
    printNodes(l->head);
    return 0;
}
#endif
#ifdef Q12
void insertNode(LNode *insertAfter, LNode *nodeToInsert)
{
    nodeToInsert->next = insertAfter->next;
    if (insertAfter)
        insertAfter->next = nodeToInsert;
    if (nodeToInsert->next)
        nodeToInsert->next->prev = nodeToInsert;
}
void addNum(List *l, type find, type add)
{
    LNode *temp = l->head;
    LNode *new = newNode(add);
    while (temp)
    {
        if (temp->data == find)
        {
            insertNode(temp, new);
        }
        temp = temp->next;
    }
    freeLNode(temp);
}

int main()
{
    List *l = malloc(sizeof(List));
    l->head = newNode(1);
    addNum(l, 1, 2);
    addNum(l, 1, 3);
    //addNum(l, 3, 3); // מקרה קצה: אם המספרים יהיו שווים. (המספר להוסיף = המספר להוסיף אחריו) זה פשוט יהיה אינסופי.
    printNodes(l->head);
    freeList(l);
    return 0;
}
#endif
#ifdef Q13

void insertNode(LNode *insertAfter, LNode *nodeToInsert)
{
    nodeToInsert->next = insertAfter->next;
    if (insertAfter)
        insertAfter->next = nodeToInsert;
    if (nodeToInsert->next)
        nodeToInsert->next->prev = nodeToInsert;
}
int isSmallToBig(List *l)
{
    LNode *temp = l->head;
    int num = temp->data;
    while (temp)
    {
        if (num <= temp->data)
        {
            num = temp->data;
        }
        else
            return 0;
        temp = temp->next;
    }
    return 1;
}
int main()
{
    List *l = malloc(sizeof(List));
    l->head = newNode(1);
    insertNode(l->head, newNode(2));
    insertNode(l->head->next, newNode(5));
    insertNode(l->head->next->next, newNode(4));
    printf("%d", isSmallToBig(l));
    return 0;
}
#endif
#ifdef Q14
void insertNodeToEnd(List *l, type data)
{
    LNode *temp = l->head;
    while (temp && temp->next)
        temp = temp->next;
    LNode *new = newNode(data);
    temp->next = new;
    new->prev = temp;
}

int isExist(LNode *n, type search)
{
    if (!n)
        return 0;
    if (n->data == search)
        return 1;
    isExist(n->next, search);
}
List *getList(List *l1, List *l2)
{
    List *ret = malloc(sizeof(List));
    ret->head = newNode(2);
    LNode *n1 = l1->head, *n2 = l2->head;
    while (n1)
    {
        if (isExist(n2, n1->data))
            insertNodeToEnd(ret, n1->data);
        n1 = n1->next;
    }
    return ret;
}
int main()
{
    List *l1 = malloc(sizeof(List)), *l2 = malloc(sizeof(List));
    //l1->head = newNode(2);
    insertNodeToEnd(l1, 3);
    printNodes(l1->head);
    return 0;
}
#endif
#ifdef Q15
typedef int type;

List *getList(List *l)
{
    List *ret = malloc(sizeof(List));
    ret->head = null;
    int avg = 0, divide = 0;
    LNode *temp = l->head;
    while (temp->next)
    {
        avg += temp->data;
        divide++;
        temp = temp->next;
    }
    avg += temp->data; //בגלל שנמנענו ממספר אחד, כשרצנו עד לטמפ->נקסט
    avg /= divide;
    temp = l->head;
    while (temp)
    {
        if (temp->data > avg)
        {
            if (!ret->head)
            {
                ret->head = temp;
            }
            else
            {
                LNode *a = ret->head;
                while (a->next)
                    a = a->next;
                a->next = temp;
            }
        }
        temp = temp->next;
    }
    freeLNode(temp);
    return ret;
}
int main()
{
    List *l = malloc(sizeof(List));
    l->head = newNode(2);
    insertNodeToEnd(l, 100);
    insertNodeToEnd(l, 50);
    List *t = getList(l);
    printNodes(t->head);

    freeList(l);
    freeList(t);
    return 0;
}
#endif
/*שאלה 16
1) List2,List2
2) L
3) List1, List1
4) List1, List2
5) List1->num
6) List2->num
*/
