#ifndef _HEADERNAME_Myvector
#define _HEADERNAME_Myvector


typedef int Rank;

const int DEFAULT_CAPACITY=8;//Ĭ������
template <typename T> class My_Vector
{
	protected:
	Rank _size;//ʵ�ʹ�ģ
	int _capacity;//Ŀǰ����
	T *_elem;//������

	protected:
	void copyFrom(T const* A,Rank _lo,Rank _hi)//������������A[lo, hi)
	{
		_elem=new T[_capacity=2 * (_hi - _lo)];_size=0;
		while(_lo<_hi) _elem[_size++]=A[_lo++];
	}
	void expand()//�ռ䲻��ʱ����
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
	//����
	My_Vector(int _c=DEFAULT_CAPACITY){ _elem=new T[_capacity=_c];_size=0; }
	//��������
	My_Vector(My_Vector<T> const &_oldvec) { copyFrom(_oldvec._elem,0,_oldvec._size); }
	//����
	~My_Vector(){ delete[] _elem; }
	//����[]��֧�ַ����ŷ���
	T& operator [](Rank r) { if(0<=r&&r<_size) return _elem[r]; }
	//����ĩβ
	T& push_back(const T c){ expand();_elem[_size++]=c;return _elem[_size-1]; }
	//ɾ��ĩβԪ��
	T pop_back(){ _size--;T _temp=*(_elem+_size);shrink();return _temp; }
	//��ѯԪ�ظ���
	Rank size(){ return _size; }
	//���Һ������Ҳ�������_lo-1
	Rank find(const T _e) { return find(_e,0,_size); }
	Rank find(const T _e,int _lo,int _hi)
	{
		while(_lo<=(--_hi) && _elem[_hi]!=_e);
		return _hi;
	}
	//�����������Բ��Һ������Ҳ�����e�ĵ�һ��λ��
	Rank search(const T _e) { return search(_e, 0, _size); }
	Rank search(const T _e,int _lo,int _hi)//����λ��-1��size-1
	{
		_lo--;
		while(_elem[_lo+1]<=_e&&(_lo+1)<_hi) _lo++;
		return _lo;
	}
	//����ɾ�������Ӷ�On
	T remove(int _pos)
	{
		T _temp=_elem[_pos];
		erase(_pos,_pos+1);
		return _temp;
	}
	//����ɾ��
	int erase(int _lo,int _hi)
	{
		if(_lo==_hi) return 0;
		int woshisb=_hi-_lo;
		while(_hi<_size) _elem[_lo++]=_elem[_hi++];
		_size-=woshisb;
		shrink();
		return _hi-_lo;
	}
	//ָ��λ�ò��뺯��
	Rank insert(T const _temp) { return insert(_size,_temp); }
	Rank insert(Rank _r,T const _temp)
	{
		expand();
		for(int _i=_size;_i>_r;_i--) _elem[_i]=_elem[_i-1];
		_elem[_r]=_temp;_size++;
		return _r;
	}
	/*void sort()//������������д
	{

	}*/
	//�пպ���
	bool empty() { return _size==0; }
	void clear()
	{
		delete[]_elem;
		_elem=new T[_capacity=DEFAULT_CAPACITY];_size=0;
	}
	

	

};
#endif
