// STUDENT RESULT MANAGEMENT SYSTEM
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string.h>
using namespace std;

class student
{
    private:
     char name[100],mom_name[100],dad_name[100],course[100],clg[100],rollno[100],result[100],dd[2],mm[2],yy[4];
    char grade;
    float percent,math,physics,chem,eg,cpro,bee;

    public:
      void intro();
      void insert();
      void update();
      void display();
      void deleterec(); 
};

void student::intro(){
    start:
     system("cls");
     cout<<"\t\t\t\t   _______________"<<endl;
     cout<<"\t\t\t\t   STUDENT RESULT MANAGEMENT SYSTEM   \t\t\t\t"<<endl;
     cout<<"\t\t\t\t   _______________"<<endl;
     cout<<"CHOOSE ANY ONE OF THE OPTIONS GIVEN BELOW"<<endl;
     cout<<"\t\t  1. CREATE NEW RECORD"<<endl;
     cout<<"\t\t  2. DISPLAY RECORD"<<endl;
     cout<<"\t\t  3. UPDATE RECORD"<<endl;
     cout<<"\t\t  4. DELETE RECORD"<<endl;
     cout<<"\t\t  5. EXIT"<<endl;
     cout<<"\t\t  CHOOSE OPTION : [ 1 / 2 / 3 / 4 / 5 ]"<<endl;
     cout<<"\t\t\t\t   _______________"<<endl;
     cout<<"\t\t\t\t   PLEASE ENTER CHOICE :"<<endl;

    
    int choice;
    char x;
    cin>>choice;
    switch(choice){
        case 1 :
        do{
            insert();
            cout<<"ADD NEW RECORD (y/n)";
            cin>>x;
        }while (x=='Y'||x=='y');
        break;

        case 2 :
         display();
         break;
        
        case 3 :
         update();
         break;
        
        case 4:
          deleterec();
          break;

		  case 5:
		  exit(0);


        default:
           cout<<"INVALID CHOICE!! PLEASE TRY AGAIN"<<endl;

    }
    cin>>x;
    goto start;
	cout<<"enter any key"<<endl;
}
void student::insert(){
    fstream file;
    system("cls");
    cout<<"_________________";
    cout<<"\t\t\t\t   Add student details :"<<endl;
    cout<<"\t\t\t\t   enter your name-->"<<endl;
    cin>> name;
    cout<<"\t\t\t\t   enter mother's name-->"<<endl;
    cin>>mom_name;
    cout<<"\t\t\t\t   enter father's name-->"<<endl;
    cin>>dad_name;
    cout<<"\t\t\t\t   enter college name-->"<<endl;
    cin>>clg;
    cout<<"\t\t\t\t   enter course name-->"<<endl;
    cin>>course;
    cout<<"\t\t\t\t   enter roll number-->"<<endl;
    cin>>rollno;
    cout<<"\t\t\t\t   enter date of birth(DD/MM/YY)->"<<endl;
    cin>>dd>>mm>>yy;
    
   file.open("studentresult.txt",ios::out|ios::app);
   file<<" "<<name<<" "<<mom_name<<" "<<dad_name<<" "<<clg<<" "<<course<<" "<<rollno<<" "<<dd<<" "<<mm<<" "<<yy<<" ";
   file.close();

}

