#ifndef SPLAY_TREE
#define SPLAY_TREE
#include"BST.h"
#include"BinTree.h"
#define IsLc(x) (x->parent!=nullptr?(x->parent->lc==x?true:false):(false))

template <typename T> class Splay:protected BST<typename T>//��չ����˫����չ
{
	protected:
	BinNodePosi(T) splay(BinNodePosi(T) v)//��v��ʼ��չ,������չ�������
	{
		if(v==_root) return v;
		BinNodePosi(T) p=nullptr; BinNodePosi(T) g=nullptr;
		while((p=v->parent)&&(g=p->parent))
		{//ע�⿼������Ϊ��
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
		_root=splay(x ? x : _hot);//����ʧ�ܾʹӸ��׿�ʼ��չ������Ӳ��ҽ����ʼ��չ
		return _root;

	}
	BinNodePosi(T) insert(const T& e)
	{
		if(!_root) { _size++; return _root=new BinNode<T>(e); } //����ԭ��Ϊ�յ��˻����
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
		if(!_root) return false;//����ԭ��Ϊ�յ��˻����
		BinNodePosi(T) x=search(e);
		if(x->_data!=e) return false;
		//���ڣ�ȷ���������գ����ҽڵ���ڡ�ע���ʱ��ɾ���ڵ��Ѿ�ͨ��search���ᵽ����ߵ㡣
		if(!x->lc)//�������գ�ֱ��ɾ�������Һ���������
		{//ע�⴦���˻������������
			_root=_root->rc;if(_root)_root->parent=nullptr;
		}
		else if(!x->rc)//�������գ�ͬ��
		{
			_root=_root->lc;if(_root) _root->parent=nullptr;
		}
		else//�����������ǿ�
		{/*�������ɣ���ʱ��ȥ������������������������ᵽroot
			������������ԭroot����ʱ�����϶�ʧ�ܣ�Ŀ�������ҵ�ԭroot��ֱ�Ӻ�̲������ᵽroot
			Ȼ��ע�⵽��root����������С�ߣ�������û�����ӡ�
			��ô��ԭ���е�������������ȥ�ͺ���~
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
