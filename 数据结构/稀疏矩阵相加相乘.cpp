#include <cstdio>
#include <cstdlib>
#include <cstring>
//#include <iostream>
#include <algorithm>
#include "My_Vector.h"
#include "My_Stack.h"
#include "My_List.h"
#include "My_Queue.h"
#include <string>
#include <time.h>

using namespace std;

struct Ele{//矩阵元素
	int i,j;//位置
	int val;//值
	Ele(){}//构造
	Ele(int _i,int _j,int _val) { i=_i;j=_j;val=_val; }//构造
};

struct Martrix{//矩阵
	My_Vector<Ele> Martrix_ele;//矩阵元素的三元组表
	int line,cross;//line行数，cross是列数
};


void read_in(Martrix &A,Martrix &B)//读入，生成三元组表
{
	printf("请输入矩阵A行和列数：");
	scanf("%d%d",&(A.line),&(A.cross));
	printf("请输入矩阵A的元素：\n");
	for(int i=0;i < A.line;i++)
	{
		for(int j=0;j < A.cross;j++)
		{
			int temp;
			if(scanf("%d",&temp)&&temp!=0) A.Martrix_ele.push_back(Ele(i,j,temp));
		}
	}

	printf("请输入矩阵B行和列数：");
	scanf("%d%d",&(B.line),&(B.cross));
	printf("请输入矩阵B的元素：\n");
	for(int i=0;i < B.line;i++)
	{
		for(int j=0;j < B.cross;j++)
		{
			int temp;
			if(scanf("%d",&temp)&&temp!=0) B.Martrix_ele.push_back(Ele(i,j,temp));
		}
	}
}
bool add(Martrix &A,Martrix &B,Martrix &C)//加法，返回成功(1)与否(0)
{
	if(A.line==B.line&&A.cross==B.cross)//可加
	{
		C.cross=A.cross;C.line=A.line;
		int i=0,j=0;
		while(i < A.Martrix_ele.size()&&j < B.Martrix_ele.size())//AB三元组表中均有元素
		{
			if(A.Martrix_ele[i].i==B.Martrix_ele[j].i && A.Martrix_ele[i].j==B.Martrix_ele[j].j)//同一位置的元素，则相加
			{
				C.Martrix_ele.push_back(Ele(A.Martrix_ele[i].i,A.Martrix_ele[i].j,A.Martrix_ele[i].val+B.Martrix_ele[j].val));
				i++;j++;
			}
			else if(A.Martrix_ele[i].i < B.Martrix_ele[j].i||(A.Martrix_ele[i].i==B.Martrix_ele[j].i && A.Martrix_ele[i].j < B.Martrix_ele[j].j))//A中元素位置在B中元素位置之前，将A中元素放到结果矩阵里面
			{
				C.Martrix_ele.push_back(A.Martrix_ele[i]);
				i++;
			}
			else//A中元素位置在B中元素位置之后，将B中元素放到结果矩阵里面
			{
				C.Martrix_ele.push_back(B.Martrix_ele[j]);
				j++;
			}
		}
		while(i < A.Martrix_ele.size())//A中有剩余元素
		{
			C.Martrix_ele.push_back(A.Martrix_ele[i]);
			i++;
		}
		while(j < B.Martrix_ele.size())//B中有剩余元素
		{
			C.Martrix_ele.push_back(B.Martrix_ele[j]);
			j++;
		}
		return 1;
	}
	else { return 0; }
}
bool mul(Martrix &A,Martrix &B,Martrix &C)//乘法，返回成功(1)与否(0)
{
	if(A.cross==B.line)//可乘
	{
		C.cross=B.cross;C.line=A.line;
		My_Vector<int> t_vec;//临时数组，用于存放每一行的结果
		for(int r=0;r < B.cross;r++) t_vec.push_back(0);//初始化
		for(int p=0,row=0;p < A.Martrix_ele.size();)//处理A矩阵每一行元素
		{
			if(A.Martrix_ele[p].i!=row)//当前p指向的元素是下一行的
			{
				for(int r=0;r < B.cross;r++)//将临时数组压入结果矩阵中
				{
					if(t_vec[r]!=0)
						C.Martrix_ele.push_back(Ele(row,r,t_vec[r]));
				}
				t_vec.clear();
				for(int r=0;r < B.cross;r++) t_vec.push_back(0);//重置
				row++;//下一行
			}
			else//否则进入矩阵B，找到对应元素做乘法
			{
				for(int q=0;q < B.Martrix_ele.size();q++)
				{
					if(A.Martrix_ele[p].j==B.Martrix_ele[q].i)
						t_vec[B.Martrix_ele[q].j]+=A.Martrix_ele[p].val*B.Martrix_ele[q].val;
				}
				p++;
			}
		}
		for(int r=0;r < B.cross;r++)//将最后一次的临时结果数组压入结果矩阵
		{
			if(t_vec[r]!=0)
				C.Martrix_ele.push_back(Ele(A.line-1,r,t_vec[r]));
		}
		return 1;
	}
	else return 0;
}
void print_martrix(Martrix &A)//打印矩阵
{
	printf("\n打印矩阵！\n");
	for(int i=0;i < A.Martrix_ele.size();i++)
		printf("(%d,%d):%d\n",A.Martrix_ele[i].i,A.Martrix_ele[i].j,A.Martrix_ele[i].val);
}
int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	//FILE *f1=fopen("time.txt","w");
	//clock_t t0,t1,t2,t3;
	//t0=clock();

	Martrix A,B,C,D;
	read_in(A,B);//读入矩阵AB

	//t1=clock();
	//fprintf(f1,"%lf\n",(double)t1 - t0);

	printf("\n矩阵加法！\n");
	if(add(A,B,C))
		print_martrix(C);
	else printf("无法相加！矩阵行列数不相等！");

	//t2=clock();
	//fprintf(f1,"%lf\n",(double)t2 - t1);

	printf("\n矩阵乘法！\n");
	if(mul(A,B,D))
		print_martrix(D);
	else printf("无法相乘！矩阵行列数不相等！");

	//t3=clock();
	//fprintf(f1,"%lf\n",(double)t3 - t2);


	system("pause");
}