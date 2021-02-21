#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <time.h>
#define null NULL
typedef char String[256];

void printArr(int *arr, int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
}

/*שאלה 1
א:
1) if(arr==NULL)
2) if(!arr)
ב:
1) assert(arr);
2) assert(arr!=NULL);

ג:
התוכנית תיעצר.
*/

/*שאלה 2
א:
גודל המחרוזת היא בגודל של פויטנר לצ'אר. אני לא חושב שיש פה מה להסביר. או שאולי אתה מתכוון שהמחרוזת ריקה, אז כאילו הגודל שלה הוא הגודל של צ'אר אחד שהוא סלאש אפס...
ב:
שורה 27 הכרחית. בגלל שעשינו מאלוק, באחריות המתכנת גם לשחרר את הזיכרון שהוקצה
ג:
וורד יצביע על המילה שנמצאת בוורד אראיי, והמיקום שהוקצה לוורד בהתחלה , יבוזבז, עד הפעלה מחדש של המחשב. כי הפרי כרגע ישחרר את מה שוורד מצביע עליו כרגע. שזה המערך וורד אראיי
(הפרי הזה בכ"מ מיותר. כי הקומפיילר היה משחרר את וורד ארראי אוטומטית)
*/

/*שאלה 3
כשאין למחשב את המקום המבוקש בזיכרון להקצות לתוכנית. (באיזור בזיכרון הראם שיש לתוכנית גישה אליו)
*/

/*שאלה 4
א:
התוכנית מנסה להקצות 1024 תאים בגודל של אינט בהיפ
ב:
אתה לא בודק האם המחשב הצליח להקצות לך את מספר התאים שביקשת ממנו. ואם הוא לא הצליח, אתה תנסה לגשת לנל.
וזה חשוב במיוחד כאן, מאחר שיש סבירות גדולה שהמחשב לא יצליח להקצות כי אתה מבקש הרבה מאוד כתובות.
*/

#pragma region  שאלה 5
void *CallocSheli(int num, int size)//לשם ההגינות, נועם כהן המקליט עזר לי עם זה
{
    char **ret = malloc(num * size);
    if (ret)
    {
        for (int i = 0; i < num; i++)
        {
            ret[i] = (char*)malloc(sizeof(char) * size);
        }
    }

    return (void *)ret;
}
#pragma endregion
/*שאלה 6
א:
הפונקציה תגדיל את הבאפר בפי 3. בכל מקרה. זה לא משנה מה היה המספר שהזין המשתמש.
ב:

1) השמה למשתנה מסוג קונסט. שהוכרז בתחילת הפונקציה כקונסט בגלל הסימון[] כשהוכרז כפרמטר.
2) שגיאעה לוגית - לא נעשה שימוש כלל בסייז
ג:
void getMoreSpace(int *buffer,int size)
{
    buffer = (int *)realloc(*buffer,SIZE(size)*sizeof(int));
}
*/

#pragma region שאלה 7
typedef struct
{
    int *arr, size;
} ret;
ret *getIchud(int *arr1, int size1, int *arr2, int size2)
{
    ret *res = malloc(sizeof(ret));
    int size = res->size = size1 + size2;
    res->arr = malloc(sizeof(int) * size);

    int i, j;
    for (i = 0; i < size1; i++)
    {
        res->arr[i] = arr1[i];
    }
    for (j = 0; i < size; i++, j++)
    {
        res->arr[i] = arr2[j];
    }

    return res;
}
#pragma endregion
#pragma region שאלה 8
void Q8_main()
{
    srand(time(NULL));
    int size;
    printf("enter size: ");
    scanf("%d", &size);
    int *arr = malloc(sizeof(int) * size);
    int i;
    for (i = 0; i < size; i++)
    {
        arr[i] = 1 + rand() % 10;
    }
    int rNum = 1 + rand() % 10;
    int found = 0;
    for (i = 0; i < size; i++)
    {
        arr[i] == rNum ? found++ : 0;
    }
    int *arr2 = malloc(sizeof(int) * found);
    int index = 0;
    for (i = 0; i < found; i++)
    {
        arr[i] == rNum ? arr[index++] = i : 0;
    }
    printArr(arr, found);
    free(arr);
    free(arr2);
}
#pragma endregion
#pragma region שאלה 9
char* Q9(String str, char c)
{
    int i = 0, numOfChars = 0, len = strnlen(str, 255); //(בג'יסיסי הוא לוקח גם את המקסימום צ'ארים)
    for (i = 0; i < len; i++)
    {
        str[i] == c ? numOfChars++ : 0;
    }
    int index = 0;
    char *arr = malloc(sizeof(char) * numOfChars);
    for (i = 0; i < len; i++)
    {
        str[i] == c ? arr[index++] = c : 0;
    }
    return arr;
}
void Q9_main()
{
    String str1 ="sFfsiJsh",str2 = "iropjgrJr",str3 = "qncisSvoas";
    char *res1 = Q9(str1,'s'),*res2 = Q9(str2,'r'),*res3 = Q9(str3,'s');
    printf("%s\n%s\n%s",res1,res2,res3);
}
#pragma endregion
#pragma region שאלה 10
typedef struct
{
    int x, y;
} point;
typedef struct
{
    point *points;
    int numOfPoints;
} polygon;
void printPoint(point *p)
{
    printf("(%d,%d) ", p->x, p->y);
}
void printPolygon(polygon *p) //כמובן שעדיף פוינטר. כדי לחסוך זיכרון, וזמן ריצה. כדי שלא נעתיק את כל הסטרקט וערכיו. אלא רק מצביע אליו
{
    printf("Num of points: %d\n", p->numOfPoints);
    int i;
    for (i = 0; i < p->numOfPoints; i++)
    {
        printPoint(p->points + i);
    }
}
void Q10_main()
{
    srand(time(null));
    point pointArr[] = {{1, 3}, {2, 4}, {3, 5}};
    polygon *p = malloc(sizeof(polygon));
    printf("Enter num of sides: ");
    scanf("%d", &p->numOfPoints);
    p->points = malloc(sizeof(point) * p->numOfPoints);
    if (p->numOfPoints >= 5)
    {
        int i;
        for (i = 0; i < p->numOfPoints; i++)
        {
            if (i < 3)
                p->points[i] = pointArr[i];
            else
                p->points[i] = (point){rand(), rand()};
        }
        printPolygon(p);
    }
    free(p->points);
    free(p);
}
#pragma endregion
#pragma region שאלה 11

#define MAX_KIDS 20

#define WHOLE_FAMILY(family, action) \
    action(&f->p1);                  \
    action(&f->p2);                  \
    int i;                           \
    for (i = 0; i < MAX_KIDS; i++)   \
        action(f->kids[i]);

typedef struct
{
    char *name;
    int id;
} Person;
typedef struct
{
    Person p1, p2;
    Person *kids[MAX_KIDS];
} Family;
/*ג:

*/
void scanPerson(Person *p)
{
    printf("Enter name: ");
    gets(p->name);
    printf("Enter id: ");
    scanf("%d", &p->id);
}
void printPerson(Person *p)
{
    printf("Name: %s, ID: %d\n", p->name, p->id);
}

void scanFamily(Family *f)
{
    WHOLE_FAMILY(f, scanPerson)
}

void printFamily(Family *f)
{
    WHOLE_FAMILY(f, printPerson)
}
void Q11_main()
{
    Family *f = malloc(sizeof(Family));
    scanFamily(f);
    printFamily(f);
}
#pragma endregion
int main()
{
    Q11_main();
    return 0;
}