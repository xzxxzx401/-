#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<ctime>
#include"My_BinTree.h"
#include"My_BST.h"
#include"My_AVL.h"
#include"My_Vector.h"
#include"My_BTree.h"
#include"My_Splay.h"
#define MAX_AMOUNT 1000000
using namespace std;

void test1()
{
	cout<<"正整数顺序性能测试"<<endl;

	clock_t a_test1, b_test1;
	cout<<"bst,100000数据,10000次删除"<<endl;
	a_test1=clock();
	My_BST<int> bst_test1;
	for(int i=0;i<MAX_AMOUNT/10;i++)
	{
		bst_test1.insert(i);
	}
	b_test1=clock();
	cout<<"插入："<<(double)b_test1-a_test1<<endl;

	a_test1=clock();
	for(int i=0;i<MAX_AMOUNT/100;i++)
	{
		bst_test1.remove(rand()%MAX_AMOUNT/10);
	}
	b_test1=clock();
	cout<<"删除："<<(double)b_test1-a_test1<<endl;

	My_AVL<int> avl_test1;
	cout<<"avl,1000000数据,100000次删除"<<endl;
	a_test1=clock();
	for(int i=0;i<MAX_AMOUNT;i++)
	{
		avl_test1.insert(i);
	}
	b_test1=clock();
	cout<<"插入："<<(double)b_test1-a_test1<<endl;

	a_test1=clock();
	for(int i=0;i<MAX_AMOUNT/10;i++)
	{
		avl_test1.remove(rand()%MAX_AMOUNT);
	}
	b_test1=clock();
	cout<<"删除："<<(double)b_test1-a_test1<<endl;

	a_test1=clock();
	Splay<int> spl_test1;
	cout<<"splay，1000000数据，100000删除"<<endl;
	a_test1=clock();
	for(int i=0;i<MAX_AMOUNT;i++)
	{
		spl_test1.insert(i);
	}
	b_test1=clock();
	cout<<"插入："<<(double)b_test1-a_test1<<endl;

	a_test1=clock();
	for(int i=0;i<MAX_AMOUNT/10;i++)
	{
		spl_test1.remove(rand()%MAX_AMOUNT);
	}
	b_test1=clock();
	cout<<"删除："<<(double)b_test1-a_test1<<endl;
}
void test2()
{
	cout<<"随机性能测试"<<endl;

	cout<<"bst,1000000数据,100000次删除"<<endl;
	clock_t a_test2, b_test2;
	a_test2=clock();
	My_BST<int> bst_test2;
	for(int i=0;i<MAX_AMOUNT;i++)
	{
		bst_test2.insert(rand()%MAX_AMOUNT*10);
	}
	b_test2=clock();
	cout<<"插入："<<(double)b_test2-a_test2<<endl;

	a_test2=clock();
	for(int i=0;i<MAX_AMOUNT/10;i++)
	{
		bst_test2.remove(rand()%MAX_AMOUNT*10);
	}
	b_test2=clock();
	cout<<"删除："<<(double)b_test2-a_test2<<endl;

	My_AVL<int> avl_test2;
	cout<<"avl,1000000数据,100000次删除"<<endl;
	a_test2=clock();
	for(int i=0;i<MAX_AMOUNT;i++)
	{
		avl_test2.insert(rand()%MAX_AMOUNT*10);
	}
	b_test2=clock();
	cout<<"插入："<<(double)b_test2-a_test2<<endl;

	a_test2=clock();
	for(int i=0;i<MAX_AMOUNT/10;i++)
	{
		avl_test2.remove(rand()%MAX_AMOUNT*10);
	}
	b_test2=clock();
	cout<<"删除："<<(double)b_test2-a_test2<<endl;

	a_test2=clock();
	Splay<int> spl_test2;
	cout<<"splay，1000000数据，100000删除"<<endl;
	a_test2=clock();
	for(int i=0;i<MAX_AMOUNT;i++)
	{
		spl_test2.insert(rand()%MAX_AMOUNT*10);
	}
	b_test2=clock();
	cout<<"插入："<<(double)b_test2-a_test2<<endl;

	a_test2=clock();
	for(int i=0;i<MAX_AMOUNT/10;i++)
	{
		spl_test2.remove(rand()%MAX_AMOUNT*10);
	}
	b_test2=clock();
	cout<<"删除："<<(double)b_test2-a_test2<<endl;
}
int main()
{
	//srand(time(NULL));
	//test1();
	//test2();
	////test3();
	My_BTree<int> bt(3);
	
	bt.insert(20);
	bt.insert(30);
	bt.insert(50);
	bt.insert(52);
	bt.insert(60);
	bt.insert(68);
	bt.insert(70);

	cout<<(bt.search(20)!=nullptr);
	cout<<(bt.search(30)!=nullptr);
	cout<<(bt.search(50)!=nullptr);
	cout<<(bt.search(52)!=nullptr);
	cout<<(bt.search(60)!=nullptr);
	cout<<(bt.search(68)!=nullptr);
	cout<<(bt.search(70)!=nullptr);
	cout<<endl;

	bt.remove(50);
	cout<<(bt.search(20)!=nullptr);
	cout<<(bt.search(30)!=nullptr);
	cout<<(bt.search(50)!=nullptr);
	cout<<(bt.search(52)!=nullptr);
	cout<<(bt.search(60)!=nullptr);
	cout<<(bt.search(68)!=nullptr);
	cout<<(bt.search(70)!=nullptr);
	cout<<endl;

	bt.remove(68);
	cout<<(bt.search(20)!=nullptr);
	cout<<(bt.search(30)!=nullptr);
	cout<<(bt.search(50)!=nullptr);
	cout<<(bt.search(52)!=nullptr);
	cout<<(bt.search(60)!=nullptr);
	cout<<(bt.search(68)!=nullptr);
	cout<<(bt.search(70)!=nullptr);
	cout<<endl;

#ifdef _DEBUG
	system("pause");
#endif // DEBUG

	return 0;
}