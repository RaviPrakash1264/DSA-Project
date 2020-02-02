#include<iostream>
#include<windows.h>
using namespace std;
class Passenger_info
{
protected:
char name[30] ;
int age ;
char mob[10];
char gender ;
char disable;
public:
void get_info()
{
cout<<"\n\tEnter name of the passenger = ";
cin>>name;
cout<<"\n\tEnter the mobile number = ";
cin>>mob;
cout<<"\n\tEnter the age of the passenger = ";
cin>>age;
cout<<"\n\tEnter the gender of the passenger = ";
cin>>gender;
cout<<"\n\tenter if the passenger is dis-abled = ";
cin>>disable;
}
friend class Flight_info;
};
class Flight_info
{
protected:
Passenger_info p[65];
int n;
int i ;
int priority = 0;
int final_priority;
char flight_num[30];
public:
void get_data()
{
cout<<"\n\tEnter the flight number = ";
cin>>flight_num;
cout<<"\n\tEnter the number of passengers = ";
cin>>n;
for(i = 0 ; i < n ; i++)
{
p[i].get_info();
}
}
void get_priority()
{
for(i = 0 ; i < n ; i++)
{
if(p[i].disable == 'Y')
{
priority = priority + 5;
}
if(p[i].age >= 45 && p[i].age < 50)
{
priority = priority + 1;
}
else if(p[i].age >= 50 && p[i].age < 55)
{
priority = priority + 2;
}
else if(p[i].age >= 55 && p[i].age < 60)
{
priority = priority + 3;
}
else if(p[i].age >= 60)
{
priority = priority + 4;
}
}
final_priority = priority;
}
int ret_priority()
{
return final_priority;
}
void display()
{
cout<<"\nFlight number = "<<flight_num;
}
};
class terminal_info:public Flight_info
{
protected:
int terminal_num;
char co_or[20];
int dist_from_security;
char type;
public:
void get_info()
{
cout<<"\n\t\t\tTERMINAL INFORMATION";
cout<<"\n\tEnter terminal number = ";
cin>>terminal_num;
cout<<"\n\tEnter co-ordinates of the terminal = ";
cin>>co_or;
cout<<"\n\tEnter the distance from the security check = ";
cin>>dist_from_security;
cout<<"\n\tIf the terminal is an airway bridge enter A , If the terminal is ground(Bus transit) enter G = ";
cin>>type;
}
int ret_terminal_distance()
{
return dist_from_security;
}
void display_gate()
{
cout<<"\tGate number/Terminal = ";
cout<<terminal_num;
}
};
int main()
{
system("color 3e");
int n , i , opt = 0 ,n1 , n2 , j , c = 0 , c1 = 0;
cout<<"\t\t\tTERMINAL ALLOTMENT SYSTEM";
cout<<"\nenter the number of flights taking off --> ";
cin>>n;
Flight_info f[n];
Flight_info temp;
int done[n];
cout<<"\nenter the number of terminal --> ";
cin>>n1;
int done1[n1];
terminal_info t[n1];
terminal_info temp1;
while(opt != 4)
{
cout<<"\n\t\t\t1.Enter the Flight's information";
cout<<"\n\t\t\t2.Enter terminal information";
cout<<"\n\t\t\t3.View Suggested treminals";
cout<<"\n\t\t\t4.Exit";
cout<<"\n\t\t\tEnter the option = ";
cin>>opt;
switch(opt)
{
case(1) :
for(i = 0 ; i < n ; i++)
{
done[i] = -1;
}
for(i = 0 ; i < n ; i++)
{
f[i].get_data();
f[i].get_priority();
}
break;
case(2) :
for(i = 0 ; i < n1 ; i++)
{
t[i].get_info();
}
break;
case(3) : for(i = 0; i <(n); i++)
{
for(j = 0; j < (n - 1); j++)
{
if(f[j].ret_priority() <
f[j + 1].ret_priority())
{
temp = f[j];
f[j] = f[j + 1];
f[j + 1] = temp;
}
}
}
for(i = 0 ; i < (n1 - 1) ; i++)
{
for(j = 0 ; j < (n1 - i - 1) ; j++)
{
if(t[j].ret_terminal_distance() > t[j+ 1].ret_terminal_distance())
{
temp1 = t[j];
t[j] = t[j + 1];
t[j + 1] =
temp1;
}
}
}
for(i = 0 ; i < n ; i++)
{
if(i < n1)
{
f[i].display();
t[i].display_gate();
 }
 else
 {
 f[i].display();
 cout<<"\tNo gates available";
}
cout<<"\n";
}
break;
 }
}
return 0;
}
