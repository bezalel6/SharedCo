#include <stdio.h>
#include <string.h>
#define null NULL
#define maxCharsPerLine 10

typedef char String[maxCharsPerLine];

void scanStrings(String str[],int lines)
{
    printf("Please enter %d lines (maximum %d chars)\n", lines, maxCharsPerLine);
    int i;
    for (i = 0; i < lines; i++)
    {
        gets(str[i]);
    }
}
void Q1()
{
    printf("%d\n", strcmp("hello", "Hello"));
    //printf("%d", stricmp("hello", "Hello"));//הקוד כרגע בהערה כדי שאוכל לקמפל.
    /*ההבדל בין 2 הפונקציות הוא: בלי האיי, פעולת ההשוואה כוללת בדיקה של אותיות גדולות וקטנות, ומחשיבה את ערכן השונה בבדיקה.
     לעומת עם האיי, שבה השוני של האותיות הגדולות והקטנות לא נבדק.*/
}
int strlenSheli(String str)
{
    /*מקרי הבדיקה שבחרתי:
    מחרוזת ריקה, ומחרוזת לא ריקה*/
    char *c = str;
    int length = 0;
    while (*(c++) != '\0')
        length++;
    return length;
}
/*שאלה 3:
יודפס Capitals letters in 'This is A homework I have to String': TAS 
מאחר שהפוינטר מצביע כל פעם לאות הראשונה שנמצאת בסטר שנמצאת בקיס, ואז מקדמים את הפוינטר באחד ככה שהוא לא יוכל לנחות על האות הזו במיקום הזה שוב.  וככה זו גם לא לולאה אינסופית*/

/*שאלה 4:
בסטרסטר צריך למצוא את כל המחרוזת השנייה במחרוזת הראשונה. ואילו בסטרפברק צריך למצוא רק את המופע הראשון של אחת מהאותיות במחרוזת
*/
#define LINES 4
void Q5()
{
    String arr[LINES], word;
    scanStrings(arr,LINES);
    printf("please enter a word: \n");
    gets(word);
    int i, count = 0;
    for (i = 0; i < LINES; i++)
    {
        if (!strcmp(arr[i], word))
            count++;
    }
    printf("%d lines are equal to %s", count, word);
}
#define SIZE 3
void Q6()
{
    String text1[SIZE], text2[SIZE], text3[SIZE];
    int i;
    for (i = 0; i < SIZE * 2; i++)
    {
        if (i == 0 || i == SIZE)
            printf("Please enter %d lines (maximum %d chars)\n", SIZE, maxCharsPerLine);
        if (i < SIZE)
            gets(text1[i]);
        else
            gets(text2[i - SIZE]);
    }
    for (i = 0; i < SIZE; i++)
    {
        if (strlen(text1[i]) + strlen(text2[i]) < maxCharsPerLine)
        {
            strcpy(text3[i], text1[i]);
            strcat(text3[i], text2[i]);
        }
        else
            strcpy(text3[i], "");
    }
    printf("text 3 is:\n");
    for (i = 0; i < SIZE; i++)
    {
        puts(text3[i]);
    }
}
#define LINES 5
void swap(String s1, String s2)
{
    String temp;
    strcpy(temp, s1);
    strcpy(s1, s2);
    strcpy(s2, temp);
}
void Q7()
{
    String arr[LINES], tmpArr[LINES];
    scanStrings(arr,LINES);
    int i,j;
    for (i = LINES-1,j=0; i >=0; i--)
    {
        strcpy(tmpArr[i],arr[j++]);
    }
    for (i = 0; i < LINES - 1; i++)
    {
        swap(tmpArr[i], tmpArr[i + 1]);
    }
    swap(tmpArr[LINES-1],tmpArr[0]);
    swap(tmpArr[LINES-2],tmpArr[1]);
    for(i=0;i<LINES;i++)
    {
        swap(arr[i],tmpArr[i]);
    } 
    for (i = 0; i < LINES; i++)
    {
        puts(arr[i]);
    }
}
typedef char *string; //סטרינג עם אות קטנה, לא באמצעות מערך. לשאלה 8 (אני מקווה שזה לא אכפת לך שהשתמשתי במערך של צ'ארים עד עכשיו. בסופו של דבר אין באמת הבדל... פשוט היה לי יותר נוח ככה)
void Q8(string arr[], int size)
{
    int i, j;
    for (i = 0; i < size - 1; i++)
        for (j = i + 1; j < size; j++)
            if (strcmp(arr[i], arr[j]) > 0)
            {
                string t = arr[i];
                arr[i] = arr[j];
                arr[j] = t;
            }
}
void Q9()
{
    //גילוי נאות - בטעות נתקלתי בhttp://www.cplusplus.com/reference/cstdio/sscanf/ כשלמדתי על ססקאנף
    char sentence[] = "My grade is: 100 and I happy";
    char str[20];
    int i;
    sscanf(sentence, "%*s %s %*s %d", str, &i);
    printf("%s -> %d", str, i);
}
int main()
{
    Q7();
    return 0;
}