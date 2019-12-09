// hw03_2.h -- modified queue template
#ifndef HW032_H_
#define HW032_H_
#include<iostream>
using namespace std;
template <class KeyType>
class Queue
{
private:
	enum { DefaultQueueSize = 10 };    // default size
	int front, rear;		// index for front rear
	KeyType * queue;		// holds queue items
	int MaxSize;
	bool flag;
public:
	explicit Queue(int MaxQueueSize = DefaultQueueSize);
	Queue(const Queue & q);
	~Queue() { delete[] queue; }
	bool isfull() { return (rear == front && flag == true); }
	bool isempty() { return (rear == front && flag == false); }
	void Add(const KeyType & item);		// add item to queue
	KeyType* Delete();					// delete an item from queue
	Queue & operator=(const Queue & q);
	friend ostream & operator << <>(ostream &, Queue<KeyType> &);
};

template <class KeyType>
Queue<KeyType>::Queue(int MaxQueueSize) : MaxSize(MaxQueueSize), front(0), rear(0), flag(false)
{
	queue = new KeyType[MaxSize];
}

template <class KeyType>
Queue<KeyType>::Queue(const Queue & q)
{
	MaxSize = q.MaxSize;
	front = q.front;
	rear = q.rear;
	flag = q.flag;
	queue = new KeyType[MaxSize];
	for (int i = 0; i < MaxSize; i++)
		queue[i] = q.queue[i];
}

template <class KeyType>
void Queue<KeyType>::Add(const KeyType & item)
{
	if (!isfull())
	{
		rear = (rear + 1) % MaxSize;
		queue[rear] = item;
		if (rear == front)
			flag = true;
	}
}

template <class KeyType>
KeyType* Queue<KeyType>::Delete()
{
	if (!isempty())
	{
		front = (front + 1) % MaxSize;
		KeyType *temp = new KeyType;
		*temp = queue[front];
		if (front == rear)
			flag = false;
		return temp;
	}
}

template <class KeyType>
Queue<KeyType> & Queue<KeyType>::operator=(const Queue<KeyType> & q)
{
	if (this == &q)
		return *this;
	delete[] queue;
	MaxSize = q.MaxSize;
	front = q.front;
	rear = q.rear;
	flag = q.flag;
	queue = new KeyType[MaxSize];
	for (int i = 0; i < MaxSize; i++)
		queue[i] = q.queue[i];
	return *this;
}
template <class KeyType>
ostream & operator << <>(ostream &os, Queue<KeyType> &q)
{
	if (q.isfull() == true)
	{
		os << "Queue is full!" << endl;
		os << "Queue index:" << endl;
		os << q.front + 1 << '\t';
		for (int i = (q.front + 2) % q.MaxSize; i != q.front+1; i = (i + 1) % q.MaxSize)
		{
			os << i << "\t";
		}
		cout << endl;
		
		os << "Queue content:" << endl;
		os << q.queue[q.front + 1] << '\t';
		for (int i = (q.front + 2) % q.MaxSize; i != q.front + 1; i = (i + 1) % q.MaxSize)
		{
			os << q.queue[i] << "\t";
		}
		cout << endl;
	}
	else if (q.isempty() == true)
		os << "Queue is empty" << endl;
	else
	{
		os << "Queue index:" << endl;
		for (int i = (q.front + 1) % q.MaxSize; i != (q.rear + 1) % q.MaxSize; i = (i + 1) % q.MaxSize)
		{
			os << i<< "\t";
		}
		cout << endl;
		os << "Queue content:" << endl;
		for (int i = (q.front + 1) % q.MaxSize; i != (q.rear + 1) % q.MaxSize; i = (i + 1) % q.MaxSize)
		{
			os << q.queue[i] << "\t";
		}
		cout << endl;
	}
	return os;
}
#endif

