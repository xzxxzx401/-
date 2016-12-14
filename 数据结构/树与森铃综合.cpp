#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
//#include "Myvector.h"
//#include "Mystack.h"
//#include "Mylist.h"
#include "Myqueue.h"
#include<queue>
#include <string>
using namespace std;
//typedef int bitree_node_type;
//struct bitree_node
//{
//	bitree_node_type data;
//	bitree_node *lson, *rson;
//};
//void creat(bitree_node* &a,int k)
//{
//	a=(bitree_node*)new bitree_node;
//	a->data=k;a->lson=a->rson=NULL;
//	int lk,rk;
//	cout<<"请输入"<<a->data<<"的两个儿子"<<endl;
//	cin>>lk>>rk;
//	if(lk!=0)
//		creat(a->lson,lk);
//	if(rk!=0)
//		creat(a->rson,rk);
//}
//void pre_visit(bitree_node *head)
//{
//	cout<<head->data<<' ';
//	if(head->lson!=NULL) pre_visit(head->lson);
//	if(head->rson!=NULL) pre_visit(head->rson);
//}
//void mid_visit(bitree_node *head)
//{
//	if(head->lson!=NULL) mid_visit(head->lson);
//	cout<<head->data<<' ';
//	if(head->rson!=NULL) mid_visit(head->rson);
//}
//bool JudgeComplete(bitree_node *bt)
//{
//	Myqueue<bitree_node*> que;que.push(bt);
//	bool ok=0;
//	while(!que.empty())
//	{
//		bitree_node* now=que.pop();
//		if(ok){ if(now->lson!=NULL||now->rson!=NULL) return false; }
//		else
//		{
//			if(now->lson!=NULL)
//			{
//				que.push(now->lson);
//				if(now->rson!=NULL) que.push(now->rson);
//				else ok=1;
//			}
//			else
//			{
//				if(now->rson==NULL) ok=1;
//				else return false;
//			}
//		}
//	}
//	return true;
//}
struct node{
	int data=1;
	node *firstchild=NULL,*nextsibling=NULL;
};
int degree(node* root)
{
	Myqueue<node*> que; que.push(root);
	int num=0;
	while(!que.empty())
	{
		node* now=que.pop();
		if(now==NULL) continue;
		if(now->firstchild==NULL) num++;
		que.push(now->firstchild);
		que.push(now->nextsibling);
	}
	return num;
}
int main()
{
	/*bitree_node *head=NULL;
	int head_k;
	cin>>head_k;
	creat(head,head_k);
	pre_visit(head);
	cout<<endl;
	mid_visit(head);
	cout<<endl;

	cout<<JudgeComplete(head)<<endl;*/

	node* head=(node*)new(node);
	head->data=1;
	head->firstchild=(node*)new(node);
	head->firstchild->firstchild=(node*)new(node);
	head->firstchild->firstchild->nextsibling=(node*)new(node);
	head->firstchild->nextsibling=(node*)new(node);
	head->firstchild->nextsibling->nextsibling=(node*)new(node);
	cout<<degree(head)<<endl;
	system("pause");
	return 0;
}