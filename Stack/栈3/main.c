#include<stdio.h>
#include<stdlib.h>
#define MAXNUM 6
typedef struct node{
    int top1;
    int top2;
    int data[MAXNUM]
}Stack,*stack;
void Init_Stack(stack L)
{
    L->top1=0;
    L->top2=MAXNUM;
}
void Pushstack1(stack L,int x)
{
    if(L->top1==L->top2)
    {
        printf("Full Stack.\n");
        return;
    }
    L->data[L->top1]=x;
    L->top1++;
}
void Pushstack2(stack L,int x)
{
    if(L->top2==L->top1)
    {
        printf("Full Stack.\n");
        return;
    }
    L->top2--;
    L->data[L->top2]=x;
}
int Popstack1(stack L)
{
    int x;
    if(L->top1==0)
    {
        printf("stack is NULL\n");
        return 0;
    }
    x=L->data[L->top1];
    L->top1--;
    return x;
}
int Popstack2(stack L)
{
    int x;
    if(L->top2-1==MAXNUM)
    {
        printf("stack is NULL\n");
        return 0;
    }
    x=L->data[L->top2];
    L->top2++;
    return x;
}
void showstack(stack L)
{
    stack p=L;
    while(p->top1 > 0)
    {
        p->top1--;
        printf("%d ",p->data[p->top1]);
    }
    printf("\n");
    while(p->top2 < MAXNUM)
    {
        printf("%d ",p->data[p->top2]);
        p->top2++;
    }
}
int main(void)
{
    stack L;
    L=(stack)malloc(sizeof(Stack));
    int x;
    Init_Stack(L);
    scanf("%d",&x);
    while(x!=0)
    {
        Pushstack1(L,x);
        scanf("%d",&x);
    }
    scanf("%d",&x);
    while(x!=0)
    {
        Pushstack2(L,x);
        scanf("%d",&x);
    }
    showstack(L);
    Popstack1(L);
    showstack(L);
    Pushstack2(L,10);
    return 0;
}
