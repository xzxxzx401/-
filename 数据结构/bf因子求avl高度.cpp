#include<iostream>
#include"My_AVL.h"

using namespace std;

int hight(BinNodePosi(int) x)
{
	int hi=0;
	while(1)
	{
		hi++;
		if(!x->lc&&!x->rc) { return hi; }
		else if(AVL_BalFactor(x)>0) { x=x->lc; }
		else if(AVL_BalFactor(x)<0) { x=x->rc; }
		else if(AVL_BalFactor(x)==0) { x=(x->lc ? x->lc : x->rc); }
	}
}

int main()
{
	My_AVL<int> avl;
	for(int i=0;i<400;i++)
	{
		avl.insert(i);
	}
	cout<<hight(avl.root())<<endl;
	cout<<(avl.root())->hight<<endl;
	//���Ӧ���ǵ�һ�бȵڶ��д�1 ��Ϊavl::root()->hight�������²�ڵ�߶�Ϊ0

#ifdef _DEBUG
	system("pause");
#endif // DEBUG
	return 0;
}