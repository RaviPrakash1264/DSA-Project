#include <iostream>
#include<string.h>
#include<windows.h>
using namespace std;
int runway1[5];
int runway2[5];
int f1 = -1, r1 = -1, n1 = 5;
int f2 = -1,r2 = -1 , n2 = 5;
class plane_info
{
char plane_num[5];
int direction;
int ETD;
int runway_num;
int priority;
int token_num;
int take_of_time[2];
int fintime;
char status;
public:
void get_plane_info()
{
cout<<"\nEnter the plane number = ";
cin>>plane_num;
cout<<"\nEnter the direction intended for take of\n1.NE\n2.NW\n3.SE\n4.SW\nDirection option = ";
cin>>direction;
cout<<"\nEnter time , 24HR format ";
cout<<"\nh = ";
cin>>take_of_time[0];
cout<<"\nm = ";
cin>>take_of_time[1];
cout<<"\nEntered status delayed(D) or on time (O) = ";
cin>>status;
if(status == 'D')
{
cout<<"\nEnter new take of time\nh = ";
cin>>take_of_time[0];
cout<<"\nm = ";
cin>>take_of_time[1];
}
fintime = 100*take_of_time[0] + take_of_time[1];
}
void get_token(int t)
{
token_num = t;
cout<<"\nplane number "<<plane_num<<" has token number = "<<t;
}
int return_status()
{
if(status == 'D')
{
return 1;
}
else
{
return 0;
}
}
int return_fintime()
{
return fintime;
}
int genrate_runway_num()
{
if(direction == 1 || direction == 4)
{
runway_num = 1;
}
else if(direction == 3 || direction == 2)
{
runway_num = 2;
}
return runway_num;
}
};
int is_full(int &front , int &rear ,int &n){
 if ((front == 0 && rear == n-1) || (front == rear+1)) {
 return 1;
 }
 else
 {
 return 0;
 }
}
void insertCQ(int val , int (&cqueue)[5] , int &front , int &rear , int &n ) {
 if ((front == 0 && rear == n-1) || (front == rear+1)) {
 cout<<"\nQueue Overflow \n";
 return;
 }
 if (front == -1) {
 front = 0;
 rear = 0;
 } else {
 if (rear == n - 1)
 rear = 0;
 else
 rear = rear + 1;
 }
 cqueue[rear] = val ;
}
void deleteCQ(int (&cqueue)[5], int &front , int &rear , int &n ) {
 if (front == -1) {
 cout<<"\nQueue Underflow\n";
 return ;
 }
 cout<<"\nFlight Departed token number : "<<cqueue[front]<<endl;

 if (front == rear) {
 front = -1;
 rear = -1;
 } else {
 if (front == n - 1)
 front = 0;
 else
 front = front + 1;
 }
}
void displayCQ(int (&cqueue)[5] , int &front , int &rear , int &n) {
 int f = front, r = rear;
 if (front == -1) {
 cout<<"\nRunway is empty"<<endl;
 return;
 }
 cout<<"\nRunway token numbers lined up are :\n";
 if (f <= r) {
 while (f <= r){
 cout<<cqueue[f]<<" ";
 f++;
 }
 } else {
 while (f <= n - 1) {
 cout<<cqueue[f]<<" ";
 f++;
 }
 f = 0;
 while (f <= r) {
 cout<<cqueue[f]<<" ";
 f++;
 }
 }
 cout<<endl;
}
int main() {
 system("color 2A");
 int ch, val , n , i , tknum = 1 , j , ptr , tmp = 0 , c1tmp = 0 , c2tmp = 0 , k ,
c1ttmp =0 , c2ttmp = 0;
 char tmpchar[5];
 cout<<"\t\t\tWELCOME TO RUNWAY ALLOTMENT";
 cout<<"\nEnter number of planes scheduled to depart = ";
 cin>>n;
 plane_info flights[n];
 plane_info flightsrunway1[n];
 plane_info flightsrunway2[n];
 plane_info temp;
 for(i = 0 ; i < n ; i++)
 {
 flights[i].get_plane_info();
 }
 for (i = 0; i < n-1; i++)
 {
 for (j = 0; j < n-i-1; j++)
 {
 if ((flights[j].return_fintime() >
flights[j+1].return_fintime())| ((flights[j + 1].return_status() == 1)&
(flights[j].return_status() == 0)))
 {
 temp = flights[j];
 flights[j] = flights[j + 1];
 flights[j + 1] = temp;
}
}
}
j = 0;
k = 0;
for(i = 0 ; i < n ; i++)
{
if(flights[i].genrate_runway_num() == 1)
{
flightsrunway1[j] = flights[i];
j++;
}
else if(flights[i].genrate_runway_num() == 2)
{
flightsrunway2[k] = flights[i];
k++;
}
}
int opt = 0 , m = 0;
i = 0;
cout<<"\n\t\t\tFINAL MANUAL RUNWAY ALLOTMENT";
while(opt != 7 )
{
cout<<"\n1.Insert in runway 1 final queue\n2.Insert in runway 2 final queue\n3.Depart form runway1\n4.Depart from runway 2\n5.Display runway1 status\n6.Display runway2 status";
cout<<"\n7.EXIT";
cout<<"\nEnter option = ";
cin>>opt;
switch(opt)
{
case(1): if(is_full(f1,r1,n1) == 0 & i < j)
{
flightsrunway1[i].get_token(tknum);
insertCQ(tknum,runway1,f1,r1,n1);
tknum++;
i++;
}
else
{
cout<<"\nExsisting planes need to depart first";
}
break;
case(2): if(is_full(f2,r2,n2) == 0 & m < k)
{
flightsrunway2[m].get_token(tknum);
insertCQ(tknum,runway2,f2,r2,n2);
tknum++;
m++;
}
else
{
cout<<"\nExsisting planes need to depart first";
}
break;
case(3): deleteCQ(runway1,f1,r1,n1);
break;
case(4): deleteCQ(runway2,f2,r2,n2);
break;
case(5): displayCQ(runway1,f1,r1,n1);
break;
case(6): displayCQ(runway2,f2,r2,n2);
break;
}
}
 return 0;
}
