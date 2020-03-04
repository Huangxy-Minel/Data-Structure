#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    int data;
    struct node *lchild,*rchild;
}bnode_type,*bnode;
//二叉树的建立，按前序遍历的方式建立二叉树，当然也可以以中序或后序的方式建立二叉树
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
		*T = (bnode)malloc(sizeof(bnode_type));	//!!! stdlib.h 头文件一定要加！！！
		if (!*T)
		{
			exit(1);	//错误退出
		}
		(*T)->data = ch;	//生成根结点
		createBiTree(&((*T)->lchild));	//构造左子树
		createBiTree(&((*T)->rchild));	//构造右子树
	}
}
void preOrderTraverse(bnode T)
{
	if (NULL == T)
	{
		return;
	}
	printf("%d ", T->data);	//显示结点数据，可以改成其他对结点的操作
	preOrderTraverse(T->lchild);	//再先序遍历左子树
	preOrderTraverse(T->rchild);	//最后先序遍历右子树
}

void inOrderTraverse(bnode T)
{
	if (NULL == T)
	{
		return;
	}
	inOrderTraverse(T->lchild);	//中序遍历左子树
	printf("%d ", T->data);			//显示结点数据，可以改成其他对结点的操作
	inOrderTraverse(T->rchild);	//最后再中序遍历右子树
}

void postOrderTraverse(bnode T)
{
	if (NULL == T)
	{
		return;
	}
	postOrderTraverse(T->lchild);	//先后序遍历左子树
	postOrderTraverse(T->rchild);	//再后序遍历右子树
	printf("%d ", T->data);			//显示结点数据，可以改成其他对结点的操作
}
void creatbsorttree(bnode *T)
{
    bnode p,q;
    *T=NULL;
    int n,i,x;
    printf("输入个数\n");
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
    if(*root==NULL)//递归结束条件
    {
        s=(bnode)malloc(sizeof(bnode_type));
        s->data=c;
        s->lchild=NULL;
        s->rchild=NULL;
        *root=s;
    }
    else if(c<(*root)->data)
        insert(&(*root)->lchild,c);//c插入左子树
    else if(c>(*root)->data)
        insert(&(*root)->rchild,c);//c插入右子树
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
    printf("输入插入的数\n");
    scanf("%d",&x);
    insert(&sortt,x);
    inOrderTraverse(sortt);
    printf("\n");
    x=GetHeight(sortt);
    printf("Height:%d",x);
    return 0;
}
