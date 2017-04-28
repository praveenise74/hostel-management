#include<iostream>
#include<cstdlib>
#include<fstream>
#include<cstring>
#include<cstdio>
#include<unistd.h>

using namespace std;
class hostel;
class detail {
        public: 
	char first_name[20];
        char last_name[20];
	int age;
        char dob[10];
	char phone_num[20];
	char address[50];
	char pin[10];
    
      	void read1();
        void read2();
        void disp1();
        void disp2();
};     

class student:public detail {
	public:
	char usn[10];
	int admn_num;
	char branch[50];
	char sec[5];
	int sem;
	char guardian_name[50];
	int room_num;
	char hostel_name[20];
	char blood_group[10];
	char guardian_address[50];
	char allocdate[10];

        void search();
	void room_search();
        void srch_name();
        void main_menu();
        void add();
        void display();
        void rooms();
        void edit();
        int check(char *,int);
        void modify();
        void delet();
//	void status();
	void sort(int *,int);
        int getroom()
           {
             return room_num;
           }
	int getadmno(){return admn_num;}
      
 	 void read();
         void disp();
	 //friend class hostel;
         friend void status(hostel h,student s);

}s;
	

class hostel
{	
	public:
	char hname[50];
	int  no_of_room;
	int room_no[999];
	char warden[50];
	void hostel_detail();
	void hdetail();
	int check2(char *,int);
	int check1(char *);
	//void status(student s);
	friend void status(hostel h,student s);

}h;


void hostel::hostel_detail(){

	char ch;
	int i;
	ofstream out("hostel.dat",ios::app|ios::binary);
	
	cout<<"HOSTEL NAME : ";		cin.get(ch);
	
	cin.getline(hname,50);
	cout<<"WARDEN NAME : ";
	cin.getline(warden,59);
	cout<<"NUMBER OF ROOMS : ";  
	cin>>no_of_room;
	cout<<"ROOM NUMBERS : ";
	for(i=0;i<no_of_room;i++)
	{
	cin>>room_no[i];
	}
	out.write((char*)&h,sizeof(h));
	out.close();

}

void hostel::hdetail()
{

 int i;
 ifstream in("hostel.dat",ios::in|ios::binary);
 while(in.read((char*)&h,sizeof(h)))
 {
 cout<<"\n\t\t\tHOSTEL NAME : ";
 cout<<hname;
 cout<<"\n\t\t\tWARDEN NAME : ";
 cout<<warden;
 cout<<"\n\t\t\tTOTAL ROOMS : ";
 cout<<no_of_room;
 cout<<"\n\t\t\tROOMS : ";
 for(i=0;i<no_of_room;i++){
 cout<<"\n\t\t\t"<<room_no[i]<<"\t";
}
 }
 in.close();
 getchar();
 cout<<"\n\t\tPRESS ANY KEY TO GO MAIN MENU";
 getchar();
}

class warden:public detail {
	public:           
     
	void ward_detail();
        void ward_display();
	void search();
}w;
        
void warden::ward_detail()
{
  ofstream out("warden.dat",ios::app|ios::binary);
  w.read1();
  w.read2();
  out.write((char *)&w,sizeof(w));
  out.close();
}

void warden::ward_display()
{
 ifstream in("warden.dat",ios::in|ios::binary);
 in.read((char *)&w,sizeof(w));
 w.disp1();
 w.disp2();
 in.close();
}

void warden::search()
{
system("clear");
char name[20]; char found='n';int ret;
ifstream in("warden.dat",ios::in|ios::binary);
cout<<"Enter warden first name : ";
cin>>name;
while(in.read((char *)&w,sizeof(w)))
{
 ret=strcasecmp(name,w.first_name);
 if(ret==0)
  {
   found='y';
   w.disp1();
   w.disp2();
   cout<<"PREESS ANY KEY TO GO MAIN MENU";
         getchar();
        getchar();
         system("clear");
  break;
  }
 }

if(found=='n')
 cout<<"warden name not found!!"<<endl;
  cout<<"PREESS ANY KEY TO GO MAIN MENU";
         getchar();
        getchar();
         system("clear");
 in.close();
}
int student::check(char *h1,int r)
{
	int flag=0,ret;

	ifstream fin("Record.dat",ios::in|ios::binary);
        fin.seekg(0);
	while(fin.read((char *)&s,sizeof (s)))
	{
 	ret=strcasecmp(h1,s.hostel_name);
	if(ret==0)
          
           {
 		
	     if(s.getroom()==r)
	{
		flag=flag+1;
            
	}
	}}
	return flag;
                        
	fin.close();		
	}

