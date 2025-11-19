#include <iostream.h>
#include<conio.h>
#include<iomanip.h>//input-output manipulator
#include<stdlib.h> 
#include<string.h>
#include<stdio.h>
#include<fstream.h>
class book
{
	char bno[6];//bookno.
	char bname[50];//bookname
	char aname[20];//authorname
	public:
	void createbook()
	{
		cout<<"\nNEW BOOK ENTRY...\n";
		cout<<"\nENTER BOOK NO.";
		cin>>bno;
		cout<<"\nENTER BOOK NAME";
		gets(bname);//enables enter with space
		cout<<"\nENTER AUTHOR NAME";
		gets(aname);
		cout<<"\n\n\nBook Created..";
	}
	void showbook()
	{
		cout<<"\nBook Number: "<<bno;
		cout<<"\nBook Name: ";
		puts(bname);
		cout<<"\nBook Author Name: ";
		puts(aname);
	}
	void modifybook()
	{
		cout<<"\nBook Number: "<<bno;
		cout<<"\nModify Book Name :";
		gets(bname);
		cout<<"\nModify Author's Name :";
		gets(aname);
		
	}
	
	char* retbno()//string return
	{
		return bno;
	
	}
	void report()
	{
		cout<<bno<<setw(30)<<bname<<setw(30)<<aname<<endl;
	}
};//class ends here


class student
{
	char admno[6];//admission no.
	char name[20];
	char stbno[6];// student book no 
	int token;//total book of student
	public:
	void createstudent()
	{
		clrscr();
		cout<<"\nNEW STUDENT ENTRY...\n";
		cout<<"\nEnter The Admission No. ";
		cin>>admno;
		cout<<"Enter The Student Name ";
		gets(name);
		token=0;
		stbno[0]='\0';
		cout<<"\n\nStudent Record Created...";
	}
	void showstudent()
	{
		cout<<"\nAdmission Number : "<<admno;
		cout<<"\nStudent Name : ";
		puts(name);
		cout<<"\nNo of Book Issued : "<<token;
		if(token==1)
		{
			cout<<"\nBook Number "<<stbno;
		}
	}
	void modifystudent()
	{
		cout<<"\nAdmission No. "<<admno;
		cout<<"\nModify Student Name : ";
		gets(name);
	}
	char* retadmno()
	{
		return admno;
	}
	char* retstbno()
	{
		return stbno;
	}
	int rettoken()
	{
		return token;
	}
	void addtoken()
	{
		token=1;
	}
	void resettoken()
	{ 
	token=0;
	}
	void getstbno(char t[])
	{
		strcpy(stbno,t);
	}
	void report()
	{
		cout<<"\t"<<admno<<setw(20)<<name<<setw(10)<<token<<endl ;
	}
};//class ends here
fstream fp,fp1;//object
book bk;//book class object
student st;//student class object
