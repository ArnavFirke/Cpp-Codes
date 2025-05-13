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
    void bookseats();
    void bookacc();
    void avail();
    void cancel();
    void cancelseats();
    void showbook();
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


void FloatList::bookseats()
{
    int n, i = 0;
    string y;
    cout << "Enter the number of seats to be booked: ";
    cin >> n;
    int arrseats[n];
    for (int j = 0; j < n; j++)
    {
        cout << "Enter the seat number: ";
        cin >> arrseats[j];
    }
    cout << "Enter your ID number: ";
    cin >> y;
    ListNode *newSeat;
    newSeat = new ListNode;
    newSeat = head;
    
    while (i < n)
    {
        if (newSeat->seatval == arrseats[i])
        {
            if (newSeat->status == 1)
                cout << "Booking Failed,Seat is already booked" << endl;
            else
            {
                newSeat->status = 1;
                newSeat->id = y;
                cout << "Seat " << arrseats[i] << " is successfully booked!" << endl;
            }
            i++;
        }
        newSeat = newSeat->next;
    }
}

void FloatList::bookacc()
{
    string y;
    int row = 0, column = 0, curr, curc, numb;
    cout << "Enter the row: ";
    cin >> row;
    cout << "\nEnter the column from where you want seats: ";
    cin >> column;
    cout << "\nEnter the number of seats you want: ";
    cin >> numb;
    cout << "\nEnter the ID: ";
    cin >> y;
    ListNode *newSeat = head;
    for (int i = 0; i < 7 * (row - 1); i++)
    {
        newSeat = newSeat->next;
    }
    for (int i = 0; i < column - 1; i++)
    {
        newSeat = newSeat->next;
    }

    for (int i = 0; i < numb; i++)
    {
        if (newSeat->status == 0)
        {
            newSeat->status = 1;
            newSeat->id = y;
            cout << "Seat " << newSeat->seatval << " is successfully booked!" << endl;
        }
        else
        {
            cout << "Booking Failed,Seat is already booked" << endl;
        }
        newSeat=newSeat->next;
    }
}

void FloatList::cancelseats()
{
    int n, i = 0;
    string y;
    cout << "Enter the number of seats to be cancled: ";
    cin >> n;
    int arrseats[n];
    for (int j = 0; j < n; j++)
    {
        cout << "Enter the seat number: ";
        cin >> arrseats[j];
    }
    cout << "Enter your ID : ";
    cin >> y;
    ListNode *newSeat = head;
    while (i < n)
    {
        if (newSeat->seatval == arrseats[i])
        {
            if (newSeat->status == 1)
            {
                if (newSeat->id == y)
                {
                    newSeat->status = 0;
                    cout << "Seat " << newSeat->seatval << " is Cancelled!" << endl;
                }
                else
                    cout << "Wrong User ID !!! Seat cannot be cancelled!!!" << endl;
            }
            else
            {
                cout << "Seat not booked yet!!" << endl;
            }
            i++;
        }
        newSeat = newSeat->next;
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

void FloatList::showbook()
{
    ListNode *newseat = head;
    cout << "\nBooked Seats are:" << endl;
    while (newseat->next != head)
    {
        if (newseat->seatval / 10 == 0 and newseat->status == 1)
            cout << "S0" << newseat->seatval << "  ";
        else if (newseat->status == 1)
            cout << "S" << newseat->seatval << "  ";

        newseat = newseat->next;
    }
    if (newseat->status == 1)
        cout << "S" << newseat->seatval << "  " << endl;
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
            cout << "Do you want consecative seats(y/n):";
            cin >> c;
            if (c == 'y')
                obj.bookacc();
            else if (c == 'n')
                obj.bookseats();
            break;
        case 3:
            cout << "3.Cancel Seat:" << endl;
            obj.cancelseats();
            break;
        case 4:
            cout << "4.Available seats:" << endl;
            obj.avail();
            break;
        case 5:
            cout << "5.Booked seats are:" << endl;
            obj.showbook();
            break;
        default:
            cout << "Wrong choice input\n";
            break;
        }
    }
    return 0;
}