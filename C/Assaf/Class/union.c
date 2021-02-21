#include <stdio.h>
#include <string.h>

typedef struct{
    int x,y;
}point;

typedef struct{
    point left,right;
}rectangle;
void printRectangle(rectangle r)
{
    printf("(%d,%d) , (%d,%d)\n",r.left.x,r.left.y,r.right.x,r.right.y);
}
void scanRectangle(rectangle *r)
{
    printf("Enter rectangle cordinates: ");
    scanf("%d %d %d %d",&(r->left.x),&(r->left.y),&(r->right.x),&(r->right.y));
}
int main()
{
    rectangle r1 = {{0,0},{3,4}},r2;

    scanRectangle(&r2);
    printRectangle(r1);
    printRectangle(r2);

    rectangle arr[3];
    int i;
    for(i=0;i<3;i++)
    {
        scanRectangle(&arr[i]);
    }
               
    return 0;
}

