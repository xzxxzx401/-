#ifndef MY_BTREE
#define MY_BTREE
#include "My_Vector.h"

#define BTNodePosi(T) My_BTNode<T>*
#define Swap(a,b) {int tmp=a;a=b;b=tmp;}
typedef int Rank;
template <typename>class My_BTree;
//My_BTNode�ڵ���
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
	{//ע�⣬My_BTNode�Ĺ���ֻ������Ϊ�¸��ڵ㹹���������ΪB������һ���������Ϸ���
		//����parentһ����nullptr��һ����ʼֻ����������
		//���������Ӳ�һ�����ڴ��ڣ�����BTree�ʼ����һ���ڵ�
		parent=nullptr;
		key.push_back(e);
		child.push_back(lc);child.push_back(rc);
		if(lc) lc->parent=this;if(rc) rc->parent=this;//��ɺ��ӵ�����
	}
	~My_BTNode()
	{
		key.~My_Vector();
		child.~My_Vector();
	}
	//My_BTNode����Ҫ������������Ϊ����������Ǹ��ڵ㣬����Ҫ����ķ���
};

template <typename T> class My_BTree
{	
	protected:
	BTNodePosi(T) _root;//���ڵ�
	BTNodePosi(T) _hot;//���Ҳ���ɾ���������ʽڵ�
	int _order;//����
	int _size;//���ߴ�
	void SolveOverFLow(BTNodePosi(T) v)//���磬����
	{
		while(v->child.size()>_order)//����Ҫ����ʱ
		{
			Rank mid=v->key.size()/2;
			//Myvector�����ṩר�ŵķ��ѷ�������ʱ��ʵ��
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
			//���Ѿ������ˣ���ô�½�һ�����ڵ㣬����һ��
			if(!p) { _root=p=new My_BTNode<T>();p->child[0]=v;v->parent=p; }
			Rank r_p=1+(p->key).search(v->key[0]);//�ҵ�����λ�� ע���1
			
			p->key.insert(r_p, e);
			p->child.insert(r_p+1, u);u->parent=p;//up����
			v=v->parent;
			//delete u, p;
			int a=3;
		}
	}
	void SolveUnderFlow(BTNodePosi(T) v)//���磬��or�ϲ�
	{
		while(v)
		{
			//��ǰ�ڵ�δ���磬����Ҫ����
			if((v->child.size()+1)/2<=_order) return;
			//��ǰ�ڵ��Ǹ�����û�ؼ�����
			BTNodePosi(T) p=v->parent;
			if(!p&&v->key.size()==0)
			{
				_root=v->child[0];_root->parent=nullptr;
				delete v;
				return;
			}
			//�����ֵܽ�һ��
			Rank r_v=0;while(p->child[r_v++]!=v);//��ʾv��p�ĵڼ�������
			if(0<r_v)
			{
				BTNodePosi(T) ls=p->child[r_v-1];//���ֵ�
				if(ls->key.size()>(_order+1)/2)//���ֵܺ��ӹ���
				{
					v->child.insert(0,ls->child.pop_back());//�ȹ��̺���
					v->key.insert(0, ls->key.pop_back());//���̹ؼ���
					Swap(v->key[0], p->key[r_v-1]);//�븸�׵Ĺؼ��뽻��
					if(v->child[0]) (v->child[0])->parent=v;//���Ӻ͸�������
				}
				return;
			}
			//�����ֵܽ�
			if(r_v<p->child.size()-1)//����������
			{
				BTNodePosi(T) rs=p->child[r_v+1];//���ֵ�
				if(rs->key.size()>(_order+1)/2)//���ֵܺ��ӹ���
				{
					v->child.push_back(rs->child.remove(0));//�ȹ��̺���
					v->key.push_back(rs->key.remove(0));//���̹ؼ���
					Swap(v->key[v->key.size()-1], p->key[r_v]);//�븸�׵Ĺؼ��뽻��
					if(v->child[v->child.size()-1]) (v->child[v->child.size()-1])->parent=v;//���Ӻ͸�������
				}
				return;
			}
			if(r_v>0)//�����ֵܺϲ�
			{
				BTNodePosi(T) ls=p->child[r_v-1];//���ֵ�
				ls->key.push_back(p->key.remove(r_v-1));//�����׵Ĺؼ���ת�Ƶ����ֵ�����
				p->child.remove(r_v);
				//��ʱls����ؼ���ͺ�����һ����
				ls->child.push_back(v->child.remove(0));
				if(ls->child[ls->child.size()-1]) (ls->child[ls->child.size()-1])->parent=ls;
				while(!(v->child.empty()))//���������ƶ� ��Ҫvector�ṩ����
				{
					ls->child.push_back(v->child.remove(0));
					if(ls->child[ls->child.size()-1]) (ls->child[ls->child.size()-1])->parent=ls;
					ls->key.push_back(v->key.remove(0));
				}
				delete v;
				v=ls->parent;
			}
			else//�����ֵܺϲ�
			{
				BTNodePosi(T) rs=p->child[r_v+1];//���ֵ�
				rs->key.insert(0,p->key.remove(r_v));//�����׵Ĺؼ���ת�Ƶ����ֵ�����
				p->child.remove(r_v);
				//��ʱrs����ؼ���ͺ�����һ����
				rs->child.insert(0,v->child.pop_back());
				if(rs->child[0]) (rs->child[0])->parent=rs;
				while(!(v->child.empty()))//���������ƶ� ��Ҫvector�ṩ����
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
	~My_BTree(){}//�ݹ����� ����д�� ������ջ���
	const BTNodePosi(T)& root() { return _root; }//���ظ�������
	const int order() { return _order; }//���ؽ���
	const int size() { return _size; }//Ԫ����Ŀ
	bool empty() { return !_root; }//�п�
	BTNodePosi(T) search(const T& e)//����
	{
		BTNodePosi(T) now=_root;_hot=nullptr;
		while(now) 
		{ 
			Rank x=now->key.search(e);//����search���Ҳ�����e�ĵ�һ��λ��
			if(0<=x&&now->key[x]==e) return now;//ȷʵ�ҵ��ˣ����ص�ǰnow����
			_hot=now;now=now->child[x+1];//ת���Һ�������
		}
		return nullptr;//û�ҵ�����null
	}
	bool insert(const T& e)//���ز����Ƿ�ɹ�
	{
		BTNodePosi(T) now=search(e);
		if(now) return false;//����Ѿ����ڣ�����������
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
		if(!now) return false;//��������ڣ�����Ϊ��ɾ��
		Rank r=now->key.search(e);
		if(now->child[0]) 
		{
			BTNodePosi(T) succ=now->child[0];//�к��
			while(succ->child[0]) succ=succ->child[0];//���������Һ��
			Swap(now->key[r], succ->key[0]);//�ú�̴���now->key[r]
			now=succ;
		}
		now->key.remove(0);now->child.pop_back();_size--;//ɾ���ڵ��Լ�һ������(null)
		SolveUnderFlow(now);
		return true;
	}
};
#endif // !MY_BTREE