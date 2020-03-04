#include<stdio.h>
#define N 8
int seq_search(int s[],int k)//À≥–Ú≤È’“£¨∑µªÿ–Ú∫≈
{
	int i;
	i=0;
	while(s[i]!=k)
	{
		i++;
	}
	if(i<N)
	{
		printf("searching success");
		return i;
	}
	else
	{
		printf("\tsearching failed\n");
		return (-1);
	}
}
int bin_search(int s[],int k)//∂˛∑÷≤È’“£¨∑µªÿ–Ú∫≈
{
	int low,high,mid;
	high=N-1;
	low=0;
	while(low<=high)
	{
		mid=(low+high)/2;
		if(s[mid]==k)
		{
			printf("searching success");
			return(mid);
		}
		else if(s[mid]<k)
		{
			low=mid+1;
		}
		else
			high=mid-1;
	}
	printf("\tsearching failed");
	return (-1);
}
void main()
{
	int s[N]={3,10,13,17,40,43,50,70};
	int k1=43,k2=5;
	int t;
	printf("using the seq_search :\n\t");
	printf("k=43:\t");
	t=seq_search(s,k1);
	if(t!=-1)
	printf("\t%d\n",s[t]);
	printf("\tk=5:\t");
	t=seq_search(s,k2);
	if(t!=-1)
	printf("\t%d\n\n",s[t]);
	printf("using the bin_search :\n\t");
	printf("k=43:\t");
	t=bin_search(s,k1);
	if(t!=-1)
	printf("\t%d\n",s[t]);
	printf("\tk=5:\t");
	t=bin_search(s,k2);
	if(t!=-1)
	printf("\t%d\n",s[t]);
}
