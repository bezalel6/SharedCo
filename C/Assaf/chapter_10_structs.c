#include <stdio.h>
#include <string.h>
#include <malloc.h>
//האינקלודים האלה הם בשביל הפונקצייה סטראייסימפ שנאלצתי למצוא באינטרנט, כי הקומפיילר שלי לא מכיר אותו
#include <assert.h>
#include <ctype.h>
#pragma region typedefs
typedef char String[256];
typedef struct
{
    String name, address;
    long id;
} Person;
typedef struct
{
    Person person;
    String cName;
} Lecturer;
typedef struct
{
    Person person;
    String c1, c2, c3;
    int grade;
} Student;
typedef struct
{
    char c;
    int num;
} Appear;
typedef struct
{
    int hour, minutes;
} clock_t1;
typedef struct
{
    int row, col;
} matLocation;
#pragma endregion

int stricmp(const char *s1, const char *s2)
{
    assert(s1 != NULL);
    assert(s2 != NULL);

#ifdef HAVE_STRCASECMP
    return strcasecmp(s1, s2)
#else
    while (tolower((unsigned char)*s1) == tolower((unsigned char)*s2))
    {
        if (*s1 == '\0')
            return 0;
        s1++;
        s2++;
    }

    return (int)tolower((unsigned char)*s1) -
           (int)tolower((unsigned char)*s2);
#endif /* !HAVE_STRCASECMP */
}

#pragma region שאלות 1 - 3
/*מקרי בדיקה: 
לא הצלחתי לחשוב על מקרי בדיקה לשאלות האלה. הדבר היחיד הוא אולי להכניס מחרוזת ריקה או משהו. וגם זה אין שום סיבה שלא יעבוד...
*/
void scanPerson(Person *person)
{
    printf("Enter name, address, id:\n");
    gets((person->name));
    gets((person->address));
    scanf("%ld", &(person->id));
}

void printPerson(Person person)
{
    printf("Name = %s, Address = %s, Id = %ld ", person.name, person.address, person.id);
}

void scanStudent(Student *student)
{
    scanPerson(&(student->person));
    printf("Enter grade: \n");
    scanf("%d", &(student->grade));
    printf("Enter 3 courses: \n");
    getchar();
    gets((student->c1));
    gets((student->c2));
    gets((student->c3));
}

void printStudent(Student student)
{
    printPerson(student.person);
    printf("grade = %d, c1 = %s, c2 = %s, c3 = %s\n", student.grade, student.c1, student.c2, student.c3);
}
int studentNameExists(Student arr[], int size, String name)
{
    int i;
    for (i = 0; i < size; i++)
    {
        if (!strcmp(name, arr[i].person.name))
            return 1;
    }
    return 0;
}
Student getBestStudent(Student arr[], int size)
{
    int i, max = arr[0].grade, index = 0;
    for (i = 1; i < size; i++)
    {
        if (arr[i].grade > max)
        {
            max = arr[i].grade;
            index = i;
        }
    }
    return arr[index];
}
Student arr[5] = {{{"name 1", "address 1", 1}, "s1 c1", "s1 c2", "s1 c3", 30},
                  {{"name 2", "address 2", 2}, "s2 c1", "s2 c2", "s2 c3", 40},
                  {{"name 3", "address 3", 3}, "s3 c1", "s3 c2", "s3 c3", 90},
                  {{"name 4", "address 4", 4}, "s4 c1", "s4 c2", "s4 c3", 60},
                  {{"name 5", "address 5", 5}, "s5 c1", "s5 c2", "s5 c3", 70}};
void Q3_main()
{

    printf("%d", studentNameExists(arr, 5, "name 1"));
}

void Q2_main()
{
    printStudent(getBestStudent(arr, 5));
}

void Q1()
{
    Lecturer lecturer;
    Student students[5];
    scanPerson(&lecturer.person);
    printf("Enter lecturer course name: \n");
    getchar();
    gets(lecturer.cName);

    int i;
    for (i = 0; i < 5; i++)
    {
        scanStudent(&students[i]);
    }
    printf("Lecturer details:\n");
    printPerson(lecturer.person);
    printf("Course: %s\n", lecturer.cName);

    for (i = 0; i < 5; i++)
    {
        printStudent(students[i]);
    }
}
#pragma endregion

