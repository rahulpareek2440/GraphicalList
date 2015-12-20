#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<graphics.h>
#include<process.h>
#include<string.h>
#include<dos.h>
int num,i,choice,count,pos;
char val[3],choice1,ch;
int l,t,r,b,rp,a1,a2,a3;
class linklist
{
private:
struct node
{
 char data[3];
 node *link;
}*p,*temp,*s,*q,*last;
struct node1
{
 struct node1 *prev;
 char info[3];
 struct node1 *next;
}*start1,*temp1,*q1;
public:
linklist();
void ll();
void s_list();
void screate();
void sdel();
void sdisplay();
void sinsert();
void c_list();
void ccreate();
void cinn();
void cdel();
void cdisplay();
void d_list();
void dcreate();
void din();
void ddel();
void ddisplay();
void graph();
void cnt();
void rec();
};
linklist::linklist()
{
p=NULL;
}
///////////////////////////counting of nodes//////////////////////////////
void linklist::cnt()
{
 count=0;
}
///////////////////////////rectangle///////////////////////////////////////
void linklist::rec()
{
 l=50;
 t=140;
 r=110;
 b=180;
 rp;
 a1=-40;
 a2=-30;
 a3=30;
}
void linklist::ll()
{
 cout<<"\n\n\t\t\tPress s for simple linked list"<<endl;
 cout<<"\n\n\t\t\tPress c for circular linked list"<<endl;
 cout<<"\n\n\t\t\tPress d for doubly linked list"<<endl;
 cout<<"\n\n\t\t\tPress e to exit"<<endl;
 cout<<"\n\n\t\t\tEnter your choice: ";
 cin>>choice1;
 switch(choice1)
 {
  case 's':
   clrscr();
   linklist::s_list();
   break;
  case 'c':
   clrscr();
   linklist::c_list();
   break;
  case 'd':
   clrscr();
   linklist::d_list();
  case 'e':
   exit(0);
 }
}
void linklist::s_list()
{

 clrscr();
 cout<<"\n\n\t\tPress 1 to create simple link list"<<endl;
 cout<<"\n\n\t\tPress 2 to display simple list"<<endl;
 cout<<"\n\n\t\tPress 3 to insert a node into simple list"<<endl;
 cout<<"\n\n\t\tPress 4 to delete a node from simple list"<<endl;
 cout<<"\n\n\t\tPres 0 to go back to main menu"<<endl;
 cout<<"\n\n\t\tEnter your choice: ";
 cin>>choice;
 switch(choice)
 {
  case 1:
   clrscr();
   linklist::screate();
   break;
  case 2:
   clrscr();
   linklist::sdisplay();
   break;
  case 3:
   clrscr();
   linklist::sinsert();
   break;
  case 4:
   clrscr();
   linklist::sdel();
  case 0:
   clrscr();
   linklist::ll();
   break;
 }
}
////////////////////SIMPLE LINK LIST CREATION//////////////////////////////
/////creation/////////
void linklist::screate()
{
 linklist::cnt();
 linklist::rec();
 rectangle(l,t,r,b);
 outtextxy((l+r)/2-20,(t+b)/2+30,"Start");
 cout<<"Enter the no. of nodes u want to create: ";
 cin>>num;
 for(i=0;i<num;i++)
 {
 cout<<"Enter the value: ";

  if(p==NULL)
  {
  temp=new node;
  gets(temp->data);
  temp->link=NULL;
	  p=temp;
  count++;
  rp=r;
  rectangle(l=l+100,t,r=r+100,b);
  outtextxy((l+r)/2-20,(t+b)/2+30,"d   l");
  outtextxy((rp+l)/2-20,(t+b)/2,"---->");
  moveto((l+r)/2,t);
  linerel(0,40);
  outtextxy((l+r)/2-20,(t+b)/2,temp->data);

  }
  else
  {
   temp=p;
   while(temp->link!=NULL)
   {
    temp=temp->link;
   }
   s=new node;
   gets(s->data);
   s->link=NULL;
   temp->link=s;

   count++;
  rp=r;
  rectangle(l=l+100,t,r=r+100,b);
  outtextxy((l+r)/2-20,(t+b)/2+30,"d   l");
  outtextxy((rp+l)/2-20,(t+b)/2,"---->");
  moveto((l+r)/2,t);
  linerel(0,40);
  outtextxy((l+r)/2-20,(t+b)/2,s->data);

  }

  if(count==num)
  {
   break;
  }

  else
  {
   continue;
  }
 }
 getch();
 linklist::s_list();
}
//////////////////insertion at any place//////
void linklist::sinsert()
{
rec();
temp=new node;
cout<<"\nEnter the value of new node: ";
gets(val);
rectangle(l=l+200,t=t+50,r=r+200,b=b+50);
outtextxy((l+r)/2-20,(t+b)/2+30,"d  l");
outtextxy((l+r)/2-20,(t+b)/2-30,"temp");
outtextxy((l+r)/2-20,(t+b)/2,val);
moveto((l+r)/2,t);
linerel(0,40);
getch();
clrscr();
cout<<"Press \n(a) for add a begin\n(b) for adding at any point\n(c) add at End: ";
ch=getch();
if(ch=='a'||ch=='A')
{
 temp=p;
 s=new node;
 strcpy(s->data,val);
 s->link=p;
 p=s;
 linklist::sdisplay();
}
if(ch=='b'||ch=='B')
{
 cout<<"\nEnter the position after which u want to add: ";
 cin>>pos;
 linklist::cnt();
 temp=p;
 while(temp->link!=NULL)
 {
 count++;
 if(count==pos)
 {
  s=new node;
  strcpy(s->data,val);
  s->link=temp->link;
  temp->link=s;
 linklist::sdisplay();
 }
 else
 {
  temp=temp->link;
 }
 }
}
if(ch=='c'||ch=='C')
{
 temp=p;
 while(temp->link!=NULL)
  {
   temp=temp->link;
  }
  s=new node;
  strcpy(s->data,val);
  s->link=NULL;
  temp->link=s;
  linklist::sdisplay();
}
 getch();
 linklist::s_list();
}
///////////////////linklist display////////////
void linklist::sdisplay()
{
 temp=p;
 linklist::rec();
 rectangle(l,t,r,b);
 outtextxy((l+r)/2-20,(t+b)/2+30,"Start");
 if(p==NULL)
 {
  cout<<"\n\n\n\t\t\tList is Empty.........";
  getch();
  linklist::s_list();
 }
 while(temp!=NULL)
 {
  delay(1000);
  sound(5000);
  rp=r;
  rectangle(l=l+100,t,r=r+100,b);
  outtextxy((l+r)/2-20,(t+b)/2+30,"d   l");
  outtextxy((rp+l)/2-20,(t+b)/2,"---->");
  moveto((l+r)/2,t);
  linerel(0,40);
  outtextxy((l+r)/2-20,(t+b)/2,temp->data);

  temp=temp->link;

 }
 nosound();
 getch();
 linklist::s_list();
}
////////////////////////simple linklist deletion////////////
void linklist::sdel()
{
 int c=0;
 cout<<"\n\tEnter the value you want to delete: ";
 gets(val);
 temp=p;
 while(temp!=NULL)
 {
  if(strcmp(temp->data,val)==0)
  {
   s=p;
   p=s->link;
   s->link=NULL;
   delete s;
   cout<<"\t\t\nElement Found---->Now Deleting.....";
   getch();
   linklist::sdisplay();
  }
  if(strcmp(temp->link->data,val)==0)
  {
   s=temp->link;
   temp->link=s->link;
   delete s;
   cout<<"\t\t\nElement Found---->Now Deleting.....";
   getch();
   linklist::sdisplay();
  }
  if(strcmp(temp->link->data,val)==0)
  {
   s=temp->link;
   delete temp;
   temp->link=NULL;
   cout<<"\t\t\nElement Found---->Now Deleting.....";
   getch();
   linklist::sdisplay();
  }
  temp=temp->link;
 }
 if(c==0)
 {
  cout<<"\t\t\nElement Not Found.....";
  linklist::sdisplay();
 }
 getch();
 linklist::s_list();
}
//////Simple linkedlist ended///////////
///////////Circular linked list///////////////////////
void linklist::c_list()
{
 clrscr();
 cout<<"\n\n\t\tPress 1 to create circular link list"<<endl;
 cout<<"\n\n\t\tPress 2 to display circular list"<<endl;
 cout<<"\n\n\t\tPress 3 to insert a node into circular list"<<endl;
 cout<<"\n\n\t\tPress 4 to delete a node from circular list"<<endl;
 cout<<"\n\n\t\tPres 0 to go back to main menu"<<endl;
 cout<<"\n\n\t\tEnter your choice: ";
 cin>>choice;
 switch(choice)
 {
  case 1:
   clrscr();
   linklist::ccreate();
   break;
  case 2:
   clrscr();
   linklist::cdisplay();
   break;
  case 3:
   clrscr();
   linklist::cinn();
   break;
  case 4:
   clrscr();
   linklist::cdel();
   break;
  case 0:
   clrscr();
   linklist::ll();
   break;
 }
}
void linklist::ccreate()
{
 last=NULL;
 linklist::rec();
 linklist::cnt();
 rectangle(l,t,r,b);
 outtextxy((l+r)/2-20,(t+b)/2+30,"Last");
 cout<<"Enter the no. of nodes u want to create: ";
 cin>>num;
 for(i=0;i<num;i++)
 {
  temp=new node;
  cout<<"Enter the value: ";
  gets(temp->data);
  if(last==NULL)
  {
   last=temp;
   temp->link=last;
  }
  else
  {
  temp->link=last->link;
  last->link=temp;
  last=temp;
  }
  count++;
  rp=r;
  rectangle(l=l+100,t,r=r+100,b);
  outtextxy((l+r)/2-20,(t+b)/2+30,"d   l");
  outtextxy((rp+l)/2-20,(t+b)/2,"---->");
  moveto((l+r)/2,t);
  linerel(0,40);
  outtextxy((l+r)/2-20,(t+b)/2,temp->data);
  if(count==num)
  {
   moveto((l+r)/2+15,t);
   linerel(0,a1);
   linerel(a2,0);
   linerel(0,a3);
   outtext("v");
   break;
  }
  else
  {
   a2=a2-100;
   continue;
  }
 }
 getch();
 linklist::c_list();
}

