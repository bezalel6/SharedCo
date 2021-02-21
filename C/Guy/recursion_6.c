#include <stdio.h>

int Q1(int num) { return num == 0 ? 0 : num + Q1(num - 1); }

float Q2(float x, int y)
{
    if (y < 0)
        return 1 / Q2(x, y * -1);
    return y == 0 ? 1 : x * Q2(x, y - 1);
}
int Q3(int num)
{
    if (!num)
        return 1;
    return num % 2 == 0 ? Q3(num / 10) : 0;
}

int Q4_printArr(int arr[], int index)
{
    if (index < 0)
        return 0;
    Q4_printArr(arr, index - 1);
    printf("%d ", arr[index]);
}

int Q5(int arr[], int index)
{
    int isZugi = 0;
    if (index < 0)
        return 0;
    if (arr[index] % 2 == 0)
        isZugi = 1;
    return isZugi += Q5(arr, index - 1);
}

int Q6(int num) { return num == 0 ? 1 : Q6_IfNot0(num); }
int Q6_IfNot0(int num)
{
    int counter = 0;
    if (!num)
        return 0;
    counter = 1;
    return counter += Q6_IfNot0(num / 10);
}
int Q7(int arr[], int index)
{
    int max = arr[index];
    if (index == 0)
        return arr[index];
    if (max > Q7(arr, index - 1))
        max = arr[index - 1];
}

void Q8_Reverse(int arr[], int start, int end)
{
    if (start >= end)
        return;
    int store1 = arr[start], store2 = arr[end];
    arr[start] = store2;
    arr[end] = store1;
    Q8_Reverse(arr, start + 1, end - 1);
}

void Q9(int num)
{
    if (num == 0)
        return;
    Q9(num - 1);
    for (int i = 0; i < num; i++)
    {
        putchar('*');
    }
    putchar('\n');
}

void Q10(int num)
{
    if (num == 0)
        return;
    for (int i = 0; i < num; i++)
    {
        putchar('*');
    }
    putchar('\n');

    Q10(num - 1);
}

void Q11_bottle(char tav, int num1, int num2)
{
    if (num1 < 0)
        return;
    for (int i = 0; i < num2; i++)
    {
        putchar(' ');
    }
    for (int i = 0; i <= num1; i++)
    {
        putchar(tav);
    }
    putchar('\n');

    Q11_bottle(tav, num1 - 2, num2 + 1);

    for (int i = 0; i < num2; i++)
    {
        putchar(' ');
    }
    for (int i = 0; i <= num1; i++)
    {
        putchar(tav);
    }
    putchar('\n');
}

int Q12_A(int x, int y)
{
    int num = 0;
    if (y == 0)
        return num;

    return num += x * y + Q12_A(x, y - 1);
}

int Q12_B(int arr[], int index)
{
    int num = 0;
    if (index < 0)
        return num;

    printf(" %i ", Q12_A(arr[index - 1], arr[index]));
    return Q12_B(arr, index - 2);
}
int Q13_A(int x, int y)
{
    if (!y)
        return 0;
    return y > x ? Q13_A(x, y - 1) + x * y : Q13_A(x - 1, y - 1) + x * y;
}
void Q13_B(int arr[], int size)
{
    printf(" %i ", Q13_A(arr[size - 1], arr[size]));
    if (size != 1)
        Q13_B(arr, size - 2);
}
int power(int x, int y) { return y ? x * power(x, y - 1) : 1; }
float Q14_A(int x, int y) { return 1 / (float)power(x, y); }
float Q14_B(int x, int y) { return y ? Q14_A(x, y) + Q14_B(x, y - 1) : 0; }
float Q14_C(int arr[], int startIndex, int endIndex)
{
    if (endIndex + 1 == startIndex)
        return 0;
    printf(" %lf ", Q14_B(arr[startIndex], arr[endIndex]));
    Q14_C(arr, startIndex + 1, endIndex - 1);
}
