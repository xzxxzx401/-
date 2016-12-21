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
	if(lo>=hi) return;//µÝ¹é»ù
	int low=lo, high=hi;
	//int key=a[lo];
	while(low<high)
	{//×¢Òâ 
		while(low<high&&a[low]<=a[high]) --high;
		/*if(low!=high)*/ swap(a[low],a[high]);
		while(a[low]<=a[high]&&low<high) ++low;
		/*if(low!=high)*/ swap(a[low], a[high]);
	}
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