int hostel::check2(char *h1,int r)
{
 
 int i, flag2=0;
 ifstream in("hostel.dat",ios::in|ios::binary);
 in.seekg(0);
 while(in.read((char *)&h,sizeof (h)))
 {
   if(!strcasecmp(h1,hname))
	{	
		for(i=0;i<no_of_room;i++)
		{
		if(r==room_no[i])
		{
		flag2=1;
		} 
		}
	}
    
 }
return flag2;	
	in.close();
}
  


int hostel::check1(char *h1)
{
  int flag1=0; 
 fstream in("hostel.dat",ios::in|ios::binary);
 in.seekg(0);
 while(in.read((char *)&h,sizeof (h)))
 {
 if(!strcasecmp(h1,hname))
  flag1=1;
  }
 return flag1;
 in.close();
 }
 


void student::add()
{
	int r,flag=0,flag1=0,flag2=0; char ans='y',ch,hostelname[50];
	system("clear");
	while(ans=='y'||ans=='Y')
	{
	cout<<"\n Enter Student Detalis";
	cout<<"\n ----------------------";

	
	cout<<"\nHOSTEL NAME : "; cin.get(ch);
	cin.getline(hostelname,50);
	flag1=h.check1(hostelname);
	if(flag1==1) 
        {
	while(ans=='y'||ans=='Y')
        {

	cout<<"\n\n Room no: ";         cin>>r;

	flag2=h.check2(hostelname,r);       
	if(flag2==1)
	{     
	flag=check(hostelname,r);
        if(flag<2)
	{
	     ofstream fo("Record.dat",ios::app);
             s.room_num=r;
	     strcpy(s.hostel_name,hostelname);
             s.read1();
             s.read();
             s.read2();
             
           fo.write((char *)&s,sizeof s);
           fo.close();
	   cout<<"Do you want to Enter again:(Y/y)";		cin>>ans;
	}

	else{
		cout<<"\nSorry..!!!Room is already booked\n";
		cout<<"\nDo you want to Enter again:(Y/y)";         cin>>ans;
             }
	
	}	
	else
	   {
		cout<<"\nINVALID ROOM NUMBER";
		cout<<"\nDO YOU WANT TO ENTER AGAIN(Y/y)";  cin>>ans;
	  }
         }}
	else
	{
		cout<<"\nINVALID HOSTEL NAME";
		cout<<"\nDO YOU WANT TO ENTER AGAIN(Y/y)";  cin>>ans;
	}	
 }
cout<<"\nPRESS ANY KEY TO GO MAIN MENU ";
getchar();
getchar();
}



void student::search()
{system("clear");
 int admn; char found='n';
 ifstream fi("Record.dat",ios::in | ios::binary);
  cout<<"Enter admission no. to be search:";
  cin>>admn;
  while(fi.read((char *)&s,sizeof(s)))
  {
    if(s.getadmno()==admn)
     {
       s.disp1();
       s.disp();
       s.disp2();
       found='y';
	cout<<"PRESS ANY KEY TO GO MAIN MENU";
	 getchar();
	getchar();
	 system("clear");
       break;
    }
 }
 if(found=='n')
 cout<<"admission no not found!!"<<endl;
 fi.close();
 getchar();
 cout<<"PRESS ANY KEY TO GO MAIN MENU";
 getchar();
}

void student::room_search()
{
 /* system("clear");
  int room,flag=1,a; char found='n';
  ifstream fi("hostel.dat",ios::in | ios::binary);
  while(1)
  {
  cout<<"ENTER ROOM NUMBER TO BE SEARCH:";
  cin>>room;
  int i;
  for(i=0;i<12;i++)
  {
   if(room[i]==room){
   flag=0;
   break;
   }
  }
  if(flag==1)
   {
   cout<<"Invalid room number\n";
   cout<<"AGAIN ";
   }
  }
  while(fi.read((char *)&s,sizeof(s)))
  {
    if(s.getroom()==room)
     {
       s.disp1();
       s.disp();
       s.disp2();
       found='y';
    }
 }
 if(found=='n')
 cout<<"this room is  not booked!!"<<endl;
 fi.close();
 cout<<"PREESS ANY KEY TO GO MAIN MENU";
 getchar();
 getchar();
 system("clear");*/
}

