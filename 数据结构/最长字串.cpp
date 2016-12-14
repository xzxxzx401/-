#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include "Myvector.h"
#include "Mystack.h"
#include "Mylist.h"
#include "Myqueue.h"
#include <string>
using namespace std;
int LongestString(char s[],int n)  //函数返回所求长度
{
	int r_max=1,t_max=1;
	for(int i=0,j=1;j<n;)
	{
		if(s[i]==s[j])
		{
			j++;
			t_max++;
		}
		else
		{
			i=j++;
			t_max=1;
		}
		r_max=max(r_max,t_max);
	}
	return r_max;
}
int main()
{
	while(1)
	{
		char read_in[100];
		memset(read_in,0,sizeof(read_in));
		scanf("%s",read_in);
		int lenth=strlen(read_in);
		int res=LongestString(read_in,lenth);
		printf("重复子串长度%d\n",res);
	}
	

	system("pause");

}