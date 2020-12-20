#pragma once
#ifndef _STACKLIST_
#define _STACKLIST_

#include <iostream>
#include "List.h"
using namespace std;

template <class T1>
class StackList
{
protected:
    List<T1> list;
public:

    StackList();
    StackList(StackList<T1>& other);
    ~StackList();

    void push(T1 elem);
    T1 pull();
    bool IsFull();
    bool IsEmpty();
    StackList<T1>& operator =(StackList<T1>& other);
    void Mix(StackList<T1>& other1, StackList<T1>& other2);
    ListElem<T1>* Search(int elem);
    template <class T1>
    friend ostream& operator<< (ostream& ostr, const StackList<T1>& A);
    template <class T1>
    friend istream& operator >> (istream& istr, StackList<T1>& A);

    int GetCount();

};

template <class T1>
ostream& operator<< (ostream& ostr, const StackList<T1>& A)
{
    return ostr<<A.list;
}

template <class T1>
istream& operator >> (istream& istr, StackList<T1>& A)
{
    return istr>>A.list;
}

template <class T1>
StackList<T1>::StackList()
{
}

template <class T1>
StackList<T1>::StackList(StackList<T1>& other)
{
    list = other.list;
}
template <class T1>
StackList<T1>::~StackList()
{
}

template<class T1>
inline void StackList<T1>::push(T1 elem)
{
    list.InsFirst(elem);
}

template<class T1>
inline T1 StackList<T1>::pull()
{
    if (list.IsEmpty())
        throw logic_error("stack_is_empty");
    T1 tmp = list.GetFirst()->GetData();
    list.DelFirst();
    return tmp;
}

template<class T1>
inline bool StackList<T1>::IsFull()
{
    return list.IsFull();
}

template<class T1>
inline bool StackList<T1>::IsEmpty()
{
    return list.IsEmpty();
}

template <class T1>
StackList<T1>& StackList<T1>::operator =(StackList<T1>& other)
{
    if (this == &other)
        return *this;
    list = other.list;;
    return *this;
}

template<class T1>
inline void StackList<T1>::Mix(StackList<T1>& other1, StackList<T1>& other2)
{
    int t = 0;
    int c = other1.list.GetCount()+ other2.list.GetCount();
    for (int i = 0; i < c; i++)
    {
    switch (rand()%2)
    {
    case 0:
        if(other1.IsEmpty()==0)
            t=other1.pull();
        else
            t = other2.pull();
        break;
    case 1:
        if (other2.IsEmpty() == 0)
            t = other2.pull();
        else
            t = other1.pull();
        break;
    }
    this->push(t);
    }
}

template<class T1>
inline ListElem<T1>* StackList<T1>::Search(int elem)
{
    if (list.IsEmpty())
        throw logic_error("stack_is_empty");
    return list.GetMiddle(elem);
}



template <class T1>
int StackList<T1>::GetCount()
{
    return list.GetCount();
}


#endif