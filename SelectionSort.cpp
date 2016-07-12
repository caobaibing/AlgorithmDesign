#include<stdio.h>
/*
	选择排序
	输入:n个元素的数组A[1..n]
	输出:按非降序排列的数组A[1..n] 
	算法的比较次数为 n(n-1)/2, 元素赋值次数介于0与3(n-1)之间 
*/
//SELECTIONSORT(A[])	可以作为子函数调用 
int A[16]={0,1,5,8,10,15,23,27,32,35,4,7,9,12,22,28}; //测试用数组
int main()
{
	int i;
	int minimum;//储存最小的元素
	int j;		//寻找当前最小元素后面的元素
	int n=16;	//数组元素个数
	int temp;	//临时变量
	for(i=1;i<=n-1;i++)
	{
		minimum=i;
		for(j=i+1;j<=n-1;j++)//在A[i]及之后寻找最小的元素 
		{
			if(A[j]<A[minimum])
			{
				minimum=j;
			}
		}
		if(minimum!=i)//A[i]如果不是最小的元素，则将找到的最小的元素交换之 
		{
			temp=A[i];
			A[i]=A[minimum];
			A[minimum]=temp;
		}
	 } 
	for(i=1;i<n;i++)
		printf("%d	",A[i]);
	return 0;
} 
