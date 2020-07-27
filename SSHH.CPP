//THE HEADER FILES
#include<fstream.h>
#include<conio.h>
#include<stdio.h>
#include<process.h>
#include<string.h>
#include<iomanip.h>
#include<dos.h>
#include<graphics.h>
fstream fp,fp1;             //GLOBAL DECLARATION
int s=99;
static int dd,mm,yy;    //STATIC DECLARATION

class book                  //CLASSES AND IT’S FUNCTIONS
{
	int bookno;
	char bookname[50];
	char a_name[20];
  public:
	 void create_book();
	 void show_book();
	 void modify_book();
	 void report();
	 char* retbookname()
	 { return bookname;
	 }
	 char* retaname()
	 { return a_name;
	 }
	 int retbookno()
	{return bookno;
	}
};

void book::create_book()
	{
		cout<<endl<<"________NEW BOOK ENTRY!!________"<<endl<<endl;
		cout<<endl<<"Enter Book name: ";
		gets(bookname);
		cout<<endl<<"Enter Author's Name: ";
		gets(a_name);
		bookno=++s;
		cout<<endl<<"Record created successfully!!!";
		cout<<endl<<"The book no.: "<<bookno;
	};
void book::show_book()
	{
		cout<<endl<<"Book no. : "<<bookno;
		cout<<endl<<"Book Name : ";
		puts(bookname);
		cout<<endl<<"Author Name : ";
		puts(a_name);
		cout<<endl;
	};

void book::modify_book()
	{
		cout<<endl<<"Book no. : "<<bookno;
		cout<<endl<<"Modify Book Name : ";
		gets(bookname);
		cout<<endl<<"Modify book's author name ";
		gets(a_name);
		cout<<endl;
	}


void book::report()
	  { cout<<bookno<<setw(34)<<bookname<<setw(24)<<a_name<<endl;
	   };
int k=0;

class members             //CLASS MEMBERS AND ITS FUNCTIONS
{
	int admno;
	char name[20];
	char add[30];
	char pno[11];
	int stbookno;
	int token;
public:
	void show();
	void create_members();
	void show_members();
	void modify_members();
	void book_issue();
	void book_deposit();
	int retadmno()
	{
		return admno;
	}
	char* retsname()
	{       return name;
	}
	int retstbookno()
	{
		return stbookno;
	}

	int rettoken()
	{
		return token;
	}
          void addtoken()
	{token=1;}
void resettoken()
	{token=0;}
void getstbookno(int t)
	{
		stbookno=t;
	}

};

void members::create_members()
{
clrscr();
cout<<endl<<"___NEW MEMBER'S ENTRY___";
cout<<endl<<"Enter member's name: "<<endl;
gets(name);
cout<<"Enter member's  address: "<<endl;
gets(add);
cout<<"Enter member's  phone no.(not less than 10  and more than 11 digits): ";
gets(pno);
while((strlen(pno)!=10&&strlen(pno)!=11)||!(pno[0]=='0'||pno[0]=='1'||pno[0]=='2'||pno[0]=='3'||pno[0]=='4'||pno[0]=='5'||pno[0]=='6'||pno[0]=='7'||pno[0]=='8'||pno[0]=='9'||pno[0]=='+'))
{
cout<<"Invalid entry.please re-enter.";
gets(pno);
}
token=0;
stbookno=0;
admno=++k;
cout<<endl<<"Student Record Created successfully!!";
cout<<endl<<"your admission no is: "<<admno;
};

void members::show_members()
{
cout<<endl<<"Admission no. : "<<admno;
cout<<endl<<"member's  Name : ";
puts(name);
cout<<endl<<"member's  address : "; puts(add);
cout<<endl<<"member's  phoneno. : "<<pno;
cout<<endl<<"No of Book issued : "<<token;
if(token==1)
cout<<"Book No "<<stbookno<<endl;
};

void members::modify_members()
{
cout<<endl<<"Admission no. : "<<admno;
cout<<endl<<"Modify member's  Name : ";
gets(name);
cout<<endl<<"Modify member's  address : ";
gets(add);
cout<<endl<<"Modify member's  contact no : ";
gets(pno);
while(strlen(pno)!=10&&strlen(pno)!=11)
{
cout<<"Invalid entry.please re-enter.";
gets(pno);}};
void members::show()
{cout<<admno<<setw(30)<<name<<setw(30)<<token<<endl;}

                           //CLASS DATE1 AND ITS FUNCTIONS
