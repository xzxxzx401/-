#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<ctime>
#include"BinTree.h"
#include"BST.h"
#include"AVL.h"
#include"Myvector.h"
#include"Splay.h"
#define MAX_AMOUNT 1000000
using namespace std;

void test1()
{
	cout<<"正整数顺序性能测试"<<endl;

	clock_t a_test1, b_test1;
	cout<<"bst,100000数据,10000次删除"<<endl;
	a_test1=clock();
	BST<int> bst_test1;
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

	AVL<int> avl_test1;
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
	BST<int> bst_test2;
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

	AVL<int> avl_test2;
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
	MyVector<int> vec;
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(5);
	cout<<vec.search(0)<<endl;
	cout<<vec.search(1)<<endl;
	cout<<vec.search(2)<<endl;
	cout<<vec.search(3)<<endl;
	cout<<vec.search(5)<<endl;
	cout<<vec.search(12)<<endl;

#ifdef _DEBUG
	system("pause");
#endif // DEBUG

	return 0;
}