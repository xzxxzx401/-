#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<ctime>
#include"My_BST.h"
using namespace std;
int main()
{
	My_BST<int> b;
	for(int i=0;i<10;i++)
	{
		b.insert(i);
	}
	system("pause");
	return 0;
}