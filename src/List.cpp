#include <bits/stdc++.h>
#include <iostream>
#include "Node.cpp"
#include <utility>
template<typename T>
class Collector
{
private:
    Node<T> *head;

private:
    int size;

public:
    Collector()
    {
        this->head = NULL;
        this->size = 0;
    };

public:
    bool isEmpty()
    {
        return this->size == 0;
    };

public:
    int Size()
    {
        return this->size;
    };

public:
    void insertFirst(T data)
    {
        Node<T> *newNode = NULL;
        newNode = new Node<T>(data);
        newNode->setNext(this->head);
        this->head = newNode;
        this->size++;
    };

public:
    Node<T> *deleteFirst()
    {
        if (this->head != NULL)
        {
            Node<T> *temp = this->head;
            this->head = this->head->getNext();
            this->size--;
            return temp;
        }
        else
        {
            return NULL;
        }
    };

public:
    void displayList()
    {
        Node<T> *current = this->head;
        while (current != NULL)
        {
            printf("%d", current->getData());
            current = current->getNext();
        }
    };
};