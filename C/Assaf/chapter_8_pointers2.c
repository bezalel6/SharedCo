#include <stdio.h>
void Q1(double *p, int size)
{
    printf("Enter number \n");
    scanf("%lf", p);
    if (size != 0)
        Q1(p + 1, size - 1);
}
void Q2(double *p, int size)
{
    if (size != 1)
        Q2(p + 1, size - 1);
    printf("%lf", *p);
}
#define SIZE 5
void Q3_main()
{
    double arr[SIZE];
    Q1(arr, SIZE);
    Q2(arr + 4, 3);
    //בחרתי בarr+4 בגלל שככה אני מגיע לאיבר השלישי, ואז נתתי לו גודל של 3. שזה בעצם הגודל של המערך ה"חדש" ששלחתי לו
    Q2(arr + 1, SIZE - 2);
}
#define lineSize 5
#define colSize 4
void Q4_main()
{
    double mat[lineSize][colSize];
    int size = sizeof(mat) / sizeof(**mat);
    double *p = *mat; 
    int i;
    for (i = 1; i < lineSize; i++, p += lineSize)
    {
        Q1(p, lineSize);
    }
    int half = size / 2;
    Q2(*mat, half);
    Q2(*mat + half, size - half);
}

int main()
{
    double arr[3];
    Q1(&arr,3);
    Q2(&arr,3);
    return 0;
}