void linklist::cdisplay()
{
 linklist::rec();
 rectangle(l,t,r,b);
 outtextxy((l+r)/2-20,(t+b)/2+30,"Last");
 if(last==NULL)
 {
  cout<<"\n\n\n\t\t\tList is empty........";
  getch();
  linklist::c_list();
 }
 q=last->link;
 while(q!=last)
 {
  delay(1000);
  sound(5000);
  rp=r;
  rectangle(l=l+100,t,r=r+100,b);
  outtextxy((l+r)/2-20,(t+b)/2+30,"d   l");
  outtextxy((rp+l)/2-20,(t+b)/2,"---->");
  moveto((l+r)/2,t);
  linerel(0,40);
  outtextxy((l+r)/2-20,(t+b)/2,q->data);
  a2=a2-100;
  q=q->link;
 }
 rp=r;
 rectangle(l=l+100,t,r=r+100,b);
 outtextxy((l+r)/2-20,(t+b)/2+30,"d   l");
 outtextxy((rp+l)/2-20,(t+b)/2,"---->");
 moveto((l+r)/2,t);
 linerel(0,40);
 outtextxy((l+r)/2-20,(t+b)/2,last->data);
 moveto((l+r)/2+15,t);
 linerel(0,a1);
 linerel(a2,0);
 linerel(0,a3);
 outtext("v");
 nosound();
 getch();
 linklist::c_list();
}
void linklist::cinn()
{
 linklist::rec();
 temp=new node;
 cout<<"Enter the value of new node: ";
 gets(val);
 rectangle(l=l+200,t=t+50,r=r+200,b=b+50);
 outtextxy((l+r)/2-20,(t+b)/2+30,"d   l");
 outtextxy((l+r)/2-20,(t+b)/2-30,"temp");
 outtextxy((l+r)/2-20,(t+b)/2,val);
 moveto((l+r)/2,t);
 linerel(0,40);
 //count++;
 getch();
 clrscr();
 cout<<"Press a for beg , b for any point & c for end: ";
 ch=getch();
 if(ch=='a')
 {
  strcpy(temp->data,val);
  temp->link=last->link;
  last->link=temp;
  linklist::cdisplay();
 }
 if(ch=='b')
 {
  cout<<"\nEnter the pos after which u want to add: ";
  cin>>pos;
  linklist::cnt();
  q=last->link;
  while(q!=last)
  {
   count++;
   if(count==pos)
   {
    temp->link=q->link;
    strcpy(temp->data,val);
    q->link=temp;
    linklist::cdisplay();
   }
   else
   {
    q=q->link;
   }
  }
 }
 if(ch=='c')
 {
  while(q!=last)
  {
   q=q->link;
  }
  strcpy(temp->data,val);
  temp->link=q->link;
  q->link=temp;
  last=temp;
  linklist::cdisplay();
 }
 getch();
 linklist::c_list();
}
void linklist::cdel()
{
 int c=0;
 cout<<"\n\tEnter the value you want to delete: ";
 gets(val);
 q=last->link;
 while(q!=last)
 {
  if(last->link==last&&(strcmp(last->data,val)==0))
  {
   temp=last;
   last=NULL;
   delete temp;
   cout<<"\t\t\nElement Found----->Now Deleting........";
   getch();
   linklist::cdisplay();
  }
  if(strcmp(q->link->data,val)==0)
  {
   temp=q->link;
   q->link=temp->link;
   delete temp;
   cout<<"\t\t\nElement Found----->Now Deleting........";
   getch();
   linklist::cdisplay();
  }
  if(strcmp(q->link->data,val)==0)
  {
   temp=last;
   q->link=temp->link;
   last=q;
   delete temp;
   cout<<"\t\t\nElement Found----->Now Deleting........";
   getch();
   linklist::cdisplay();
  }
 q=q->link;
 }
 if(c==0)
 {
  cout<<"\n\n\n\n\t\t\tElement Not Found.......";
 }
 getch();
 linklist::c_list();
}
//////////Circular linked list ended/////////////////

