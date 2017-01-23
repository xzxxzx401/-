#ifndef MY_AVL
#define MY_AVL

#include"My_BST.h"
#include"My_BinTree.h"
#define AVL_BalFactor(x) get_hight(x->lc)-get_hight(x->rc)//ƽ������
#define AVL_Balenced(x) ((-2<AVL_BalFactor(x)) && (AVL_BalFactor(x)<2))//ƽ��ô��


template <typename T> class My_AVL:protected My_BST<typename T>
{
	public:
	BinNodePosi(T) root() { return _root; }
	BinNodePosi(T)& search(const T& e) { return My_BST<T>::search(e); }

	BinNodePosi(T) insert(const T& e)
	{
		BinNodePosi(T) & x=search(e); if(x) return x; //ȷ��Ŀ��ڵ㲻����
		BinNodePosi(T) xx=x=new My_BinNode<T>(e, _hot); _size++;
		//ע���Ժ������ת ���ڴ˴������¸߶� Ҳ���ܵ���BST::insert
		for(BinNodePosi(T) h=_hot;h;h=h->parent)//Ѱ��ʧ��㲢����ƽ��
		{
			if(!AVL_Balenced(h))
			{//ע�⴦��������
				(is_root(h) ? _root : (h->parent->lc==h ? h->parent->lc : h->parent->rc))
					=rotateAt(taller_child(taller_child(h)));
				break;
			}
			else
				updateHight(h);
		}
		return xx;
	}

	bool remove(const T& e)
	{
		if(!My_BST<T>::remove(e)) return false;

		for(BinNodePosi(T) h=_hot;h;h=h->parent)
		{
			if(!AVL_Balenced(h))
			{
				(My_BinTree<T>::is_root(h) ? _root : (h->parent->lc==h ? h->parent->lc : h->parent->rc))
					=rotateAt(taller_child(taller_child(h)));
			}
			updateHight(h);
		}
		return true;
	}
	void travInorder() { return My_BST<T>::travInorder(); }
	int size() { return _size; }
	
	protected:
	BinNodePosi(T) rotateAt(BinNodePosi(T) v)
	{//��ת��ע�⽫�µľֲ������ȵĽڵ��parent����ԭ�������Ƚڵ��parent��
	 //��Ҫע����¸߶�
	 //�����3-4�ع�
		BinNodePosi(T) p=v->parent;//����
		BinNodePosi(T) g=p->parent;//�游
		if(g->lc==p)//zig
		{
			if(p->lc==v)//zig_g
			{
				BinNodePosi(T) bb=g->parent;
				g->lc=p->rc;if(g->lc) g->lc->parent=g;
				p->rc=g;g->parent=p;
				p->parent=bb;
				updateHight(g);updateHight(v);updateHight(p);
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
				updateHight(g);updateHight(v);updateHight(p);
				return p;
			}
		}
	}

};


#endif // !MY_AVL#pragma once
