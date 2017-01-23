#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<ctime>
#include"My_List.h"
using namespace std;
int main()
{
	My_List<int> li;
	for(int i=0;i<10;i++)
	{
		li.InsertAsFirst(i);
	}
	system("pause");
	return 0;
}