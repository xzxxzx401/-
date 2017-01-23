#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<ctime>
#include"My_RBTree.h"
using namespace std;
int main()
{
	My_RBTree<int> tree;
	int i=0;
	for(int i=0;i<1000;i++)
	{
		tree.insert(i);
	}
	for(int i=0;i<1000;i++)
	{
		cout<<(!tree.search(i))<<' ';
		tree.remove(i);
		cout<<(!tree.search(i))<<endl;
	}
	system("pause");
	return 0;
}