//////////Doubly linked list started////////////////
void linklist::d_list()
{
 clrscr();
 cout<<"\n\n\t\tPress 1 to create double link list"<<endl;
 cout<<"\n\n\t\tPress 2 to display double list"<<endl;
 cout<<"\n\n\t\tPress 3 to insert a node into double list"<<endl;
 cout<<"\n\n\t\tPress 4 to delete a node from double list"<<endl;
 cout<<"\n\n\t\tPress 0 to go back to main menu"<<endl;
 cout<<"Enter your choice: ";
 cin>>choice;
 switch(choice)
 {
  case 1:
   clrscr();
   linklist::dcreate();
   break;
  case 2:
   clrscr();
   linklist::ddisplay();
   break;
  case 3:
   clrscr();
   linklist::din();
   break;
  case 4:
   clrscr();
   linklist::ddel();
   break;
  case 0:
   clrscr();
   linklist::ll();
   break;
 }
}

void linklist::dcreate()
{
 start1=NULL;
 linklist::rec();
 linklist::cnt();
 rectangle(l,t,r,b);
 outtextxy((l+r)/2-20,(t+b)/2+30,"Start");
 cout<<"Enter the no. of nodes u want to create: ";
 cin>>num;
 for(i=0;i<num;i++)
 {
  temp1=new node1;
  cout<<"Enter the value: ";
  gets(temp1->info);
  temp1->next=NULL;
  if(start1==NULL)
  {
   temp1->prev=NULL;
   start1=temp1;
   start1->prev=temp1;
  }
  else
  {
   q1=start1;
   while(q1->next!=NULL)
   {
    q1=q1->next;
   }
   q1->next=temp1;
   temp1->prev=q1;
  }
  count++;
  rp=r;
  rectangle(l=l+100,t,r=r+100,b);
  outtextxy((l+r)/2-25,(t+b)/2+30,"p  i  n");
  outtextxy((rp+l)/2-20,(t+b)/2-10,"---->");
  outtextxy((rp+l)/2-20,(t+b)/2+10,"<----");
  moveto((l+r)/2-15,t);
  linerel(0,40);
  moveto((l+r)/2+15,t);
  linerel(0,40);
  outtextxy((l+r)/2-10,(t+b)/2,temp1->info);
  if(count==num)
  {
   break;
  }

  else
  {
   continue;
  }
 }
 getch();
 linklist::d_list();
}

