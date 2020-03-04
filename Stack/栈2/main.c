#include<stdio.h>
#include<stdlib.h>
#define MaxSize 20
typedef struct node* SeQuence;
struct node {
    int data[MaxSize];
    int Front, Rear; //Front队头，出队用，Rear队尾，入队用
};
//初始化
void InitQuence(SeQuence *L) {
    (*L) = (SeQuence)malloc(sizeof(struct node));
    (*L)->Front = 0;
    (*L)->Rear = 0;
}
//入队
void AadQuence(SeQuence L, int x) {

    if ((L->Rear + 1) % MaxSize == L->Front) { //Front和Rear相遇队列满
        printf("满队列");
    }
    else {
        L->Rear = (L->Rear + 1) % MaxSize;  //队尾加一
        L->data[L->Rear] = x;
    }
}
//出队
void DeQuence(SeQuence L, int *x) {
    if (L->Front ==L->Rear) { //相等说明空队列
        printf("空队列");
    }
    else {
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
    printf("%d", L->data[i]); //队尾
    printf("\n");
}
void aa(SeQuence L)
{
    int i,x;
    int *y;
    y=&x;
    i = L->Rear;
    while(i != L->Front)
    {
        DeQuence(L,y);
        if(*y>0)
            AadQuence(L,x);
    }
}
int main() {
    SeQuence q;
    int* y;
    int x,i;
    y = &x;
    InitQuence(&q);
    int num[10]={2, 3, -4, 6, -5, 8, -9, 7, -10, 20};
	for(i=0;i<10;i++)
		AadQuence(q,num[i]);
    PrintQuence(q);
    aa(q);
    PrintQuence(q);

}
