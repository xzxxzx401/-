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

struct Ele{//����Ԫ��
	int i,j;//λ��
	int val;//ֵ
	Ele(){}//����
	Ele(int _i,int _j,int _val) { i=_i;j=_j;val=_val; }//����
};

struct Martrix{//����
	My_Vector<Ele> Martrix_ele;//����Ԫ�ص���Ԫ���
	int line,cross;//line������cross������
};


void read_in(Martrix &A,Martrix &B)//���룬������Ԫ���
{
	printf("���������A�к�������");
	scanf("%d%d",&(A.line),&(A.cross));
	printf("���������A��Ԫ�أ�\n");
	for(int i=0;i < A.line;i++)
	{
		for(int j=0;j < A.cross;j++)
		{
			int temp;
			if(scanf("%d",&temp)&&temp!=0) A.Martrix_ele.push_back(Ele(i,j,temp));
		}
	}

	printf("���������B�к�������");
	scanf("%d%d",&(B.line),&(B.cross));
	printf("���������B��Ԫ�أ�\n");
	for(int i=0;i < B.line;i++)
	{
		for(int j=0;j < B.cross;j++)
		{
			int temp;
			if(scanf("%d",&temp)&&temp!=0) B.Martrix_ele.push_back(Ele(i,j,temp));
		}
	}
}
bool add(Martrix &A,Martrix &B,Martrix &C)//�ӷ������سɹ�(1)���(0)
{
	if(A.line==B.line&&A.cross==B.cross)//�ɼ�
	{
		C.cross=A.cross;C.line=A.line;
		int i=0,j=0;
		while(i < A.Martrix_ele.size()&&j < B.Martrix_ele.size())//AB��Ԫ����о���Ԫ��
		{
			if(A.Martrix_ele[i].i==B.Martrix_ele[j].i && A.Martrix_ele[i].j==B.Martrix_ele[j].j)//ͬһλ�õ�Ԫ�أ������
			{
				C.Martrix_ele.push_back(Ele(A.Martrix_ele[i].i,A.Martrix_ele[i].j,A.Martrix_ele[i].val+B.Martrix_ele[j].val));
				i++;j++;
			}
			else if(A.Martrix_ele[i].i < B.Martrix_ele[j].i||(A.Martrix_ele[i].i==B.Martrix_ele[j].i && A.Martrix_ele[i].j < B.Martrix_ele[j].j))//A��Ԫ��λ����B��Ԫ��λ��֮ǰ����A��Ԫ�طŵ������������
			{
				C.Martrix_ele.push_back(A.Martrix_ele[i]);
				i++;
			}
			else//A��Ԫ��λ����B��Ԫ��λ��֮�󣬽�B��Ԫ�طŵ������������
			{
				C.Martrix_ele.push_back(B.Martrix_ele[j]);
				j++;
			}
		}
		while(i < A.Martrix_ele.size())//A����ʣ��Ԫ��
		{
			C.Martrix_ele.push_back(A.Martrix_ele[i]);
			i++;
		}
		while(j < B.Martrix_ele.size())//B����ʣ��Ԫ��
		{
			C.Martrix_ele.push_back(B.Martrix_ele[j]);
			j++;
		}
		return 1;
	}
	else { return 0; }
}
bool mul(Martrix &A,Martrix &B,Martrix &C)//�˷������سɹ�(1)���(0)
{
	if(A.cross==B.line)//�ɳ�
	{
		C.cross=B.cross;C.line=A.line;
		My_Vector<int> t_vec;//��ʱ���飬���ڴ��ÿһ�еĽ��
		for(int r=0;r < B.cross;r++) t_vec.push_back(0);//��ʼ��
		for(int p=0,row=0;p < A.Martrix_ele.size();)//����A����ÿһ��Ԫ��
		{
			if(A.Martrix_ele[p].i!=row)//��ǰpָ���Ԫ������һ�е�
			{
				for(int r=0;r < B.cross;r++)//����ʱ����ѹ����������
				{
					if(t_vec[r]!=0)
						C.Martrix_ele.push_back(Ele(row,r,t_vec[r]));
				}
				t_vec.clear();
				for(int r=0;r < B.cross;r++) t_vec.push_back(0);//����
				row++;//��һ��
			}
			else//����������B���ҵ���ӦԪ�����˷�
			{
				for(int q=0;q < B.Martrix_ele.size();q++)
				{
					if(A.Martrix_ele[p].j==B.Martrix_ele[q].i)
						t_vec[B.Martrix_ele[q].j]+=A.Martrix_ele[p].val*B.Martrix_ele[q].val;
				}
				p++;
			}
		}
		for(int r=0;r < B.cross;r++)//�����һ�ε���ʱ�������ѹ��������
		{
			if(t_vec[r]!=0)
				C.Martrix_ele.push_back(Ele(A.line-1,r,t_vec[r]));
		}
		return 1;
	}
	else return 0;
}
void print_martrix(Martrix &A)//��ӡ����
{
	printf("\n��ӡ����\n");
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
	read_in(A,B);//�������AB

	//t1=clock();
	//fprintf(f1,"%lf\n",(double)t1 - t0);

	printf("\n����ӷ���\n");
	if(add(A,B,C))
		print_martrix(C);
	else printf("�޷���ӣ���������������ȣ�");

	//t2=clock();
	//fprintf(f1,"%lf\n",(double)t2 - t1);

	printf("\n����˷���\n");
	if(mul(A,B,D))
		print_martrix(D);
	else printf("�޷���ˣ���������������ȣ�");

	//t3=clock();
	//fprintf(f1,"%lf\n",(double)t3 - t2);


	system("pause");
}