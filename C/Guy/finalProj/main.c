#include "Headers/student.h"
#include "Headers/binTree.h"
#include "Headers/heap.h"

#define M 15

BinNode *students[M];
heapAvg *h;

int hash(ulong id)
{
    int S = 1;
    while (id != 0)
    {
        id /= 10;
        if (id % 10 != 0)
            S *= id % 10;
    }
    return S % M;
}

void updateAll()
{
    for (size_t i = 0; i < h->size; i++)
    {
        ulong id = h->data[i].id;
        student *s = search(students[hash(id)], id);
        s->index = getIndex(h, h->data[i]);
    }
 }
void printAllStudents()
{
    for (size_t i = 0; i < M; i++)
    {
        if (students[i])
        {
            printAllSons(students[i]);
        }
    }
}
void insertStudent(student *s)
{
    stdAvg *avg =malloc(sizeof(stdAvg));
    avg->avg = getAvg(s);
    avg->id =  s->id;
    s->index = heapInsert(h, *avg);
    ulong hashRes = hash(s->id);
    students[hashRes] = insert(students[hashRes], s);
    updateAll();
}
void changeGrade(ulong id, course *c)
{
    student *s = search(students[hash(id)], id);
    for (size_t i = 0; i < s->numOfCourses; i++)
    {
        if (s->courses[i].courseNum == c->courseNum)
        {
            s->courses[i].grade = c->grade;
            h->data[s->index].avg = c->grade;
            buildHeap(h);
            updateAll();
            return;
        }
    }
    ERROR("DIDNT FIND COURSE TO UPDATE");
}
stdAvg ExtractMax(heapAvg *h)
{
    buildHeap(h);//רק ליתר בטחון
    stdAvg max = *h->data;
    for (size_t i = 0; i < h->size - 1; i++)
    {
        h->data[i] = h->data[i + 1];
    }
    h->size--;
    buildHeap(h);
    updateAll();
    return max;
}
void milga()
{
    for (size_t i = 0; i < 5; i++)
    {
        stdAvg avg = ExtractMax(h);
        search(students[hash(avg.id)], avg.id)->index = -1;
    }
}
double courseAvg(int courseID, ulong stds[], int size)
{
    double avg = 0;
    int divide = 0;
    for (size_t i = 0; i < size; i++)
    {
        student *s = search(students[hash(stds[i])], stds[i]);
        int grade = searchCourse(s, courseID);
        if (grade != -1)
        {
            divide++;
            avg += grade;
        }
    }
    if (divide)
        return avg / divide;

    ERROR("DIDNT FIND ANY STUDENT WITH THIS COURSE");
    return -1;
}

int main()
{
    srand(time(null));
    h = malloc(sizeof(heapAvg));
    initHeap(h);
    int numOfStudents = 15;
    student **s = generateStudents(numOfStudents);//יצירת 15 הסטודנטים
    for (size_t i = 0; i < numOfStudents; i++)
    {
        int numOfCourses = 1 + rand() % 8;
        course *courseArr = generateCourses(numOfCourses);
        for (size_t j = 0; j < numOfCourses; j++)//הוספת הקורסים לסטודנט הנוכחי
        {
            addCourse(s[i], courseArr[j]);
        }
        insertStudent(s[i]);// הכנסת הסטודנט הנוכחי לטבלת הגיבוב
    }
    printAllStudents();//הדפסת הסטודנטים ולכל אחד את הממוצע שלו
    printHeap(h);//הדפסת ערימת הממוצעים

    student *s1 = s[rand() % numOfStudents];//בחירת סטודנט באופן רנדומלי
    course c1 = {s1->courses[rand() % s1->numOfCourses].courseNum, 0};//יצירת הקורס האלטרנטיבי, שבו נשתמש כדי לשנות את הציון
    changeGrade(s1->id,&c1);////שינוי ציון הקורס

    printAllStudents();//הדפסת הסטודנטים ולכל אחד את הממוצע שלו
    printHeap(h);//הדפסת ערימת הממוצעים

    milga();//מציאת 5 הסטודנטים הזכאים למלגה
    ulong *arr = malloc(5* sizeof(ulong));//יצירת מערך שבו אאחסן כל אחת   מתעודות הזהות שיקבלו עכשיו מלגה בפעם הראשונה. כדי שאדע להתעלם מהם בפעם השנייה שאחפש את התלמידים החדשים שזכאים לקבלת המלגה
    int *index = calloc(1,sizeof(int));//יצירת פוינטר למשתנה מסוג אינט שבעזרתו אעקוב אחרי המיקום הפנוי הבא במערך (זה דווקא פוינטר, מכיוון שאנו רוצים לשמר את המידע שיישתנה אחרי הקריאה לפונקציה בכל פעם בתוך הלולאה. אחרת - הוא כל פעם היה מתאפס. ובחרתי דווקא בקאלוק, כדי שהוא כבר יאפס את המשתנה)
    int i;
    for (i = 0; i < M; i++)
    {
        findMilgaStudents(students[i], arr, index, 0);//הכנסת 5 הסטודנטים שזכאים למילגה למערך. הפונקציה מקבלת גם את הערך 0 לפרמטר שבודקים איתו האם זה החיפוש השני או הראשון
        //הערה: ההדפסה תקרה בתוך הפונקציה עצמה
    }
    printHeap(h);//הדפסת ערימת הממוצעים

    milga();//מציאת 5 הסטודנטים הנוספים הזכאים למלגה
    for (i = 0; i < M; i++)
    {
        findMilgaStudents(students[i], arr, index, 1);//במקרה הזה, הפונקציה מקבלת את הערך 1 לפרמטר הבדיקה. מאחר שזו הפעם השנייה שאנו מחפשים את הסטודנטים הזכאים למילגה
        //הערה: ההדפסה תקרה בתוך הפונקציה עצמה
    }
    free(index);
    free(arr);
    free(s);
    free(h);
    return 0;
}