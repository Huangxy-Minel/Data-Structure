#include<stdio.h>
#include<string.h>
struct student
{
	char name[20];
};
struct student s[30];
int hash(char *cp)//哈希查找
{
	int sum=0;
	int n,k;
	char *q;
	q=cp;
	int i;
	n=strlen(cp);
	for(i=0;i<n;i++)
	{
		sum+=(*cp);
		cp++;
	}
	k=sum%30;
	while(s[k].name[0]!='\0'&&strcmp(s[k].name,q)!=0)
	{k=(k+1)%30;}
	if(s[k].name[0]!='\0')
	{printf("searching success\n");}
	else
	printf("searching failed\n");
	return 0;
}
void hash_save()//哈希表的建立
{
	int i=0,n,sum=0;
	int k;
	char name[20];
	char *p;
	printf("input the number of the names:\t");
	scanf("%d",&n);
	while(n--)
	{
		printf("input the name:");
		scanf("%s",name);
		p=name;
		k=strlen(p);
	    for(i=0;i<k;i++)
		{
		sum+=(*p);
		p++;
		}
	    k=sum%30;
		while(s[k].name[0]!='\0')
		{
			k=(k+1)%30;
		}
		i=0;
		while(name[i]!='\0')
		{
			s[k].name[i]=name[i];
			i++;
		}
	}
}
int main(void)
{
	void hash_save();
	int hash(char *cp);
	hash_save();
	char name[20];
	printf("input  one name to search:\t");
	scanf("%s",name);
	hash(name);
	printf("input the another name to search:\t");
	scanf("%s",name);
	hash(name);
	return 0;
}
