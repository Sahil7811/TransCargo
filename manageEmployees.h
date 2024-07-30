#include<bits/stdc++.h>
#include<windows.h>
using namespace std;

int last=0;
// HANDLE col=GetStdHandle(STD_OUTPUT_HANDLE);

void addEmployee(){
    int branch,admin_level;
    cout<<"Branch no: ";cin>>branch;cin.ignore();
    if(!branches.count(branch)){
        RED;
        cout<<"\nThis branch does not exists.\n"<<endl;
        DEFAULT;
        return;
    }
    admin_level=1;
    int id=++last;
    branches[branch]->Employees.insert(id);
    string name,email,password,mobile,address;
    cout<<"Name: ";getline(cin,name);
    cout<<"Email: ";getline(cin,email);
    cout<<"Mobile: ";getline(cin,mobile);
    password=name+mobile.substr(0,4);
    cout<<"Address: ";getline(cin,address);
    Employee* emp = new Employee(id,name,email,password,mobile,address,branch,admin_level);
    employees[id]=emp;
    GREEN;
    cout<<"\nEmployee added successfully.\n"<<endl;
    DEFAULT;
}
void removeEmployee(){
    cout<<"Enter employee id(to be removed): ";
    int id;cin>>id;cin.ignore();
    if(!employees.count(id)){
        RED;
        cout<<"\nEmployee with this id does not exists.\n"<<endl;
        DEFAULT;
        return;
    }
    cout<<"Are you sure?(1 for confirmation): ";
    int confirm;cin>>confirm;cin.ignore();
    if(confirm!=1)
        return;
    branches[employees[id]->branch]->Employees.erase(id);
    employees.erase(id);
    GREEN;
    cout<<"\nEmployee with id-"<<id<<" removed successfully.\n"<<endl;
    DEFAULT;
}
void editEmployee(){
    cout<<"Enter id: ";
    int id;cin>>id;cin.ignore();
    if(!employees.count(id)){
        RED;
        cout<<"\nEmployee with this id does not exists.\n"<<endl;
        DEFAULT;
        return;
    }
    cout<<"\nCurrent details:- "<<endl;
    cout<<"1. Name: "<<employees[id]->name<<endl;
    cout<<"2. Email: "<<employees[id]->email<<endl;
    cout<<"3. Mobile: "<<employees[id]->mobile<<endl;
    cout<<"4. Address: "<<employees[id]->address<<endl;
    cout<<"5. Branch: "<<employees[id]->branch<<endl;
    cout<<"6. Cancel"<<endl;
    cout<<"Select option to edit: "<<endl;
    int opt;cin>>opt;
    cin.ignore();
    switch(opt){
        case 1: {
            cout<<"Enter new name: ";
            string name;
            getline(cin,name);
            employees[id]->name=name;
            break;
        }case 2:{
            cout<<"Enter new email: ";
            string email;
            getline(cin,email);
            employees[id]->email=email;
            break;
        }case 3:{
            cout<<"Enter new mobile: ";
            string mobile;
            getline(cin,mobile);
            employees[id]->mobile=mobile;
            break;
        }case 4:{
            cout<<"Enter new address: ";
            string address;
            getline(cin,address);
            employees[id]->address=address;
            break;
        }case 5:{
            cout<<"Enter new branch number: ";
            int branch;
            cin>>branch;cin.ignore();
            if(!branches.count(branch)){
                RED;
                cout<<"\nThis branch does not exists.\n"<<endl;
                DEFAULT;
                break;
            }
            branches[employees[id]->branch]->Employees.erase(id);
            branches[branch]->Employees.insert(id);
            employees[id]->branch=branch;
            break;
        }default:
            cout<<endl;
            break;
    }
    if(opt!=6){
        GREEN;
        cout<<"\nChanges saved!\n"<<endl;
        DEFAULT;
    }
}
void changePassword(){
    cout<<"To change password, first confirm its you:-"<<endl;
    cout<<"Enter your email: ";
    string email;getline(cin,email);
    if(email!=employees[currUser]->email){
        RED;
        cout<<"\nEmail not matched!\n"<<endl;
        DEFAULT;
        return;
    }
    cout<<"Enter your mobile: ";
    string mobile;getline(cin,mobile);
    if(mobile!=employees[currUser]->mobile){
        RED;
        cout<<"\nMobile not matched!\n"<<endl;
        DEFAULT;
        return;
    }
    cout<<"Enter new password: ";
    string password;getline(cin,password);
    cout<<"Re-enter new password: ";
    string rePassword;getline(cin,rePassword);
    if(password!=rePassword){
        RED;
        cout<<"\nPasswords not matched!\n"<<endl;
        DEFAULT;
        return;
    }
    employees[currUser]->password=password;
    GREEN;
    cout<<"\nPassword changed successfully.\n"<<endl;
    DEFAULT;
}