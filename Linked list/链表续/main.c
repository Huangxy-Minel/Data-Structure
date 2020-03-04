#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    int member;
    struct node *pNext;
}Node,*pNode;
typedef struct DNode		//定义双链表结点类型
{
	int data;
	struct DNode *prior;	//指向前驱结点
	struct DNode *next;		//指向后继结点
} DNode,*dNode;
pNode CreatList1(void);
dNode CreatList(void);
void TraverseListd(dNode dHead);
void Bubble(dNode dHead);
int Insert_node(pNode pHead,int front,int data);
int Delete(pNode pHead,int i);
int FindNode(pNode pHead,int n);
void TraverseList(pNode pHead);
void Deletefu(pNode pHead);
void Insert_youxu(pNode pHead,int x);
int main()
{
    int n,m;
    pNode L;
    dNode D;
    D=CreatList();
    TraverseListd(D);
    //Bubble(D);
    TraverseListd(D);
    printf("Plesae enter the data.\n");
    L=CreatList1();
    TraverseList(L);
    printf("Plesae enter the data you want to find.\n");
    scanf("%d",&n);
    m=FindNode(L,n);
    TraverseList(L);
    Insert_youxu(L,3);
    TraverseList(L);
    Deletefu(L);
    TraverseList(L);
    return 0;
}
pNode CreatList1(void)
{
    int val;
    pNode pHead =(pNode)malloc(sizeof(Node));
    pNode pTail = pHead;
    pTail->pNext = NULL;
    while(1)
    {
        scanf("%d",&val);
        if(val==0)
            break;
        pNode pNew = (pNode)malloc(sizeof(Node));
        pNew->member = val;
        pTail->pNext = pNew;
        pNew->pNext = NULL;
        pTail = pNew;
    }
    return pHead;
}
dNode CreatList(void)
{
    int val;
    dNode dHead = (dNode)malloc(sizeof(DNode));
    dNode dTail = dHead;
    dTail->next = NULL;
    dTail->prior = NULL;
    while(1)
    {
        scanf("%d",&val);
        if(val==0)
            break;
        dNode dNew = (dNode)malloc(sizeof(DNode));
        dNew->data=val;
        dNew->next=NULL;
        dNew->prior=dTail;
        dTail->next=dNew;
        dTail=dNew;
    }
    return dHead;
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
void TraverseListd(dNode dHead)
{
    dNode p=dHead->next;
    while(p!=NULL)
    {
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
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

int FindNode(pNode pHead,int n)
{
    int i=1;
    pNode p = pHead->pNext;
    while(p!=NULL)
    {
        if(p->member==n)
        {
            Delete(pHead,i);
            return 1;
        }
        p=p->pNext;
        i++;
    }
    Insert_node(pHead,i,n);
    return 0;
}
void Deletefu(pNode pHead)
{
    pNode p=pHead;
    pNode pp=p->pNext;
    while(p->pNext!=NULL)
    {
        pp=p->pNext;
        if(pp->member<0)
        {
           p->pNext=pp->pNext;
        }
        if(pp->member>0)
        p=p->pNext;
    }
}
void Insert_youxu(pNode pHead,int x)
{
    pNode p=pHead->pNext;
    int i=1;
    while(p!=NULL)
    {
        if(x >= p->member && x < p->pNext->member)
        {
           Insert_node(pHead,i+1,x);
           break;
        }
        i++;
        p=p->pNext;
    }
}
void Bubble(dNode dHead)
{
    dNode p = dHead->next;
    dNode temp = p;
    int i=0,j,k;
    while(p!=NULL)
    {
        p=p->next;
        i++;
    }
    printf("%d\n",i);
    p=dHead->next;
    for(j=1;j<i;j++)
    {
        for(k=1;k<i-1;k++)
        {
            if((p->data) > (p->next->data))
            {
                temp=p->next;
                p->prior->next=temp;
                temp->next->prior=p;
                p->next=temp->next;
                temp->prior=p->prior;
                temp->next=p;
                p->prior=temp;
                p=p->prior;
                printf("%d\n",p->data);
            }
            if(p->next==NULL)
                break;
            p=p->next;
        }
        p=dHead->next;
    }
}