void status(hostel h,student s)
{
 system("clear");
 int i,flag=0;
 int ret;
 ifstream fi("hostel.dat",ios::in | ios::binary);
 if(!fi)
  {
   cout<<"UNABLE TO OPEN FILE";
  }

 fi.seekg(0);
  while(fi.read((char *)&h,sizeof(h)))
   {

	  cout<<"\nHOSTEL NAME : ";
	  cout<<h.hname;
  	  cout<<"\nROOM NUMBER WITH STATUS \n";
	  for(i=0;i<h.no_of_room;i++)
	  {
	    ifstream fin("Record.dat",ios::in | ios::binary);
 	    if(!fin)
  	    {
   	    cout<<"UNABLE TO OPEN FILE";
  	     }
 	     fin.seekg(0);
              flag=0;
 	    while(fin.read((char *)&s,sizeof(s)))
	     {
		
	//	cout<<s.room_num<<"  "<<h.room_no[i];
                
 		ret=strcasecmp(h.hname,s.hostel_name);
                if(ret==0)
                 {
       	      if(s.room_num==h.room_no[i])
	      {  flag=flag+1;}}}
	  	
	        cout<<h.room_no[i];	
		if (flag==1)
		
                {
	 	cout<<" - - - - - - 1 BED VACANT\n";
		}

		else if(flag==2)
		{
                  cout<<" - - - - - - BOOKED\n";}
         	else
	   	{
            	cout<<" - - - - - -  VACANT\n";
	   	}fin.close();
	      }
	
	}
  


 fi.close();getchar();
cout<<"PRESS ANY KEY TO GO MAIN MENU";
getchar();
 //fin.close();
}
    
void student::delet()
{
        ifstream fi("Record.dat",ios::in);
        ofstream fo("temp.dat",ios::out);
        int admn; char found='n' ,confirm='n';
        cout<<"Enter admission no of student whose record is to be deleted :: ";
        cin>>admn;
        while(fi.read((char *)&s,sizeof(s)))
        {
                 if(s.getadmno()==admn)
                {
                        s.disp1();
                        s.disp();
			s.disp2();
                        found='y';
                        cout<<"are you sure?(y/n)..:";
                        cin>>confirm;
			if(confirm=='y')
                         {
                           cout<<"DELETE SUCCESFUL\n";}
                        if(confirm=='n')
                          fo.write((char *)&s,sizeof(s));
                }
                else
                   fo.write((char *)&s,sizeof(s));
        }
        if(found=='n')
        cout<<"Record not found\n";
        fi.close();
        fo.close();
        getchar();
        cout<<"PRESS ANY KEY TO GO MAIN MENU";
         getchar();
        remove("Record.dat");
        rename("temp.dat","Record.dat");
}




