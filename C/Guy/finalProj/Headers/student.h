
#pragma once

/*מאחר שכל שאר הקבצים "יורשים" מהקובץ הזה, הגדרנו כאן כמה דברים כדי שלא נצטרך להוסיף אותם בכל קובץ.*/
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <time.h>
#include <math.h>
#include <assert.h>
/*כמה מאקרואים שימושיים*/
#define P(str) printf("%s\n", #str);
#define PI(num) printf("%d\n", num);
#define PID(id) printf("id =  %lu \n", id);
#define ERROR(str) printf("\nERROR: %s. in File: %s, Line: %d, in Function: %s\n", str, __FILE__, __LINE__, __FUNCTION__);abort();

#define ulong unsigned long
#define null NULL

typedef struct
{
    int courseNum, grade;
} course;
typedef struct
{
    ulong id;
    course *courses;
    int numOfCourses, index;

} student;
typedef struct
{
    double avg;
    ulong id;
} stdAvg;

student *newStudent(ulong id)
{
    student *s = malloc(sizeof(s));
    s->courses = malloc(sizeof(course));
    s->id = id;
    s->numOfCourses = 0;
    s->index = -1;
    return s;
}
void addCourse(student *s, course c)
{    
    s->numOfCourses++;
    s->courses = realloc(s->courses, s->numOfCourses * sizeof(course));
    s->courses[s->numOfCourses-1]= c;
}
int searchCourse(student *s, int courseNum)
{
    for (size_t i = 0; i < s->numOfCourses; i++)
        if (s->courses[i].courseNum == courseNum)
            return s->courses[i].grade;
    return 0;
}
double getAvg(student *s)
{
    course *p = s->courses;
    int i;
    double sum = 0;
    for (i = 0; i < s->numOfCourses; i++, p++)
    {
        sum += p->grade;
    }
    return sum / s->numOfCourses;
}
course *generateCourses(int num)
{
    course *ret = malloc(sizeof(course) * num);
    for (size_t i = 0; i < num; i++)
    {
        course c = {1+rand(), rand() % 101};
        ret[i] = c;
    }
    return ret;
}
ulong generateID()
{
    ulong ret =rand()%899999999;
    ret += 100000000;
    return ret;
}
student **generateStudents(int amount)
{
    student **ret = malloc(sizeof(student) * amount);
    for (size_t i = 0; i < amount; i++)
    {
        ret[i] = newStudent(generateID());
    }
    return ret;
}

void printStudent(student *s)
{
    printf("----------\nStudent ID: %lu\nCourses:\n", s->id);
    int i;
    for (i = 0; i < s->numOfCourses; i++)
    {
        printf("    Course number: %d\n    Course Grade: %d\n", s->courses[i].courseNum,s->courses[i].grade);
        if (i < s->numOfCourses - 1)
            printf("    ---\n");
    }
    printf("Average: %0.1lf\n----------\n", getAvg(s));
}
