#include<bits/stdc++.h>
#include<windows.h>
#include "dataStructures.h"
#include "manageEmployees.h"
#include "manageTrucks.h"
#include "manageConsignments.h"
using namespace std;

void showMenu(int id);
void showRevenue();
void createBranch();
int lastBranch=0;

bool login(){
    cout<<"Enter id: ";
    int id;cin>>id;
    cin.ignore();
    if(!employees.count(id)){
        RED;
        cout<<"Unknown user!\n"<<endl;
        DEFAULT;
        return false;
    }
    cout<<"Enter password: ";
    string pass;
    getline(cin,pass);
    if(employees[id]->password!=pass){
        RED;
        cout<<"Incorrect password!\n"<<endl;
        DEFAULT;
        return false;
    }
    currUser=id;
    GREEN;
    cout<<"\nLogin Successful. Have a good day!\n"<<endl;
    DEFAULT;
    showMenu(id);
    return true;
}

void showMenu(int id){
    cout<<"What do you want to do?\n"<<endl;
    // for manager
    if(id==0){
        while(1){
            CYAN;
            cout<<"1. Add new Employee."<<endl;
            cout<<"2. Fire an employee."<<endl;
            cout<<"3. Edit Employee details."<<endl;
            cout<<"4. Add new Truck."<<endl;
            cout<<"5. Edit Truck details."<<endl;
            cout<<"6. Remove a truck."<<endl;
            cout<<"7. Show revenue."<<endl;
            cout<<"8. Add a new Branch."<<endl;
            cout<<"9. Change password."<<endl;
            cout<<"10. Logout.\n"<<endl;
            DEFAULT;
            int choice;cin>>choice;
            cin.ignore();
            if(choice==10){
                cout<<"Logged out."<<endl;
                break;
            }
            switch (choice){
                case 1:
                    addEmployee();
                    break;
                case 2:
                    removeEmployee();
                    break;
                case 3:
                    editEmployee();
                    break;
                case 4:
                    addTruck();
                    break;
                case 5:
                    editTruck();
                    break;
                case 6:
                    removeTruck();
                    break;
                case 7:
                    showRevenue();
                    break;
                case 8:
                    createBranch();
                    break;
                case 9:
                    changePassword();
                    break;
                default:
                    break;
            }
        }
    }else{
        // for Employee:
        while(1){
            CYAN;
            cout<<"1. Create new Consignment."<<endl;
            cout<<"2. Consignment details."<<endl;
            cout<<"3. Complete Consignment."<<endl;
            cout<<"4. Truck details."<<endl;
            cout<<"5. Change password."<<endl;
            cout<<"6. Logout.\n"<<endl;
            DEFAULT;
            int choice;cin>>choice;
            cin.ignore();
            if(choice==6){
                cout<<"Logged out."<<endl;
                break;
            }
            switch (choice){
                case 1:
                    createConsignment();
                    break;
                case 2:
                    consignmentDetails();
                    break;
                case 3:
                    completeConsignment();
                    break;
                case 4:
                    truckDetails();
                    break;
                case 5:
                    changePassword();
                    break;
                default:
                    break;
            }
        }
    }
}

void createBranch(){
    int branch_number=++lastBranch;
    cout<<"Enter branch name: ";
    string name;getline(cin,name);
    cout<<"Enter branch address: ";
    string address;getline(cin,address);
    Branch* newB=new Branch(branch_number, name, address);
    branches[branch_number]=newB;
    GREEN;
    cout<<"New branch("<<name<<")"<<" added.\n"<<endl;
    DEFAULT;
}
void showRevenue(){
    cout<<"Enter branch: ";
    int branch;cin>>branch;cin.ignore();
    long long revenue=0;
    if(branch==0){
        for(auto b:branches){
            revenue+=b.second->total_revenue;
        }
        cout<<"\nTotal Revenue: "<<revenue<<endl;
        cout<<endl;
        return;
    }
    if(!branches.count(branch)){
        RED;
        cout<<"\nThis branch does not exists.\n"<<endl;
        DEFAULT;
        return;
    }
    cout<<"\nTotal Revenue: "<<branches[branch]->total_revenue<<endl;
    cout<<endl;
}

int main(){
    // Manager
    manager = new Employee(0,"Sahil", "Sahil@gmail.com","test7878","9876543210","AOT",0,2);
    employees[0]=manager;
    // login
    while(1){
        while(login()==false);
    }
    return 0;
}