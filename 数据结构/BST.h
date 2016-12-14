#ifndef BinSearchTree
#define BinSearchTree

#include "BinTree.h"

template <typename T> class BST :protected BinTree<typename T>
{
	//bstģ���� �鷽���Ĳ��Ҳ���ɾ��
	protected:
	BinNodePosi(T) _hot;
	/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!//
	!!ע�⣬v�Ǹ����ã�������ʱ��ָ��������Բ����޸�v�������������ƶ�!!
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
		//ע��x�Ǹ����ã���x�����Ǹ�xָ��ָ���Ԫ�أ����Ǹ�xָ��Ԫ�ص�ֵ������else������붨λ��parent�������
		BinNodePosi(T) succ=nullptr;//��ɾ���ڵ�ĺ��
		BinNodePosi(T) now=x;//ʵ�ʱ�ɾ���ڵ㣬��ֵΪx
		if(x->lc==nullptr) succ=x=x->rc;
		else if(x->rc==nullptr) succ=x=x->lc;
		else//�ҵ�x�������ֱ�Ӻ��
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
	//����
	virtual BinNodePosi(T)& search(const T& e) { return searchIn(_root, e, _hot=NULL); }
	//����
	virtual BinNodePosi(T) insert(const T& e)//����
	{
		BinNodePosi(T)& x=search(e); 
		if(x) return x;
		x=new BinNode<T>(e, _hot); 
		_size++;
		updateHightAbove(x);
		return x;
	}
	//ɾ��
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
