#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<ctime>

using namespace std;
int a[1000000+1];
void q_sort(int lo, int hi)
{
	if(lo>=hi) return;//递归基
	int low=lo, high=hi;

	//三者取中
	int kk=(low+high)/2;
	if(a[kk]>a[low]&&a[kk]>a[high]) kk=(a[lo]>=a[high] ? lo : high);
	else if(a[kk]<a[low]&&a[kk]<a[high]) kk=(a[lo]<=a[high] ? lo : high);
	int key=a[kk];

	while(low<high)
	{
		while(low<high&&key<=a[high]) --high;
		/*if(low!=high)*/ a[low]=a[high];
		while(low<high&&a[low]<=key) ++low;
		/*if(low!=high)*/ a[high]=a[low];
	}
	a[low]=key;
	q_sort(lo, low-1);
	q_sort(high+1, hi);
}
int main()
{
	srand((unsigned)time(NULL));
	for(int i=1;i<=1000000;i++)
	{
		a[i]=rand()%2000000;
		//printf("%d%c", a[i], i==10 ? '\n' : ' ');
	}
	q_sort(1, 1000000);
	for(int i=1;i<=100;i++)
	{
		printf("%d%c", a[i], i%10==0 ? '\n' : ' ');
	}
#ifdef _DEBUG
	system("pause");
#endif // _DEBUG
	return 0;
}