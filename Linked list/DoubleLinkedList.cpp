#include <iostream>
#include <string>
using namespace std;
class FloatList
{
private:
    struct ListNode
    {
        float value;
        struct ListNode *next;
        struct ListNode *prev;
    };
    ListNode *head;

public:
    FloatList(void)
    {
        head = NULL;
    }
    ~FloatList();
    void appendNode(float);
    void insertNode(float, int);
    void deleteNode(int);
    void displayList(void);
};
void FloatList::appendNode(float num)
{
    ListNode *newNode, *nodePtr;
    newNode = new ListNode;
    newNode->value = num;
    newNode->next = NULL;
    newNode->prev = NULL;

    if (!head)
    {
        head = newNode;
    }
    else
    {
        nodePtr = head;
        while (nodePtr->next)
            nodePtr = nodePtr->next;

        nodePtr->next = newNode;
        newNode->prev = nodePtr;
    }
}

void FloatList::insertNode(float num, int pos)
{
    ListNode *newNode, *nodeptr = head;
    newNode = new ListNode;
    newNode->value = num;
    newNode->next = NULL;
    newNode->prev = NULL;
    int i = 1;
    if (pos == 0 || pos == 1)
    {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    else
    {
        while (i != pos - 1 and nodeptr->next != NULL)
        {
            nodeptr = nodeptr->next;
            i++;
        }

        newNode->next = nodeptr->next;
        nodeptr->next->prev = newNode;

        newNode->prev = nodeptr;
        nodeptr->next = newNode;
    }
}

void FloatList::deleteNode(int pos)
{
    ListNode *nodeptr = head;
    for (int i = 1; i < pos - 1; i++)
    {
        nodeptr = nodeptr->next;
    }

    if (pos > 1)
    {
        nodeptr->next->next->prev = nodeptr;
        nodeptr->next = nodeptr->next->next;
    }

    else
    {
        head->next->prev=NULL;
        head = head->next;
    }
}

void FloatList::displayList(void)
{
    ListNode *nodePtr = head;
    while (nodePtr)
    {
        cout << nodePtr->value << endl;
        nodePtr = nodePtr->next;
    }
}

FloatList::~FloatList(void)
{
    ListNode *nodePtr, *nextNode;
    nodePtr = head;
    while (nodePtr != NULL)
    {
        nextNode = nodePtr->next;
        delete nodePtr;
        nodePtr = nextNode;
    }
}
int main()
{
    FloatList l;
    int n, inp, pos;
    float val;
    cout << "Operations are" << endl;
    cout << "1.Create Linked list" << endl;
    cout << "2.Insert value" << endl;
    cout << "3.Delete value" << endl;
    cout << "4.Display value" << endl;
    cout << "5.Exit" << endl;
    while (true)
    {
        cout << "\nEnter the operation number: ";
        cin >> inp;
        if (inp == 5)
        {
            cout << "Exited successfully" << endl;
            break;
        }
        switch (inp)
        {
        case 1:
            cout << "Enter the number of element: ";
            cin >> n;
            for (int i = 0; i < n; i++)
            {
                cout << "Enter the value: ";
                cin >> val;
                l.appendNode(val);
            }

            break;
        case 2:
            cout << "Enter the value to be inserted: ";
            cin >> val;
            cout << "Enter the Position: ";
            cin >> pos;
            l.insertNode(val, pos);
            break;

        case 3:
            cout << "Enter the Position of element: ";
            cin >> pos;
            l.deleteNode(pos);
            break;

        case 4:
            cout << "Elements are :" << endl;
            l.displayList();
            break;

        default:
            cout << "Enter valid operation" << endl;
            break;
        }
    }

    return 0;
}