void student::display()
{
    system("cls");
    fstream file;
    cout<<"__________________"<<endl;
    cout<<"STUDENT RECORD TABLE"<<endl;
    cout<<"__________________"<<endl;
    file.open("studentresult.txt",ios::in);
    if (!file){
          cout<<"\t\t\t\t data not found"<<endl;
          file.close();
    }else{
        file>>name>>mom_name>>dad_name>>clg>>course>>rollno>>dd>>mm>>yy;
        while (!file.eof()){
            cout<<"\n\t________________________________"<<endl;
            cout<<"\t |  STUDENT NAME  |\t MOTHER'S NAME |\t FATHER'S NAME |\t NAME OF COLLEGE |\t COURSE |\t  ROLL NO |\t DATE OF BIRTH"<<endl;
            cout<<"\t |  "<<name<<"    |\t"<<mom_name<<" |\t"<<dad_name<<" |\t"<<clg<<"        |\t"<<course<<"   |\t"<<rollno<<"    |\t"<<dd<<"/"<<mm<<"/"<<yy<<endl;

            file>>name>>mom_name>>dad_name>>clg>>course>>rollno>>dd>>mm>>yy;
        }
    }
     file.close();
    
	cout<<"enter any key"<<endl;
}

void student::update()
{
    fstream file;
    system("cls");
    cout << "_________________" << endl;
    cout << "\t\t\t\t   enter roll number to update record : " << endl;
    char roll[100];
    cin >> roll;
    int found = 0;
    file.open("studentresult.txt", ios::in | ios::out);
    while (!file.eof())
    {
        file >> name >> mom_name >> dad_name >> clg >> course >> rollno >> dd >> mm >> yy;
        if (strcmp(roll, rollno) == 0)
        {
            found = 1;
            cout << "\n\t\t\t\t   enter updated information of student : " << endl;
            cout << "\t\t\t\t   enter your name-->" << endl;
            cin >> name;
            cout << "\t\t\t\t   enter mother's name-->" << endl;
            cin >> mom_name;
            cout << "\t\t\t\t   enter father's name-->" << endl;
            cin >> dad_name;
            cout << "\t\t\t\t   enter college name-->" << endl;
            cin >> clg;
            cout << "\t\t\t\t   enter course name-->" << endl;
            cin >> course;
            cout << "\t\t\t\t   enter roll number-->" << endl;
            cin >> rollno;
            cout << "\t\t\t\t   enter date of birth(DD/MM/YY)->" << endl;
            cin >> dd >> mm >> yy;

            // update the record in the file
            file.seekp(file.tellg() - strlen(name) - strlen(mom_name) - strlen(dad_name) - strlen(clg) - strlen(course) - strlen(rollno) - strlen(dd) - strlen(mm) - strlen(yy) - 9);
            file << " " << name << " " << mom_name << " " << dad_name << " " << clg << " " << course << " " << rollno << " " << dd << " " << mm << " " << yy << " ";

            cout << "\t\t\t\t   record updated successfully" << endl;
            break;
        }
    }
    if (!found)
    {
        cout << "\t\t\t\t   record not found" << endl;
    }
    file.close();
    cout << "enter any key" << endl;
}

void student::deleterec()
{
    system("cls");
    fstream file, temp;
    char rollno[100];
    bool found = false;
    cout<<"_________________"<<endl;
    cout<<"\t\t\t\t   Delete student record :"<<endl;
    cout<<"\t\t\t\t   enter roll number to delete-->"<<endl;
    cin>>rollno;
    file.open("studentresult.txt", ios::in);
    temp.open("temp.txt", ios::out);
    file>>name>>mom_name>>dad_name>>clg>>course>>rollno>>dd>>mm>>yy;
    while(!file.eof()){
        if(strcmp(rollno, this->rollno) != 0){
            temp<<" "<<name<<" "<<mom_name<<" "<<dad_name<<" "<<clg<<" "<<course<<" "<<rollno<<" "<<dd<<" "<<mm<<" "<<yy<<" ";
        } else {
            found = true;
        }
        file>>name>>mom_name>>dad_name>>clg>>course>>rollno>>dd>>mm>>yy;
    }
    file.close();
    temp.close();
    remove("studentresult.txt");
    rename("temp.txt", "studentresult.txt");
    if(found){
        cout<<"Record deleted successfully"<<endl;
    } else {
        cout<<"Record not found"<<endl;
    }
    cout<<"Enter any key to continue"<<endl;
}


int main(){
    student s;
    s.intro();
    return 0;
}