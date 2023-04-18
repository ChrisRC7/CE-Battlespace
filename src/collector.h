#ifndef COLLECTOR_H
#define COLLECTOR_H

#include <QList>
#include "node.h"

template<typename T>
class Collector {
public:
    Collector() {}
    virtual ~Collector() {}

    void insertFirst(T *item) 
    {
        Node<T> *newNode= new Node<T>(item);
        newNode->setNext(head);
        head= newNode;
        size++; 
    }
    void removeNode(T *item) 
    { 
        Node<T> *current= head;
        Node<T> *temp= nullptr;
        if (current->getData() == item) {
            head= current->getNext();
            return;
        } else{
            temp= current;
            current= current->getNext();
            while (current!= nullptr)
            {
                if (current->getData() == item)
                {
                    temp->setNext(current->getNext());
                    size--;
                    break;
                }
                temp= current;
                current= current->getNext();
            }
        }
        
    }
    T* getFirstNode() const { return head->getData(); }

    T* getNext (T *item)
    { 
        Node<T> *current= head;
            while (current!= nullptr)
            {
                if (current->getData() == item and current->getNext()!= nullptr)
                {
                    current= current->getNext();
                    return current->getData();
                }
                current= current->getNext();
            }
            return nullptr;
    }

    int getSize() {return size;}

private:
    Node<T>* head;
    int size;

};

#endif // COLLECTOR_H

