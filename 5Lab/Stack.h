#ifndef STACK_H
#define STACK_H
#include <stdio.h>
#include <iostream>
template <typename T> class Stack
{
    private:
        T *stackptr;
        const int size;
        int top;
    public:
        Stack(int = 10);
        Stack(const Stack<T> &);
        virtual ~Stack();

        void push(const T &);
        void pop();
        void printStack();
        int getStackSize() const;
        T *getPtr() const;
        int getTop() const;
};

template <typename T>
Stack<T>::Stack(int maxSize): size(maxSize)
{
    stackptr = new T[size];
    top = 0;
}

template <typename T>
Stack<T>::Stack(const Stack<T> &otherStack): size(otherStack.getStackSize())
{
    stackptr = new T[size];
    top = otherStack.getTop();

    for(int ix=0;ix<top;ix++)
    {
        stackptr[ix] = otherStack.getPtr()[ix];
    }
}

template <typename T>
Stack<T>::~Stack()
{
    delete [] stackptr;
}

template <typename T>
void Stack<T>::push(const T &value)
{
    try
    {
        if (top >= size)
        {
            throw 0;
        }
        else
        {
            stackptr[top++]=value;
        }
    }
    catch(int a)
    {
        std::cout << "ERROR, stack is full" << std::endl;
    }
}

template <typename T>
void Stack<T>::pop()
{
    try
    {
        if(top <=0)
        {
            throw 0;
        }
        else
        {
            stackptr[--top];
        }
    }
    catch(int a)
    {
        std::cout << "ERROR, stack is empty" << std::endl;
    }
}

template <typename T>
void Stack<T>::printStack()
{
    for(int ix=top-1;ix>=0;ix--)
    {
        std::cout << "|    " << stackptr[ix] << std::endl;
    }
}

template <typename T>
int Stack<T>::getStackSize() const
{
    return size;
}

template <typename T>
T *Stack<T>::getPtr() const
{
    return stackptr;
}

template <typename T>
int Stack<T>::getTop() const
{
    return top;
}

#endif // STACK_H
