#include <stdio.h>
void Q1_main()
{
    int x = 10, y = 5;
    Q2(&x, &y);
}
void Q1(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void Q2(int *a, int *b)
{
    *a += *b;
    *b = (*a) - (*b);
    *a -= *b;
}

#define SIZE 5
void Q4()
{
    int arr1[SIZE], arr2[SIZE], arr3[SIZE], arr4[SIZE], i, j; //הגדרת 4 המערכים

    for (i = 0; i < SIZE; i++) //השמה של מספרים במערכים
        arr1[i] = arr2[i] = arr3[i] = arr4[i] = i;

    int *A[] = {arr1, arr2, arr3, arr4}; //הגדרת המערך של הפוינטרים

    for (i = 0; i < sizeof(A) / sizeof(A[0]); i++)
    {
        for (j = 0; j < SIZE; j++)
        {
            int num = *(A[i] + i); //אחסון ערך התא הנוכחי
            if (num % 2 == 0)
                printf("%d", num);
        }
    }
}

void Q5_A(int arr[], int size, int jump, int num) //סעיף א
{
    int *p = arr;           //הגדרת הפוינטר המדלג
    while (p != arr + size) //עד שהפוינטר יגיע לכתובת האחרונה של המערך +1
    {
        int index = p++ - arr; //מציאת האינדקס הנוכחי ע"י חיסור של הפוינטר המדלג לכתובת הראשונה של המערך. על הדרך גם קידמתי את הפוינטר לתא הבא במערך. כמו שלמדנו, המספר המתקבל הוא מספר רגיל, ולא פוינטר, ששווה לכמות *הסוג* (במקרה הזה אינטים) שנכנסים בין אותם כתובות
        if (index % jump == 0)
            *(p - 1) = num; //השמת המספר במיקום של הפוינטר -1 (כי קידמנו אותו ב1)
    }
}

#define SIZE 10
void Q5_B_main() //סעיף ב
{
    int mat[SIZE][SIZE] = {0}, i, j; //הגדרת המטריצה ואיתחול כל התאים באפסים
    for (i = 0; i < SIZE; i++)
    {
        Q5_A(&mat[0][i], SIZE * SIZE, SIZE, i); //שליחת הכתובת של השורה הראשונה, וכל פעם מתקדמים בעמודות. הגודל של המטריצה תמיד יהיה סייז * סייז. ולכן השתמשתי בזה במקום סייז אוף,הקפיצות הן קפיצות של שורה שלמה, ולכן הוא קופץ בסייז כל פעם. ואיי זה פשוט מספור העמודות בהתאמה לעמודה שעליה נמצאת המטריצה כרגע
    }

    for (i = 0; i < SIZE; i++) //הדפסת המטריצה
    {
        for (j = 0; j < SIZE; j++)
            printf("%d", mat[i][j]);

        putchar('\n');
    }
}

int main()
{
   
    return 0;
}
