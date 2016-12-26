#ifndef _HEADERNAME_Mylist
#define _HEADERNAME_Mylist

#define ListNodePosi(T) Mylist_Node<T>*
typedef int Rank;//秩

template <typename T> struct My_List_Node//双向链表节点封装
{
	ListNodePosi(T) _prev;//前驱指针
	T _data;//数据域
	ListNodePosi(T) _succ;//后继指针
	Mylist_Node(){}//构造
	Mylist_Node(T __data,ListNodePosi(T) __prev=NULL,ListNodePosi(T) __succ=NULL){ _data=__data;_prev=__prev;_succ=__succ; }//构造

	//前插函数
	ListNodePosi(T) InsertAs_Prev(T const &_e)
	{
		ListNodePosi(T) _x=new Mylist_Node(_e,_prev,this);
		/*prev指this的前驱，this是当前调用节点，
		这样会让x的prev指向this的前驱，x的succ指向this，达到插入目的
		*/
		_prev->_succ=_x;//this前驱的succ指向x
		_prev=_x;//this的前驱指向x
		return _x;
	}
	//后插函数，同上
	ListNodePosi(T) InsertAs_Succ(T const &_e)
	{
		ListNodePosi(T) _x=new Mylist_Node(_e,this,_succ);//同上
		_succ->_prev=_x;
		_succ=_x;
		return _x;
	}

};
template <typename T> class My_List//带首末节点的双向链表
{
	private:
	ListNodePosi(T) _header;//首节点
	ListNodePosi(T) _trailer;//末节点
	int _size;//不包括首末节点的节点数

	public:
	//构造
	Mylist(){ init(); }
	//析构
	~Mylist(){ clear();/*delete _header;delete _trailer;*/ }
	//重载[]实现下标访问
	T& operator [](Rank r){ ListNodePosi(T) p=first();while(r--) p=p->_succ;return p->_data; }
	//返回头节点(第一个元素)
	ListNodePosi(T) first(){ return _header->_succ; }
	//返回末节点(最后一个元素)
	ListNodePosi(T) last(){ return _trailer->_prev; }
	//返回元素个数
	Rank size(){ return _size; }
	//判空
	bool empty(){ return _size==0; }
	//查找
	ListNodePosi(T) find(T const e,int n,ListNodePosi(T) pos)
	{//从pos(不包括pos)起的 前n个前驱
		while(n--) if((pos=pos->_prev)->_data==e) return pos;
		return NULL;
	}
	ListNodePosi(T) find(T const e){ return find(e,_size,_trailer); }
	//作为末节点插入
	ListNodePosi(T) InsertAsLast(T const &_e) { _size++;return _trailer->InsertAs_Prev(_e); }
	//作为头节点插入
	ListNodePosi(T) InsertAsFirst(T const &_e) { _size++;return _header->InsertAs_Succ(_e); }
	//插在某节点前面
	ListNodePosi(T) InsertAsPrev(T const &_e,ListNodePosi(T) _p){ _size++;return _p->InsertAs_Prev(e); }
	//插在某节点后面
	ListNodePosi(T) InsertAsSucc(T const &_e,ListNodePosi(T) _p){ _size++;return _p->InsertAs_Succ(e); }
	//删除节点
	T RemoveNode(ListNodePosi(T) _p)//删除节点
	{
		_size--;//节点数--
		T _temp=_p->_data;
		//链接p的前驱和后继
		_p->_prev->_succ=_p->_succ;
		_p->_succ->_prev=_p->_prev;
		delete _p;
		return _temp;
	}
	T RemoveFirst() { return RemoveNode(first()); }
	T RemoveLast() { return RemoveNode(last()); }

	protected:
	//创建首末节点并连接彼此，初始化一个链表
	void init()
	{ 
		_header=new Mylist_Node<T>;_trailer=new Mylist_Node<T>;
		_header->_prev=NULL;_header->_succ=_trailer;
		_trailer->_prev=_header;_trailer->_succ=NULL; 
		_size=0;
	}
	//清空所有元素，不清空首末节点
	int clear()
	{
		int _sum=_size;
		while(_size>0) RemoveNode(_header->_succ);//不断清除头节点
		return _sum;
	}

};

#endif // _HEADERNAME_Mylist#pragma once
