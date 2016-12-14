#ifndef BinSearchTree
#define BinSearchTree

#include "BinTree.h"

template <typename T> class BST :protected BinTree<typename T>
{
	//bst模板类 虚方法的查找插入删除
	protected:
	BinNodePosi(T) _hot;
	/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!//
	!!注意，v是个引用，进来的时候指向跟，所以不能修改v，否则树根会移动!!
	//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
	static BinNodePosi(T)& searchIn(BinNodePosi(T)& v, const T& e, BinNodePosi(T)& _hot)
	{
		if(!v||v->_data==e) return v;
		_hot=v;
		while(1)
		{
			BinNodePosi(T) &c=(e < _hot->_data) ? _hot->lc : _hot->rc;
			if(!c||c->_data==e) return c;
			_hot=c;
		}
	}

	void removeAt(BinNodePosi(T) &x, BinNodePosi(T) &hot)
	{
		//注意x是个引用，改x并不是改x指针指向的元素，而是改x指向元素的值，所以else里面必须定位到parent完成链接
		BinNodePosi(T) succ=nullptr;//被删除节点的后继
		BinNodePosi(T) now=x;//实际被删除节点，初值为x
		if(x->lc==nullptr) succ=x=x->rc;
		else if(x->rc==nullptr) succ=x=x->lc;
		else//找到x的中序得直接后继
		{
			now=x->rc;	while(now->lc) now=now->lc;
			T temp=now->_data; now->_data=x->_data; x->_data=temp;
			
			BinNodePosi(T) u=now->parent;
			(u==x ? u->rc : u->lc)=now->rc;
			succ=now->rc;

		}
		hot=now->parent;
		if(succ) succ->parent=now->parent;
	}

	public:
	//查找
	virtual BinNodePosi(T)& search(const T& e) { return searchIn(_root, e, _hot=NULL); }
	//插入
	virtual BinNodePosi(T) insert(const T& e)//插入
	{
		BinNodePosi(T)& x=search(e); 
		if(x) return x;
		x=new BinNode<T>(e, _hot); 
		_size++;
		updateHightAbove(x);
		return x;
	}
	//删除
	virtual bool remove(const T& e)
	{
		BinNodePosi(T)& x=search(e);
		if(!x) return false;
		removeAt(x,_hot);
		_size--;
		updateHightAbove(_hot);
		return true;
	}
	void travInorder() { return BinTree::travInorder(); }
	BinNodePosi(T) root() { return BinTree::root(); }
	int size() { return _size; }
};


#endif // !BinSearchTree#pragma once
