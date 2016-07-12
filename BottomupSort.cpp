#include<stdio.h>
/*
	自底向上合并排序
	输入:n个元素的数组A[1..n]
	输出:按非降序排列的数组
	当n为2的幂时,元素比较次数在(nlog n)/2到 (nlog n)-n+1之间。
	赋值次数为2nlog n  
*/
//BottonupSort(A[],n)	可以作为子函数调用 
int A[16]={0,1,5,8,10,15,23,27,32,35,4,7,9,12,22,28};//测试数组 

int Merge(int A[],int p,int q,int r)
{
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
	}
	return 0;
}
int main()
{
	int t=1;
	int n=15;
	int s=t;
	int i;
	while (t<n)
	{
		s=t;
		t=2*s;
		i=0;
		while(i+t<=n)
		{
			Merge(A,i+1,i+s,i+t);
			i=i+t;
		}
		if(i+s<n)
			Merge(A,i+1,i+s,n);
	 } 
	 for(int i=1;i<=n;i++)
	{
		printf("%d	",A[i]);
	}
	return 0;
}
