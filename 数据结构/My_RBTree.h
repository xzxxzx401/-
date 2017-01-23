#ifndef MY_RBTREE
#define MY_RBTREE
#include"My_BST.h"
#define IsBlack(x) (!(x)||((x)->color==RB_BLACK))
#define IsRed(x) (!IsBlack(x))
#define Brother(x) ((x->parent->lc==x)?(x->parent->rc):(x->parent->lc))


template<typename T> class My_RBTree :protected My_BST<typename T>
{
	protected:
	int updateHight(BinNodePosi(T) x)//���½ڵ�x�ĸ߶�
	{
		//if(!x) return -1;
		x->hight=max(get_hight(x->lc), get_hight(x->rc));
		//if(IsBlack(x)) x->hight++;
		//return x->hight;
		return IsBlack(x) ? x->hight++ : x->hight;
	}
	
	BinNodePosi(T) connect34(BinNodePosi(T) a, BinNodePosi(T) b, BinNodePosi(T) c,
		BinNodePosi(T) t1, BinNodePosi(T) t2, BinNodePosi(T) t3, BinNodePosi(T) t4)//3+4�ع�
	{
		a->lc=t1;if(t1) t1->parent=a;
		a->rc=t2;if(t2) t2->parent=a;
		b->lc=t3;if(t3) t3->parent=b;
		b->rc=t4;if(t4) t4->parent=b;
		c->lc=a;c->rc=b;a->parent=c;b->parent=c;
		return c;//�����¸�
	}
	
	BinNodePosi(T) ZigZag(BinNodePosi(T) x)//ȷ��x����������
	{//���ڲ�����������ȵ����ӣ������������ں����ⲿ����
		BinNodePosi(T) p=x->parent;
		BinNodePosi(T) g=p->parent;
		if(g->lc==p)//zig
		{
			if(p->lc==x)//zig_g
			{
				p->parent=g->parent;
				return connect34(x, g, p, x->lc, x->rc, p->rc, g->rc);
			}
			else//zag_p-zig_g
			{
				x->parent=g->parent;
				return connect34(p, g, x, p->lc, x->lc, x->rc, g->rc);
			}
		}
		else//zag
		{
			if(p->lc==x)//zig_p-zag_g
			{
				x->parent=g->parent;
				return connect34(g, p, x, g->lc, x->lc, x->rc, p->rc);
			}
			else//zag_g
			{
				p->parent=g->parent;
				return connect34(g, x, p, g->lc, p->lc, x->lc, x->rc);
			}
		}
	}
	void SolveDoubleRed(BinNodePosi(T) x)//˫������
	{
		if(!(x->parent))//���˸��ڵ㣬ֱ�ӱ�ڣ����¸߶ȣ�����
		{
			x->color=RB_BLACK;
			x->hight++;
			return;
		}
		BinNodePosi(T) p=x->parent;
		if(IsBlack(p)) return;
		else
		{
			BinNodePosi(T) g=p->parent;//x���죬������游
			BinNodePosi(T) u=Brother(p);
			if(IsBlack(u))
			{
				//��ת����
				BinNodePosi(T) gg=g->parent;
				BinNodePosi(T) newr=ZigZag(x);
				((!gg) ? _root : (gg->lc==g ? gg->lc : gg->rc))=newr;//��������ȵ�����
				//��Ⱦɫ
				newr->color=RB_BLACK;
				newr->lc->color=newr->rc->color=RB_RED;
				updateHight(newr->lc);
				updateHight(newr->rc);
				updateHight(newr);
			}
			else
			{
				p->color=RB_BLACK;p->hight++;
				u->color=RB_BLACK;u->hight++;
				if(g->parent) g->color=RB_RED;
				SolveDoubleRed(g);
			}
		}
	}
	void SolveDoubleBlack(BinNodePosi(T) x)//˫������
	{
		BinNodePosi(T) p=(x ? x->parent : _hot); if(!p) return;//������ ����
		BinNodePosi(T) s=((x==p->lc) ? p->rc : p->lc);//x���ֵ�
		if(IsBlack(s))
		{
			BinNodePosi(T) t=nullptr;//s�ĺ캢��
			if(s&&IsRed(s->lc)) t=s->lc;
			else if(s&&IsRed(s->rc)) t=s->rc;
			
			if(t)//BB-1:��s�к���t(p���ʲô��ɫ)
			{
				RBColor p_color=p->color;
				BinNodePosi(T) g=nullptr;
				BinNodePosi(T) nr=nullptr;
				if(!(p->parent)) nr=_root=ZigZag(t);
				else
				{
					g=p->parent;
					if(g->lc==p) nr=g->lc=ZigZag(t);
					else nr=g->rc=ZigZag(t);
				}
				if(nr->lc) { nr->lc->color=RB_BLACK;updateHight(nr->lc); }
				if(nr->rc) { nr->rc->color=RB_BLACK;updateHight(nr->rc); }
				nr->color=p_color;
				updateHight(nr);
			}
			else
			{
				if(s)
				{
					s->color=RB_RED;
					s->hight--;
				}
				if(p->color==RB_RED)//BB-2R:��s�޺��ӣ�p��
				{
					p->color=RB_BLACK;
				}
				else//BB-2B:��s�޺��ӣ�p��
				{
					p->hight--;
					SolveDoubleBlack(p);
				}
			}
		}
		else//BB-3:��s��p�غ�
			//����һ���ع���ת��BB-1��BB-2R
		{
			s->color=RB_BLACK;p->color=RB_RED;
			s->hight++;p->hight--;
			BinNodePosi(T) g=(p->parent);
			if(p->lc==s)
			{
				p->lc=s->rc;if(p->lc) p->lc->parent=p;
				s->rc=p;p->parent=s;
				((!g) ? _root : (g->lc==p ? g->lc : g->rc))=s;s->parent=g;
			}
			else
			{
				p->rc=s->lc;if(p->rc) p->rc->parent=p;
				s->lc=p;p->parent=s;
				((!g) ? _root : (g->lc==p ? g->lc : g->rc))=s;s->parent=g;
			}
			_hot=p;
			SolveDoubleBlack(x);
		}

	}
	void trans(BinNodePosi(T) x)//����������������
	{
		if(!x)
		{
			//if(x->parent->lc||x->parent->rc) cout<<"null";
			return;
		}
		cout<<'(';
		trans(x->lc);
		cout<<x->_data<<' '<<x->color<<',';
		trans(x->rc);
		cout<<')';

	}
	public:
	BinNodePosi(T) root(){ return My_BST<T>::root(); }
	BinNodePosi(T)& search(const T& e) { return My_BST<T>::search(e); }
	BinNodePosi(T) insert(const T& e)//����ؼ���e
	{
		BinNodePosi(T)& x=search(e);if(x) return x;
		x=new My_BinNode<T>(e, _hot);_size++;
		x->hight=-1;
		SolveDoubleRed(x);
		return x;
	}
	bool remove(const T& e)//ɾ���ؼ���e
	{
		BinNodePosi(T)& x=search(e);if(!x) return false;
		bool balanced=(x->color==RB_RED);
		BinNodePosi(T) succ=My_BST<T>::removeAt(x, _hot);
		if(!(--_size)) return true;
		if(_hot==nullptr)//ɾȥ���Ǹ��������¸���ת�ڲ����¸��ĸ߶�
		{
			_root->color=RB_BLACK;
			updateHight(_root);
			return true;
		}
		else if(balanced) return true;
		else if(IsRed(succ)){ succ->color=RB_BLACK;succ->hight++;return true; }
		//x��succ��Ϊ��ɫ��˫������
		else SolveDoubleBlack(succ);

		return true;
	}
	void test()//���ű�ʾ����ӡ��,20������Ч
	{
		if(_size<20) trans(_root);
	}
	
};


#endif // !MY_RBTREE
#pragma once
