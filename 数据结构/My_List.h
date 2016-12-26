#ifndef _HEADERNAME_Mylist
#define _HEADERNAME_Mylist

#define ListNodePosi(T) Mylist_Node<T>*
typedef int Rank;//��

template <typename T> struct My_List_Node//˫������ڵ��װ
{
	ListNodePosi(T) _prev;//ǰ��ָ��
	T _data;//������
	ListNodePosi(T) _succ;//���ָ��
	Mylist_Node(){}//����
	Mylist_Node(T __data,ListNodePosi(T) __prev=NULL,ListNodePosi(T) __succ=NULL){ _data=__data;_prev=__prev;_succ=__succ; }//����

	//ǰ�庯��
	ListNodePosi(T) InsertAs_Prev(T const &_e)
	{
		ListNodePosi(T) _x=new Mylist_Node(_e,_prev,this);
		/*prevָthis��ǰ����this�ǵ�ǰ���ýڵ㣬
		��������x��prevָ��this��ǰ����x��succָ��this���ﵽ����Ŀ��
		*/
		_prev->_succ=_x;//thisǰ����succָ��x
		_prev=_x;//this��ǰ��ָ��x
		return _x;
	}
	//��庯����ͬ��
	ListNodePosi(T) InsertAs_Succ(T const &_e)
	{
		ListNodePosi(T) _x=new Mylist_Node(_e,this,_succ);//ͬ��
		_succ->_prev=_x;
		_succ=_x;
		return _x;
	}

};
template <typename T> class My_List//����ĩ�ڵ��˫������
{
	private:
	ListNodePosi(T) _header;//�׽ڵ�
	ListNodePosi(T) _trailer;//ĩ�ڵ�
	int _size;//��������ĩ�ڵ�Ľڵ���

	public:
	//����
	Mylist(){ init(); }
	//����
	~Mylist(){ clear();/*delete _header;delete _trailer;*/ }
	//����[]ʵ���±����
	T& operator [](Rank r){ ListNodePosi(T) p=first();while(r--) p=p->_succ;return p->_data; }
	//����ͷ�ڵ�(��һ��Ԫ��)
	ListNodePosi(T) first(){ return _header->_succ; }
	//����ĩ�ڵ�(���һ��Ԫ��)
	ListNodePosi(T) last(){ return _trailer->_prev; }
	//����Ԫ�ظ���
	Rank size(){ return _size; }
	//�п�
	bool empty(){ return _size==0; }
	//����
	ListNodePosi(T) find(T const e,int n,ListNodePosi(T) pos)
	{//��pos(������pos)��� ǰn��ǰ��
		while(n--) if((pos=pos->_prev)->_data==e) return pos;
		return NULL;
	}
	ListNodePosi(T) find(T const e){ return find(e,_size,_trailer); }
	//��Ϊĩ�ڵ����
	ListNodePosi(T) InsertAsLast(T const &_e) { _size++;return _trailer->InsertAs_Prev(_e); }
	//��Ϊͷ�ڵ����
	ListNodePosi(T) InsertAsFirst(T const &_e) { _size++;return _header->InsertAs_Succ(_e); }
	//����ĳ�ڵ�ǰ��
	ListNodePosi(T) InsertAsPrev(T const &_e,ListNodePosi(T) _p){ _size++;return _p->InsertAs_Prev(e); }
	//����ĳ�ڵ����
	ListNodePosi(T) InsertAsSucc(T const &_e,ListNodePosi(T) _p){ _size++;return _p->InsertAs_Succ(e); }
	//ɾ���ڵ�
	T RemoveNode(ListNodePosi(T) _p)//ɾ���ڵ�
	{
		_size--;//�ڵ���--
		T _temp=_p->_data;
		//����p��ǰ���ͺ��
		_p->_prev->_succ=_p->_succ;
		_p->_succ->_prev=_p->_prev;
		delete _p;
		return _temp;
	}
	T RemoveFirst() { return RemoveNode(first()); }
	T RemoveLast() { return RemoveNode(last()); }

	protected:
	//������ĩ�ڵ㲢���ӱ˴ˣ���ʼ��һ������
	void init()
	{ 
		_header=new Mylist_Node<T>;_trailer=new Mylist_Node<T>;
		_header->_prev=NULL;_header->_succ=_trailer;
		_trailer->_prev=_header;_trailer->_succ=NULL; 
		_size=0;
	}
	//�������Ԫ�أ��������ĩ�ڵ�
	int clear()
	{
		int _sum=_size;
		while(_size>0) RemoveNode(_header->_succ);//�������ͷ�ڵ�
		return _sum;
	}

};

#endif // _HEADERNAME_Mylist#pragma once
