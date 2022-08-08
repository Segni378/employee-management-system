#include<iostream>
#include<fstream>
#include<cstring>
#include<string>
#include<windows.h>
#include<conio.h>
#include<iomanip>
using namespace std;


class employee{						//class of employee
	public: 
	string fname, lname, password;
	char sex;
	long ID, salary;
};

// //////////////////// add 

void add(class employee &emp)			//hiring function
{
	fstream data;
	data.open("data.txt", ios::out | ios::app);																			// open data in output and append mode
	data<<emp.ID<<" "<<emp.fname<<" "<<emp.lname<<" "<<emp.password<<" "<<emp.sex<<" "<<emp.salary<<"\n";				//write the data on the employee class to data.txt
	data.close();
	cout<<" \n Entry added successfully!! \n";
}

// //////////////////// Display 

void display(class employee &emp){																							// display the employee list
	fstream data;
	string store;
	for(int i=0; i<120; i++)cout<<"*";
	cout<<"\n* \t \t \t \t \t \t \t EMPLOYEE LIST \t \t \t \t \t \t \t*\n";
	for(int i=0; i<120; i++)cout<<"*";
	cout<<setw(15)<<"ID"<<setw(20)<<"F.Name"<<setw(25)<<"L.NAME"<<setw(25)<<"SEX"<<setw(25)<<"SALARY"<<"\n";
	for(int i=0; i<120; i++){
		cout<<"-";
	}
	data.open("data.txt",ios::in);																// open data.txt in input mode
	while(data>>emp.ID>>emp.fname>>emp.lname>>emp.password>>emp.sex>>emp.salary){																		// read line by line
cout<<setw(15)<<emp.ID<<setw(20)<<emp.fname<<setw(25)<<emp.lname<<setw(25)<<emp.sex<<setw(25)<<emp.salary<<"\n";	
}
cout<<" \n Entry displayed successfully!! \n";
	getch();
}

// //////////////////// searches 

void search(class employee &emp){																		// search from the text file
	fstream data;
	data.open("data.txt", ios::in);
	int srch;	
	cout<<"Enter ID to search: ";																		// enter the ID number
	cin>>srch;
	data.seekg (0, ios::beg);																			// moves the pointer to the beggining 
	
	bool found = false;																					// boolean to check the status of search 
	while(!found){																					// while it is true ...
	data>> emp.ID >> emp.fname >> emp.lname>> emp.password>>emp.sex>>emp.salary;					//copy the strings separated by space to the respective employee data
	if(emp.ID == srch){																					//check if the entered ID and the current ID is the same
	//cout<<emp.ID<<" "<<emp.fname<<" "<<emp.lname<<" "<<emp.password<<" "<<emp.sex<<" "<<emp.salary;		// this displays the data of the employee
	cout<<setw(15)<<"ID"<<setw(20)<<"F.Name"<<setw(25)<<"L.NAME"<<setw(25)<<"SEX"<<setw(25)<<"SALARY"<<"\n";
	cout<<setw(15)<<emp.ID<<setw(20)<<emp.fname<<setw(25)<<emp.lname<<setw(25)<<emp.sex<<setw(25)<<emp.salary<<"\n";
	found = true;																						// boolean changes to true and while loop stops
	}
	if(data.eof()&&found==false){
		cout<<"\n Error! ID Not found \n ";
		break;
	}}
	data.close(); 
	cout<<" \n Search ended successfully!! \n"; 
}

// //////////////////// copies from datanew.txt to data.txt 

void replacetxt() {						// replaces the data with the modified data
	fstream data, data2;
	string temp;
	data.open("data.txt", ios::out);
	data2.open("datanew.txt", ios::in);
	while(!data2.eof()) {
	getline(data2, temp);
	data<<temp<<"\n";
	
	}
	data.close();
	data2.close();
}

// //////////////////// editing data

