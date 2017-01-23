#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<ctime>
#include"My_BST.h"
#include"My_AVL.h"
#include"My_Splay.h"
#include"My_RBTree.h"
#define MAX_AMOUNT 1000000
using namespace std;

void test1()
{
	cout<<"正整数顺序性能测试"<<endl;

	clock_t a_test1, b_test1;
	/*********************avl*********************/
	My_AVL<int> avl_test1;
	cout<<"avl,"<<MAX_AMOUNT<<"数据,"<<MAX_AMOUNT/10<<"次删除"<<endl;

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

	/*********************splay*********************/
	My_Splay<int> spl_test1;
	cout<<"splay，"<<MAX_AMOUNT<<"数据,"<<MAX_AMOUNT/10<<"次删除"<<endl;

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

	/*********************rb-tree*********************/
	My_RBTree<int> rb_test1;
	cout<<"rb，"<<MAX_AMOUNT<<"数据,"<<MAX_AMOUNT/10<<"次删除"<<endl;

	a_test1=clock();
	for(int i=0;i<MAX_AMOUNT;i++)
	{
		rb_test1.insert(i);
	}
	b_test1=clock();
	cout<<"插入："<<(double)b_test1-a_test1<<endl;

	a_test1=clock();
	for(int i=0;i<MAX_AMOUNT/10;i++)
	{
		rb_test1.remove(rand()%MAX_AMOUNT);
	}
	b_test1=clock();
	cout<<"删除："<<(double)b_test1-a_test1<<endl;
}
void test2()
{
	cout<<endl<<"正整数随机性能测试"<<endl;

	cout<<"bst,"<<MAX_AMOUNT<<"数据, "<<MAX_AMOUNT/10<<"次删除"<<endl;
	clock_t a_test2, b_test2;
	My_BST<int> bst_test2;

	a_test2=clock();
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
	cout<<"avl,"<<MAX_AMOUNT<<"数据, "<<MAX_AMOUNT/10<<"次删除"<<endl;
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

	My_Splay<int> spl_test2;
	cout<<"splay"<<MAX_AMOUNT<<"数据, "<<MAX_AMOUNT/10<<"次删除"<<endl;
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

	My_RBTree<int> rb_test2;
	cout<<"rb-tree"<<MAX_AMOUNT<<"数据, "<<MAX_AMOUNT/10<<"次删除"<<endl;
	a_test2=clock();
	for(int i=0;i<MAX_AMOUNT;i++)
	{
		rb_test2.insert(rand()%MAX_AMOUNT*10);
	}
	b_test2=clock();
	cout<<"插入："<<(double)b_test2-a_test2<<endl;

	a_test2=clock();
	for(int i=0;i<MAX_AMOUNT/10;i++)
	{
		rb_test2.remove(rand()%MAX_AMOUNT*10);
	}
	b_test2=clock();
	cout<<"删除："<<(double)b_test2-a_test2<<endl;
}
int main()
{
	srand(time(NULL));
	test1();
	test2();
	////test3();

	system("pause");

	return 0;
}