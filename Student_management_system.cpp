#include<iostream>
#include<fstream>
#include<conio.h>
#include<cstring>
#include<cstdio>
using namespace std;
class student{
  private:
      char name[25],roll_no[10],branch[4],phone_number[11],email_id[50],college_name[50];
public:
    void showdata();
    student(){}
    student(string name_,string roll,string college,string br,string email,string phone){
       strcpy(name,name_.c_str());
       strcpy(roll_no,roll.c_str());
       strcpy(college_name,college.c_str());
       strcpy(branch,br.c_str());
       strcpy(email_id,email.c_str());
       strcpy(phone_number,phone.c_str());

    }
    string rollno(){
     return roll_no;
    }

};
 void Insert(){
     string name_,roll,college,br,email,phone;
     cout<<"   \n\n\t\t\t\t\tENTER STUDENT NAME: " ;
cin.ignore();
getline(cin,name_);
cout<<"   \n\n\t\t\t\t\tENTER STUDENT ROLL_NO: " ;
getline(cin,roll);
cout<<"   \n\n\t\t\t\t\tENTER COLLEGE NAME: " ;
getline(cin,college);
cout<<"   \n\n\t\t\t\t\tENTER BRANCH: " ;
getline(cin,br);
cout<<"   \n\n\t\t\t\t\tENTER STUDENT EMAIL_ID: " ;
getline(cin>>ws,email);
cout<<"   \n\n\t\t\t\t\tENTER STUDENT PHONE_NUMBER: " ;
getline(cin,phone);
student s(name_,roll,college,br,email,phone);
fstream file;
file.open("student.bin",ios::app|ios::binary);
file.write((char*)&s,sizeof(s));
file.close();
}
void view(){
  ifstream file;
  student s;
  int n=1;
  file.open("student.bin",ios::in);
  while(file.read((char*)&s,sizeof(s))){
    cout<<"\t\t\t STUDENT NUMBER "<<n<<endl;
    s.showdata();
    n++;
  }
  file.close();
  }
void modify(){
    int p,y=0;
 fstream file("student.bin",ios::out|ios::in|ios::binary);
 string roll;
 cout<<"   \n\n\t\t\t\t\tENTER THE ROLL NUMBER YOU WANT TO MODIFY: ";
 cin>>roll;
 student s;
 while(file.read((char*)&s,sizeof(s))){
     p=file.tellg();
    if(roll==s.rollno()){
            y=1;
        s.showdata();
        string name_,roll,college,br,email,phone;
     cout<<"   \n\n\t\t\t\t\tENTER STUDENT NAME: " ;
cin.ignore();
getline(cin,name_);
cout<<"   \n\n\t\t\t\t\tENTER STUDENT ROLL_NO: " ;
getline(cin,roll);
cout<<"   \n\n\t\t\t\t\tENTER COLLEGE NAME: " ;
getline(cin,college);
cout<<"   \n\n\t\t\t\t\tENTER BRANCH: " ;
getline(cin,br);
cout<<"   \n\n\t\t\t\t\tENTER STUDENT EMAIL_ID: " ;
getline(cin>>ws,email);
cout<<"   \n\n\t\t\t\t\tENTER STUDENT PHONE_NUMBER: " ;
getline(cin,phone);
student s(name_,roll,college,br,email,phone);
        file.seekg(p-sizeof(s));
        file.write((char*)&s,sizeof(s));
        break;
    }
}
if(y){
     cout<<"   \n\n\t\t\t\t\tSUCCESSFULLY MODIFIED...";
}
else{
     cout<<"   \n\n\t\t\t\t\tNO RECORD FOUND...";
}
file.close();
}
void Search(string roll){
    ifstream file("student.bin",ios::in|ios::binary);
student s;
int y=0;
 while(file.read((char*)&s,sizeof(s))){
    if(roll==s.rollno()){
        s.showdata();
        y=1;
        break;
    }
 }
 if(y==0){
    cout<<"NO STUDENT RECORD FOUND...";
 }
file.close();
}
void Delete(){
 fstream file;
 file.open("student.bin",ios::in|ios::out|ios::binary);
 ofstream f("temp.bin",ios::binary|ios::out);
 student s;
 string roll;
 cout<<"   \n\n\t\t\t\t\tENTER THE ROLL NUMBER YOU WANT TO DELETE: ";
 cin>>roll;
 int y=0;
 while(file.read((char*)&s,sizeof(s))){
   if(roll!=s.rollno()){
        f.write((char*)&s,sizeof(s));
       }
    else{
        y=1;
    }
}
f.close();
file.close();
remove("student.bin");
rename("temp.bin","student.bin");
if(y){
    cout<<"   \n\n\t\t\t\t\tSUCCESSFULLY DELETED...";
}
else{
    cout<<"   \n\n\t\t\t\t\tNO RECORD FOUND...";
}
}
void student::showdata(){

    cout<<"\t\t\tNAME: "<<name<<endl;
    cout<<"\t\t\tROLL NUMBER: "<<roll_no<<endl;
    cout<<"\t\t\tCOLLEGE: "<<college_name<<endl;
    cout<<"\t\t\tBRANCH: "<<branch<<endl;
    cout<<"\t\t\tEMAIL_ID: "<<email_id<<endl;
    cout<<"\t\t\tPHONE NUMBER: "<<phone_number<<endl;
    cout<<endl;
}
void menu(){
    int choice;
    string roll;
    menustart:
   system("cls");
   cout<<"\n\t\t\t\t\t\t\t\t\t\t   MENU"<<endl;
   cout<<"\t\t\t\t\t\t\t\t\t\t   ----"<<endl;
   cout<<"\t\t\t\t\t\t\t\t 1) ADD STUDENT RECORD "<<endl;
   cout<<"\t\t\t\t\t\t\t\t 2) VIEW  STUDENT RECORD "<<endl;
   cout<<"\t\t\t\t\t\t\t\t 3) MODIFY STUDENT RECORD "<<endl;
   cout<<"\t\t\t\t\t\t\t\t 4) SEARCH STUDENT RECORD "<<endl;
   cout<<"\t\t\t\t\t\t\t\t 5) DELETE STUDENT RECORD "<<endl;
   cout<<"\t\t\t\t\t\t\t\t 6) EXIT "<<endl;

   cout<<"   \n\n\t\t\t\t\tENTER YOUR CHOICE [OPTION: 1/2/3/4/5/6]:";
   cin>>choice;
   switch(choice){
case 1:
    char x;
    do{
Insert();
cout<<"   \n\n\t\t\t\t\tDO YOU WANT TO CONTINUE[Y/N]: " ;
cin>>x;
    }while(x=='y'||x=='Y');
    break;
case 2:
    view();
    break;
case 3:
    modify();
    break;
case 4:
    cout<<"   \n\n\t\t\t\t\tENTER THE ROLL NUMBER YOU WANT TO SEARCH: ";
    cin>>roll;
    Search(roll);
    break;
case 5:
    Delete();
    break;
case 6:
    exit(0);
    break;
default:
    cout<<"   \n\n\t\t\t\t\tINVALID CHOICE TRY AGAIN..."<<endl;
    break;
   }
   getch();
   goto menustart;
}





int main(){

   cout<<"\t\t\t\t\t\t\t\t\t ------------------------ "<<endl;
   cout<<"\t\t\t\t\t\t\t\t\t |STUDENT MANAGEMENT APP| "<<endl;
   cout<<"\t\t\t\t\t\t\t\t\t ------------------------ "<<endl;
   menu();
}