void edit(class employee &emp)				// modify the data
{
	int choice;
	cout<<"\n Enter ID";
	cin>>choice;
	
	fstream data,data2;
	data.open("data.txt", ios::in);
	data2.open("datanew.txt", ios::out);
	bool found=false;
	
	while(data>>emp.ID>>emp.fname>>emp.lname>>emp.password>>emp.sex>>emp.salary){			//reads 
		
		if(emp.ID == choice && found==false){																	// if the ID is the same with the entered
			cout<<"Enter the new ID: ";
			cin>>emp.ID;
			cout<<"Enter the new First name";
			cin>>emp.fname;
			cout<<"Enter the new Last name";
			cin>>emp.lname;
			cout<<"Enter the new sex";
			cin>>emp.sex;																									// replaces the modified data on the memory
			data2<<emp.ID<<" "<<emp.fname<<" "<<emp.lname<<" "<<emp.password<<" "<<emp.sex<<" "<<emp.salary<<"\n"; // writes to a second txt file
			found = true;
		}
		else
		data2<<emp.ID<<" "<<emp.fname<<" "<<emp.lname<<" "<<emp.password<<" "<<emp.sex<<" "<<emp.salary<<"\n";			// writes the value to a second txt file
}
	data.close();
	data2.close();
	replacetxt();
	
cout<<" \n Data modified successfully!! \n";
	}
	
	// //////////////////// firing employee 
	
void del(class employee &emp)				// modify the data
{
	int choice;
	cout<<"\n Enter ID";
	cin>>choice;
	
	fstream data,data2, data3;
	data.open("data.txt", ios::in);
	data2.open("datanew.txt", ios::out);
	bool found=false;
	
	while(data>>emp.ID>>emp.fname>>emp.lname>>emp.password>>emp.sex>>emp.salary){
		
		if(emp.ID == choice && found==false){
			data3.open("removed.txt", ios::out|ios::in|ios::app);
			data3<<emp.ID<<" "<<emp.fname<<" "<<emp.lname<<" "<<emp.password<<" "<<emp.sex<<" "<<emp.salary<<"\n";
			cout<<" \n Data deleted successfully!! \n";																	// if the ID is the same with the entered
			found = true;
			data3.close();
		}
		else{
		data2<<emp.ID<<" "<<emp.fname<<" "<<emp.lname<<" "<<emp.password<<" "<<emp.sex<<" "<<emp.salary<<"\n";			// writes the value to a second txt file
}}
	data.close();
	data2.close();
	replacetxt();}	

// //////////////////// Read messages

void message(){
fstream msg;
string temp;
msg.open("messages.txt", ios::in);
while(getline(msg, temp))
cout<<temp<<"\n";
msg.close();

cout<<" \n Message shown successfully!! \n";
}

// //////////////////// send broadcast message 

void send(){
	fstream msg;
	string message;
	string subj;
	msg.open("messages.txt", ios::out | ios::app);
	cout<<"Enter the Message: ";
	cin>>subj;
	getline(cin, message);	
	msg<<"************************************** \n";
	msg<<subj<<message<<"\n";
	msg<<"************************************** \n";
	msg.close();
	
	cout<<"\n Message sent successfully!! \n";
}

// //////////////////// Shows information of employee

void info(class employee &emp){
	string temp, pass;
	long ID;
	fstream data;
	cout<<"Enter your ID: ";
	cin>>ID;
	cout<<"Enter your Password: ";
	cin>>pass;
	
	data.open("data.txt", ios::in);
	data.seekg (0, ios::beg);		
	bool found = false;			

	while(data>> emp.ID >> emp.fname >> emp.lname>> emp.password >> emp.sex>> emp.salary){
	if(emp.ID == ID && emp.password == pass){				
		found = true;
		cout<<setw(15)<<"ID"<<setw(20)<<"F.Name"<<setw(25)<<"L.NAME"<<setw(25)<<"SEX"<<setw(25)<<"SALARY"<<"\n";
		cout<<setw(15)<<emp.ID<<setw(20)<<emp.fname<<setw(25)<<emp.lname<<setw(25)<<emp.sex<<setw(25)<<emp.salary<<"\n";
		break;
}
else 
continue;}}

// //////////////////// Sallary raise 

void raise(class employee &emp){ 
	int choice;
	cout<<"\n Enter ID";
	cin>>choice;
	
	fstream data,data2;
	data.open("data.txt", ios::in);
	data2.open("datanew.txt", ios::out);
	bool found=false;
	
	while(data>>emp.ID>>emp.fname>>emp.lname>>emp.password>>emp.sex>>emp.salary){
		
		if(emp.ID == choice && found==false){																	// if the ID is the same with the entered
			cout<<"Enter the new salary ";
			cin>>emp.salary;																									// replaces the modified data on the memory
			data2<<emp.ID<<" "<<emp.fname<<" "<<emp.lname<<" "<<emp.password<<" "<<emp.sex<<" "<<emp.salary<<"\n";			 // writes to a second txt file
			found = true;
		}
		else
		data2<<emp.ID<<" "<<emp.fname<<" "<<emp.lname<<" "<<emp.password<<" "<<emp.sex<<" "<<emp.salary<<"\n";			// writes the value to a second txt file
}
	data.close();
	data2.close();
	replacetxt();
	
cout<<" \n Data modified successfully!! \n";
}

