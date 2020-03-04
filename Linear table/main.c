#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100
typedef struct LNode*List;
struct LNode
{
    int Data[MAXSIZE];
    int Last;
} L;
struct LNode L;
List Ptrl;
List MakeEmpty()
{
    List Ptrl;
    Ptrl=(List)malloc(sizeof(struct LNode));
    Ptrl->Last=-1;
    return Ptrl;
}
void Insert(int X,int i,List Ptrl)
{
    int j;
    if(Ptrl->Last==MAXSIZE-1)
    {
        printf("表满");
        return;
    }
    if(i<1||i>Ptrl->Last+2)
    {
        printf("位置不合法");
        return;
    }
    for(j=Ptrl->Last;j>=i-1;j--)
        Ptrl->Data[j+1]=Ptrl->Data[j];
}
int main(void)
{
    int i;
    MakeEmpty();
    int a[5];
    printf("Plesae enter five numbers.");
    for(i=0;i<5;i++)
        scanf("%d",&a[i]);
    for(i=0;i<5;i++)
        Ptrl->Data[i]=a[i];
    for(i=0;i<5;i++)
        printf("%d",a[i]);
    return 0;
}
