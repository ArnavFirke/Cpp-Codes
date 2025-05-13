#include<iostream>
#include<cstring>
using namespace std;

class Student{
private:
    string RollNo,div;
    string telph;
    string DLno;
    string name,Class,BloodGroup,contactadd,birthday;
    int static mem;


public:
    Student()
 {
      RollNo="0";
      div="3";
     Class="Se";
     telph="988543545";
        DLno="A101";
        name="Arnav";
        BloodGroup="o+ve";
        contactadd="patang plaza";
         birthday="5/5/2001";

          mem++;
 }
    void getdata(){
        cout<<"Enter Roll no: ";
        cin>>RollNo;
        getchar();
        cout<<"Enter your name: ";
        getline(cin,name);
        cout<<"Enter your class: ";
        getline(cin,Class);
        cout<<"Enter division: ";
        getline(cin,div);
        cout<<"Enter Blood group: ";
        getline(cin,BloodGroup);
        cout<<"Enter birthday: ";
        getline(cin,birthday);
        cout<<"Enter contact address: ";
        getline(cin,contactadd);
        cout<<"Enter Driving license no: ";
        getline(cin,DLno);
        cout<<"Enter Telephone number: ";
        getline(cin,telph);
    }
    ~Student()
    {
        cout<<this->name<<" (Object) is destroyed!"<<endl;
        mem--;
    }
    Student(Student &s){
        RollNo=s.RollNo;
        name=s.name;
        telph=s.telph;
        DLno=s.DLno;
        BloodGroup=s.BloodGroup;
        Class=s.Class;
        div=s.div;
        birthday=s.birthday;
        contactadd=s.contactadd;
        mem+=1;
    }


    void display()
        {
        cout<<"\nRoll no. is: "<<this->RollNo<<endl;
        cout<<"Name is: "<<this->name<<endl;
        cout<<"Class is: "<<this->Class<<endl;
        cout<<"Division is: "<<this->div<<endl;
        cout<<"Birthday is: "<<this->birthday<<endl;
        cout<<"Blood group is: "<<this->BloodGroup<<endl;
        cout<<"Contact address is: "<<this->contactadd<<endl;
        cout<<"Driving license no. is: "<<this->DLno<<endl;
        cout<<"Telephone number is: "<<this->telph<<endl;
        }
    static void members(){
        cout<< "Total members are: "<< mem <<endl;
    }

};

int Student::mem;

int main()

{
   
    Student s;
    s.display();
    s.getdata();
    s.display();
    int n;
    cout<<"\nHow many objects u want to create:";
    cin>>n;
    Student *ptr[n];
    for(int i=0;i<n;i++)
    {
       ptr[i]=new Student(); //new operator use to dynamic memory(run time) allocation
       ptr[i]->getdata();
    }

    for(int i=0;i<n;i++)
    {
       ptr[i]->display();
    }
    Student::members();
     for(int i=0;i<n;i++)
    {
        delete(ptr[i]); //delete operator use to deallocation of memory
    }

    return 0;

}