#pragma region שאלה 4
int Q4(String str, Appear arr[26])
{
    int i, j;
    for (i = 0; i < 26; i++)
    {
        arr[i].c = i + 'A';
        arr[i].num = 0;
    }
    for (i = 0; i < strlen(str); i++)
    {
        for (j = 0; j < 26; j++)
        {
            if (!stricmp(&str[i], &arr[j].c))
            {
                arr[j].num++;
            }
        }
    }
}

void Q4_main()
{
    Appear arr[26];
    Q4("abc", arr);
    int i;
    for (i = 0; i < 26; i++)
    {
        printf("%c,%d   ", arr[i].c, arr[i].num);
    }
}
#pragma endregion

#pragma region שאלה 5
/*מקרי בדיקה: 
הוספת 0 שניות*/
clock_t1 addMinutes(clock_t1 c, int minutes)
{
    c.minutes += minutes;
    c.hour += c.minutes / 60;
    c.minutes %= 60;
    return c;
}

void printClock(clock_t1 c)
{
    printf("%d:%d", c.hour, c.minutes);
}

void Q5_main()
{
    clock_t1 c1, c2;
    int toAdd;
    printf("Enter time and minutes to add: ");
    scanf("%d %d %d", &c1.hour, &c1.minutes, &toAdd);
    printf("The time is:\n");
    printClock(c1);
    c2 = addMinutes(c1, toAdd);
    printf("\nthe new time is: ");
    printClock(c2);
    putchar('\n');
}

#pragma endregion

#pragma region שאלה 7

void Q7(int *mat, int lineSize)
{
    int i, j;
    for (i = 0; i < lineSize - 1; i++)
        for (j = i + 1; j < lineSize; j++)
        {
            int *c1 = mat + i * lineSize + i, *c2 = mat + j * lineSize + j;
            if (*c1 > *c2)
            {
                int t = *c1;
                *c1 = *c2;
                *c2 = t;
            }
        }
}
void printMat(int *mat, int lineSize)
{
    int i, j;
    for (i = 1; i <= lineSize * lineSize; i++)
    {
        printf("%d ", *(mat + i - 1));

        if (i % lineSize == 0)
            putchar('\n');
    }
}
void Q7_main()
{

    int mat[3][3] = {{3, 5, 6}, {7, 1, 9}, {1, 2, 2}};
    int i;
    printMat(&mat[0][0], 3);
    Q7(&mat[0][0], 3);

    putchar('\n');
    printMat(&mat[0][0], 3);
}
#pragma endregion

#pragma region שאלה 8
void Q8(String str)
{
    int i, j;
    for (i = 0; i < strlen(str) - 1; i++)
        for (j = i + 1; j < strlen(str); j++)
        {
            if (stricmp(&str[i], &str[j]) > 0)
            {
                char temp = str[i];
                str[i] = str[j];
                str[j] = temp;
            }
        }
}
void Q8_main()
{
    String str = "BcAd";
    puts(str);
    Q8(str);
    puts(str);
}
#pragma endregion

#pragma region שאלה 9
#define SIZE 4
int binarySearch(int mat[SIZE][SIZE], int num, int col)
{
    int left, right, m;
    left = 0, right = SIZE - 1;
    while (left <= right)
    {
        m = left + ((right - left) / 2);

        if (mat[m][col] == num)
        {
            printf("Found %d at: %d,%d \n", num, m, col);
            return m;
        }
        if (mat[m][col] < num)
            left = m + 1;
        else
            right = m - 1;
    }
    return -1;
}
matLocation Q9(int mat[SIZE][SIZE], int num)
{
    int res = -1, col;
    for (col = 0; col < SIZE; col++)
    {
        int res = binarySearch(mat, num, col);
        if (res != -1)
        {
            return (matLocation){res, col};
        }
    }
    return (matLocation){-1, -1};
}

void Q9_main()
{
    int mat[SIZE][SIZE] =
        {{2, 1, 5, 1},
         {3, 6, 6, 2},
         {8, 7, 7, 3},
         {9, 8, 9, 4}};
    matLocation s = Q9(mat, 7);
    printf("%d,%d", s.row, s.col);
}
#pragma endregion
int main()
{
    Q9_main();
    return 0;
}