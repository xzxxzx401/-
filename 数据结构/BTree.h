#ifndef BTREE_H
#define BTREE_H
#include "Myvector.h"//���滻��stl::vector

#define BTNodePosi(T) BTNode<T>*
typedef int Rank;

//BTNode�ڵ���
template <typename T> class BTNode
{
	protected:
	BTNodePosi(T) parent;
	MyVector<T> key;
	MyVector<BTNodePosi(T)> child;

	public:
	BTNode() { parent=nullptr;child.push_back(nullptr); }
	BTNode(T e, BTNodePosi(T) lc=nullptr, BTNodePosi(T) rc=nullptr)
	{//ע�⣬BTNode�Ĺ���ֻ������Ϊ�¸��ڵ㹹���������ΪB������һ���������Ϸ���
		//����parentһ����nullptr��һ����ʼֻ����������
		//���������Ӳ�һ�����ڴ��ڣ�����BTree�ʼ����һ���ڵ�
		parent=nullptr;
		key.push_back(e);
		child.push_back(lc);child.push_back(rc);
		if(lc) lc->parent=this;if(rc) rc->parent=this;//��ɺ��ӵ�����
	}
	//BTNode����Ҫ������������Ϊ����������Ǹ��ڵ㣬����Ҫ����ķ���
};

template <typename T> class BTree
{
	protected:
	BTNodePosi(T) _root;//���ڵ�
	BTNodePosi(T) _hot;//���Ҳ���ɾ���������ʽڵ�
	int _order;//����
	int _size;//���ߴ�
	BTNodePosi(T) SolveOverFLow(BTNodePosi(T) s)//���磬����
	{
		while(s->key.size()>_order)//����Ҫ����ʱ
		{

		}
	}
	void SolveUnderFlow(BTNodePosi(T) s)//���磬��or�ϲ�
	{

	}

	public:
	BTree(int order=3) { _order=order;_size=0;_hot=nullptr;_root=new BTNode<T>(); }
	~BTree(){}//�ݹ����� ����д�� ������ջ���
	const BTNodePosi(T)& root() { return _root; }//���ظ�������
	const int order() { return _order; }//���ؽ���
	const int size() { return _size; }//Ԫ����Ŀ
	bool empty() { return !_root; }//�п�
	const BTNodePosi(T)& search(const T& e)//����
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
	BTNodePosi(T) insert(const T& e)
	{
		BTNodePosi(T) now=search(e);
		if(now) return now;//����Ѿ����ڣ�����������
		Rank r=_hot->key.search(e);
		_hot->key.insert(r+1, e);
		_hot->child.push_back(nullptr);
		_size++;
		return SolveOverFLow(_hot);
	}
	bool remove()
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
		now->key.remove(0);now->child.pop_back();size--;//ɾ���ڵ��Լ�һ������(null)
		SolveUnderFlow(now);
		return true;
	}
};


#endif // !BTREE
