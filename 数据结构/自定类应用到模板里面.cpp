#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<ctime>
#include"My_BST.h"
#include"My_RBTree.h"
using namespace std;
class integer
{
	private:
	int a;
	public:
	integer(){ a=0; }
	integer(int t){ a=t; }
	integer(const integer& A){ a=A.a; }
	~integer(){}
	bool operator <(const integer A)const{ return a<A.a; }
	bool operator ==(const integer& A){ return a==A.a; }
	friend ostream &operator<<(ostream &os, const integer &c)
	{
		os<<c.a;
		return os;
	}
	friend istream &operator>>(istream &is, integer &c)
	{
		is>>c.a;
		return is;
	}
	int& operator*() { return a; }
	int* operator->() { return &a; }
	int& operator&() { return a; }
};
int main()
{
	My_RBTree<integer> b;
	for(int i=0;i<10;i++)
	{
		b.insert(integer(i));
	}
	system("pause");
	return 0;
}