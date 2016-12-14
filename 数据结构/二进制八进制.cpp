#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include "Myvector.h"
#include "Mystack.h"
#include <string>
#define HEAD_NODE -oo;
using namespace std;

const int oo=0x3f3f3f3f;
typedef long long LL;

int main()
{
	char c;
	printf("请输入一段二进制序列，以#结束\n");
	Mystack<int>sta;
	Mystack<int>res_sta;
	while(scanf("%c",&c)&&c!='#') if(c!='\n'&&c!=' ') sta.push((int) c-'0');
	while(!sta.empty())
	{
		int t_res=0;
		if(!sta.empty()) t_res+=sta.pop();
		if(!sta.empty()) t_res+=sta.pop()*2;
		if(!sta.empty()) t_res+=sta.pop()*4;
		res_sta.push(t_res);

	}
	printf("八进制序列是:");
	while(!res_sta.empty()) printf("%d",res_sta.pop());
	printf("\n");
	system("pause");
}