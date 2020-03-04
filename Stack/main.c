#include<stdio.h>
#include<stdlib.h>
typedef int ElementType;
typedef struct node* LinkStack;
struct node {
    ElementType data;
    LinkStack next;
};
//��ʼ��
void InitLinkStack(LinkStack *L) {
    (*L) = NULL;
}
//��ջ
void PushStack(LinkStack *L, ElementType x) {
    LinkStack s;
    s = (LinkStack)malloc(sizeof(struct node));
    s->data = x;
    s->next = (*L); //L��ջ��Ԫ��
    (*L) = s;  //s��Ϊ�µ�ջ��Ԫ��
}
//��ջ
void PopStack(LinkStack *L) {
    if ((*L)->next == NULL) {
        printf("��ջ");
    }
    else {
        LinkStack p;
        p = (*L);  //���ջ��
        (*L) = (*L)->next;
        free(p); //��ջ
    }
}
void PrintNode(LinkStack L) {
    while (L != NULL) {
        printf("%d", L->data);
        L = L->next;
    }
    printf("\n");
}
int main() {
    LinkStack s;
    ElementType c;
    InitLinkStack(&s);
    printf("��ջԪ��Ϊ:\n");
    scanf("%d ", &c);
    while (c != 0) {
        PushStack(&s, c);
        scanf("%d", &c);
    }
    PrintNode(s);
    PopStack(&s);
    printf("ջ��ʣ��Ԫ��Ϊ:\n");
    PrintNode(s);
    PopStack(&s);
    printf("ջ��ʣ��Ԫ��Ϊ:\n");
    PrintNode(s);
}
