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

void writebook()
{
	char ch;
	fp.open("book.dat",ios::out|ios::app);//write and append data
	do{
		clrscr();
		bk.createbook();
		fp.write((char*)&bk,sizeof(book));//size of class
		cout<<"\n\nDo you want to add more record...(y/n?) ";
		cin>>ch;
	}while(ch=='y'||ch=='Y');
	fp.close();
}

void writestudent()
{
	char ch;
	fp.open("student.dat",ios::out|ios::app);//write and append data
	do{
		clrscr();
		st.createstudent();
		fp.write((char*)&st,sizeof(student));//size of class
		cout<<"\n\nDo you want to add more record...(y/n?) ";
		cin>>ch;
	}while(ch=='y'||ch=='Y');
	fp.close();
}
 void displayspb(char n[])
 {
	 cout<<"\nBOOK DETAILS\n";
	 int flag=0;//book not found
	 fp.open("book.dat",ios::in);//read data
	 while(fp.read((char *)&bk,sizeof(book)))
	 {
		 if(strcmpi(bk.retbno(),n)==0)//not case sensitive
		 {
			  bk.showbook();
			  flag=1;
		 }
	 }
	 fp.close();
	 if(flag==0)//book not found
	 {
		 cout<<"\n\nBook does not exist";
         		 
	 }
	 getch();
}
 void displaysps(char n[])
 {
	 cout<<"\nSTUDENT DETAILS\n";
	 int flag=0;//student not found
	 fp.open("student.dat", ios::in);//read data
	 while(fp.read((char *)&st,sizeof(student)))
	 {
		 if(strcmpi(st.retadmno(),n)==0)//not case sensitive
		 {
			  st.showstudent();
			  flag=1;
		 }
	 }
	 fp.close();
	 if(flag==0)//student not found
	 {
		 cout<<"\n\nStudent does not exist";
         		 
	 }
	 getch();
}
void modifybook()
{
	char n[6];
	int found=0;//seach book of given data
	clrscr();
	cout<<"\n\nMODIFY BOOK RECORD...";
	cout<<"\n\nEnter the book no. ";
	cin>>n;
	fp.open("book.dat",ios::in|ios::out);
	while(fp.read((char*)&bk,sizeof(book)) && found==0)
	{
		if(strcmpi(bk.retbno(),n)==0)
		{
			bk.showbook();
			cout<<"\nEnter the new details book";
			bk.modifybook();
			int pos=-1*sizeof(bk);
			fp.seekp(pos,ios::cur);//back from current position
			fp.write((char *)&bk,sizeof(book));
			cout<<"\n\nRecord Updated";
			found=1;
		}
			
	}
	fp.close();
	if(found==0)
	{
		cout<<"\n\nRecord Not Found";
		
	}
	getch();//press key to get out	
}
 void modifystudent()
{
	char n[6];
	int found=0;//seach book of given data
	clrscr();
	cout<<"\n\nMODIFY STUDENT RECORD...";
	cout<<"\n\nEnter the Admission no. ";
	cin>>n;
	fp.open("student.dat",ios::in|ios::out);
	while(fp.read((char*)&st,sizeof(student)) && found==0)
	{
		if(strcmpi(st.retadmno(),n)==0)
		{
			st.showstudent();
			cout<<"\nEnter the new details of student";
			st.modifystudent();
			int pos=-1*sizeof(st);
			fp.seekp(pos,ios::cur);//back from current position
			fp.write((char *)&st,sizeof(student)); 
			cout<<"\n\nRecord Updated";
			found=1;
		}
			
	}
	fp.close();
	if(found==0)
	{
		cout<<"\n\nRecord Not Found";
		
	}
	getch();//press key to get out	
}

