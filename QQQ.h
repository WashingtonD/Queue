#ifndef QQQ_H_INCLUDED
#define QQQ_H_INCLUDED
#include <iostream>
#include <stdexcept>
#include "QQQ.h"
using namespace std;

template<typename T>
struct Queue
{
    private:
    struct Node
    {
        T value;
        Node* next;
        Node(T v, Node* n = nullptr)
        {
            value = v;
            next = n;
        }
    };
Node* head = nullptr;
int counter = 0;
public:
    Queue() = default;
    Queue(const Queue&);

    ~Queue();
    Queue& operator=(const Queue&);
    void push(T);
    T pop();
    void print() const;
    void clear();
};


template<typename T>
Queue<T>& Queue<T>::operator=(const Queue& s)
{
    if(this != &s)
    {
        Node* pred = nullptr;
        Node* succ = head;
        Node* walker = s.head;
        while(walker)
        {
            if(succ != nullptr)
                succ->value = walker->value;
            else
            {
                succ = new Node(walker->value);
                if(!pred)
                    head = succ;
                else
                    pred->next = succ;
            }
        pred = succ;
        succ = succ->next;
        walker = walker->next;
        }
    }
return *this;
}





template<typename T>
Queue<T>::Queue(const Queue& s)
{
   if(this != &s)
   {
       Node* walker = s.head;
       Node* succ = head;
       Node* pred = nullptr;
       while(walker)
       {
           if(succ)
           {
               succ->value = walker->value;
           }
           else
           {
               succ = new Node(walker->value);
               if(pred == nullptr)
                head = succ;
               else
                pred->next = succ;
           }
           pred = succ;
            succ = succ->next;
            walker = walker->next;
       }
    while(succ != nullptr)
    {
        Node* killer = succ;
        succ = succ->next;
        delete killer;
    }
   }
}

template<typename T>
void Queue<T>::push(T v)
{
    Node* creator = new Node(v);
    if(head == nullptr)
        {
            head = creator;
            counter++;
            return;
        }
Node* walker = head;
Node* pred = nullptr;
while(walker)
{
    pred = walker;
    walker = walker->next;
}
pred->next = creator;
counter++;
}

template<typename T>
T Queue<T>::pop()
{
    if(head == nullptr)
        throw logic_error("Empty Queue!");
    Node* killer = head;
    head = head->next;
    T v = killer->value;
    delete killer;
    counter--;
    return v;
}

template<typename T>
void Queue<T>::print() const
{
    cout << "Your Q";
    if(!head)
    {
        cout << " is empty :/";
        return;
    }
cout <<" = ";
Node* walker = head;
while(walker)
{
    cout << " " << walker->value;
    walker = walker->next;
}
cout << endl;
}

template<typename T>
void Queue<T>::clear()
{
    while(head)
    {
        Node* killer = head;
        head = head->next;
        delete killer;
    }
}


template<typename T>
Queue<T>::~Queue()
{
    clear();
}




#endif // QQQ_H_INCLUDED