void linklist::ddisplay()
{
 linklist::rec();
 rectangle(l,t,r,b);
 outtextxy((l+r)/2-20,(t+b)/2+30,"Start");
 if(start1==NULL)
 {
  cout<<"\n\n\n\t\t\tList is empty........";
  getch();
  linklist::d_list();
 }

 q1=start1;
 while(q1!=NULL)
 {
 delay(1000);
 sound(5000);
 rp=r;
 rectangle(l=l+100,t,r=r+100,b);
 outtextxy((l+r)/2-25,(t+b)/2+30,"p  i  n");
 outtextxy((rp+l)/2-20,(t+b)/2-10,"---->");
 outtextxy((rp+l)/2-20,(t+b)/2+10,"<----");
 moveto((l+r)/2-15,t);
 linerel(0,40);
 moveto((l+r)/2+15,t);
 linerel(0,40);
 outtextxy((l+r)/2-10,(t+b)/2,q1->info);
 q1=q1->next;
 }
 nosound();
 getch();
 linklist::d_list();
}

void linklist::din()
{
 linklist::rec();
 temp1=new node1;
 cout<<"Enter the value of new node: ";
 gets(val);
 rectangle(l=l+200,t=t+50,r=r+200,b=b+50);
 outtextxy((l+r)/2-25,(t+b)/2+30,"p  i  n");
 outtextxy((l+r)/2-20,(t+b)/2-30,"temp");
 outtextxy((l+r)/2-10,(t+b)/2,val);
 moveto((l+r)/2-15,t);
 linerel(0,40);
 moveto((l+r)/2+15,t);
 linerel(0,40);
 getch();
 clrscr();
 cout<<"Press a for beg , b for any point & c for end: ";
 ch=getch();
 if(ch=='a')
 {
  strcpy(temp1->info,val);
  temp1->prev=NULL;
  temp1->next=start1;
  start1=temp1;
  start1->prev=temp1;
  linklist::ddisplay();
  getch();
 }
 if(ch=='b')
 {
  cout<<"\nEnter the pos after which u want to add: ";
  cin>>pos;
  q1=start1;
  for(i=0;i<count-1;i++)
  {
   q1=q1->next;
  }
  strcpy(temp1->info,val);
  q1->next->prev=temp1;
  temp1->next=q1->next;
  temp1->prev=q1;
  q1->next=temp1;
  linklist::ddisplay();
 }
 if(ch=='c')
 {
  q1=start1;
  while(q1->next!=NULL)
  {
   q1=q1->next;
  }
  strcpy(temp1->info,val);
  temp1->next=NULL;
  q1->next=temp1;
  temp1->prev=q1;
  linklist::ddisplay();
 }
 getch();
 linklist::d_list();
}
void linklist::ddel()
{
 int c=0;
 cout<<"\n\tEnter the value you want to delete: ";
 gets(val);
 q1=start1;
 while(q1!=NULL)
 {
  if(strcmp(q1->info,val)==0)
  {
   c=c+1;
   temp1=start1;
   start1=start1->next;
   start1->prev=NULL;
   delete temp1;
   cout<<"\t\t\nElement Found----->Now Deleting";
   getch();
   linklist::ddisplay();
  }
  if(strcmp(q1->next->info,val)==0)
  {
   c=c+1;
   temp1=q1->next;
   q1->next=temp1->next;
   temp1->next->prev=q1;
   delete temp1;
   cout<<"\t\t\nElement Found----->Now Deleting";
   getch();
   linklist::ddisplay();
  }
  if(strcmp(q1->next->info,val)==0)
  {
   c=c+1;
   temp1=q1->next;
   delete temp1;
   q1->next=NULL;
   cout<<"\t\t\nElement Found----->Now Deleting";
   getch();
   linklist::ddisplay();
  }
  q1=q1->next;
 }
 if(c==0)
 {
  cout<<"\n\n\n\n\n\t\t\tElement not found" ;
 }
 getch();
 linklist::d_list();
}


