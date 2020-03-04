#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    int data;
    struct node *lchild,*rchild;
}bnode_type,*bnode;
//�������Ľ�������ǰ������ķ�ʽ��������������ȻҲ��������������ķ�ʽ����������
void createBiTree(bnode *T)
{
    int ch;
    scanf ("%d", &ch);
    if (0 == ch)
    {
        *T = NULL;
    }
    else
	{
		*T = (bnode)malloc(sizeof(bnode_type));	//!!! stdlib.h ͷ�ļ�һ��Ҫ�ӣ�����
		if (!*T)
		{
			exit(1);	//�����˳�
		}
		(*T)->data = ch;	//���ɸ����
		createBiTree(&((*T)->lchild));	//����������
		createBiTree(&((*T)->rchild));	//����������
	}
}
void preOrderTraverse(bnode T)
{
	if (NULL == T)
	{
		return;
	}
	printf("%d ", T->data);	//��ʾ������ݣ����Ըĳ������Խ��Ĳ���
	preOrderTraverse(T->lchild);	//���������������
	preOrderTraverse(T->rchild);	//����������������
}

void inOrderTraverse(bnode T)
{
	if (NULL == T)
	{
		return;
	}
	inOrderTraverse(T->lchild);	//�������������
	printf("%d ", T->data);			//��ʾ������ݣ����Ըĳ������Խ��Ĳ���
	inOrderTraverse(T->rchild);	//������������������
}

void postOrderTraverse(bnode T)
{
	if (NULL == T)
	{
		return;
	}
	postOrderTraverse(T->lchild);	//�Ⱥ������������
	postOrderTraverse(T->rchild);	//�ٺ������������
	printf("%d ", T->data);			//��ʾ������ݣ����Ըĳ������Խ��Ĳ���
}
void creatbsorttree(bnode *T)
{
    bnode p,q;
    *T=NULL;
    int n,i,x;
    printf("�������\n");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&x);
        p=(bnode)malloc(sizeof(bnode_type));
        p->data=x;
        p->lchild=NULL;
        p->rchild=NULL;
        if(*T == NULL)
            *T=p;
        else
        {
            q=*T;
            while(q!=NULL)
            {
                if(x<q->data)
                    if(q->lchild!=NULL) q=q->lchild;
                    else{
                    q->lchild=p;
                    q=NULL;
                }
                else
                    if(q->rchild!=NULL) q=q->rchild;
                    else
                    {
                        q->rchild=p;
                        q=NULL;
                    }
            }
        }
    }
}

void insert(bnode *root,int c)
{
    bnode s;
    if(*root==NULL)//�ݹ��������
    {
        s=(bnode)malloc(sizeof(bnode_type));
        s->data=c;
        s->lchild=NULL;
        s->rchild=NULL;
        *root=s;
    }
    else if(c<(*root)->data)
        insert(&(*root)->lchild,c);//c����������
    else if(c>(*root)->data)
        insert(&(*root)->rchild,c);//c����������
}
int GetHeight(bnode T)
{
	int hl, hr, max;
	if (T != NULL)
	{
		hl = GetHeight(T->lchild);
		hr = GetHeight(T->rchild);
		max = hl > hr ? hl : hr;
		return (max + 1);

	}
	else
		return 0;
}
int main()
{
    int x;
    bnode T=NULL;
    bnode sortt=NULL;
    createBiTree(&T);
    preOrderTraverse(T);
    printf("\n");
    inOrderTraverse(T);
    printf("\n");
    postOrderTraverse(T);
    printf("\n");
    creatbsorttree(&sortt);
    inOrderTraverse(sortt);
    printf("����������\n");
    scanf("%d",&x);
    insert(&sortt,x);
    inOrderTraverse(sortt);
    printf("\n");
    x=GetHeight(sortt);
    printf("Height:%d",x);
    return 0;
}
