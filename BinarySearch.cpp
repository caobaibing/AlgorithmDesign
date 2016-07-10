/*
	输入：n个元素的升序数组A[1..n]和需要查找的元素x
	输出：如果x=A[j],1<=j<=n,则输出j,否则输出0 
	对于一个大小为n的排序数组，二分搜索的最大比较次数为(log n)+1
*/
#include<stdio.h>
//BINARYSEARCH(A[],low,high,j,x)	可以作为子函数调用  
int A[16]={0,1,4,5,7,8,9,10,12,15,22,23,27,32,35};//测试用数组 
int main()
{
	int n=16;
	int low=1;		//查询数组的起点 
	int high=n-1;	//查询数组的终点 
	int j=0;		//查询数组的结果 
	int mid;		//中间元素 
	int x=15;		//需要查询的值 
	while(low <=high && j==0)
	{
		mid=(low+high)/2;
		if(x==A[mid])
		{
			j=mid;
		}
		else if(x<A[mid])
		{
			high = mid-1;
		}
		else
		{
			low=mid+1;
		}
	}
	printf("j=%d\n",j);
	return j;
 } 
