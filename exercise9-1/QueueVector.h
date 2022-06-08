/*
binyamin shapira 208965863
oz asban 207565607.

we make together

course : cadna c++.
exercise 9 question 1

the file is definition of class "QueueVector" (this class is sun of class "Queue")
and declaration of is methods          .*/

#pragma once
#include "Queue.h"

template <class T>
class QueueVector : public Queue<T>
{
public:
	QueueVector(int max);
	//QueueVector(const QueueVector&);
	void clear() override;
	T dequeue() override;
	void enqueue(T value) override;
	T front() override;
	bool isEmpty() const override;
private:
	T* data;
	int capacity;
	int nextSlot;
	int firstUse;
};
//implementation of queue
template <class T>
QueueVector<T> ::QueueVector(int size)//ctor
{
	capacity = size + 1;
	data = new T[capacity];
	clear();
}

template <class T>
void QueueVector<T>::clear()//clear
{
	nextSlot = 0;
	firstUse = 0;
}

template <class T>
T QueueVector<T>::dequeue()
{
	if (isEmpty()) throw "Queue is empty\n";
	int dataloc = firstUse;
	++firstUse %= capacity;
	return data[dataloc];
}

template <class T>
void QueueVector<T>::enqueue(T val) {
	if ((nextSlot + 1) % capacity == firstUse)
		throw "the Queue is full\n";
	data[nextSlot] = val;
	++nextSlot %= capacity;
}

template <class T>
T QueueVector<T>::front() {
	if (isEmpty())
		throw "Queue is empty\n";
	return data[firstUse];
}

template <class T>
bool QueueVector<T>::isEmpty() const {
	return nextSlot == firstUse;
}
