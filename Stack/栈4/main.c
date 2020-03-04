#include<stdio.h>
#include<stdlib.h>
#define MaxSize 5
typedef struct node* SeQuence;
struct node {
    int data[MaxSize];
    int Front, Rear,Flag; //Front队头，出队用，Rear队尾，入队用
};
//初始化
void InitQuence(SeQuence *L) {
    (*L) = (SeQuence)malloc(sizeof(struct node));
    (*L)->Front = 0;
    (*L)->Rear = 0;
    (*L)->Flag = 0;
}
//入队
void AadQuence(SeQuence L, int x) {

    if (L->Flag==1) { //Front和Rear相遇队列满
        printf("满队列");
        return ;
    }
    else {
        if((L->Rear + 1) % MaxSize == L->Front)
        {
            L->Flag=1;
        }
        L->Rear = (L->Rear + 1) % MaxSize;  //队尾加一
        L->data[L->Rear] = x;
    }
}
//出队
void DeQuence(SeQuence L, int *x) {
    if (L->Front ==L->Rear && L->Flag==0) { //相等说明空队列
        printf("空队列");
    }
    else {
            if(L->Flag==1)
            {
                *x=L->data[L->Front];
                L->Flag=0;
                L->Front = (L->Front + 1) % MaxSize;
                return;
            }
        L->Front = (L->Front + 1) % MaxSize; //队头加一
        *x = L->data[L->Front];
    }
}
void PrintQuence(SeQuence L) {
    int i;
    i = (L->Front + 1) % MaxSize; //队头加一开始遍历
    while (i != L->Rear) {
        printf("%d ", L->data[i]);
        i = (i + 1) % MaxSize;
    }
    printf("%d ", L->data[i]); //队尾
    printf("\n");
}
int main() {
    SeQuence q;
    int* y;
    int x,i;
    y = &x;
    InitQuence(&q);
     scanf("%d",&x);
    while(x!=0)
    {
        AadQuence(q,x);
        scanf("%d",&x);
    }
    PrintQuence(q);
    for(i=0;i<3;i++)
        DeQuence(q,y);
    PrintQuence(q);
    scanf("%d",&x);
    while(x!=0)
    {
        AadQuence(q,x);
        scanf("%d",&x);
    }
    PrintQuence(q);
    return 0;
}
