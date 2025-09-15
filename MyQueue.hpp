#pragma once

#include <iostream>
#include <exception>

template <typename t>
class MyQueue
{
public:
    MyQueue();
    MyQueue(const MyQueue<t>& other);
    MyQueue<t>& operator=(const MyQueue<t>& other);
    ~MyQueue();

    void push(const t& obj);
    void pop();
    const t& peek() const;
    bool isEmpty() const;
private:
    t* data;
    size_t size;
    size_t capacity;

    size_t get;
    size_t put;
    void resize();
    void copyFrom(const MyQueue<t>& other);
    void free();
};

template <typename t>
MyQueue<t>::MyQueue()
{
    capacity = 4;
    size = 0;
    data = new t[capacity];
    get = put = 0;
}

template <typename t>
void MyQueue<t>::push(const t& obj)
{
    if (size >= capacity)
    {
        resize();
    }

    data[put] = obj;
    (++put) %= capacity;
    size++;
}

template <typename t>
bool MyQueue<t>::isEmpty() const
{
    return size == 0;
}

template <typename t>
const t& MyQueue<t>::peek() const
{
    if (isEmpty())
    {
        throw std::out_of_range("MyQueue is empty");
    }

    return data[get];
}

template <typename t>
void MyQueue<t>::pop()
{
    if (isEmpty())
    {
        throw std::out_of_range("MyQueue is empty");
    }

    (++get) %= capacity;
    size--;
}

template <typename t>
void MyQueue<t>::resize()
{
    t* newData = new t[capacity*2];
    for (size_t i = 0; i < size; i++)
    {
        newData[i] = data[get];
        (++get) %= capacity;
    }
    capacity *= 2;
    delete [] data;
    data = newData;
    get = 0;
    put = size;
}

template <typename t>
void MyQueue<t>::copyFrom(const MyQueue<t>& other)
{
    data = new t[other.size];
    for (size_t i = 0; i < other.size; i++)
    {
        data[i] = other.data[i];
    }
    size = other.size;
    capacity = other.capacity;
    get = other.get;
    put = other.put;
}

template <typename t>
void MyQueue<t>::free()
{
    delete [] data;
}

template <typename t>
MyQueue<t>::MyQueue(const MyQueue<t>& other)
{
    copyFrom(other);
}

template <typename t>
MyQueue<t>& MyQueue<t>::operator=(const MyQueue<t>& other)
{
    if (this != &other)
    {
        free();
        copyFrom(other);
    }
    return *this;
}

template <typename t>
MyQueue<t>::~MyQueue()
{
    free();
}
