#pragma once
#define _TTextLink_h_
#include<iostream>
using namespace std;

	template <class T>
	struct TNode
	{
		T val;
		TNode <T>* pNext;
	};
	template<class T>
	class TListStack
	{
		TNode<T>* pFirst;
	public:
		TListStack() { pFirst = NULL; }
		TListStack(const TListStack<T>& a);
		TListStack& operator=(const TListStack& a);
		void Clear();
		bool IsEmpty() { return pFirst == NULL; }
		void Push(T a);
		T Top();
		T Pop();
		~TListStack();
		bool IsFull();
		int GetNum();
	};
	template<class T>
	TListStack<T>::TListStack(const TListStack<T>& a)
	{
		TNode<T>* tmp = new TNode<T>;
		tmp = a.pFirst;
		while (tmp != 0)
		{
			pFirst = tmp;
			tmp = tmp->pNext;
		}

	}
	template<class T>
	TListStack<T>& TListStack<T>:: operator=(const TListStack& a)
	{
		TNode<T>* tmp = new TNode<T>;
		tmp = a.pFirst;
		while (tmp != 0)
		{
			pFirst = tmp;
			tmp = tmp->pNext;
		}
		return *this;
	}
	template<class T>
	void TListStack<T>::Clear()
	{
		TNode <T>* tmp = pFirst;
		while (pFirst != NULL)
		{
			pFirst = pFirst->pNext;
			delete tmp;
			tmp = pFirst;
		}
	}
	template<class T>
	void TListStack<T>::Push(T a)
	{
		TNode <T>* TMP;
		TMP = new TNode<T>;
		TMP->pNext = pFirst;
		TMP->val = a;
		pFirst = TMP;
	}
	template<class T>
	T TListStack<T>::Top()
	{
		if (IsEmpty())throw - 1;
		return pFirst->val;
	}
	template<class T>
	T TListStack<T>::Pop()
	{
		if (IsEmpty())throw - 1;
		T res = pFirst->val;
		TNode<T>* tmp = pFirst;
		pFirst = pFirst->pNext;
		delete tmp;
		return res;
	}
	template<class T>
	TListStack<T>::~TListStack()
	{
		TNode <T>* tmp = pFirst;
		while (pFirst != NULL)
		{
			pFirst = pFirst->pNext;
			delete tmp;
			tmp = pFirst;
		}
	}
	template<class T>
	bool TListStack<T>::IsFull()
	{
		TNode<T>* p = new TNode<T>;
		if (p)
		{
			delete p;
			return true;
		}
		else
		{
			return false;
		}
	}
	template<class T>
	int TListStack<T>::GetNum()
	{
		TNode<T>* p = pFirst;
		int i = 0;
		while (p != NULL)
		{
			i++;
			p = (*p).pNext;
		}
		return i;
	}