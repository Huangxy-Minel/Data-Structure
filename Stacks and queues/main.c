#include <stdio.h>
#include <stdlib.h>
#define N 30
void Input(long num[], int score[], int n);
void Totalave(int score[], int n);
void Scoredes(long num[], int score[], int n, int(*compare)(int a, int b));
int Ascending(int a, int b);
void Numas(long num[], int score[], int n);
void Search(long num[], int score[], int n, int x);
void statistis(long num[], int score[], int n);
void List(long num[], int score[], int n);
int main()
{
	int n, score[N], c, x, i;
	long num[N];
	printf("输入学生人数");
	scanf("%d", &n);
	printf("1.Input record\n");
	printf("2.Caculate totel and average score of course\n");
	printf("3.Sort in descending order by score\n");
	printf("4.Sort in ascending order by number\n");
	printf("5.Search by number\n");
	printf("6.Statistic analysis\n");
	printf("7.List record\n");
	printf("0.Exit\n");
	printf("Please enter your choice:\n");
	printf("\n");
	while(1)
	{
		scanf("%d", &c);
		switch (c)
		{
		case 1:
			Input(num, score, n);
			printf("Please enter your choice:\n");
			break;
		case 2:
			Totalave(score, n);
			printf("Please enter your choice:\n");
			break;
		case 3:
			Scoredes(num, score, n, Ascending);
			for (i = 0; i < n; i++)
				printf("ID:%10ld,score:%d\n", num[i], score[i]);//以长整形打印用%ld
			printf("Please enter your choice:\n");
			break;
		case 4:
			Numas(num, score, n);
			printf("Please enter your choice:\n");
			break;
		case 5:
			printf("请输入查找学号\n");
			scanf("%d", &x);
			Search(num, score, n, x);
			printf("Please enter your choice:\n");
			break;
		case 6:
			statistis(num, score, n);
			printf("Please enter your choice:\n");
			break;
		case 7:
			List(num, score, n);
			Totalave(score, n);
			printf("Please enter your choice:\n");
			break;
		case 0:
			exit(0);
		}
		c=8;
	}
	return 0;
}
void Input(long num[], int score[], int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		printf("Input student's ID and score");
		scanf("%ld% d", &num[i], &score[i]);
	}
}
void Totalave(int score[], int n)
{
	int i, sum = 0;
	double ave;
	for (i = 0; i < n; i++)
		sum = sum + score[i];
	ave = (double)sum / n;
	printf("Caculate total=%d,average score of course=%f\n", sum, ave);
}
void Scoredes(long num[], int score[], int n, int(*compare)(int a, int b))
{
	int i, j, k, t, h;
	for (i = 0; i < n; i++)
	{
		k = i;
		for (j = i + 1; j < n; j++)
		{
			if ((*compare)(score[j], score[k]))
				k = j;
		}
		if (i != k)
		{
			t = score[k], h = num[k];
			score[k] = score[i], num[k] = num[i];
			score[i] = t, num[i] = h;
		}
	}
}
int Ascending(int a, int b)
{
	return a < b;
}
void Numas(long num[], int score[], int n)
{
	int i, j, k, t, h;
	for (i = 0; i < n; i++)
	{
		k = i;
		for (j = i + 1; j < n; j++)
		{
			if (num[j] < num[k])
				k = j;
		}
		if (i != k)
		{
			t = score[k], h = num[k];
			score[k] = score[i], num[k] = num[i];
			score[i] = t, num[i] = h;
		}
	}
	for (i = 0; i < n; i++)
		printf("ID:%10ld,score:%d\n", num[i], score[i]);//以长整形打印用%ld
}
void Search(long num[], int score[], int n, int x)
{
	int high = n - 1, low = 0, mid, c = 0, pos, find = 0, i, j, k, t, h;
	for (i = 0; i < n; i++)
	{
		k = i;
		for (j = i + 1; j < n; j++)
		{
			if (num[j] < num[k])
				k = j;
		}
		if (i != k)
		{
			t = score[k], h = num[k];
			score[k] = score[i], num[k] = num[i];
			score[i] = t, num[i] = h;
		}
	}
	while (find == 0 && low <= high)
	{
		mid = (high + low) / 2;
		if (x > num[mid])
			low = mid + 1;
		else if (x < num[mid])
			high = mid - 1;
		else
		{
			pos = mid;
			find = 1;
		}
	}
	if (find == 0)
		printf("not find\n");
	else
	{
		for (i = 0; i < n; i++)
		{
			if (score[i] > score[pos])
				c++;
		}
		printf("ID:%10ld，order:%d,score:%d\n", num[pos], c + 1, score[pos]);
	}
}
void statistis(long num[], int score[], int n)
{
	int a = 0, b = 0, c = 0, d = 0, e = 0, i;
	double A, B, C, D, E;
	for (i = 0; i < n; i++)
	{
		if (score[i] >= 90)
			a++;
		else if (score[i] >= 80)
			b++;
		else if (score[i] >= 70)
			c++;
		else if (score[i] >= 60)
			d++;
		else
			e++;
	}
	A = (double)a / n * 100;
	B = (double)b / n * 100;
	C = (double)c / n * 100;
	D = (double)d / n * 100;
	E = (double)e / n * 100;
	printf("优秀人数%d,百分比:%f%%\n", a, A);
	printf("良好人数%d,百分比:%f%%\n", b, B);
	printf("中等人数%d,百分比:%f%%\n", c, C);
	printf("及格人数%d,百分比:%f%%\n", d, D);
	printf("不及格人数%d,百分比:%f%%\n", e, E);
}
void List(long num[], int score[], int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		printf("ID:%10ld,score:%d\n", num[i], score[i]);
	}
}
