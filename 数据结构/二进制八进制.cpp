#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include "My_Vector.h"
#include "My_Stack.h"
#include <string>
#define HEAD_NODE -oo;
using namespace std;

const int oo=0x3f3f3f3f;
typedef long long LL;

int main()
{
	char c;
	printf("������һ�ζ��������У���#����\n");
	My_Stack<int>sta;
	My_Stack<int>res_sta;
	while(scanf("%c",&c)&&c!='#') if(c!='\n'&&c!=' ') sta.push((int) c-'0');
	while(!sta.empty())
	{
		int t_res=0;
		if(!sta.empty()) t_res+=sta.pop();
		if(!sta.empty()) t_res+=sta.pop()*2;
		if(!sta.empty()) t_res+=sta.pop()*4;
		res_sta.push(t_res);
	}
	printf("�˽���������:");
	while(!res_sta.empty()) printf("%d",res_sta.pop());
	printf("\n");
	system("pause");
	return 0;
}