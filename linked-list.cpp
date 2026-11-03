#include <iostream>
using namespace std;

int size = 0;

class Node
{
public:
    int data;
    Node* next_add;

    void addData(int n)
    {
        data = n;
    }

    int getData()
    {
        return data;
    }

    void setNext(Node* next)
    {
        next_add = next;
    }

    Node* getNext()
    {
        return next_add;
    }
};

class List
{
public:
    Node* head;
    Node* lastNode;

    // Constructor
    List()
    {
        head = NULL;
        lastNode = NULL;
    }

    // Add new node
    void add()
    {
        int n;

        cout << "\n\n Enter value: ";
        cin >> n;

        Node* currentNode = new Node;

        currentNode->addData(n);
        currentNode->setNext(NULL);

        if (head == NULL)
        {
            head = currentNode;
            lastNode = currentNode;
        }
        else
        {
            lastNode->setNext(currentNode);
            lastNode = currentNode;
        }

        size++;

        cout << "\n\n New node inserted";
    }

    // Removing
    void remove()
    {
        if(head == NULL)
        {
            cout << "\n\nLinked list is empty";
        }
        else
        {
            int n, found = 0;

            cout << "\n\nEnter value for deletion:";
            cin >> n;

            if(n == head->getData())
            {
                Node* ptr = head;
                head = head->getNext();

                delete ptr;

                if(head == NULL)
                {
                    lastNode = NULL;
                }

                found++;
                size--;

                cout << "\n\n First Node deleted";
            }
            else
            {
                Node* pre = head;
                Node* ptr = head->getNext();

                while(ptr != NULL)
                {
                    if(n == ptr->getData())
                    {
                        pre->setNext(ptr->getNext());

                        if(ptr == lastNode)
                        {
                            lastNode = pre;
                        }

                        delete ptr;

                        cout << "\n\n Node deleted";

                        found++;
                        size--;
                        break;
                    }

                    pre = ptr;
                    ptr = ptr->getNext();
                }
            }

            if(found == 0)
            {
                cout << "\n\n Value cant found ";
            }
        }
    }

    void length()
    {
        cout << "\n\n Total nodes: " << size;
    }
};

int main()
{
    List obj;

    obj.add();
    obj.add();
    obj.remove();
    obj.length();

    return 0;
}