void student::modify()
{	char f_n[59],phn[20],l_n[20],db[20],un[20],brnch[30],sc[10],bg[4],gn[50],ga[100],hstnm[30],rad[10],ad[100],pnc[10];
	int ag,admn,sm;
        fstream fio("Record.dat",ios::in|ios::out|ios::binary);
        if(fio==0)
	cout<<"\n File cannot open!";
	ofstream fo("temp.dat",ios::out);
	int ch; int pos; char found=0; char confirm='n';
        cout<<"Enter admission no of student whose record is to be modified \n";
        cin>>admn;
	fio.seekg(0);
        while(fio.read((char*)&s,sizeof(s)))
        {
                pos=fio.tellg();
		
                if(s.getadmno()==admn)
                { 
			found=1;
			//cout<<pos;

                        s.disp1();
			s.disp();
			s.disp2();
                        found='y';
			cout<<"1.FIRST NAME\n2.LAST NAME\n3.AGE\n4.PHONE NUMBER\n5.DOB\n6.USN\n7.ADDMISSIN NUMBER\n8.BRANCH\n9.SEMESTER\n10.SECTION\n11.BLOOD GROUP\n12.GUARDIAN NAME\n13.GUARDIAN ADDRESS\n14.HOSTEL NAME\n15.HOSTEL ADMISSION DATE\n16.ADDRESS\n17.PIN CODE\n";
			cout<<"What do you want to modify\n";
			cin>>ch;
                        cout<<"are you sure?(y/n)..:";
                        cin>>confirm;
			confirm=toupper(confirm);
                        if(confirm=='Y')
                        {
			 cout<<"\n\tENTER NEW ";
                         switch(ch)
			  {
 				case 1: cout<<" FIRST NAME : ";
					getchar();	cin.getline(f_n,59);
					strcpy(s.first_name,f_n);break;
          
          			case 2:cout<<"LAST NAME : ";getchar();
					cin.getline(l_n,59);
					strcpy(s.last_name,l_n);
					break;
          
          			case 3:cout<<"AGE 		     : ";
					cin>>ag;
					s.age=ag;
         		         /*	fio.seekg(pos-sizeof(s));
                        		fio.write((char*)&s,sizeof(s));*/
          				break;
          			case 4:cout<<"PHONE NUMBER 	     : ";getchar();
					cin.getline(phn,20);
					strcpy(s.phone_num,phn);break;

          
          			case 5:cout<<"DATE OF BIRTH 	     : ";
					getchar();	cin.getline(db,29);
					strcpy(s.dob,db);break;

	  			case 6:cout<<"USN 	             : ";
					getchar();cin.getline(un,20);
					strcpy(s.usn,un);
					break;         
          			case 7:cout<<"ADMISSION NUMBER 	     : ";
					cin>>admn;
					s.admn_num=admn;break;
				
          			case 8:cout<<"BRANCH 		     : ";
					getchar();	cin.getline(brnch,40);
					strcpy(s.branch,brnch);break;
          
          			case 9:cout<<"SEMESTER 		     : ";
					cin>>sm;
					s.sem=sm;break;
          
          			case 10:cout<<"SECTION 		     : ";
					getchar();cin.getline(sc,30);
					strcpy(s.sec,sc);break;
          
          			case 11:cout<<"BLOOD GROUP 	     : ";
					getchar();cin.getline(bg,30);
					strcpy(s.blood_group,bg);break;
          
          			case 12:cout<<"GUARDIAN NAME 	     : ";
					getchar();cin.getline(gn,50);
					strcpy(s.guardian_name,gn);break;
          
          			case 13:cout<<"GUARDIAN ADDRESS	     : ";
					getchar();cin.getline(ga,100);
					strcpy(s.guardian_address,ga);break;
					
          
          			case 14:cout<<"HOSTEL NAME	     : ";
					getchar();cin.getline(hstnm,30);
					strcpy(s.hostel_name,hstnm);break;
          
          			case 15:cout<<" ROOM ALLOCATION DATE : ";
					getchar();cin.getline(rad,40);
					strcpy(s.allocdate,rad);break;
          
          			case 16:cout<<"ADDRESS 		     : ";
					getchar();cin.getline(ad,100);
					strcpy(s.address,ad);break;
          
          			case 17:cout<<"PIN CODE		     : ";getchar();
					cin.getline(pnc,10);
					strcpy(s.pin,pnc);
					break;
				default:cout<<"INVALID ENTRY!!!";
					break;
			}
                        fio.seekg(pos-sizeof(s));
                        fio.write((char*)&s,sizeof(s));
                        cout<<"\n\t\tMODIFIED\n";
                        }
                }

	}if(found==0){cout<<"\n\n\t\tADMISSION NUMBER NOT FOUND";
			cout<<"PRESS ANY KEY TO GO MAIN MENU";
getchar();
	}
         
 fio.close();

cout<<"\n\n\t\tPRESS ANY KEY TO GO MAIN MENU";
getchar();
} 


void student::read()
{ 	  char ch;
 	  cout<<"\n\tUSN :: ";
          cin.getline(usn,20);
          cout<<"\n\tADMISSION NUMBER :: ";
          cin>>admn_num;
          cout<<"\n\tBRANCH :: ";cin.get(ch);
          cin.getline(branch,50);
          cout<<"\n\tSEMESTER :: ";
          cin>>sem;
          cout<<"\n\tSECTION :: ";
          cin>>sec;
          cout<<"\n\tBLOOD GROUP :: ";
          cin>>blood_group;
          cout<<"\n\tGUARDIAN NAME :: ";cin.get(ch);
          cin.getline(guardian_name,50);
          cout<<"\n\tGUARDIAN ADDRESS :: ";
          cin.getline(guardian_address,200);
          cout<<"\n\tHOSTEL ADMISSION  DATE :: ";
          cin>>allocdate;cin.get(ch);
}
void detail::read1()
{
 	  char ch;        
          cout<<"\n\tFIRST NAME :: ";cin.get(ch);
          cin.getline(first_name,50);
          cout<<"\n\tLAST NAME :: ";
          cin.getline(last_name,50);
          cout<<"\n\tAGE :: ";
          cin>>age;
          cout<<"\n\tPHONE NUM :: ";
          cin>>phone_num;
          cout<<"\n\tENTER DOB :: ";cin.get(ch);
          cin.getline(dob,20);
}
void detail::read2()
         {
          char ch;
	  cout<<"\n\tADDRESS :: ";//cin.get(ch);
          cin.getline(address,100);
          cout<<"\n\tPIN :: ";
          cin.getline(pin,10);
          }

