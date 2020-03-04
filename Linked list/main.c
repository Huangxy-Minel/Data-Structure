#include <stdio.h>
#include <stdlib.h>
#define true 1
#define false 0
typedef struct node{
    int member;
    struct node *pNext;
}Node,*pNode;
pNode CreatList(int len);
void TraverseList(pNode pHead);
int Insert_node(pNode pHead,int front,int data);
int Delete(pNode pHead,int i);
int main()
{
    int n,data,m;
    pNode L;
    L=CreatList(5);
    TraverseList(L);
    printf("Please enter position and data\n");
    scanf("%d %d",&n,&data);
    m=Insert_node(L,n,data);
    TraverseList(L);
    printf("Please enter position\n");
    scanf("%d",&n);
    Delete(L,n);
    TraverseList(L);
    return 0;
}
pNode CreatList(int len)
{
    int i,val;
    pNode pHead =(pNode)malloc(sizeof(Node));
    pNode pTail = pHead;
    pTail->pNext = NULL;
    for(i=0;i< len;i++)
    {
        scanf("%d",&val);
        pNode pNew = (pNode)malloc(sizeof(Node));
        pNew->member = val;
        pTail->pNext = pNew;
        pNew->pNext = NULL;
        pTail = pNew;
    }
    return pHead;
}
void TraverseList(pNode pHead)
{
    pNode p = pHead->pNext;
    while(NULL != p)
    {
        printf("%d ",p->member);
        p = p->pNext;
    }
    printf("\n");
    return ;
}
int Insert_node(pNode pHead,int front,int data)
{
    int i=0;
    pNode p=pHead;
    if(front<1 || p==NULL)
        return 0;
    while(i<front-1)
    {
        p=p->pNext;
        ++i;
    }
    if(!p || i>front-1)
        return 0;
    pNode pNew=(pNode)malloc(sizeof(Node));
    pNew->member=data;
    pNew->pNext=p->pNext;
    p->pNext=pNew;
    return 1;
}
int Delete(pNode pHead,int i)
{
    pNode p=pHead;
    int j=0;
    for(j=0;j<i-1;j++)
        p=p->pNext;
    pNode pNew=(pNode)malloc(sizeof(Node));
    pNew=p->pNext;
    p->pNext=pNew->pNext;
    return 1;
}
