#include <iostream>
#include "StackList.h"
#include "QueueList.h"
void main()
{
	List<int> l;
	ListElem<int>* t;
	int k = 7;
	int m = 5;
	int n = 3;
	l.InsFirst(k);
	l.InsLast(n);
	l.InsLast(m);
	l.InsLast(m);
	cout << "List" << endl << l << endl;
	StackList<int> s1;
	s1.push(k);
	s1.push(k);
	s1.push(k);
	cout << "StackList1" << endl << s1 << endl;
	StackList<int> s2;
	for(int i=0;i<10;i++)
	s2.push(m);
	cout << "StackList2" << endl << s2 << endl;
	StackList<int> res;
	res.Mix(s1, s2);
	cout << "Result" << endl << res << endl;
	QueueList<int> q;
	q.push(k);
	q.push(m);
	q.push(n);
	cout << "Queue" << endl << q << endl;
	q.Rotate();
	cout << "Changed Queue" << endl << q << endl;
	cout << "Find element in queue" << endl << q.Search(3)->GetData() << endl;
	cout << "Find element in stack" << endl << q.Search(5)->GetData() << endl;
}
