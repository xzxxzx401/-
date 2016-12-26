#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<ctime>
#include"My_Priority_Queue.h"

using namespace std;
void SelectSort(int a[],int lo,int hi)
{
	int Ccount=0,Mcount=0;
	//比较次数和初始状态无关，永远为n*(n-1)/2
	for(int i=hi;i>=lo;i--)
	{
		int max_num=lo;
		for(int j=lo+1;j<=i;j++)
		{
			if(++Ccount&&a[j]>a[max_num]) max_num=j;
		}
		if(i!=max_num)
		{
			swap(a[i],a[max_num]);
			Mcount+=3;
		}
	}
	cout<<"Ccount:"<<Ccount<<endl<<"Mcount:"<<Mcount<<endl;
}

int main()
{
	int a[10+1];
	for(int i=1;i<=10;i++)
	{
		//scanf("%d",&a[i]);
		a[i]=i;
	}
	SelectSort(a,1,10);
	for(int i=1;i<=10;i++)
	{
		printf("%d%c",a[i],i%10==0 ? '\n' : ' ');
	}
	system("pause");
	return 0;
}