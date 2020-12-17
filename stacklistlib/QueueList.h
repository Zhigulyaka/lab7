#pragma once
#ifndef _QUEUELIST_
#define _QUEUELIST_

#include <iostream>
#include "List.h"
using namespace std;


template <class T2>
class QueueList
{
protected:
    List<T2> list;
public:
    QueueList();
    QueueList(QueueList<T2>& A);
    ~QueueList();

    void push(T2 elem);
    T2 pull();

    bool IsFull();
    bool IsEmpty();

    QueueList& operator = (QueueList<T2>& A);
    int GetCount();
    template<class T2>
    friend istream& operator>>(istream& in, QueueList<T2>& A);
    template<class T2>
    friend ostream& operator<<(ostream& out, const QueueList<T2>& A);
};

template<class T2>
istream& operator>>(istream& in, QueueList<T2>& A)
{
    return istr >> A.list;
}
template<class T2>
ostream& operator<<(ostream& out, const QueueList<T2>& A)
{
    return ostr<<A.list;
}
template<class T2>
inline QueueList<T2>::QueueList()
{
}

template<class T2>
inline QueueList<T2>::~QueueList()
{
}
template<class T2>
inline void QueueList<T2>::push(T2 elem)
{
    list.InsLast(elem);
}
template<class T2>
inline T2 QueueList<T2>::pull()
{
    if (list.IsEmpty())
        throw logic_error("stack_is_empty");
    T2 tmp = list.GetFirst()->GetData();
    list.DelFirst();
    return tmp;
}
template<class T2>
inline bool QueueList<T2>::IsFull()
{
    return list.IsFull();
}
template<class T2>
inline bool QueueList<T2>::IsEmpty()
{
    return list.IsEmpty();
}
template<class T2>
inline QueueList<T2>::QueueList(QueueList<T2>& A)
{
    this->list = A.list;
}

template<class T2>
inline QueueList<T2>& QueueList<T2>::operator=(QueueList<T2>& A)
{
    if (this == &A)
        return *this;
    this->list = A.list;
    return *this;
}
template<class T2>
inline int QueueList<T2>::GetCount()
{
    return list.GetCount();
}
#endif