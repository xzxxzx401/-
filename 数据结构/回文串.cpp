#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include "My_Stack.h"
#include "My_Queue.h"
#include <string>
using namespace std;

int main()
{
	My_Queue<char> que;
	My_Stack<char> sta;
	char t;
	while(scanf("%c",&t)&&t!='#')
	{
		if(t!='\n')
		{
			que.push(t);
			sta.push(t);
		}
	}
	char ta,tb;
	bool flag=0;
	while(!que.empty())
	{
		ta=que.pop();tb=sta.pop();
		if(ta!=tb) { flag=1;break; }
	}
	if(!flag) printf("�����ǻ��Ĵ���\n");
	else printf("���벻�ǻ��Ĵ���\n");
	system("pause");
	return 0;
}