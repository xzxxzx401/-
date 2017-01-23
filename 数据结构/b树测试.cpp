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

int main()
{
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
	cout<<endl;//1111111

	bt.remove(50);
	cout<<(bt.search(20)!=nullptr);
	cout<<(bt.search(30)!=nullptr);
	cout<<(bt.search(50)!=nullptr);
	cout<<(bt.search(52)!=nullptr);
	cout<<(bt.search(60)!=nullptr);
	cout<<(bt.search(68)!=nullptr);
	cout<<(bt.search(70)!=nullptr);
	cout<<endl;//1101111

	bt.remove(68);
	cout<<(bt.search(20)!=nullptr);
	cout<<(bt.search(30)!=nullptr);
	cout<<(bt.search(50)!=nullptr);
	cout<<(bt.search(52)!=nullptr);
	cout<<(bt.search(60)!=nullptr);
	cout<<(bt.search(68)!=nullptr);
	cout<<(bt.search(70)!=nullptr);
	cout<<endl;//1101101

#ifdef _DEBUG
	system("pause");
#endif // DEBUG

	return 0;
}