// //////////////////// Retirement calculator
void restore(){
	fstream data,data2;
	long Id;
	employee emp;
	data.open("removed.txt",ios::in);
	if(!data.is_open()){
		cout<<"couldn't open the required text file.\n";
	}
	else{
	
	data2.open("datanew.txt",ios::out|ios::app);
	cout<<"Enter the Id number of the fired employee to be restored to the list:\n";
	cin>>Id;
	bool ba =false;
	while(data>>emp.ID>>emp.fname>>emp.lname>>emp.password>>emp.sex>>emp.salary)
	{
		
		
		if(emp.ID==Id){
			data2<<emp.ID<<" "<<emp.fname<<" "<<emp.lname<<" "<<emp.password<<" "<<emp.sex<<" "<<emp.salary<<endl;
			break;
		}
		else if(data.eof()&&ba==false){
			cout<<"There wasn't any with this Id number.\n";
			
		}
		
		
	}
} 
 data.close();
	data2.close();
	replacetxt();
	
}
void retirement(int y){
	int retirement;
	retirement= 2019- y;
	if(retirement>18 && retirement<65){
	cout<<65-retirement <<" Years left until retirement \n ";}
	else if(retirement>65)
	cout<<"\n You are already Retired.\n ";
	else
	cout<<"\n Too young to be hired! try entering your age again";
}

// //////////////////// Counter  

int counter()
{
	int c=0;
	string temp;
	fstream data;
	data.open("data.txt", ios::in);
	while(getline(data, temp)){
	c++;
	}
	data.close();
	return c;
}

// //////////////////// for dashboard 

void dashboard(class employee &emp){
fstream data;
long store=0;
data.open("data.txt", ios::in);
for(int i=0; i<120; i++)
cout<<"-";
cout<<"\t \t \t \t \t \t \t INFORMATION DASHBOARD \t \t \t \t \t \t \t\n";
for(int i=0; i<120; i++)
cout<<"-";
cout<<"\n\t \t \t \t There are "<<counter()-1<<" employees total in this company \n";
while(data>>emp.ID>>emp.fname>>emp.lname>>emp.password>>emp.sex>>emp.salary){
	store+=emp.salary;
}
cout<<"\n\t \t \t \t The total expense of the company on salary is: "<<store;
data.close();
}

// //////////////////// Sorting 

void sort(class employee &emp){
	fstream data;
	data.open("data.txt", ios::in | ios::out);
	int c = counter()-1;
	int i=0;
	employee temp, aemp[c];
	
	while(data>>emp.ID>>emp.fname>>emp.lname>>emp.password>>emp.sex>>emp.salary){
		aemp[i]=emp;
		i++;
	}

	for(i=0; i<c; i++){
	for(int j=0; j<c-1; j++)
	if(aemp[j+1].ID<aemp[j].ID){
		temp=aemp[j+1];
		aemp[j+1]=aemp[j];
		aemp[j]=temp;
	}}
	cout<<setw(15)<<"ID"<<setw(20)<<"F.Name"<<setw(25)<<"L.NAME"<<setw(25)<<"SEX"<<setw(25)<<"SALARY"<<"\n";
	for(int j=0; j<c; j++){
		cout<<setw(15)<<aemp[j].ID<<setw(20)<<aemp[j].fname<<setw(25)<<aemp[j].lname<<setw(25)<<aemp[j].sex<<setw(25)<<aemp[j].salary<<"\n";
		data<<aemp[j].ID<<" "<<aemp[j].fname<<" "<<aemp[j].lname<<" "<<aemp[j].sex<<" "<<aemp[j].salary<<endl;
	}
		
	data.close();
}

