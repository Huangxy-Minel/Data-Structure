#include<stdio.h>
#include<stdlib.h>
#define MaxSize 20
typedef struct node* SeQuence;
struct node {
    int data[MaxSize];
    int Front, Rear; //Front��ͷ�������ã�Rear��β�������
};
//��ʼ��
void InitQuence(SeQuence *L) {
    (*L) = (SeQuence)malloc(sizeof(struct node));
    (*L)->Front = 0;
    (*L)->Rear = 0;
}
//���
void AadQuence(SeQuence L, int x) {

    if ((L->Rear + 1) % MaxSize == L->Front) { //Front��Rear����������
        printf("������");
    }
    else {
        L->Rear = (L->Rear + 1) % MaxSize;  //��β��һ
        L->data[L->Rear] = x;
    }
}
//����
void DeQuence(SeQuence L, int *x) {
    if (L->Front ==L->Rear) { //���˵���ն���
        printf("�ն���");
    }
    else {
        L->Front = (L->Front + 1) % MaxSize; //��ͷ��һ
        *x = L->data[L->Front];
    }
}
void PrintQuence(SeQuence L) {
    int i;
    i = (L->Front + 1) % MaxSize; //��ͷ��һ��ʼ����
    while (i != L->Rear) {
        printf("%d ", L->data[i]);
        i = (i + 1) % MaxSize;
    }
    printf("%d", L->data[i]); //��β
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
