#ifndef NODE_H
#define NODE_H

template<typename T>
class Node {
public:
    Node(T* data){
        this->next= nullptr;
        this->data= data;
    }
   


    T* getData() const { return this->data; }
    Node<T>* getNext() const { return this->next;}
    void setNext(Node<T>* data) {this->next = data;}
    void setData(T* data) { this->data = data; }

private:
    T* data;
    Node<T>* next;
};


#endif // NODE_H
