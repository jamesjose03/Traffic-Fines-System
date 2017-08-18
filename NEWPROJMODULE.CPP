//Computer Science Project - ROP Fines Management
#include<fstream.h>
#include<conio.h>
#include<stdio.h>
#include<process.h>
#include<iomanip.h>
class ROP
 {
  int recno;
  char offense[100];
  char offholder[100];
  int dd;
  int mm;
  int yyyy;
  int plateno;
  char carmake[20];
  float fine;

  public:
   int getrecno()
    {
     return recno;
    }
   void input();
   void display();

   void getnewfine()
    {
     cout<<"\n Enter the new fine ";
     cin>>fine;
   }
   void search();
   void modify();
   void Delete();
   void allRec();
 };

void ROP::input()
 {

     cout<<"\n ----------------ROYAL OMAN POLICE HQ @ SALALAH-------------------";
     cout<<"\n ----------------------Offences Database--------------------------";
     cout<<"\n -------------------ROP OFFENSE INPUT PORTAL--------------------";
     cout<<"\n _________________________________________________________________";
     cout<<"\n Enter offense record no. : ";
     cin>>recno;
     cout<<"\n Enter the name of the offense holder: ";
     gets(offholder);
     cout<<"\n Enter the CAR MAKE and the PLATE NO. : ";
     cin>>carmake>>plateno;
     cout<<"\n Enter the offense: ";
     gets(offense);
     cout<<"\n Enter the date of offense commited: ";
     cin>>dd>>mm>>yyyy;
     cout<<"\n Enter the fine to be paid: ";
     cin>>fine;
 }

void ROP::display()
 {

     cout<<"\n ----------------ROYAL OMAN POLICE HQ @ SALALAH-------------------";
     cout<<"\n ----------------------Offences Database--------------------------";
     cout<<"\n -----------------ROP OFFENSE RECORD REGISTRY------------------";
     cout<<"\n _________________________________________________________________";

     cout<<"\n Offense record no. : ";
     cout<<recno;
     cout<<"\n Name of the offense holder: ";
     cout<<offholder;
     cout<<"\n Car Make: ";
     cout<<carmake;
     cout<<"\n Plate No. :";
     cout<<plateno;
     cout<<"\n Offense committed: ";
     cout<<offense;
     cout<<"\n Date of offense commited: ";
     cout<<dd<<"-"<<mm<<"-"<<yyyy;
     cout<<"\n Fine to be paid: ";
     cout<<fine;


    }

void ROP::search()
 {
 ROP r;
 fstream afile,ofile;
 int recno1, flag=0;
 cout<<"\n Enter the record number to view the corresponding record ";
     cin>>recno1;
     afile.open("record.dat",ios::in|ios::binary);

     while(afile.read((char*)&r, sizeof(ROP)))
      {

         if(recno1==r.getrecno())
          {
           r.display();
           flag=1;
           break;
          }
       }
       afile.close();
       if(flag==0)
        {
         cout<<"\n No Record of entered Record No. and plate number found ";
        }

  }


void ROP::modify()
 {
 fstream afile,ofile;
 int rec1,flag2=0;
 ROP r;
  cout<<"\n Enter Record No. to be modified ";
     cin>>rec1;
     afile.open("record.dat",ios::in|ios::ate|ios::binary);
     while(afile.read((char*)&r, sizeof(ROP)))
      {


        if(rec1==r.getrecno())
         {
          r.display();
          r.getnewfine();
          int pos=(-1)*(sizeof(ROP));
          afile.seekp(pos,ios::cur);
          afile.write((char*)&r, sizeof(ROP));
          cout<<"\n The record under the given record number is updated";
          flag2=1;
         }

      }
      afile.close();
      if(flag2==0)
      cout<<"\n Record not found";
 }