class date1
 {
	   public:
	   int day,mon,year;
	   int df(int d1,int m1,int y1);
	   void ext(int,int,int,int);
  };
void date1:: ext(int d1, int m1, int y1, int days)
{
static int month[]={31,29,31,30,31,30,31,31,30,31,30,31} ;
for(int i=1; i<=days; i++)
{
d1++ ;
if((d1>month[m1-1])||(y1%4!=0&&m1==2&&d1> 28))
{
d1= 1 ;
m1++ ;}
if (m1 > 12)
{
m1 = 1 ;
y1++;
}}
::dd= d1 ;
::mm = m1 ;
::yy= y1 ;
cout<<"the date of return is "<<::dd<<"-"<<::mm<<"-"<<::yy<<endl;
}

int date1::df(int d1, int m1, int y1)
{
int days = 0 ;
static int month[] = {31,29,31,30,31,30,31,31,30,31,30,31} ;
while (::dd != d1 || ::mm != m1 || ::yy != y1)
{
days++ ;
dd++ ;
if ((::dd > month[mm-1]) || (::yy%4 != 0 && ::mm == 2 && ::dd > 28))
{
::dd = 1 ;
::mm++ ;
}
if (::mm > 12)
{
::mm = 1 ;
::yy++ ;
}
}
return days ;}

//DATE AND TIME FUNCTION
void time()
{
	     int d,m,y;
	     struct date d2;
	     getdate(&d2);
	     y= d2.da_year;
	     d= d2.da_day;
	     m= d2.da_mon;
	     cout<<"Date:"<<d<<"-"<<m<<"-"<<y<<"                                ";

   struct  time t;
   gettime(&t);
   printf(" Current time : %2d:%02d:%02d.%02d\n",
	  t.ti_hour, t.ti_min, t.ti_sec, t.ti_hund);

      getch();
}

book bk;               //OBJECT DECLARATION
members st;
void write_book()
{
	char ch;
	fp.open("book.dat",ios::out|ios::app);
	do
	{
		clrscr();
		bk.create_book();
		fp.write((char*)&bk,sizeof(book));
		cout<<endl<<"Do you want to add more record..(y/n?)  ";
		cin>>ch;
		cout<<endl;
	}while(ch=='y'||ch=='Y');
	fp.close();
}

void write_members()
{
	char ch;
	fp.open("members.dat",ios::out|ios::app);
	do
	{
		st.create_members();
		fp.write((char*)&st,sizeof(members));
		cout<<"\n\ndo you want to add more record..(y/n?)";
		cin>>ch;
	}while(ch=='y'||ch=='Y');
	fp.close();
}
void display_alls()
{
	clrscr();
	fp.open("members.dat",ios::in);
	if(!fp)
	{
		cout<<"ERROR!!! ";
		return;
	}

	cout<<endl<<"________STUDENT LIST________"<<endl;
	cout<<"=================================================================="<<endl;
	cout<<"Admission No."<<setw(20)<<"Name"<<setw(30)<<"Book Issued"<<endl;
	cout<<"=================================================================="<<endl;

	while(fp.read((char*)&st,sizeof(members)))
	{
		st.show();
	}

	fp.close();

}


void display_allb()
{
	clrscr();
	fp.open("book.dat",ios::in);
	if(!fp)
	{
		cout<<"ERROR!!! ";
		return;
	}

	cout<<endl<<endl<<"_________Book LIST________"<<endl;
	cout<<"========================================================================="<<endl;
	cout<<"Book Number"<<setw(20)<<"Book Name"<<setw(30)<<"Author"<<endl;
	cout<<"========================================================================="<<endl;

	while(fp.read((char*)&bk,sizeof(book)))
	{
		bk.report();
	}
	fp.close();

}
void display_spb()
{display_allb();
int z=0;int flag=0;int b;
char c[20];
cout<<"search by:"<<endl<<"1). book name."<<endl<<"2).Author name."<<endl<<"3).book no."<<endl;
cin>>z;
fp.open("book.dat",ios::in);
if(z==1)
{
 cout<<"enter book name: ";
gets(c);
while(fp.read((char*)&bk,sizeof(book)))
{if((strcmp(bk.retbookname(),c)==0))
   {
    bk.show_book();
    flag=1;
   }
}
}
if(z==2)
{
cout<<"enter author name: ";
gets(c);

while(fp.read((char*)&bk,sizeof(book)))
{if(strcmp(bk.retaname(),c)==0)
		{
			bk.show_book();
			flag=1; break;
		}
	}
	}
 if(z==3)
{
cout<<"enter book no: ";
cin>>b;
while(fp.read((char*)&bk,sizeof(book)))
{if(bk.retbookno()==b)
		{
			bk.show_book();
			flag=1; break;
		}
	}
}
fp.close();
if(flag==0)
cout<<"\n\nBook does not exist";
}

