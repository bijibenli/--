#pragma once
template<typename T>
class vector
{
private:
	int contain_size, _size;//容量空间  与  元素数目
	T* _a;//数组
public:
	//默认构造
	vector() :contain_size(0), _size(0), _a(nullptr) {}
	//拷贝构造
	vector(const vector& x) :contain_size(x.contain_size), _size(x._size)
	{
		_a = new T[contain_size];
		for (int i = 0; i < _size; i++)
		{
			_a[i] = x._a[i];
		}
	}
	//构造(int a,b)
	vector(int w_size, int num) :contain_size(w_size), _size(w_size), _a(nullptr)
	{
		_a = new T[contain_size];
		for (int i = 1; i < _size; i++)
		{
			_a[i] = num;
		}
	}
	//开头
	T* begin()
	{
		return _a;
	}
	//结尾
	T* end()
	{
		return _a + _size;
	}

	T& operator[] (const T& x)
	{
		return _a[x];
	}

	//存入数据
	void push_back(const T x)
	{
		//判断空间是否充足
		if (_size == contain_size)resize(_size * 2);

		_a[_size++] = x;

	}
	int size()//返回元素个数
	{
		return _size;
	}
	vector& operator= (const vector& x)
	{
		clear();
		resize(x.contain_size);
		_size = x._size;

		for (int i = 0; i < x.size(); i++)
		{
			_a[i] = x._a[i];
		}
	}
	//清理空间
	void clear()
	{
		if (contain_size)
		{
			delete[] _a;
			contain_size = 0;
			_size = 0;
		}
		return;
	}
	//申请更多的空间
	void resize(int x)
	{
		if (!x)x = 1;
		contain_size = x;
		T* node = new T[contain_size];
		for (int i = 0; i < _size; i++)
		{
			node[i] = _a[i];
		}
		delete[] _a;
		_a = node;
	}
	//删除元素
	void pop_back()
	{
		--_size;
	}
	//析构函数
	~vector()
	{
		clear();
	}
};