void student::display()
{

 ifstream fi("Record.dat",ios::in | ios::binary);
 while(fi.read((char *)&s,sizeof(s)))
        {
		s.disp1();
		s.disp();
		s.disp2();
	}
	fi.close();
 getchar();
 cout<<"PRESS ANY KEY TO GO MAIN MENU";
 getchar();
}


void student::disp()
{
          cout<<"\t\t\t\t\t\t\tUSN :: ";
          cout<<usn;
          cout<<"\n\n\t\tADMISSION NUMBER :: ";
          cout<<admn_num;
          cout<<"\t\t\t\t\t\tBRANCH :: ";
          cout<<branch;
          cout<<"\n\n\t\tSEMESTER :: ";
          cout<<sem;
          cout<<"\t\t\t\t\t\t\t\tSECTION :: ";
          cout<<sec;
          cout<<"\n\n\t\tBLOOD GROUP :: ";
          cout<<blood_group;
          cout<<"\t\t\t\t\t\t\tGUARDIAN NAME :: ";
          cout<<guardian_name;
          cout<<"\n\n\t\tGUARDIAN ADDRESS :: ";
          cout<<guardian_address;
          cout<<"\n\n\t\tHOSTEL NAME :: ";
          cout<<hostel_name;
          cout<<"\t\t\t\t\t\t\tROOM NUM :: ";
          cout<<room_num;
          cout<<"\n\n\t\tROOM ALLOCATION DATE :: ";
          cout<<allocdate;

 
}

void detail::disp1()
{         cout<<"\n\t_________________________________________________________________________________________________________________________________";
          cout<<"\n\n\t\tFIRST NAME :: ";
          cout<<first_name;
          cout<<"\t\t\t\t\t\t\tLAST NAME :: ";
          cout<<last_name;
          cout<<"\n\n\t\tAGE :: ";
          cout<<age;
          cout<<"\t\t\t\t\t\t\t\tPHONE NUM :: ";
          cout<<phone_num;
          cout<<"\n\n\t\tENTER DOB :: ";
          cout<<dob;

}


void detail::disp2()
{
          cout<<"\n\n\t\tADDRESS :: ";
          cout<<address;
          cout<<"\n\n\t\tPIN :: ";
          cout<<pin;
	 cout<<"\n\n\t_________________________________________________________________________________________________________________________________\n";
}

int main()
{
 system("clear");
 cout<<"\n\n\n\n";
  cout<<"\n\t\t\t\t\t\t===========================================================\n";

 cout<<"\t\t\t\t\t\t   ****** WELCOME TO NMIT HOSTEL MANAGMENT SYSTEM ******" ;
  cout<<"\n\t\t\t\t\t\t===========================================================\n\n";
 char pass[10]="1234";
 char *password;
 password=getpass("Enter the password\n");
 int ch;
 student s;
 if(strcmp(pass,password)==0)
 {
// warden w;
 while(1)
{system("clear");
 cout<<"\n\t\t\t\t\t\t===========================================================\n";
 cout<<"\t\t\t\t\t\t   ****** WELCOME TO NMIT HOSTEL MANAGMENT SYSTEM ******" ;
  cout<<"\n\t\t\t\t\t\t===========================================================\n\n";
 
cout<<"\n\t\t\t\t\t\t\t\t\t1. Allot room  \n\t\t\t\t\t\t\t\t\t2. Display  \n\t\t\t\t\t\t\t\t\t3. Searh \n\t\t\t\t\t\t\t\t\t4. Delete \n\t\t\t\t\t\t\t\t\t5. Modify\n\t\t\t\t\t\t\t\t\t6. Enter New Hostel Detail\n\t\t\t\t\t\t\t\t\t7. Detail of hostel\n\t\t\t\t\t\t\t\t\t8. Room status\n\t\t\t\t\t\t\t\t\t9. Enter warden detail\n\t\t\t\t\t\t\t\t\t10. Search warden Detail \n\t\t\t\t\t\t\t\t\t11. Exit";
cout<<"\n\n\n\t\t\t\t\t\t\t\t\tPLEASE ENTER YOUR CHOICE : ";
 cin>>ch;
 switch(ch)
   {
    
     case 1:s.add();
             break;
     case 2:s.display();
             break;
     case 3:s.search();
	     break;
     case 4:s.delet();
	     break;
     case 5:s.modify();
		break;
      case 6: h.hostel_detail();
		break;
      case 7:h.hdetail();
		break;
     case 8:status(h,s);
	 	break;
      case 9: w.ward_detail();
		break;
      case 10:w.search();
		break;
      case 11:exit(0);
   default:cout<<"invalid choice\n";
           break;
}
}
}
else
{
	cout<<"Incorrect password\n";	
	return 0;
}
return 0;
}