void ROP::Delete()
 {
 fstream afile,ofile;
 int rno1, flag1=0;
 ROP r;
 cout<<"\n Enter record number to delete record: ";
 cin>>rno1;
 afile.open("record.dat",ios::in|ios::binary);
 ofile.open("tmprecord.dat",ios::out|ios::binary);
 afile.seekg(0,ios::beg);
  while(afile.read((char*)&r,sizeof(ROP)))
   {

     if(r.getrecno()!=rno1)
      {
       ofile.write((char*)&r,sizeof(ROP));
      }
   else
    {
    flag1=1;
    cout<<"\n Fine deleted ! Payment recorded.";
    }
   }
 if(flag1==0)
 cout<<"\n No offence found!!";
 afile.close();
 ofile.close();
 afile.open("tmprecord.dat",ios::in|ios::binary);
 ofile.open("record.dat",ios::out|ios::binary);
 while(afile.read((char*)&r,sizeof(ROP)))
  {

  ofile.write((char*)&r,sizeof(ROP));
  }
 afile.close();
 ofile.close();
}

void ROP::allRec()
 {
 cout<<"\n"<<recno<<setw(15)<<" "<<offholder<<setw(15)<<dd<<"-"<<mm<<"-"<<yyyy<<setw(15)<<" "<<offense;
 }

void displayall()
 {
 ROP r;
 fstream afile;
 afile.open("record.dat",ios::in|ios::binary);
 if(!afile)
 cout<<"\n File could not be opened. Sorry!";
  else
  {
  cout<<"\n Record No.       Offense Holder    Date of offense      Offense Committed";
  cout<<"\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++";
   while(afile.read((char*)&r,sizeof(ROP)))
   {
   r.allRec();
   }
   afile.close();
  }
 }




 void main()
  {
   ROP r;
   fstream ofile, afile;
   int ch, no, flag, rec1, fine, flag1;
   char n;
   do
   {
   cout<<"\n ----------------ROYAL OMAN POLICE HQ @ SALALAH-------------------";
   cout<<"\n ----------------------Offences Database--------------------------";
   cout<<"\n _________________________________________________________________";

   cout<<"\n 1. Enter record ";
   cout<<"\n 2. Search for a record ";
   cout<<"\n 3. Modify a record ";
   cout<<"\n 4. Delete a record ";
   cout<<"\n 5. Display records";
   cout<<"\n 6. Exit database";


   cout<<"\n Enter choice corresponding to operation ";
   cin>>ch;

   switch(ch)
    {
     case 1:


      cout<<"\n ----------------ROYAL OMAN POLICE HQ @ SALALAH-------------------";
      cout<<"\n ----------------------Offences Database--------------------------";
      cout<<"\n _________________________________________________________________";
      ofile.open("record.dat", ios::app|ios::binary);
      r.input();
      ofile.write((char*)&r, sizeof(ROP));

      ofile.close();
      break;

     case 2:


     cout<<"\n ----------------ROYAL OMAN POLICE HQ @ SALALAH-------------------";
     cout<<"\n ----------------------Offences Database--------------------------";
     cout<<"\n ___________________ Search Records Section _______________________";
      r.search();
      break;

     case 3:

     cout<<"\n ----------------ROYAL OMAN POLICE HQ @ SALALAH-------------------";
     cout<<"\n ----------------------Offences Database--------------------------";
     cout<<"\n __________________ Modify Records Section ________________________";
     r.modify();
     break;

    case 4:
     cout<<"\n ----------------ROYAL OMAN POLICE HQ @ SALALAH-------------------";
     cout<<"\n ----------------------Offences Database--------------------------";
     cout<<"\n __________________ Delete Records Section _______________________";
     r.Delete();
     break;

    case 5:
     cout<<"\n ----------------ROYAL OMAN POLICE HQ @ SALALAH-------------------";
     cout<<"\n ----------------------Offences Database--------------------------";
     displayall();
     break;

     case 6:

      cout<<"\n ----------------------Thank you-----------------------";
      cout<<"\n ------------Do visit our portal for any queries------ ";
      cout<<"\n ----------------Exiting the portal------------- ";
      exit(0);
     break;


    }//end of switch cases

   cout<<"\n Operation complete! Do you want to continue?(y/n)";
   cin>>n;
   }while(n=='y');
getch();
}


