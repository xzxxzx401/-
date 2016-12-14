#ifndef AVL_Tree
#define AVL_Tree

#include"BST.h"
#include"BinTree.h"
#define AVL_BalFactor(x) get_hight(x->lc)-get_hight(x->rc)//平衡因子
#define AVL_Balenced(x) ((-2<AVL_BalFactor(x)) && (AVL_BalFactor(x)<2))//平衡么？


template <typename T> class AVL:protected BST<typename T>
{
	public:
	BinNodePosi(T)& search(const T& e) { return BST::search(e); }

	BinNodePosi(T) insert(const T& e)
	{
		BinNodePosi(T) temp=BST::insert(e);
		for(BinNodePosi(T) h=_hot;h;h=h->parent)//寻找失衡点并重新平衡
		{
			if(!AVL_Balenced(h))
			{//注意处理跟的情况
				(is_root(h) ? _root : (h->parent->lc==h ? h->parent->lc : h->parent->rc))
					=rotateAt(taller_child(taller_child(h)));
				break;
			}
			else
				updateHightAbove(h);
		}
		return temp;
	}

	bool remove(const T& e)
	{
		if(!BST::remove(e)) return false;

		for(BinNodePosi(T) h=_hot;h;h=h->parent)
		{
			if(!AVL_Balenced(h))
			{
				(is_root(h) ? _root : (h->parent->lc==h ? h->parent->lc : h->parent->rc))
					=rotateAt(taller_child(taller_child(h)));
			}
			updateHightAbove(h);
		}
		return true;
	}
	void travInorder() { return BST::travInorder(); }
	int size() { return _size; }
	
	protected:
	BinNodePosi(T) rotateAt(BinNodePosi(T) v)
	{//旋转，注意将新的局部最祖先的节点的parent连到原来最祖先节点的parent上
	 //还要注意更新高度
	 //亦可用3-4重构
		BinNodePosi(T) p=v->parent;//父亲
		BinNodePosi(T) g=p->parent;//祖父
		if(g->lc==p)//zig
		{
			if(p->lc==v)//zig_g
			{
				BinNodePosi(T) bb=g->parent;
				g->lc=p->rc;if(g->lc) g->lc->parent=g;
				p->rc=g;g->parent=p;
				p->parent=bb;
				updateHight(p);updateHight(g);updateHight(v);
				return p;
			}
			else//zag_p-zig_g
			{
				BinNodePosi(T) bb=g->parent;
				p->rc=v->lc;if(p->rc) p->rc->parent=p;
				g->lc=v->rc;if(g->lc) g->lc->parent=g;
				v->rc=g;g->parent=v;
				v->lc=p;p->parent=v;
				v->parent=bb;
				updateHight(p);updateHight(g);updateHight(v);
				return v;
			}
		}
		else//zag
		{
			if(p->lc==v)//zig_p-zag_g
			{
				BinNodePosi(T) bb=g->parent;
				p->lc=v->rc;if(p->lc) p->lc->parent=p;
				g->rc=v->lc;if(g->rc) g->rc->parent=g;
				v->lc=g;g->parent=v;
				v->rc=p;p->parent=v;
				v->parent=bb;
				updateHight(p);updateHight(g);updateHight(v);
				return v;
			}
			else//zag_g
			{
				BinNodePosi(T) bb=g->parent;
				g->rc=p->lc;if(g->rc) g->rc->parent=g;
				p->lc=g;g->parent=p;
				p->parent=bb;
				updateHight(p);updateHight(g);updateHight(v);
				return p;
			}
		}
	}

};


#endif // !AVL_Tree#pragma once