int main(){
	
	system("color 06");
	employee emp;
	int opt1, opt2;
	string pass;
	char c;
	
cout<<"\t\t\t      ****              ****         **********   **************  **        **\n";Sleep(100);
cout<<"\t\t\t    ********          ********     ************** **************  **        **\n";Sleep(100);
cout<<"\t\t\t   ***    ***        ***    ***    ***        *** **    **    **  **        **\n";Sleep(100);
cout<<"\t\t\t  ***      ***      ***      ***   ***                  **        **        **\n";Sleep(100);
cout<<"\t\t\t ***        ***    ***        ***   ************        **        **        **\n";Sleep(100);
cout<<"\t\t\t****************  ****************   ************       **        **        **\n";Sleep(100);
cout<<"\t\t\t****************  ****************             ***      **        **        **\n";Sleep(100);
cout<<"\t\t\t**            **  **            ** ***         ***      **        ************\n";Sleep(100);
cout<<"\t\t\t**            **  **            **  *************      ****        ********** \n";Sleep(100);
cout<<"\t\t\t**            **  **            **    *********        ****          *******  \n";Sleep(100);
Sleep(1000);
cout<<"\t\t\tProgramming II Project \n\n ";
cout<<"\t\t\tSubmitted to Tr. Eleni \n";
getch();
system("cls");

	
	
	
do {
	system("cls");
	for(int i=0; i<120; i++)cout<<"*";
	cout<<"\n* \t \t \t \t \t \t EMPLOYEE MANAGMENT SYSTEM \t \t \t \t \t \t*\n";
	for(int i=0; i<120; i++)cout<<"*";
	dashboard(emp);
	cout<<"\n \n Choose your account: \n \t \t \t 1. EMPLOYEE \t \t \t 2. HUMAN RESOURCES \n \n \t \t \t 3. ACCOUNTANT \t \t \t 4. MANAGER \n \n \t \t \t 5. COMMUNICATION MANAGER \t 6. SYSTEM ADMIN \n \n \t \t \t 7. EXIT \n";		//choose account
	cin>>opt1;
	int d,m,y;
	switch(opt1){
	case 1 :
			system("cls");
			for(int i=0; i<120; i++)cout<<"*";
			cout<<"\n* \t \t \t \t \t \t \t EMPLOYEE \t \t \t \t \t \t \t*\n";
			for(int i=0; i<120; i++)cout<<"*";
			cout<<" 1. VIEW MESSAGE \n 2. SEE INFORMATION \n 3. CHECK RETIREMENT DATE \n 4. BACK \n";
			cin>>opt2;
			if(opt2 == 1){
			message();	
			}
			else if(opt2 == 2){
			info(emp);
			}
			else if(opt2==3){
			system("cls");
			bday: 
			cout<<"Enter your Date of birth(dd/mm/yy): ";
			cin>>d;
			cin.get();
			cin>>m;
			cin.get();
			cin>>y;
			if(y<2019 && y>1930)retirement(y);
			else{ cout<<"Wrong Entry \n";
			goto bday;}
			}
			else{
				cout<<"\n Returning... \n";
			}
			break;
		
	case 2:
			system("cls");
			for(int i=0; i<120; i++)cout<<"*";
			cout<<"\n* \t \t \t \t \t \t HUMAN RESOURCES \t \t \t \t \t \t*\n";
			for(int i=0; i<120; i++)cout<<"*";
			cout<<"Enter password: ";
			cin>>pass;
		if(pass=="hr"){
	
		do{
		cout<<" 1. HIRE EMPLOYEE \n 2. FIRE EMPLOYEE \n 3. Restore fired employee\n 4. BACK \n";
			cin>>opt2;
			if(opt2==1 )
			{
	cout<<"Input ID: ";							// input data on the employee class
	cin>>emp.ID;
	cout<<"Input First name: ";
	cin>>emp.fname;
	cout<<"Input last name ";
	cin>>emp.lname;
	cout<<"Input your password ";
	cin>>emp.password;
	cout<<"Input your sex ";
	cin>>emp.sex;
	cout<<"Input your salary ";
	cin>>emp.salary;	
			add(emp);
		}
			else if(opt2==2)
			del(emp);
			else if (opt2==3)
			restore();
			else{
				cout<<"\n Returning... \n";
				break;
			}}
		while(true);		}
		if(pass!="hr"){
			cout<<"Wrong Password. \n Returning... \n ";
			
			break;}
			break;
	
	case 3 :
			system("cls");
			for(int i=0; i<120; i++)cout<<"*";
	cout<<"\n* \t \t \t \t \t \t ACCOUNTANT \t \t \t \t \t \t*\n";
	for(int i=0; i<120; i++)cout<<"*";
			cout<<"Enter password: ";
			cin>> pass;
			
			if(pass=="ac"){
			do {
			cout<<" 1. MODIFY EMPLOYEE INFORMATION \n 2. DISPLAY EMPLOYEE LIST \n 3. SEARCH \n 4. SORT \n 5. BACK \n";
			cin>>opt2;
			system("cls");
			if(opt2 == 1)
			edit(emp);
			else if(opt2 == 2){
			system("cls");
			display(emp);
		}
			else if(opt2 == 3)
			search(emp);
			else if(opt2 == 4)
			sort(emp);
			
			else{
			cout<<"\n Returning... \n";
			break;
			}}
			while(true);
			break;
			}
			if(pass!="ac"){
			cout<<"Wrong Password. \n Returning... \n";
			break;}
			break;
	
	case 4: 
			system("cls");
			for(int i=0; i<120; i++)cout<<"*";
	cout<<"\n* \t \t \t \t \t \t MANAGER \t \t \t \t \t \t*\n";
	for(int i=0; i<120; i++)cout<<"*";
			cout<<"Enter password: ";
			cin>>pass;
			
			if(pass=="man"){
				system("cls");
			cout<<" 1. LIST EMPLOYEES \n 2. SALARY RAISE \n 3. EXIT \n";
			cin>>opt2;
			if(opt2==1){
			system("cls");
			display(emp);}
			else if(opt2==2)
			raise(emp);
			else{
				cout<<"\n RETURNING... \n ";
				break;
			}}
			if(pass != "man"){
				cout<<"Wrong Password. \n Returning... \n";
				break;
			}
			break;
	case 5:
			system("cls");
			for(int i=0; i<120; i++)cout<<"*";
	cout<<"\n* \t \t \t \t \t \t COMMUNICATON MANAGER \t \t \t \t \t \t*\n";
	for(int i=0; i<120; i++)cout<<"*";
			cout<<"Enter password: ";
			cin>>pass;
			
			if(pass=="cm"){
			cout<<" 1. BROADCAST MESSAGE \n 2. EXIT \n";
			cin>>opt2;
			if(opt2==1)
			send();
			else{
				cout<<"\n RETURNING... \n ";
				break;}
			}
			
			if(pass!= "cm"){
				cout<<"Wrong Password. \n Returning... \n";
				break;
			}
			break;	
	case 6: 
			system("cls");
			for(int i=0; i<120; i++)cout<<"*";
	cout<<"\n* \t \t \t \t \t \t SYSTEM ADMINISTRATOR \t \t \t \t \t \t*\n";
	for(int i=0; i<120; i++)cout<<"*";
			cout<<"Enter password: ";
			cin>>pass;
			
			if(pass=="ad"){
			cout<<" 1. ADD EMPLOYEE \n 2. LIST EMPLOYEES \n 3. SEARCH \n 4. BROADCAST MESSAGE \n 5. FIRED EMPLOYEES \n 6. EXIT \n";
			cin>>opt2;
			if(opt2==1)
				{
	cout<<"Input ID: ";							// input data on the employee class
	cin>>emp.ID;
	cout<<"Input First name: ";
	cin>>emp.fname;
	cout<<"Input last name ";
	cin>>emp.lname;
	cout<<"Input your password ";
	cin>>emp.password;
	cout<<"Input your sex ";
	cin>>emp.sex;
	cout<<"Input your salary ";
	cin>>emp.salary;	
			add(emp);}
			else if(opt2==2)
			display(emp);
			else if(opt2==3)
			search(emp);
			else if(opt2==4)
			send();
			else if(opt2==5)
			{string temp;
				fstream data3;
				data3.open("removed.txt", ios::in);
				cout<<setw(15)<<"ID"<<setw(20)<<"F.Name"<<setw(25)<<"L.NAME"<<setw(25)<<"SEX"<<setw(25)<<"SALARY"<<"\n";
				while(data3>>emp.ID>>emp.fname>>emp.lname>>emp.password>>emp.sex>>emp.salary){
				
		//	data3<<emp.ID<<" "<<emp.fname<<" "<<emp.lname<<" "<<emp.password<<" "<<emp.sex<<" "<<emp.salary<<"\n";
			
			cout<<setw(15)<<emp.ID<<setw(20)<<emp.fname<<setw(25)<<emp.lname<<setw(25)<<emp.sex<<setw(25)<<emp.salary<<"\n";
				}
				data3.close();
			}
			else{
				cout<<"\n RETURNING... \n ";
				break;}
			}
			
			if(pass!= "ad"){
				cout<<"Wrong Password. \n Returning... \n";
				break;
			}
			break;
			
	case 7: break;
	default:{
			cout<<"\n Try Again!! \n ";
			break;
		}}
		cout<<"Continue? Y/N  ";
		cin>>c;
}		
while(c=='Y'|| c=='y');

return 0;
}