void display_sps()
{display_alls();
int z;int flag=0;int b;
char f[20];
cout<<"search by:"<<endl<<"1). members name."<<endl<<"2).Admission no."<<endl;
cin>>z;
	fp.open("members.dat",ios::in);
	       if(z==1)
	{       cout<<"Enter members's name: ";
		gets(f);
	while(fp.read((char*)&st,sizeof(members)))
	{if((strcmp(st.retsname(),f)==0))
		{
			st.show_members();
			flag=1; break;
	 }	}  }
		if(z==2)
	 {        cout<<"Enter admission no.: ";
		  cin>>b;
	 while(fp.read((char*)&st,sizeof(members)))
	{
		if(st.retadmno()==b)
		{
			st.show_members();
			flag=1;break;
		}
	}
	  }
	fp.close();
	if(flag==0)
		cout<<"\n\nmember's  does not exist";

}
void modify_book()
{
	int n;
	int found=0;
	clrscr();
	cout<<endl<<"________MODIFY BOOK REOCORD_________";
	display_allb();
	cout<<endl<<endl<<"Enter The book no. of The book";
	cin>>n;
	fp.open("book.dat",ios::in|ios::out);
	while(fp.read((char*)&bk,sizeof(book)) && found==0)
	{
		if(bk.retbookno()==n)
		{
			bk.show_book();
			cout<<endl<<"Enter The New Details of book"<<endl;
			bk.modify_book();
			int pos=-1*sizeof(bk);
			fp.seekp(pos,ios::cur);
			fp.write((char*)&bk,sizeof(book));
			cout<<endl<<"Record Updated";
			found=1;
		}
	}

	fp.close();
	if(found==0)
		cout<<endl<<" Record Not Found ";
}
void modify_members()
{
	int n;
	int found=0;
	clrscr();
	cout<<endl<<"_________MODIFY MEMBER RECORD________ ";
	display_alls();
	cout<<endl<<"Enter The admission no. of The members";
	cin>>n;
	fp.open("members.dat",ios::in|ios::out);
	while(fp.read((char*)&st,sizeof(members)) && found==0)
	{
		if(st.retadmno()==n)
		{
			st.show_members();
			cout<<endl<<"Enter The New Details of members"<<endl;
			st.modify_members();
			int pos=-1*sizeof(st);
			fp.seekp(pos,ios::cur);
			fp.write((char*)&st,sizeof(members));
			cout<<endl<<" Record Updated";
			found=1;
		}
	}

	fp.close();
	if(found==0)
		cout<<endl<<" Record Not Found ";
}
void delete_members()
{
	int n;
	int c=0;
	clrscr();
	cout<<endl<<"_________DELETE MEMBER_________";
	display_alls();
	cout<<endl<<"Enter The admission no. of the member's  You Want To Delete : ";
	cin>>n;
	cout<<endl;
	fp.open("members.dat",ios::in|ios::out);
	fstream fp2;
	fp2.open("Temp.dat",ios::out);
	fp.seekg(0,ios::beg);
	while(fp.read((char*)&st,sizeof(members)))
	{
		if(st.retadmno()!=n)
			fp2.write((char*)&st,sizeof(members));
		else
			c=1;
	}
	fp2.close();
	fp.close();
	remove("members.dat");
	rename("Temp.dat","members.dat");
	if(c==1)
	       {
		cout<<endl<<"Record Deleted ..";
		k--;
		}
	else
		cout<<endl<<"Record not found";
}
void delete_book()
{
	int n;
	clrscr();
	cout<<"________DELETE BOOK________";
	display_allb();
	cout<<endl<<"Enter The Book no. of the Book You Want To Delete : ";
	cin>>n;
	cout<<endl;
	fp.open("book.dat",ios::in|ios::out);
	fstream fp2;
	fp2.open("Temp.dat",ios::out);
	fp.seekg(0,ios::beg);
	while(fp.read((char*)&bk,sizeof(book)))
	{
		if(bk.retbookno()!=n)
		{
			fp2.write((char*)&bk,sizeof(book));
		}
	}

	fp2.close();
	fp.close();
	remove("book.dat");
	rename("Temp.dat","book.dat");
	cout<<endl<<"Record Deleted successfully";
	s--;
}
void members:: book_issue()
{
   date1 h1;
   struct date d;
   getdate(&d);
       int a=d.da_day;
       int b=d.da_mon;
       int l=d.da_year;
	int sn,bn;
	int found=0,c=0;
	clrscr();
	cout<<"________BOOK ISSUE _________";
	display_alls();
	cout<<endl<<"Enter The members's admission no.";
	cin>>sn;
	cout<<endl;   cout<<"ALL THE BOOKS AVAILBALE IN LIBRARY ARE:"<<endl;
	display_allb();
	fp.open("members.dat",ios::in|ios::out);
	fp1.open("book.dat",ios::in|ios::out);
	while(fp.read((char*)&st,sizeof(members)) && found==0)
	{
		if(st.retadmno()==sn)
		{
			found=1;
			if(st.rettoken()==0)
			{
				cout<<endl<<"Enter the book no. ";
				cin>>bn;
				while(fp1.read((char*)&bk,sizeof(book))&& c==0)
				{
					if(bk.retbookno()==bn)
					{
						bk.show_book();
						c=1;
						st.addtoken();
						st.getstbookno(bk.retbookno());
						int pos=-1*sizeof(st);
						fp.seekp(pos,ios::cur);
						fp.write((char*)&st,sizeof(members));
						cout<<endl<<" Book issued successfully"<<endl;
						h1.ext(a,b,l,15);
						cout<<endl<<"Please Note:"<<endl;
						cout<<" Write current date at back of book and submit within 15 days Or fine of Rs.2 for each day will be charged"<<endl;
					}
				}
				if(c==0)
					cout<<endl<<"Book no does not exist";
			}
			else
				cout<<endl<<"You have not returned the last book ";

		}
	}
	if(found==0)
		cout<<"member's  record not exist...";
	getch();
	fp.close();
	fp1.close();
}


