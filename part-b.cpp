#include <iostream>
#include <string>

using namespace std;

template <typename T>
struct Node
{
    T data;

    Node(T newdata)
    {
        data = newdata;
    }

    Node()
    {
    }

    Node *next;
};

template <typename T>
class LinkedList
{
private:
    Node<T> *_head;
    Node<T> *_tail;

public:
    LinkedList() : _head(NULL), _tail(NULL) {}
    ~LinkedList();

    void add(const T &value);
    void remove(const T &value);

    inline T head() const { return _head; }
    inline T tail() const { return _tail; }

    inline bool isEmpty() const { return _head == NULL; }
    void show() const;
};

template <typename T>
LinkedList<T>::~LinkedList()
{
    cout << "destructor is called." << endl;

    Node<T> *temp = new Node<T>;
    temp = _head->next;
    delete _head;

    while (temp->next != NULL)
    {
        _head = temp;
        temp = temp->next;
        delete _head;
    }
    delete temp;
}

template <typename T>
void LinkedList<T>::add(const T &value)
{
    if (isEmpty())
    {
        Node<T> *newnode = new Node<T>(value);

        _head = newnode;
        _tail = newnode;

        newnode->next = NULL;
    }
    else
    {
        Node<T> *newnode = new Node<T>(value);

        _tail->next = newnode;
        _tail = newnode;

        newnode->next = NULL;
    }
}

template <typename T>
void LinkedList<T>::remove(const T &value)
{
    if (isEmpty())
    {
        cerr << "ERROR: You cannot remove from an empty list!" << endl;
    }
    else
    {
        Node<T> *current = new Node<T>;

        if (_head->data == value)
        {
            current = _head;

            _head = _head->next;
            delete current;
        }
        else if (_tail->data == value)
        {
            current = _head;

            while (current != NULL)
            {

                if (current->next->data == value)
                {
                    Node<T> *temp = new Node<T>;
                    temp = _tail;

                    _tail = current;
                    current->next = temp->next;
                    delete temp;
                }
                current = current->next;
            }
        }
        else
        {
            current = _head;

            while (current->next != NULL)
            {
                if (current->next->data == value)
                {
                    Node<T> *temp = new Node<T>;
                    temp = current->next;

                    current->next = temp->next;
                    delete temp;
                }
                current = current->next;
            }
        }
    }
}

template <typename T>
void LinkedList<T>::show() const
{
    cout << "head -> ";
    if (isEmpty())
    {
        cout << "NULL" << endl;
    }
    else
    {
        Node<T> *current = new Node<T>;
        current = _head;

        while (current != NULL)
        {
            cout << current->data << " -> ";
            current = current->next;
        }
        cout << "NULL" << endl;
    }
}

int main()
{
    //int test
    LinkedList<int> *li = new LinkedList<int>;

    for (int i = 10; i > 0; --i)
    {
        li->add(i);
    }
    li->show();

    li->remove(10);
    li->remove(5);
    li->remove(1);
    li->show();

    delete li;

    //char test
    LinkedList<char> *li2 = new LinkedList<char>;

    li2->add('a');
    li2->add('b');
    li2->add('c');
    li2->add('d');
    li2->add('e');
    li2->add('f');

    li2->show();

    li2->remove('a');
    li2->remove('d');
    li2->remove('f');

    li2->show();

    delete li2;

    return 0;
}