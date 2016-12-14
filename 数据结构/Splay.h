#ifndef SPLAY_TREE
#define SPLAY_TREE
#include"BST.h"
#include"BinTree.h"
#define IsLc(x) (x->parent!=nullptr?(x->parent->lc==x?true:false):(false))

template <typename T> class Splay:protected BST<typename T>//伸展树，双层伸展
{
	protected:
	BinNodePosi(T) splay(BinNodePosi(T) v)//从v开始伸展,返回伸展后的树根
	{
		if(v==_root) return v;
		BinNodePosi(T) p=nullptr; BinNodePosi(T) g=nullptr;
		while((p=v->parent)&&(g=p->parent))
		{//注意考虑子树为空
			int flag=0;
			BinNodePosi(T) gg=g->parent;
			IsLc(g) ? flag=0 : flag=1;
			if(IsLc(p)&&IsLc(v))//zig_g-zig_p
			{
				g->lc=p->rc;if(g->lc) g->lc->parent=g;
				p->lc=v->rc;if(p->lc) p->lc->parent=p;
				v->rc=p;p->parent=v;
				p->rc=g;g->parent=p;
			}
			else if(IsLc(p)&&!IsLc(v))//zag_p-zig_g
			{
				p->rc=v->lc;if(p->rc) p->rc->parent=p;
				g->lc=v->rc;if(g->lc) g->lc->parent=g;
				v->lc=p;p->parent=v;
				v->rc=g;g->parent=v;
			}
			else if(!IsLc(p)&&IsLc(v))//zig_p-zag_g
			{
				g->rc=v->lc;if(g->rc) g->rc->parent=g;
				p->lc=v->rc;if(p->lc) p->lc->parent=p;
				v->lc=g;g->parent=v;
				v->rc=p;p->parent=v;
			}
			else//zag_g-zag_p
			{
				g->rc=p->lc;if(g->rc) g->rc->parent=g;
				p->rc=v->lc;if(p->rc) p->rc->parent=p;
				p->lc=g;g->parent=p;
				v->lc=p;p->parent=v;
			}
			if(!gg) v->parent=nullptr;
			else
			{
				flag==0 ? gg->lc=v : gg->rc=v;
				v->parent=gg;
			}
		}
		if(p&&!g)
		{
			if(IsLc(v))
			{
				p->lc=v->rc;if(p->lc) p->lc->parent=p;
				v->rc=p;p->parent=v;
			}
			else
			{
				p->rc=v->lc;if(p->rc) p->rc->parent=p;
				v->lc=p;p->parent=v;
			}
			v->parent=nullptr;
		}
		return v;
	}

	public:

	void travInorder() { return BST::travInorder(); }
	BinNodePosi(T)& search(const T& e)
	{
		BinNodePosi(T) x=BST::search(e);
		_root=splay(x ? x : _hot);//查找失败就从父亲开始伸展，否则从查找结果开始伸展
		return _root;

	}
	BinNodePosi(T) insert(const T& e)
	{
		if(!_root) { _size++; return _root=new BinNode<T>(e); } //处理原树为空的退化情况
		BinNodePosi(T) x=search(e);
		if(x&&x->_data==e) return x;
		else
		{
			if(x->_data>e)
			{
				T ori=x->_data;
				x->_data=e;
				BinNodePosi(T) temp=x->rc;
				BinNodePosi(T) xrc=x->insertAsRC(ori);
				xrc->rc=temp;
				if(temp) temp->parent=xrc;
			}
			else
			{
				T ori=x->_data;
				x->_data=e;
				BinNodePosi(T) temp=x->lc;
				BinNodePosi(T) xlc=x->insertAsLC(ori);
				xlc->lc=temp;
				if(temp) temp->parent=xlc;
			}
		}
		_size++;
		return x;
	}
	bool remove(const T& e)
	{
		if(!_root) return false;//处理原树为空的退化情况
		BinNodePosi(T) x=search(e);
		if(x->_data!=e) return false;
		//现在，确保了树不空，而且节点存在。注意此时待删除节点已经通过search被提到了最高点。
		if(!x->lc)//左子树空，直接删除，把右孩子提上来
		{//注意处理退化到空树的情况
			_root=_root->rc;if(_root)_root->parent=nullptr;
		}
		else if(!x->rc)//右子树空，同理
		{
			_root=_root->lc;if(_root) _root->parent=nullptr;
		}
		else//左右子树均非空
		{/*方法很巧，暂时切去左子树，将右子树提出来，提到root
			对右子树搜索原root，此时搜索肯定失败，目的在于找到原root的直接后继并将它提到root
			然后注意到新root是右子树最小者，所以他没有左孩子。
			那么将原来切掉的左子树练上去就好啦~
			*/
			BinNodePosi(T) lc=_root->lc;
			_root=_root->rc;_root->parent=nullptr;
			search(e);
			_root->lc=lc;lc->parent=_root;
		}
		_size--;
		return true;
	}
	BinNodePosi(T) root() { return BST::root(); }
	int size() { return _size; }

};



#endif // !SPLAY_TREE#pragma once
