#ifndef COLLECTOR_H
#define COLLECTOR_H

#include <QList>
#include "node.h"

template<typename T>
class Collector {
public:
    Collector() {
        head=nullptr;
        size=0;
    }
    virtual ~Collector() {
        head=nullptr;
        size=0;
    }

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
            size--;
            return;
        } else{
            temp= current;
            current= current->getNext();
            while (current!= nullptr)
            {
                if (current->getData() == item)
                {
                    size--;
                    temp->setNext(current->getNext());
                    break;
                }
                temp= current;
                current= current->getNext();
            }
        }
        
    }
    T* getFirstNode() const { 
        if(size==0){
            return nullptr;
        }
        return head->getData();
    }

    T* getNext (T *item)
    { 
        if (size==0){
            return nullptr;
        }
        Node<T> *current= head;
            while (current!= nullptr)
            {
                if (current->getData() == item && current->getNext() != nullptr)
                {
                    current= current->getNext();
                    return current->getData();
                }
                current= current->getNext();
            }
            return nullptr;
    }

    int getSize() {return size;}

    bool isEmpty()
    {
        if(size==0) {return true;} else {return false;}
    }

private:
    Node<T>* head;
    int size;

};

#endif // COLLECTOR_H

