#include <stdio.h>
#include <stdlib.h>
typedef struct CLinkNode
{
	EleType data;
	struct CLinkNode *next;
}CLinkNode,*CLinkList;
int main()
{
    printf("Hello world!\n");
    return 0;
}
int InitCLinkList(CLinkList *list)
{
    int i=0;
	if (list == NULL)
	{
		return ERROR;
	}
	int data = 0;
	CLinkNode* target = NULL;
	CLinkNode* head_node = NULL;
	printf("请输入学号，0代表结束初始化:\n");
	while (1)
	{
		scanf("%d", &data);
		//fflush(stdin);
		if (data == 0)
		{
			//退出循环标志，用户输入0 表示结束输入数据
			break;
		}
		if (*list == NULL)
		{
			CLinkNode* head= (CLinkNode*)malloc(sizeof(CLinkNode));
			//分配结点空间失败
			if (head == NULL)
			{
				exit(0);
			}
			*list = head;//链表指向头结点

			CLinkNode* node = (CLinkNode*)malloc(sizeof(CLinkNode));
			if (node == NULL)
			{
				exit(0);
			}
			node->data = data;
			node->next = head;
			head->next = node;
		}
		else
		{
		    for (target = (*list)->next; target->next != *list; target = target->next);
			head_node = target->next;
			CLinkNode* node = (CLinkNode*)malloc(sizeof(CLinkNode));
			if (node == NULL)
			{
				exit(0);
			}
			node->data = data;
			node->next = head_node;
			target->next = node;
		}
		i++;
    }
		return i;
}
int ShowCLinkList(CLinkList list)
{
	if (list == NULL)
	{
		return ERROR;
	}
	CLinkNode* target = NULL;
	printf("--------循环链表元素------\n");
	for (target = list->next; target != list; target = target->next)
		printf("%d \t",target->data);
		printf("\n");
	return OK;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Node pNode;
struct Node
{
    int data;
    pNode *prev, *next;
};
/* 初始化链表，尾插法 */
pNode *InitList(pNode **head, int n)
{
    pNode *p, *s;
    (*head) = (pNode *)malloc(sizeof(pNode));
    if ((*head) == NULL)
        exit(0);
    (*head)->next = NULL;//head的prev和next均指向NULL
    (*head)->prev = NULL;
    p = (*head);//p指向head
    int i;
    for (i = 0; i < n; ++i)
    {
        s = (pNode *)malloc(sizeof(pNode));
        if (s == NULL)
            exit(0);
        printf("Input the value of the %dth node:", i + 1);
        scanf("%d", &s->data);
        s->next = NULL;
        p->next = s;
        s->prev = p;
        p = s;//p指向尾节点
    }
    return p;
}
void jiaohuan(pNode *p)
{
    pNode *temp;
    temp=p->next;
    p->next=p;
    p=temp;
}
/* 遍历打印 */
void PrintList(pNode *head)
{
    pNode *p;
    p = head->next;
    if (head->next == NULL)
        printf("the list is empty\n");
    while(p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}
/* 清空链表 */
void DeleteList(pNode **head)
{
    pNode *p;
    while((*head)->next != NULL)
    {
        p = (*head);
        p->next->prev = NULL;
        (*head) = p->next;
        free(p);
    }
}
/* 查找链表内的某个值 */
int SearchList(pNode *head)
{
    int number;
    printf("Values are about to be deleted:");
    scanf("%d", &number);
    pNode *p;
    p = head->next;
    while(p != NULL)
    {
        if (p->data == number)
        {
            return number;
        }
        p = p->next;
    }
    return 0;
}
/* 删除链表中某个元素，令p的前驱节点和后驱节点相互指向即可，如果p是尾节点则直接将前驱节点指向NULL*/
void DelNumqList(pNode **head, int n)
{
    int i;
    pNode *p;
    p = (*head)->next;
    for (i = 1; i < n; ++i)
        p = p->next;
    if(p->next == NULL)
    {
        p->prev->next = NULL;
        free(p);
    }
    else
    {
        p->next->prev = p->prev;
        p->prev->next = p->next;
        free(p);
    }
}
int main(int argc, char const *argv[])
{
    int n, element, flag;
    pNode *head, *last;
    /***************************************************************/
    printf("Please input the size of the list:");
    scanf("%d", &n);
    last = InitList(&head, n);//初始化链表并赋值,返回尾节点last
    printf("%d %d \n", head->next->data, last->data); //打印为第一个元素和最后一个元素
    PrintList(head);
    /***************************************************************/
    flag = SearchList(head); //搜索某个值并删除节点
    if (flag > 0 && flag <= n)
    {
        DelNumqList(&head, flag);
        PrintList(head);
    }
    else
        printf("Element does not exist, cannot be deleted\n");
    /***************************************************************/
    DeleteList(&head);//清空列表
    PrintList(head);
    return 0;
}
