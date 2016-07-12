#include<stdio.h>
/*
	输入：数组A[1..m]和它的三个索引p,q,r,1<=p<=q<r<=m,两个子数组A[p..q]和A[q+1...r]各自按升序排列
	输出:合并两个子数组 A[p..q]和A[q+1...r]的数组A[p..r] 
*/
//MERGE(A[],p,q,r)	可以作为子函数调用
int A[16]={0,1,5,8,10,15,23,27,32,35,4,7,9,12,22,28};	//测试用数组 
int main()
{
	//测试部分
	int p=1,q=9,r=15;
	 
	//函数部分 
	int B[15];		//辅助数组
	int first=p;	//p为第一个数组的第一个元素 
	int second=q+1;	//q为第二个数组的第一个元素 ,r为第二个数组的需要排序的最后一项
	int k=p; 		//k为辅助数组的起始项 
	
	while(first<=q && second<=r)//开始合并 
	{
		if(A[first]<=A[second])
		{
			B[k]=A[first];
			first=first+1;
		}	
		else
		{
			B[k]=A[second];
			second=second+1;
		}
		k=k+1;
	}
	if(first==q+1)//将未合并的数组部分合并 
	{
		while(second<=r)
		{
			B[k]=A[second];
			k+=1; 
			second+=1; 
		}
	}
	else
	{
		while(first<=q)
		{
			B[k]=A[first];
			k+=1;
			first+=1;
		}
	}
	for(int i=1;i<=r;i++)
	{
		A[i]=B[i]; 
		printf("%d	",A[i]);
	}
	return 0;
} 
