#include <iostream>
#include <string>
using namespace std;
class ListNode
{
    float value;
    struct ListNode *next;

public:
    ListNode(float v = 0, ListNode *nt = nullptr) : value(v), next(nt) {}
    friend class FloatList;
};
class FloatList
{
private:
    ListNode *head;

public:
    FloatList(void)
    {
        head = NULL;
    }
    ~FloatList();
    void appendNode(float);      // insert at last
    void insertNode(float, int); // insert at begening and middle
    void deleteNode(int);        // delete acc to position
    void displayList(void);
    void reverse();
    int length();
};
int FloatList::length()
{
    if (!head)
        return 0;
    int count = 0;
    ListNode *nptr = head;
    while (nptr != nullptr)
    {
        count++;
        nptr = nptr->next;
    }
    return count;
}
void FloatList::appendNode(float num)
{
    ListNode *newNode, *nodePtr;
    newNode = new ListNode(num);
    if (!head)
        head = newNode;
    else
    {
        nodePtr = head;
        while (nodePtr->next)
            nodePtr = nodePtr->next;
        nodePtr->next = newNode;
    }
}
void FloatList::insertNode(float num, int pos)
{
    ListNode *newNode, *nodeptr = head;
    newNode = new ListNode;
    newNode->value = num;
    newNode->next = NULL;
    int i = 1, len = this->length();
    if (pos > len)
    {
        cout << "Length is:" << this->length() << endl;
        cout << "position exceeds" << endl;
        return;
    }
    if (pos == 0 || pos == 1)
    {
        newNode->next = head;
        head = newNode;
    }
    else
    {
        while (i != pos - 1)
        {
            nodeptr = nodeptr->next;
            i++;
        }
        newNode->next = nodeptr->next;
        nodeptr->next = newNode;
    }
}
void FloatList::deleteNode(int pos)
{
    ListNode *preNode = NULL, *nodeptr = head;
    int i = 1, len = this->length();
    if (pos > len)
    {
        cout << "Length is:" << this->length() << endl;
        cout << "position exceeds" << endl;
        return;
    }
    for (int i = 1; i < pos; i++)
    {
        preNode = nodeptr;
        nodeptr = nodeptr->next;
    }
    if (pos > 0)
        preNode->next = nodeptr->next;
    else
        head = head->next;
    free(nodeptr);
}
void FloatList::displayList(void)
{
    ListNode *nodePtr;
    nodePtr = head;
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
void FloatList::reverse()
{

    // ListNode *current = head;
    // ListNode *prev = NULL, *next = NULL;

    // while (current != NULL)
    // {
    //     // Store next
    //     next = current->next;
    //     // Reverse current node's pointer
    //     current->next = prev;
    //     // Move pointers one position ahead.
    //     prev = current;
    //     current = next;
    // }
    // head = prev;
    ListNode *p, *q, *r;
    p = nullptr, q = head, r = q->next;
    while (q != nullptr)
    {
        q->next = p;
        p = q;
        q = r;
        if (r != nullptr)
            r = r->next;
    }
    head = p;
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
    cout << "5.Reverse list" << endl;
    cout << "6.Exit" << endl;
    while (true)
    {
        cout << "\nEnter the operation number: ";
        cin >> inp;
        // if (inp == 6)
        // {
        //     cout << "Exited successfully" << endl;
        //     break;
        // }
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
            // cout << l.length() << endl;
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
        case 5:
            cout << "Elements are :" << endl;
            l.displayList();
            l.reverse();
            cout << "Elements are :" << endl;
            l.displayList();
            break;
        case 6:
            exit(0);

        default:
            cout << "Enter valid operation" << endl;
            break;
        }
    }

    return 0;
}