//////////Doubly linked list ended//////////////////
//////////////////////////GRAPHICS DEFINITION//////////////////////////////
void linklist::graph()
{
/* request auto detection */
int gdriver = DETECT, gmode, errorcode;
/* initialize graphics and local variables */
initgraph(&gdriver, &gmode, "\\tc\\bgi");
/* read result of initialization */
errorcode = graphresult();
if (errorcode != grOk)  /* an error occurred */
{
   printf("Graphics error: %s\n", grapherrormsg(errorcode));
   printf("Press any key to halt:");
   getch();
   exit(1); /* terminate with an error code */
}
}
///////////////////////////////MAIN FUNCTION///////////////////////////////
void main()
{
linklist l;
 clrscr();
 l.graph();
 setbkcolor(CYAN);
 int midx,midy;
 midx=getmaxx()/2;
 midy=getmaxy()/2;
 outtextxy(midx-100,midy,"Hello !!! Welcome User...");
 outtextxy(midx-100,midy+30,"Project created by :");
 outtextxy(midx-100,midy+40,"Rahul Pareek , Roll no 50");
 outtextxy(midx-100,midy+50,"Shweta Patil , Roll no 53");
 outtextxy(midx-100,midy+60,"Abhay Agrawal, Roll no 2 ");
 getch();
 clrscr();
 l.ll();
 getch();
 closegraph();
}
