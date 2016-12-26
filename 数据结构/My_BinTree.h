#ifndef MY_BINTREE
#define MY_BINTREE
#include<algorithm>
#define BinNodePosi(T) BinNode<T>*
#define get_hight(p) ((p) ? (p)->hight : -1)
#define taller_child(p) (get_hight(p->lc)>get_hight(p->rc)?p->lc:p->rc)
enum RBColor{ RB_RED, RB_BLACK };

template <typename T> class My_BinNode
{
	public:
	//带参不带参构造，析构
	BinNode() :_data(0), parent(nullptr), lc(nullptr), rc(nullptr), hight(0), npl(0), color(RB_RED) {}
	BinNode(T e, BinNodePosi(T) p=nullptr, BinNodePosi(T) lc=nullptr, BinNodePosi(T) rc=nullptr, int h=0, int l=1, RBColor c=RB_RED) :
		_data(e), parent(p), lc(lc), rc(rc), hight(h), npl(l), color(c) { }
	~BinNode() {};

	//封装新节点，作为当前节点左孩子插入
	BinNodePosi(T) insertAsLC(T const &_e) { return lc=new BinNode(_e, this); }
	//封装新节点，作为当前节点右孩子插入
	BinNodePosi(T) insertAsRC(T const &_e) { return rc=new BinNode(_e, this); }
	//修改节点值
	BinNodePosi(T) modefyNode(T const &_e) { _data=_e;return this; }
	//统计当前节点为根的子树的节点数目和
	int size() { int _s=1;if(lc) _s+=lc->size();if(rc) _s+=rc->size();return s; }
	//中序后继 BinNodePosi(T) succ()
	//序遍历
	void travPre(BinNodePosi(T) _p) 
	{ 
		if(!_p) return;
		cout<<_p->_data<<' ';
		travPre(_p->lc);
		travPre(_p->rc);
	}
	void travIn(BinNodePosi(T) _p)
	{
		if(!_p) return;
		travIn(_p->lc);
		cout<<_p->_data<<' ';
		travIn(_p->rc);
	}
	void travPost(BinNodePosi(T) _p)
	{
		if(!_p) return;
		travPost(_p->lc);
		travPost(_p->rc);
		cout<<_p->_data<<' ';
	}

	//层序遍历 void travLevel(){}
	bool operator <(BinNode const & _n) { return _data<_n._data; }
	bool operator ==(BinNode const &_n) { return _data==_n._data; }



	public:
	T _data;
	BinNodePosi(T) parent; BinNodePosi(T) lc; BinNodePosi(T) rc;
	int hight;
	int npl; //Null Path Length（左式堆，也可直接用height代替）
	RBColor color; //颜色（红黑树）
};

template <typename T> class My_BinTree
{

	protected:
	//删除节点及其子树
	void remove(BinNodePosi(T) _b)
	{
		if(_b==nullptr) return;
		if(_b->lc) remove(_b->lc);
		if(_b->rc) remove(_b->rc);
		if(_b->parent)
		{
			if(_b->parent->lc==_b) _b->parent->lc=nullptr;
			if(_b->parent->rc==_b) _b->parent->rc=nullptr;
		}
		delete _b;
	}
	//更新高度
	virtual int updateHight(BinNodePosi(T) _x)
	{
		return _x->hight=1+max(get_hight(_x->lc), get_hight(_x->rc));
	}
	void updateHightAbove(BinNodePosi(T) _x)
	{
		while(_x)
		{
			updateHight(_x);
			_x=_x->parent;
		}
	}
	int _size;
	BinNodePosi(T) _root;

	public:
	BinTree() :_size(0), _root(NULL) {}
	~BinTree() {}
	virtual int size() { return _size; }
	bool empty() { return (_root==nullptr); }
	bool is_root(BinNodePosi(T) x) { return x==_root; }
	virtual BinNodePosi(T) root() const { return _root; }
	//插入根节点
	BinNodePosi(T) insertAsRoot(T const& e) { _size=1;_root=new BinNode<T>(e);return _root; }

	//作为孩子插入，返回新插入节点
	BinNodePosi(T) insertAsLC(BinNodePosi(T) _x, T const& _e)
	{
		_x->insertAsLC(_e);_size++;
		updateHightAbove(_x);
		return _x->lc;
	}
	BinNodePosi(T) insretAsRC(BinNodePosi(T) _x, T const& _e)
	{
		_x->insertAsRC(_e);_size++;
		updateHightAbove(_x);
		return _x->rc;
	}
	//接入一棵子树
	BinNodePosi(T) attachAsLC(BinNodePosi(T) _x, BinTree<T>* _S)
	{
		if(_x->lc) remove(_x->lc);
		_x->lc=_S->_root;
		_size+=_S->_size;
		updateHightAbove(x);
		_S->_root=nullptr;_S->_size=0;
		delete _S;
		return _x->lc;
	}
	BinNodePosi(T) attachAsRC(BinNodePosi(T) _x, BinTree<T>* _S)
	{
		if(_x->rc) remove(_x->rc);
		_x->rc=_S->_root;
		_size+=_S->_size;
		updateHightAbove(x);
		_S->_root=nullptr;_S->_size=0;
		delete _S;
		return _x->rc;
	}
	//序遍历
	void travPreorder() { if(_root) _root->travPre(_root); }
	virtual void travInorder() { if(_root) _root->travIn(_root); }
	void travPostorder() { if(_root) _root->travPost(_root); }
	//层序遍历 void travLevel() {}

};


#endif // !MY_BINTREE#pragma once
