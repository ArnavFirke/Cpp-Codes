#include <iostream>
#include <string>
using namespace std;
class FloatList
{
private:
    struct ListNode
    {
        int seatval, status;
        string id;
        struct ListNode *next;
        struct ListNode *prev;
    };
    ListNode *head;

public:
    FloatList(void)
    {
        head = nullptr;
    }
    void create_list();
    void bookseat();
    void avail();
    void cancel();
    void displayList();
};
void FloatList::create_list()
{
    ListNode *newSeat, *tail;
    newSeat = new ListNode;
    newSeat->seatval = 1;
    newSeat->status = 0;
    newSeat->id = "";
    tail = head = newSeat;

    for (int i = 2; i <= 70; i++)
    {
        ListNode *p;
        p = new ListNode;
        p->seatval = i;
        p->status = 0;
        p->id = "";

        tail->next = p;
        p->prev = tail;
        tail = p;
        tail->next = head;
        head->prev = tail;
    }
}
void FloatList::displayList()
{
    ListNode *newSeat;
    newSeat = head;
    int count = 0;
    cout << "\n------------------------------------------------------------------------------------" << endl;
    cout << "\t\t\t\t Screen this way" << endl;
    cout << "------------------------------------------------------------------------------------" << endl;
    do
    {
        if (newSeat->seatval / 10 == 0)
            cout << "S0" << newSeat->seatval << " :";
        else
            cout << "S" << newSeat->seatval << " :";

        if (newSeat->status == 0)
            cout << "|___| ";
        else
            cout << "|_B_| ";
        count++;
        if (count % 7 == 0)
        {
            cout << endl;
        }
        newSeat = newSeat->next;
    } while (newSeat != head);
}
void FloatList::bookseat()
{
    int x;
    string y;
label:
    cout << "\nEnter seat number to be booked: ";
    cin >> x;
    if (x < 1 || x > 70)
    {
        cout << "Enter correct seat number to book (1-70)\n";
        goto label;
    }
    cout << "Enter your ID number: ";
    cin >> y;
    ListNode *newSeat;
    newSeat = new ListNode;
    newSeat = head;
    while (newSeat->seatval != x)
    {
        newSeat = newSeat->next;
    }

    if (newSeat->status == 1)
        cout << "Booking Failed,Seat is already booked" << endl;
    else
    {
        newSeat->status = 1;
        newSeat->id = y;
        cout << "Seat " << x << " is successfully booked!" << endl;
    }
}
void FloatList::cancel()
{
    int x;
    string y;
label1:
    cout << "Enter seat number to cancel booking: ";
    cin >> x;
    if (x < 1 || x > 70)
    {
        cout << "Enter correct seat number to cancel (1-70)" << endl;
        goto label1;
    }
    ListNode *newSeat;
    // newSeat = new ListNode;
    newSeat = head;
    while (newSeat->seatval != x)
    {
        newSeat = newSeat->next;
    }
    if (newSeat->status == 0)
    {
        cout << "Seat not booked yet!!" << endl;
        goto label1;
    }
    else
    {
        cout << "Enter you ID: ";
        cin >> y;
        if (newSeat->id == y)
        {
            newSeat->status = 0;
            cout << "Seat Cancelled!" << endl;
        }

        else
            cout << "Wrong User ID !!! Seat cannot be cancelled!!!" << endl;
    }
}
void FloatList::avail()
{
    ListNode *newseat = head;
    int count = 0;
    cout << "\n\n--------------------------------------------------------------------------------\n";
    cout << " \t\t\t\tScreen this way \n";
    cout << "--------------------------------------------------------------------------------\n";
    while (newseat->next != head)
    {
        {
            if (newseat->seatval / 10 == 0)
                cout << "S0" << newseat->seatval << " :";
            else
                cout << "S" << newseat->seatval << " :";
            if (newseat->status == 0)
                cout << "|___| ";
            else if (newseat->status == 1)
                cout << "      "; // 7 spaces

            count++;
            if (count % 7 == 0)
            {
                cout << endl;
            }
        }
        newseat = newseat->next;
    }
    cout << "S" << newseat->seatval << " :";
    if (newseat->status == 0)
        cout << "|___| " << endl;
    else
        cout << "       " << endl;
}
int main()
{
    FloatList obj;
    obj.create_list();
    int ch;
    char c;
    cout << "\n*********************************************\n";
    cout << " \tCINEMAX MOVIE THEATRE\n";
    cout << "*********************************************\n";
    cout << "\n1.Current Seat Status" << endl;
    cout << "2.Book Seat" << endl;
    cout << "3.Cancel Seat" << endl;
    cout << "4.Available seats" << endl;
    cout << "5.Show Booked seats" << endl;
    cout << "6.Exit" << endl;
    while (true)
    {
        cout << "\nEnter Choice:";
        cin >> ch;
        if (ch == 6)
            return 0;

        switch (ch)
        {
        case 1:
            cout << "1.Current Seat Status:" << endl;
            obj.displayList();
            break;
        case 2:
            cout << "2.Book Seat:" << endl;
            obj.bookseat();
            break;
        case 3:
            cout << "3.Cancel Seat:" << endl;
            obj.cancel();
            break;
        case 4:
            cout << "4.Available seats:" << endl;
            obj.avail();
            break;
        default:
            cout << "Wrong choice input\n";
            break;
        }
    }
    return 0;
}