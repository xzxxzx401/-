#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<ctime>

using namespace std;

void BubbleSort(int a[], int lo, int hi)
{
	int Ccount=0, Mcount=0;//统计比较次数和交换次数
	int low=lo, high=hi;
	bool change=1;
	for(int i=low;i<=high&&(change!=0);high--)
	{
		change=0;
		for(int j=low+1;j<=high;j++)
		{
			++Ccount;
			if(a[j-1]>a[j])//交换一次相当于移动三次，change也赋值1
			{
				swap(a[j-1], a[j]);
				Mcount+=3;
				change=1;
			}
		}
		//for(int j=lo;j<=hi;j++) printf("%d%c", a[j], j==hi ? '\n' : ' ');
	}
	cout<<"Ccount:"<<Ccount<<endl<<"Mcount:"<<Mcount<<endl;
}
void DoubleBubbleSort(int a[], int lo, int hi)
{
	int Ccount=0, Mcount=0;
	int low=lo, high=hi;
	bool change=1;
	while(low<high&&change)
	{
		change=0;
		for(int j=low+1;j<=high;j++)
		{
			++Ccount;
			if(a[j-1]>a[j])
			{
				swap(a[j-1], a[j]);
				Mcount+=3;
				change=1;
			}
		}
		high--;
		//for(int j=lo;j<=hi;j++) printf("%d%c", a[j], j==hi ? '\n' : ' ');
		for(int j=high-1;change&&j>=low;j--)
		{
			++Ccount;
			if(a[j+1]<a[j])
			{
				swap(a[j+1], a[j]);
				Mcount+=3;
				change=1;
			}
		}
		low++;
		//for(int j=lo;j<=hi;j++) printf("%d%c", a[j], j==hi ? '\n' : ' ');
	}
	cout<<"Ccount:"<<Ccount<<endl<<"Mcount:"<<Mcount<<endl;
}
int main()
{
	clock_t t1,t2;
	int a[10000+1];
	int b[10000+1];
	for(int i=1;i<=10000;i++)
	{
		//scanf("%d", &(a[i]));
		b[i]=a[i]=rand()%10000;
	}
	a[10000]=b[10000]=1;
	t1=clock();
	BubbleSort(a, 1, 10000);
	t2=clock();
	cout<<endl<<t2-t1<<endl;

	t1=clock();
	DoubleBubbleSort(b, 1, 10000);
	t2=clock();
	cout<<endl<<t2-t1<<endl;

#ifdef _DEBUG
	system("pause");
#endif // _DEBUG
	return 0;
}