void members::book_deposit()
{   clrscr();
    date1 h1;
    int sn,bn;
    int d,m,y;
    int sh=0,c=0,fine,bb=0;
    clrscr();
    cout<<endl<<"_________BOOK DEPOSIT_________"<<endl;
    display_alls();
    cout<<endl<<"Enter The members's admission no. who wants to return the book";
    cin>>sn;
    cout<<"Enter the date of return: "<<endl;
    cout<<"enter day:";
    cin>>d;
    while(!(d>0&&d<=31))
    {
    cout<<"Invalid entry!!! RE-ENTER.."; cin>>d;
    }

    cout<<"enter month:";
    cin>>m;
    while(!(m>0&&m<=12))
    {
    cout<<"Invalid entry!!! RE-ENTER.."; cin>>m;
    }

    cout<<"enter year";
    cin>>y;
    while(!(y>0&&y<2050))
    {
    cout<<"Invalid entry!!! RE-ENTER.."; cin>>y;
    }

    cout<<endl<<"The date of deposit is: "<<d<<"-"<<m<<"-"<<y;
    cout<<endl;
    fp.open("members.dat",ios::in|ios::out);
    fp1.open("book.dat",ios::in|ios::out);
    while(fp.read((char*)&st,sizeof(members)) && sh==0)
       {
	    if(st.retadmno()==sn)
	    {
		    sh=1;
		    if(st.rettoken()==1)
		    {
			while(fp1.read((char*)&bk,sizeof(book))&& c==0)
			{
			   if(bk.retbookno()==st.retstbookno())
			{       bk.show_book();
				c=1;
				bb=h1.df(d,m,y);
				cout<<"The actual date of return was: "<<::dd<<"-"<<::mm<<"-"<<::yy<<endl;
				cout<<endl<<"Book deposited after "<<bb<<" days from the actual date";
				cout<<bb;
				cout<<endl;
				   fine=(bb)*2;
				   cout<<endl<<"Fine to be deposited is Rs."<<fine;
					st.resettoken();
					int pos=-1*sizeof(st);
					fp.seekp(pos,ios::cur);
					fp.write((char*)&st,sizeof(members));
					cout<<endl<<" Book deposited successfully";
			}
		    }
		  if(c==0)
		    cout<<endl<<"Book no does not exist";
		      }
		 else
			cout<<endl<<"No book is issued..please check!!";
		}
	   }
      if(sh==0)
	cout<<endl<<"member's  record not exist..."<<endl;
	 fp.close();
	 fp1.close();
	 char g;
	 cout<<"Want to issue more? Y/N";
	 cin>>g;
	 if(g=='y'||g=='Y')
	 {
	 clrscr();
	 st.book_issue();
	 }

  }

