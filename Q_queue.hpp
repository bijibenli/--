#pragma once
#include<iostream>
#include"Heap_sort.hpp"
using namespace std;

template<typename T>
class q_queue
{
protected:
	T* __a;
	int __size, __contain;
	void apply_contain(int x);
	bool flag = 0;// «∑Ò≈≈–Ú
public:
	q_queue() :__a(nullptr), __size(0), __contain(0) {}
	void push(T x);
	T top();
	int size();
	void pop();
};

template<typename T>
inline void q_queue<T>::push(T x)
{
	if (__size == __contain)
	{
		apply_contain(__size);
	}
	__size++;
	__a[__size - 1] = x;
	flag = 0;
}

template<typename T>
inline T q_queue<T>::top()
{
	if (flag == 0)
	{
		heap_sort(__a, __size);
		flag = 1;
	}
	return __a[0];
}

template<typename T>
inline void q_queue<T>::apply_contain(int x)
{ 
	if (x == 0)x = 1;
	x *= 2;
	__contain = x;
	T* node = new T[x];
	for (int i = 0; i < size(); i++)
	{
		node[i] = __a[i];
	}
	free(__a);
	__a = node;
	
}

template<typename T>
inline int q_queue<T>::size()
{
	return __size;
}

template<typename T>
inline void q_queue<T>::pop()
{
	T* node = new T[__contain];
	for (int i = 1; i < size(); i++)
	{
		node[i - 1] = __a[i];
	}
	free(__a);
	__a = node;
	__size--;
	flag = 0;
}
