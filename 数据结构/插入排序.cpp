#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<ctime>

using namespace std;

void InsertSort(int a[],int n)
{
	int Ccount=0, Mcount=0;
	for(int i=2;i<=n;i++)
	{
		if(++Ccount&&a[i]<a[i-1])
		{
			a[0]=a[i];
			Mcount++;
			a[i]=a[i-1];
			Mcount++;
			int j=0;
			for(j=i-2;++Ccount&&a[0]<a[j];j--)
			{
				a[j+1]=a[j];
				Mcount++;
			}
			a[j+1]=a[0];
			Mcount++;
		}
	#ifdef _DEBUG
		for(int i=0;i<=10;i++) printf("%d%c", a[i], i==10 ? '\n' : ' ');
	#endif // _DEBUG
		
	}
#ifdef _DEBUG
	cout<<"Ccount:"<<Ccount<<endl<<"Mcount:"<<Mcount<<endl;
#endif // _DEBUG
}
void BinInsertSort(int a[], int n)
{
	int Ccount=0, Mcount=0;
	for(int i=2;i<=n;i++)
	{
		int hi=i-1, lo=1,mid=0;
		a[0]=a[i];
		Mcount++;
		while(lo<=hi)
		{
			mid=(lo+hi)>>1;
			if(++Ccount&&a[mid]>a[0]) hi=mid-1;
			else lo=mid+1;
		}
		for(int j=i-1;j>=lo;j--)
		{
			a[j+1]=a[j];
			Mcount++;;
		}
		a[lo]=a[0];
		Mcount++;
	#ifdef _DEBUG
		for(int i=0;i<=10;i++) printf("%d%c", a[i], i==10 ? '\n' : ' ');
	#endif // _DEBUG
	}
#ifdef _DEBUG
	cout<<"Ccount:"<<Ccount<<endl<<"Mcount:"<<Mcount<<endl;
#endif // _DEBUG
}
int main()
{//Ccount统计比较次数,Mcount统计移动次数
	int a[10+1];
	for(int i=1;i<=10;i++)
	{
		a[i]=100-i;
		//scanf("%d", &a[i]);
	}
	InsertSort(a, 10);
	for(int i=1;i<=10;i++)
	{
		a[i]=100-i;
		//scanf("%d", &a[i]);
	}
	BinInsertSort(a, 10);
#ifdef _DEBUG
	system("pause");
#endif // _DEBUG
	return 0;
}