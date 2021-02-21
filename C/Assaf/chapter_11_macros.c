#include <stdio.h>
#include <assert.h>
#define INC(p) (*p)++;
void Q1_main()
{
    int num=0,*p=&num;
    printf("%d ",num);
    INC(p);
    printf("%d ",num);
}

/*שאלה 2
x = (2018+2)*5 = 2020*5 = 10100
*/

/*שאלה 3
x = 2+2+2+4 = 10
יודפס 10
*/

/*שאלה 4
x = 2.0/2*2/4
פותרים משמאל לימין לפי טבלת קדימויות
x = 1*2 /4 = 2/4 = 1/2
יודפס חצי
*/

/*שאלה 5
x = (3)+6*3 = 21
*/

/*שאלה 6
x = 5+2*3+2 = 5+(2*3)+2=13
*/

/*שאלה 7
א:
יודפס 19. בגלל שהוא כבר מוגדר, אז הערך לא מוגדר מחדש ל 17
ב:
יודפס 17. בגלל שהוא כבר לא מוגדר, אז מגדירים אותו ל17
*/

//שאלה 8
#define MY_ASSERT(exp) if(!(exp)) printf("assertion %s failed: file %s,line %d",#exp,__FILE__,__LINE__);

/*שאלה 9
1: f4(3,4,2): 4/2+3*3 = 11
2: f2(ptr1)f2(m): *ptr1*m = 4*5 = 20
הלולאה תרוץ 5 פעמים, ובכל פעם, היא מומסיפה 2 לוי אחד. ולכן ייתווסף לוי 1 עוד 10
3: 13
x = (f3(m,z)==f3(z,y))?2:4; = (5/2==3/2): FALSE ולכן יוכנס לאיקס 4
4: 4
v[0] = y = 2
לכן נוסיף לוי במיקום אחד שתיים
5: 2
v[0] = m = 5
נרוץ 10 פעמים בתוך הלולאה. ומאחר וכל פעם מורידים 1 מוי במיקום 0, כעת הוא יהיה -5
6: -5
*/
#define f1(x) x*x
#define f2(x) *x
#define f3(x,y) x/y
#define f4(x,y,z) f3(y,z)+f1(x)

int main()
{
    int x,y=2,z=3,t=4,m=5;
    int v[2];
    int *ptr1,*ptr2;
    printf("%d\n",f4(z,t,y));
    ptr1 = &t;
    ptr2 = &m;
    printf("%d\n",f2(ptr1)f2(m));
    v[0] = f2(ptr2);
    v[1] = z;
    while(f2(v))
    {
        v[1]+=2;
        v[0]--;
    }
    printf("%d\n",v[1]);
    x = (f3(m,z)==f3(z,y))?2:4;
    printf("%d\n",x);
    v[0]=y;
    v[1]=0;
    switch (v[0])
    {
    case 1:v[1]+=1;
    case 2:v[1]+=2;
    case 3:v[1]+=3;
    default:v[1]++;
    }
    printf("%d\n",v[1]);
    v[0] = m;
    x=0;
    while(!(--v[0]%2))
    {
        v[0]--;
        x++;
        if(x==10)break;
    }
    printf("%d\n", v[0]);
    return 0;
}