#include <iostream>
 
using namespace std;

template<typename T>
class List
{
public:
    List();
    ~List();
    //void show();
    void push_back(T data);

private:

    //template<typename S>
    class Node
    {
    public:
        Node *pNext;
        S data;

        Node(S data=T(), Node *pNext=nullptr)
        {
            this->data = data;
            this->pNext= pNext;
        }
    };

    Node <T> *head;
    int size;
};

template<typename T>
List<T>::List()
{
    size = 0;
    head = nullptr;
}

template<typename T>
List<T>::~List()
{
    
}

template<typename T>
void List<T>::push_back(T data)
{
    if(head == nullptr)
    {
        head = new Node<T>(data);
    }
    else
    {
        Node<T> *current=this->head;
        while(current->pNext!=nullptr)
        {
            current = current->pNext;
        }

        current->pNext = new Node<T>(data);
    }

}

int main()
{
    List<int> lst;

    lst.push_back(1);
    lst.push_back(2);
    lst.push_back(3);

    return 0;
}