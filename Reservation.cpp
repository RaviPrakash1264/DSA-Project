#include<iostream>
#include<iomanip>
#include<conio.h>
#include<string>
#include<windows.h>
#include <cstdlib>
using namespace std;
char dom_desti[10][20]={"DELHI","HYDERABAD","LAHORE","BENGALURU","CHENNAI","GOA","MUMBAI","INDORE","CALICUT","PUNE"};
char inter_desti[10][20]={"LONDON","BERLIN","DUBAI","NEWYORK","BEIJING","PARIS","CAPE TOWN","TOKYO","LOS ANGELES","MUMBAI"};
class ttime
{
protected:
int choose;
public:
void getinfo()
{
 cout<<"AT WHICH TIME DO YOU WANT TO TRAVEL?"<<endl;
 cout<<"PRESS 1 FOR 11 AM"<<endl;
 cout<<"PRESS 2 FOR 2 PM"<<endl;
 cout<<"PRESS 3 FOR 9 PM"<<endl;
 cin>>choose;
}
void show()
{
 if(choose==1)
 {
 cout<<" flight time: 11 AM"<<endl;

cout<<"|_________________________________________________________________________"<<endl;
 cout<<" GOOD BYE AND HAVE A SAFE JOURNEY"<<endl;
}
 if(choose==2)
 {
 cout<<" flight time: 2 PM"<<endl;

cout<<"|_________________________________________________________________________"<<endl;
 cout<<" GOOD BYE AND HAVE A SAFE JOURNEY"<<endl;
 }
 if(choose==3)
 {
 cout<<" flight time: 9 PM"<<endl;

cout<<"|_________________________________________________________________________"<<endl;
 cout<<" GOOD BYE AND HAVE A SAFE JOURNEY"<<endl;
 }
}
};
class passenger
{
public:
 virtual void getinfo()
{
}
virtual void show()
{
}
};
class booking:public passenger
{
protected:
char pass_num[60];
char ch;
char first_name[60];
char last_name[60];
char crnt_loc[30];
char dest[30];
char reserv_no[60];
int option;
public:
void getinfo()
{
 cout<<setw(40)<<"\n\n ::Please enter the required information for passenger number::"<<endl;
 cout<<"\n\n\nEnter the firstname of passenger: ";
 cin.getline(first_name,60);
 cout<<endl;
 cout<<"Enter the lastname of passenger: ";
 cin.getline(last_name,60);
 cout<<endl<<endl;
 cout<<"Enter passport unique code of passenger: ";
 cin.getline(pass_num,60);
 cout<<endl<<endl;
 cout<<"Enter the Resevation No. of Ticket"<<endl;
 cin.getline(reserv_no,60);
 cout<<endl<<endl;
 cout<<"Enter the current location of passenger(IN CAPITAL LETTERS ONLY):";
 cin.getline(crnt_loc,60);
 cout<<endl<<endl;
 cout<<"Enter the destination of passenger(IN CAPITAL LETTERS ONLY): ";
 cin.getline(dest,60);
 cout<<endl<<endl;
 system("CLS");
}
void show()
{
int t=rand();
int r=rand();
 cout<<" AIRLINE TICKET "<<endl;
 cout<<"|Ticket No."<<t<<" Reference No."<<r<<"\t "<<endl;
 cout<<"|Resevation No. :"<<reserv_no<<" "<<endl;
 cout<<"|\n";
 cout<<"|Passenger Information : "<<endl;
 cout<<"|Name :"<<last_name<<"/"<<first_name<<" "<<endl;
 cout<<"|Passport no:"<<pass_num<<" "<<endl;
 cout<<"|\n";
 cout<<"|flight Information : "<<endl;
 cout<<"|12 aug 2011 "<<endl;
 cout<<"|BOING 747 "<<endl;
 cout<<"|Depart :"<<crnt_loc<<" "<<endl;
 cout<<"|Arrive :"<<dest<<" "<<endl;
 cout<<"|\n|\n";
 cout<<"|*BAGGAGE allowed 32 Kilos "<<endl;
 cout<<"|*contact Airline to Confirm baggage allowance"<<endl;
}
};
class search
{
public:
void searching()
{
 cout<<"FOLLOWING ARE THE INTERNATIONAL FLIGHTS AVAILABLE"<<endl;
 for(int i=0;i<10;i++)
{
for(int j=0;j<10;j++)
{
 cout<<"FLIGHT FROM "<<dom_desti[i]<<" TO"<<inter_desti[j]<<endl;
 }
 }
}
};
class local: public booking
{
protected:
int bus_seat;
int eco_seat;
int ch;
int k;
int p;
int option;
ttime t1;
public:
void getinfo()
{
 k=0;
 p=0;
 cout<<"In which AIRLINE you want to travel"<<endl<<endl;
 cout<<"1)AIR JET"<<endl;
 cout<<"2)AIR INDIA"<<endl;
 cout<<"3)AIR INDIGO"<<endl;
 cout<<"4)SPICEJET"<<endl;
 cout<<"enter your choice"<<endl;;
 cin>>option;
 system ("cls");
 switch(option)
 {
 case 1:
 cout<<setw(40)<<"\n\n\n WELCOME TO AIR JET"<<endl;break;
 case 2:
 cout<<setw(40)<<"\n\n\n WELCOME TO AIR INDIA"<<endl;break;
 case 3:
 cout<<setw(40)<<"\n\n\n WELCOME TO AIR INDIGO"<<endl;break;
 case 4:
 if(option==4)
 cout<<setw(40)<<"\n\n\n WELCOME TO SPICEJET"<<endl;break;
 }
 cout<<setw(40)<<"\nTHESE ARE THE LOCAL PLACES AVAILABLE\n\n\n"<<endl;
 cin.ignore();
 for(int i=0;i<10;i++)
 {
 cout<<dom_desti[i]<<endl;
 }
 booking::getinfo();
 for(int j=0;j<10;j++)
 {
 if(strcmp(dom_desti[j],crnt_loc)==0)
 {
 k++;
 }
 }
 for( int i=0;i<10;i++)
 {
 if(strcmp(dom_desti[i],crnt_loc)==0)
 {
 p++;
 }
 }
 if(k==1&&p==1)
 {
 cout<<" FLIGHT AVAILABLE ON THIS ROUTE"<<endl;
 bus_seat=30;
 eco_seat=40;
 cout<<"In which class you want to travel?"<<endl;
 cout<<"Make your choice"<<endl<<endl;
 cout<<"\n\n\n\n\n\n";
 cout<<setw(60)<<"* Press 1 for buisness class *"<<endl;
 cout<<setw(60)<<"* Press 2 for economy class *"<<endl;
 cout<<endl<<endl<<endl<<endl;
 cout<<"Enter your choice"<<endl;
 cin>>ch;
 cout<<endl;
 switch(ch)
 {
 case 1:
 bus_seat--;
 if(bus_seat<=0)
 cout<<"SORRY NO SEAT AVAILABLE"<<endl;
 else
 cout<<"SEAT AVAILABLE"<<endl;
 break;
 case 2:
 eco_seat--;
 if(eco_seat<=0)
 cout<<"SORRY NO SEAT AVAILABLE"<<endl;
 else
 cout<<"SEAT AVAILABLE"<<endl;
 break;
 }
 t1.getinfo();
 system("CLS");
 booking::show();
 if(ch==1)
 {
 cout<<"|Ticket Information:"<<endl<<
 "|BUISNESS CLASS"<<endl;
 }
 if(ch==2)
 {
 cout<<"|Ticket Information:"<<endl<<
 "|ECONOMY CLASS"<<endl;
 }
 cout<<"|Status: Confirmed"<<endl;
 t1.show();
 }
 else

 {

cout<<"^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^"<<endl;
 cout<<" SORRY NO FLIGHT AVAILABLE ON THIS ROUTE RIGHT NOW"<<endl;

cout<<"__________________________________________________________________________"<<endl;

 }
}
};
class international:public booking
{
protected:
 int bus1_seat;
 int eco1_seat;
 int choice;
 int c;
 int b;
 int v;
 char g;
 ttime t1;
public:
 void getinfo()
 {
 b=0;
 v=0;
 cout<<"In which AIRLINE you want to travel"<<endl<<endl;
 cout<<"1)BRITISH AIRWAYS"<<endl;
 cout<<"2)AMERICAN AIRWAYS"<<endl;
 cout<<"3)ARAB EMIRATES"<<endl;
 cout<<"4)QATAR AIRWAYS"<<endl;
 cout<<"enter your choice"<<endl;;
 cin>>option;
 system ("cls");
 switch(option)
 {
 case 1:
 if (option==1)
 cout<<setw(40)<<"\n\n\n WELCOME TO BRITISH AIRWAYS"<<endl;
 break;
 case 2:
 if(option==2)
 cout<<setw(40)<<"\n\n\n WELCOME TO AMERICAN AIRWAYS"<<endl;
 break;
 case 3:
 if(option==3)
 cout<<setw(40)<<"\n\n\n WELCOME TO ARAB EMIRATES"<<endl;
 break;
 case 4:
 if(option==4)
 cout<<setw(40)<<"\n\n\n WELCOME TO QATAR AIRWAYS"<<endl;
 break;
 }
 cout<<"\n\nTHESE ARE THE INTERNATIONAL PLACES AVAILABLE"<<endl<<endl;
 cin.ignore();
 for(int i=0;i<10;i++)
 {
 cout<<inter_desti[i]<<endl;
 }
 booking::getinfo();
 for(int j=0;j<10;j++)
 {
 if(strcmp(inter_desti[j],dest)==0)
 {
 v++;
 }
 }
 for( int i=0;i<10;i++)
 {
 if(strcmp(dom_desti[i],crnt_loc)==0)
 {
 b++;
 }
 }
 if(b==1&&v==1)
 {
 cout<<" FLIGHT AVAILABLE ON THIS ROUTE"<<endl;
 bus1_seat=30;
 eco1_seat=40;
 cout<<"In which class you want to travel?"<<endl;
 cout<<"Make your choice"<<endl<<endl;
 cout<<"\n\n\n\n\n\n";
 cout<<setw(60)<<"* Press 1 for buisness class *"<<endl;
 cout<<setw(60)<<"* Press 2 for economy class *"<<endl;
 cout<<endl;
 cout<<"Enter your choice"<<endl;
 cin>>choice;
 cout<<endl;
 switch(choice)
 {
 case 1:
 bus1_seat--;
 if(bus1_seat<=0)
 cout<<"SORRY NO SEAT AVAILABLE"<<endl;
 else
 cout<<"SEAT AVAILABLE"<<endl;
 break;
 case 2:
 eco1_seat--;
 if(eco1_seat<=0)
 cout<<"SORRY NO SEAT AVAILABLE"<<endl;
 else
 cout<<"SEAT AVAILABLE"<<endl;
 break;
 }
 t1.getinfo();
 system("CLS");
 booking::show();
 if(choice==1)
 {
 cout<<"|Ticket Information: "<<endl;
 cout<<"|BUISNESS CLASS "<<endl;
 cout<<"|Ticket Information: "<<endl<<
 "|BUSINESS CLASS "<<endl;
 }
 if(choice==2)
 {
 cout<<"|Ticket Information: "<<endl;
 cout<<"|ECONOMY CLASS "<<endl;
 cout<<"|Ticket Information: "<<endl<<
 "|ECONOMY CLASS "<<endl;
 }
 cout<<"|Status: confirmed "<<endl;
 cout<<"|Status: confirmed "<<endl;
 t1.show();
 }
 else
 {

cout<<"^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^"<<endl;
 cout<<"| SORRY NO FLIGHT AVAILABLE ON THIS ROUTE RIGHT NOW"<<endl;

cout<<"__________________________________________________________________________"<<endl;
 }
}
};
class main1
{
private:
 char f;
 int menu_choice;
 char a;
public:
void getinfo()
{
m:
 cout<<"\n\n\n\n\n\n";
 cout<<setw(60)<<"* AIRWAYS RESERVATION *"<<endl;
 cout<<setw(60)<<"* MAIN MENU *"<<endl;
 cout<<setw(60)<<"* ENTER YOUR CHOICE *"<<endl;
 cout<<setw(60)<<"* PRESS 1 FOR LOCAL BOOKING *"<<endl;
 cout<<setw(60)<<"* PRESS 2 FOR INTERNATIONAL BOOKING *"<<endl;
 cout<<setw(60)<<"* PRESS 3 FOR SEARCH OF FLIGHTS *"<<endl;
 cout<<setw(60)<<"* NOW ENTER YOUR CHOICE: *"<<endl;
 cin>>menu_choice;
 system("cls");
 passenger* p1;
 booking b1;
 international i1;
 local l1;
 char back;
 switch(menu_choice)
 {
 case 1:
 p1=&l1;
 p1->getinfo();
 cout<<"To Go To Main Menu Press b"<<endl;
 cin>>back;
 system("CLS");
 if (back=='b')
 {
 goto m;
 }
 else
 {
 cout<<"\n\n\n\n\n\n";
 cout<<setw(40)<<"BYE FROM AIR RESERVATION SYSTEM";
 }
 break;
 case 2:
 p1=&i1;
 p1->getinfo();
 cout<<"To Go To Main Menu Press b"<<endl;
 cin>>back;
 system("CLS");
 if (back=='b')
 {
 goto m;
 }
 else
 {
 cout<<"\n\n\n\n\n\n";
 cout<<setw(40)<<"BYE FROM AIR RESERVATION SYSTEM";
 }
 break;
 case 3:
 search s1;
 s1.searching();
 cout<<"To Go To Main Menu Press b"<<endl;
 cin>>back;
 system("CLS");
 if (back=='b')
 {
 goto m;
 }
 else
 {
 cout<<"\n\n\n\n\n\n";
 cout<<setw(40)<<"BYE FROM AIR RESERVATION SYSTEM";
 }
 break;
}
}
};
int main()
{
system("color 2A");
cout<<"\n\n\n\n\n\n\n\n\n\n\t\t WELCOME TO AIRWAYS RESERVATION SYSTEM";
Sleep(1500);
system ("cls");
cout<<"\n\n\n\n\n\n\n\t\t Developed by :";
Sleep(500);
 cout<<"RAVI PRAKASH";
 Sleep(500);
 cout<<"\n\n\n\t\t For DSA PROJECT";
Sleep(2000);
system("cls");
main1 m1;
m1.getinfo();
}
