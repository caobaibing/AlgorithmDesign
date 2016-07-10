#include<stdio.h>
/*
	输入：数组A[1..m]和它的三个索引p,q,r,1<=p<=q<r<=m,两个子数组A[p..q]和A[q+1...r]各自按升序排列
	输出:合并两个子数组 A[p..q]和A[q+1...r]的数组A[p..r] 
*/
//MERGE(A[],p,q,r)	可以作为子函数调用
int A[16]={0,1,5,8,10,15,23,27,32,35,4,7,9,12,22,27};	//测试用数组 
int main()
{
	//测试部分
	int p=1,q=9,r=15;
	 
	//函数部分 
	int B[15];		//辅助数组
	int s=p;		//s为第一个数组的第一个元素 
	int t=q+1;		//t为第二个数组的第一个元素 
	int k=p; 		//k为辅助数组的起始项 
	
	while(s<=q && t<=r)//开始合并 
	{
		if(A[s]<=A[t])
		{
			B[k]=A[s];
			s=s+1;
		}	
		else
		{
			B[k]=A[t];
			t=t+1;
		}
		k=k+1;
	}
	if(s==q+1)//将未合并的数组部分合并 
	{
		while(t<=r)
		{
			B[k]=A[t];
			k+=1; 
			t+=1; 
		}
	}
	else
	{
		while(s<=q)
		{
			B[k]=A[s];
			k+=1;
			s+=1;
		}
	}
	for(int i=1;i<r;i++)
	{
		A[i]=B[i]; 
		printf("%d	",A[i]);
	}
	return 0;
} 
