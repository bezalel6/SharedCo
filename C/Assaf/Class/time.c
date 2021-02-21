#include <stdio.h>
#define null NULL
typedef struct time{
int hours,minutes;
}time;
int hefresh(time time1,time time2)
{   
    return (time1.minutes+time1.hours*60)-(time2.minutes+time2.hours*60);
}
int main()
{
    time time1,time2;
    printf("enter time1 hours: ");
    scanf("%d",&time1.hours);
    
    printf("enter time1 minutes: ");
    scanf("%d",&time1.minutes);

    printf("enter time2 hours: ");
    scanf("%d",&time2.hours);
    
    printf("enter time2 minutes: ");
    scanf("%d",&time2.minutes);
    
    printf("Hefresh = %d",hefresh(time1,time2));
    return 0;
}