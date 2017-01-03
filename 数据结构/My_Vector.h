#ifndef _HEADERNAME_Myvector
#define _HEADERNAME_Myvector


typedef int Rank;

const int DEFAULT_CAPACITY=8;//默认容量
template <typename T> class My_Vector
{
	protected:
	Rank _size;//实际规模
	int _capacity;//目前容量
	T *_elem;//数据域

	protected:
	void copyFrom(T const* A,Rank _lo,Rank _hi)//复制数组区间A[lo, hi)
	{
		_elem=new T[_capacity=2 * (_hi - _lo)];_size=0;
		while(_lo<_hi) _elem[_size++]=A[_lo++];
	}
	void expand()//空间不足时扩容
	{
		if(_size<_capacity) return;
		T *_old_elem=_elem;
		_elem=new T[_capacity<<=1];
		for(int _i=0;_i<_size;_i++) _elem[_i]=_old_elem[_i];
		delete[] _old_elem;
	}
	void shrink()
	{
		if(_capacity<DEFAULT_CAPACITY << 1) return;
		if(_size << 2 > _capacity) return;
		T*_old_elem=_elem;
		_elem=new T[_capacity>>=1];
		for(int _i=0;_i<_size;_i++)
		{
			_elem[_i]=_old_elem[_i];
		}
		delete[] _old_elem;
	}

	public:
	//构造
	My_Vector(int _c=DEFAULT_CAPACITY){ _elem=new T[_capacity=_c];_size=0; }
	//拷贝构造
	My_Vector(My_Vector<T> const &_oldvec) { copyFrom(_oldvec._elem,0,_oldvec._size); }
	//析构
	~My_Vector(){ delete[] _elem; }
	//重载[]，支持方括号访问
	T& operator [](Rank r) { if(0<=r&&r<_size) return _elem[r]; }
	//插入末尾
	T& push_back(const T c){ expand();_elem[_size++]=c;return _elem[_size-1]; }
	//删除末尾元素
	T pop_back(){ _size--;T _temp=*(_elem+_size);shrink();return _temp; }
	//查询元素个数
	Rank size(){ return _size; }
	//查找函数，找不到返回_lo-1
	Rank find(const T _e) { return find(_e,0,_size); }
	Rank find(const T _e,int _lo,int _hi)
	{
		while(_lo<=(--_hi) && _elem[_hi]!=_e);
		return _hi;
	}
	//有序向量线性查找函数，找不大于e的第一个位置
	Rank search(const T _e) { return search(_e, 0, _size); }
	Rank search(const T _e,int _lo,int _hi)//返回位置-1到size-1
	{
		_lo--;
		while(_elem[_lo+1]<=_e&&(_lo+1)<_hi) _lo++;
		return _lo;
	}
	//单点删除，复杂度On
	T remove(int _pos)
	{
		T _temp=_elem[_pos];
		erase(_pos,_pos+1);
		return _temp;
	}
	//区间删除
	int erase(int _lo,int _hi)
	{
		if(_lo==_hi) return 0;
		int woshisb=_hi-_lo;
		while(_hi<_size) _elem[_lo++]=_elem[_hi++];
		_size-=woshisb;
		shrink();
		return _hi-_lo;
	}
	//指定位置插入函数
	Rank insert(T const _temp) { return insert(_size,_temp); }
	Rank insert(Rank _r,T const _temp)
	{
		expand();
		for(int _i=_size;_i>_r;_i--) _elem[_i]=_elem[_i-1];
		_elem[_r]=_temp;_size++;
		return _r;
	}
	/*void sort()//排序函数，不会写
	{

	}*/
	//判空函数
	bool empty() { return _size==0; }
	void clear()
	{
		delete[]_elem;
		_elem=new T[_capacity=DEFAULT_CAPACITY];_size=0;
	}
	

	

};
#endif
