#include<stdio.h>
/*
	插入排序
	输入:n个元素的数组A[1..n]
	输出:按非降序排列的数组A[1..n]
	比较次数在n-1到 n(n-1)/2之间，元素赋值次数等于元素比较次数加上 n-1 
*/ 
//InsertionSort(A[],n)	可以作为子函数调用 
int A[16]={0,1,5,8,10,15,23,27,32,35,4,7,9,12,22,28}; //测试用数组
int main()
{
	int i;
	int j;
	int n=15;	//数组元素个数
	int x;
	for(i=2;i<=n;i++)
	{
		x=A[i];
		j=i-1;
		while(j>0&&A[j]>x)
		{
			A[j+1]=A[j];
			j=j-1;
		}
		A[j+1]=x;
	}
	for(i=1;i<=n;i++)
		printf("%d	",A[i]);
	return 0;
}
