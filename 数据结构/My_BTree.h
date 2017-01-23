#ifndef MY_BTREE
#define MY_BTREE
#include "My_Vector.h"

#define BTNodePosi(T) My_BTNode<T>*
#define Swap(a,b) {int tmp=a;a=b;b=tmp;}
typedef int Rank;
template <typename>class My_BTree;
//My_BTNode节点类
template <typename T> class My_BTNode
{
	protected:
	BTNodePosi(T) parent;
	My_Vector<T> key;
	My_Vector<BTNodePosi(T)> child;

	public:

	friend class My_BTree<T>;
	My_BTNode() { parent=nullptr;child.push_back(nullptr); }
	My_BTNode(T e, BTNodePosi(T) lc=nullptr, BTNodePosi(T) rc=nullptr)
	{//注意，My_BTNode的构造只可能作为新根节点构造出来，因为B树长高一定是往根上方长
		//所以parent一定是nullptr，一定初始只有两个孩子
		//但两个孩子不一定都在存在，想想BTree最开始插入一个节点
		parent=nullptr;
		key.push_back(e);
		child.push_back(lc);child.push_back(rc);
		if(lc) lc->parent=this;if(rc) rc->parent=this;//完成孩子的连接
	}
	~My_BTNode()
	{
		key.~My_Vector();
		child.~My_Vector();
	}
	//My_BTNode不需要其他方法，因为构造出来就是根节点，不需要插入的方法
};

template <typename T> class My_BTree
{	
	protected:
	BTNodePosi(T) _root;//根节点
	BTNodePosi(T) _hot;//查找插入删除的最后访问节点
	int _order;//阶数
	int _size;//树尺寸
	void SolveOverFLow(BTNodePosi(T) v)//上溢，分裂
	{
		while(v->child.size()>_order)//当需要分裂时
		{
			Rank mid=v->key.size()/2;
			//Myvector可以提供专门的分裂方法，暂时不实现
			BTNodePosi(T) u=new My_BTNode<T>();u->child.clear();
			for(int i=mid+1;i<_order;i++)
			{
				u->child.push_back(v->child.remove(mid+1));
				u->key.push_back(v->key.remove(mid+1));
			}
			u->child.push_back(v->child.remove(mid+1));
			if(u->child[0]) { for(int i=0;i<_order-mid;i++) u->child[i]->parent=u; }
			T e=v->key.pop_back();
			BTNodePosi(T) p=v->parent;
			//若已经到根了，那么新建一个根节点，长高一下
			if(!p) { _root=p=new My_BTNode<T>();p->child[0]=v;v->parent=p; }
			Rank r_p=1+(p->key).search(v->key[0]);//找到插入位置 注意加1
			
			p->key.insert(r_p, e);
			p->child.insert(r_p+1, u);u->parent=p;//up互联
			v=v->parent;
			//delete u, p;
			int a=3;
		}
	}
	void SolveUnderFlow(BTNodePosi(T) v)//下溢，借or合并
	{
		while(v)
		{
			//当前节点未下溢，不需要分裂
			if((v->child.size()+1)/2<=_order) return;
			//当前节点是根，且没关键码了
			BTNodePosi(T) p=v->parent;
			if(!p&&v->key.size()==0)
			{
				_root=v->child[0];_root->parent=nullptr;
				delete v;
				return;
			}
			//向左兄弟借一个
			Rank r_v=0;while(p->child[r_v++]!=v);//表示v是p的第几个孩子
			if(0<r_v)
			{
				BTNodePosi(T) ls=p->child[r_v-1];//左兄弟
				if(ls->key.size()>(_order+1)/2)//左兄弟孩子够多
				{
					v->child.insert(0,ls->child.pop_back());//先过继孩子
					v->key.insert(0, ls->key.pop_back());//过继关键码
					Swap(v->key[0], p->key[r_v-1]);//与父亲的关键码交换
					if(v->child[0]) (v->child[0])->parent=v;//孩子和父亲连接
				}
				return;
			}
			//向右兄弟借
			if(r_v<p->child.size()-1)//它不是最右
			{
				BTNodePosi(T) rs=p->child[r_v+1];//右兄弟
				if(rs->key.size()>(_order+1)/2)//有兄弟孩子够多
				{
					v->child.push_back(rs->child.remove(0));//先过继孩子
					v->key.push_back(rs->key.remove(0));//过继关键码
					Swap(v->key[v->key.size()-1], p->key[r_v]);//与父亲的关键码交换
					if(v->child[v->child.size()-1]) (v->child[v->child.size()-1])->parent=v;//孩子和父亲连接
				}
				return;
			}
			if(r_v>0)//与左兄弟合并
			{
				BTNodePosi(T) ls=p->child[r_v-1];//左兄弟
				ls->key.push_back(p->key.remove(r_v-1));//将父亲的关键码转移到左兄弟里面
				p->child.remove(r_v);
				//此时ls里面关键码和孩子数一样多
				ls->child.push_back(v->child.remove(0));
				if(ls->child[ls->child.size()-1]) (ls->child[ls->child.size()-1])->parent=ls;
				while(!(v->child.empty()))//可以批量移动 需要vector提供方法
				{
					ls->child.push_back(v->child.remove(0));
					if(ls->child[ls->child.size()-1]) (ls->child[ls->child.size()-1])->parent=ls;
					ls->key.push_back(v->key.remove(0));
				}
				delete v;
				v=ls->parent;
			}
			else//与右兄弟合并
			{
				BTNodePosi(T) rs=p->child[r_v+1];//右兄弟
				rs->key.insert(0,p->key.remove(r_v));//将父亲的关键码转移到右兄弟里面
				p->child.remove(r_v);
				//此时rs里面关键码和孩子数一样多
				rs->child.insert(0,v->child.pop_back());
				if(rs->child[0]) (rs->child[0])->parent=rs;
				while(!(v->child.empty()))//可以批量移动 需要vector提供方法
				{
					rs->child.insert(0,v->child.pop_back());
					if(rs->child[0]) (rs->child[0])->parent=rs;
					rs->key.insert(0,v->key.pop_back());
				}
				delete v;
				v=rs->parent;
			}
		}
	}

	public:

	template <typename T> friend class My_BTNode;

	My_BTree(int order=3) { _order=order;_size=0;_hot=nullptr;_root=new My_BTNode<T>(); }
	~My_BTree(){}//递归析构 懒得写了 而且怕栈溢出
	const BTNodePosi(T)& root() { return _root; }//返回根的引用
	const int order() { return _order; }//返回阶数
	const int size() { return _size; }//元素数目
	bool empty() { return !_root; }//判空
	BTNodePosi(T) search(const T& e)//查找
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
	bool insert(const T& e)//返回插入是否成功
	{
		BTNodePosi(T) now=search(e);
		if(now) return false;//如果已经存在，返回它本身
		Rank r=_hot->key.search(e);
		_hot->key.insert(r+1, e);
		_hot->child.push_back(nullptr);
		_size++;
		SolveOverFLow(_hot);
		return true;
	}
	bool remove(const T& e)
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
		now->key.remove(0);now->child.pop_back();_size--;//删除节点以及一个子树(null)
		SolveUnderFlow(now);
		return true;
	}
};
#endif // !MY_BTREE