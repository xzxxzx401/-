#ifndef BTREE_H
#define BTREE_H
#include "Myvector.h"//可替换成stl::vector

#define BTNodePosi(T) BTNode<T>*
typedef int Rank;

//BTNode节点类
template <typename T> class BTNode
{
	protected:
	BTNodePosi(T) parent;
	MyVector<T> key;
	MyVector<BTNodePosi(T)> child;

	public:
	BTNode() { parent=nullptr;child.push_back(nullptr); }
	BTNode(T e, BTNodePosi(T) lc=nullptr, BTNodePosi(T) rc=nullptr)
	{//注意，BTNode的构造只可能作为新根节点构造出来，因为B树长高一定是往根上方长
		//所以parent一定是nullptr，一定初始只有两个孩子
		//但两个孩子不一定都在存在，想想BTree最开始插入一个节点
		parent=nullptr;
		key.push_back(e);
		child.push_back(lc);child.push_back(rc);
		if(lc) lc->parent=this;if(rc) rc->parent=this;//完成孩子的连接
	}
	//BTNode不需要其他方法，因为构造出来就是根节点，不需要插入的方法
};

template <typename T> class BTree
{
	protected:
	BTNodePosi(T) _root;//根节点
	BTNodePosi(T) _hot;//查找插入删除的最后访问节点
	int _order;//阶数
	int _size;//树尺寸
	BTNodePosi(T) SolveOverFLow(BTNodePosi(T) s)//上溢，分裂
	{
		while(s->key.size()>_order)//当需要分裂时
		{

		}
	}
	void SolveUnderFlow(BTNodePosi(T) s)//下溢，借or合并
	{

	}

	public:
	BTree(int order=3) { _order=order;_size=0;_hot=nullptr;_root=new BTNode<T>(); }
	~BTree(){}//递归析构 懒得写了 而且怕栈溢出
	const BTNodePosi(T)& root() { return _root; }//返回根的引用
	const int order() { return _order; }//返回阶数
	const int size() { return _size; }//元素数目
	bool empty() { return !_root; }//判空
	const BTNodePosi(T)& search(const T& e)//查找
	{
		BTNodePosi(T) now=_root;_hot=nullptr;
		while(now) 
		{ 
			Rank x=now->key.search(e);//调用search，找不大于e的第一个位置
			if(0<=x&&now->key[x]==e) return now;//确实找到了，返回当前now引用
			_hot=now;now=now->child[x+1];//转向右孩子引用
		}
		return nullptr;//没找到返回null
	}
	BTNodePosi(T) insert(const T& e)
	{
		BTNodePosi(T) now=search(e);
		if(now) return now;//如果已经存在，返回它本身
		Rank r=_hot->key.search(e);
		_hot->key.insert(r+1, e);
		_hot->child.push_back(nullptr);
		_size++;
		return SolveOverFLow(_hot);
	}
	bool remove()
	{
		BTNodePosi(T) now=search(e);
		if(!now) return false;//如果不存在，则认为已删除
		Rank r=now->key.search(e);
		if(now->child[0]) 
		{
			BTNodePosi(T) succ=now->child[0];//有后继
			while(succ->child[0]) succ=succ->child[0];//不断左找找后继
			Swap(now->key[r], succ->key[0]);//用后继代替now->key[r]
			now=succ;
		}
		now->key.remove(0);now->child.pop_back();size--;//删除节点以及一个子树(null)
		SolveUnderFlow(now);
		return true;
	}
};


#endif // !BTREE
