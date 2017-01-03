#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

typedef char tree_node_elem_type;
struct tree_node
{
	tree_node_elem_type data;
	tree_node *lchild, *rchild;
	tree_node() { lchild=rchild=nullptr;data=0; }
};
void build(tree_node* &(root))
{
	char a;
	cin>>a;
	if(a=='*') return;
	root=(tree_node*)new tree_node;
	root->data=a;
	root->lchild=nullptr;
	root->rchild=nullptr;

	build(root->lchild);
	build(root->rchild);
}
void previsit(tree_node* &(root))
{
	cout<<root->data;
	if(root->lchild) previsit(root->lchild);
	if(root->rchild) previsit(root->rchild);
}
int main()
{
	string ss;
	cout<<"ÇëÊäÈë½¨Ê÷ÐòÁÐ£º";
	tree_node *root;
	build(root);
	previsit(root);
	cout<<endl;
	system("pause");
	return 0;
}