//LIBRARIAN’S FUNCTION
void libraryans_corner()
{
	int heli;
	cout<<endl<<"________________LIBRARIAN's MENU_________________";
	cout<<endl<<"1.CREATE MEMBER RECORD";
	cout<<endl<<"2.DISPLAY ALL MEMBERS RECORD";
	cout<<endl<<"3.DISPLAY SPECIFIC MEMBER RECORD ";
	cout<<endl<<"4.MODIFY MEMBER RECORD";
	cout<<endl<<"5.DELETE MEMBER RECORD";
	cout<<endl<<"6.CREATE BOOK ";
	cout<<endl<<"7.DISPLAY ALL BOOKS ";
	cout<<endl<<"8.DISPLAY SPECIFIC BOOK ";
	cout<<endl<<"9.MODIFY BOOK ";
	cout<<endl<<"10.DELETE BOOK ";
	cout<<endl<<"11.BACK TO MAIN MENU";
	cout<<endl<<"Please Enter Your Choice (1-11) ";
	cin>>heli;
	switch(heli)
	{
		case 1: clrscr();  time();
			write_members(); delay(5000);
			break;
		case 2: clrscr();  time();
			display_alls();delay(5000);break;
		case 3:  clrscr(); time();
			display_sps(); delay(5000);
			break;
		case 4: clrscr(); time();
			modify_members();delay(5000);break;
		case 5: clrscr(); time();
			delete_members();delay(5000);break;
		case 6: clrscr(); time();
			write_book();delay(5000);break;
		case 7: clrscr(); time();
			display_allb();delay(5000);break;
		case 8: clrscr(); time();
			{
			display_spb();delay(5000);
			break;
			}
		case 9: clrscr();time();
			modify_book();delay(5000);break;
		case 10:clrscr(); time();
			delete_book();delay(5000);break;
		case 11: return;
		default:cout<<"invalid choice.please re-enter.";
	}
	libraryans_corner();
}

//THE INTRO FUNCTION
void info()
{
clrscr();
           date1 p;
	time();
textcolor(BLUE+BLINK);
textbackground(WHITE);
gotoxy(31,5);
cout<<"WELCOME TO";
gotoxy(28,7);
textcolor(BLACK+BLINK);
textbackground(WHITE);
cprintf("LIBRARY MANAGEMENT");
gotoxy(15,10);
textcolor(WHITE);
textbackground(BLACK);
cout<<"This project has the facility of mainaining records";
gotoxy(15,11);
cout<<"of BOOKS and MEMBERS. ";
gotoxy(15,14);
cout<<"One member can issue one book at a time.if he/she";
gotoxy(15,15);
cout<<"does not return book upto 15 days, he/she have to";
gotoxy(15,16);
cout<<"pay fine of Rs.2/- per day";
textcolor(BROWN+BLINK);
textbackground(WHITE);
gotoxy(20,18);
cprintf("MADE  BY:: HELI DESAI & SHIVANGI SINGH");
}

//THE MAIN FUNCTION
void main()
{       clrscr();
	info();
	int e;
	gotoxy(18,24);
	cout<<"enter '1' to conti.....";
	cin>>e;
	textcolor(WHITE);
	textbackground(BLACK);
           if(e==1)
	{
	char ch;
	do
	{  clrscr();
		time();
	       gotoxy(5,5);	cout<<endl<<"________________MAIN MENU_________________";
		gotoxy(5,7);	cout<<endl<<"01. LIBRARIYANS CORNER";
		gotoxy(5,9) ;	cout<<endl<<"02. ISSUE BOOK";
		gotoxy(5,11) ;	cout<<endl<<"03. RETURN BOOK";
		gotoxy(5,13) ;	cout<<endl<<"04. EXIT";
		gotoxy(5,15);	cout<<endl<<"Please Select Your Option (1-4)";
		cin>>ch;
		clrscr();
		switch(ch)
		{
			case '1':clrscr();  time();
				 libraryans_corner();
				 break;
			case '2':time(); st.book_issue();
				 break;
			case '3':time(); st.book_deposit();
				 break;
			case '4':exit(0);
			default :cout<<"invalid";
		}
	}while(ch!='4');
	 }
}
