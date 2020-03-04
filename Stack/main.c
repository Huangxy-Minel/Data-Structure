#include<stdio.h>
#include<stdlib.h>
typedef int ElementType;
typedef struct node* LinkStack;
struct node {
    ElementType data;
    LinkStack next;
};
//初始化
void InitLinkStack(LinkStack *L) {
    (*L) = NULL;
}
//入栈
void PushStack(LinkStack *L, ElementType x) {
    LinkStack s;
    s = (LinkStack)malloc(sizeof(struct node));
    s->data = x;
    s->next = (*L); //L是栈顶元素
    (*L) = s;  //s成为新的栈顶元素
}
//出栈
void PopStack(LinkStack *L) {
    if ((*L)->next == NULL) {
        printf("空栈");
    }
    else {
        LinkStack p;
        p = (*L);  //标记栈顶
        (*L) = (*L)->next;
        free(p); //出栈
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
    printf("入栈元素为:\n");
    scanf("%d ", &c);
    while (c != 0) {
        PushStack(&s, c);
        scanf("%d", &c);
    }
    PrintNode(s);
    PopStack(&s);
    printf("栈中剩余元素为:\n");
    PrintNode(s);
    PopStack(&s);
    printf("栈中剩余元素为:\n");
    PrintNode(s);
}
