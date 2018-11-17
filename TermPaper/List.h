#ifndef LIST_H
#define LIST_H
#include <fstream>

template<typename T>
class List
{
    private:
        template<typename U>
        class Node
        {
        friend class List;
        public:
        Node(U data = U(), Node *pNext = nullptr, Node *pPrev = nullptr)
        {
            this->data = data;
            this->pNext = pNext;
            this->pPrev = pPrev;
        }

        private:
            Node *pNext = nullptr;
            Node *pPrev = nullptr;
            T data;
        };
        Node<T> *head;
        Node<T> *tail;
        int size;
    public:

        List();
        virtual ~List();

        void push_back(T data);
        void push_front(T data);
        void pop_back();
        void pop_front();
        void insert(T data, int index);
        void remove(int index);
        void clear();
        int GetSize() {return size;}

        class ListIterator
        {
            private:
                Node<T> *nodeptr;
            public:
                ListIterator(Node<T> *ptr):nodeptr(ptr){}
                ~ListIterator(){}//{delete nodeptr;}
                T& operator*(){return nodeptr->data;}
                ListIterator& operator++() {nodeptr = nodeptr->pNext; return *this;}
                //ListIterator& operator++(int) {}
                ListIterator& operator--() {nodeptr = nodeptr->pPrev; return *this;}
                //ListIterator& operator--(int) {}
                bool operator==(const ListIterator& ptr) {return nodeptr==ptr.nodeptr;}
                bool operator!=(const ListIterator& ptr) {return nodeptr!=ptr.nodeptr;}
        };
        typedef ListIterator iterator;

        ListIterator begin()
        {
            return ListIterator(head);
        }

        ListIterator end()//NOT FOR REVERSE. For reverse we need tail.
        {
            return nullptr;//ListIterator(tail);
        }

        void addList(List<T>&other);
        T &operator*();
        T &operator[](const int index);
};

template<typename T>
List<T>::List()
{
    size=0;
    this->head=nullptr;
    this->tail=nullptr;
}

template<typename T>
List<T>::~List()
{
    clear();
}

template<typename T>
void List<T>::push_back(T data)
{
    if(head==nullptr)
    {
        head = new Node<T>(data);
        tail = head;
    }
    else
    {
        Node<T> *current = this->tail;
        tail->pNext = new Node<T>(data);
        tail = tail->pNext;
        tail->pPrev = current;
        tail->pNext = nullptr;
    }
    size++;
}

template<typename T>
void List<T>::push_front(T data)
{
    if(head==nullptr)
    {
        head = new Node<T>(data);
        tail = head;
    }
    else
    {
        Node<T> *current = this->head;
        head->pPrev = new Node<T>(data);
        head = head->pPrev;
        head->pPrev = nullptr;
        head->pNext = current;
    }
    size++;
}

template<typename T>
void List<T>::pop_back()
{
    if(size==1)
    {
        Node<T> *tmp = tail;
        tail = nullptr;
        head = nullptr;
        delete tmp;
        size--;
    }
    if(size>1)
    {
        Node<T> *current = tail;
        tail = tail->pPrev;
        delete current;
        tail->pNext = nullptr;
        size--;
    }
}

template<typename T>
void List<T>::pop_front()
{
    if(size==1)
    {
        Node<T> *tmp = head;
        tail = nullptr;
        head = nullptr;
        delete tmp;
        size--;
    }
    if(size>1)
    {
        head = head->pNext;
        delete head->pPrev;
        head->pPrev = nullptr;
        size--;
    }
}

template<typename T>
void List<T>::insert(T data, int index)
{
    if(index>=0 && index<=size)
    {
    if(index==0)
    {
        push_front(data);
    }
    else if(index==size)
    {
        push_back(data);
    }
    else
    {
        if(size/2>=index)
        {
            Node<T> *current = head;
            Node<T> *newNode = new Node<T>(data);
            for(int i=0;i<index;i++)
            {
                current = current->pNext;
            }
            newNode->pNext = current;
            newNode->pPrev = current->pPrev;
            current->pPrev->pNext = newNode;
            current->pPrev = newNode;
            size++;
        }
        else
        {
            Node<T> *current = tail;
            Node<T> *newNode = new Node<T>(data);
            for(int i=size-1;i>index;i--)
            {
                current = current->pPrev;
            }
            newNode->pNext = current;
            newNode->pPrev = current->pPrev;
            current->pPrev->pNext = newNode;
            current->pPrev = newNode;
            size++;
        }
    }
    }
}

template<typename T>
void List<T>::remove(int index)
{
    if(index>=0 && index<size)
    {
        if(index == 0)
        {
            pop_front();
        }
        else if(index == size-1)
        {
            pop_back();
        }
        else
        {
            if(size/2>=index)
            {
                Node<T> *current = head;
                Node<T> *tmp;
                for(int i=0;i<index-1;i++)
                {
                    current = current->pNext;
                }
                tmp = current->pNext;
                current->pNext = tmp->pNext;
                current->pNext->pPrev = current;
                delete tmp;
                size--;
            }
            else
            {
                Node<T> *current = tail;
                Node<T> *tmp;
                for(int i=size;i>index;i--)
                {
                    current = current->pPrev;
                }
                tmp = current->pNext;
                current->pNext = tmp->pNext;
                current->pNext->pPrev = current;
                delete tmp;
                size--;
            }
        }
    }
}

template<typename T>
void List<T>::clear()
{
    while(size!=0)
    {
        pop_front();
    }
}

template<typename T>
void List<T>::addList(List<T> &other)
{
    if(this->head == other.head)
    {
        this->size += other.size;
        Node<T> *current = this->head;
        while(current->pNext != nullptr)
        {
            current = current->pNext;
        }
        Node<T> *other_current = other.head;
        for(int i=0;i<other.size;i++)
        {
            Node<T> *newnode = new Node<T>;
            newnode->data = other_current->data;
            newnode->pPrev = current;
            current->pNext = newnode;
            other_current = other_current->pNext;
            current = current->pNext;
        }
        this->tail = nullptr;
    }
    else
    {
        this->size += other.size;
        Node<T> *current = this->head;
        while(current->pNext != nullptr)
        {
            current = current->pNext;
        }
        Node<T> *other_current = other.head;
        while(other_current!= nullptr)
        {
            Node<T> *newnode = new Node<T>;
            newnode->data = other_current->data;
            newnode->pPrev = current;
            current->pNext = newnode;
            other_current = other_current->pNext;
            current = current->pNext;
        }
        this->tail = nullptr;
    }
}


template<typename T>
T& List<T>::operator*()
{
    return this->data;
}

template<typename T>
T& List<T>::operator[](const int index)
{
    int counter=0;
    Node<T> *current = this->head;
    while(current!=nullptr)
    {
        if(counter == index)
        {
            return current->data;
        }
        current = current->pNext;
        counter++;
    }
}

#endif // LIST_H
