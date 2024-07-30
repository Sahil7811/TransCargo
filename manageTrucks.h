#include<bits/stdc++.h>
#include<windows.h>
using namespace std;

int lastTruck=0;
set<int>availTrucks,bookedTrucks;

void addTruck(){
    int truck_number=++lastTruck;
    int branch,volume,driver_id;
    string status,source_address,destination_address;
    cout<<"Branch: ";cin>>branch;cin.ignore();
    if(!branches.count(branch)){
        RED;
        cout<<"\nThis branch does not exists.\n"<<endl;
        DEFAULT;
        return;
    }
    branches[branch]->Trucks.insert(truck_number);
    cout<<"Volume(in cubic meter:max-500): ";cin>>volume;cin.ignore();
    if(volume<0 || volume>500){
        RED;
        cout<<"\nVolume should be in range [0,500].\n"<<endl;
        DEFAULT;
        return;
    }
    cout<<"Driver_id: ";cin>>driver_id;cin.ignore();
    // cout<<"Status: ";getline(cin,status);
    // cout<<"Source address: ";getline(cin,source_address);
    // cout<<"Destination address: ";getline(cin,destination_address);
    Truck* truck = new Truck(truck_number,branch,volume,driver_id,"Free","","");
    trucks[truck_number]=truck;
    GREEN;
    cout<<"\nTruck added successfully.\n"<<endl;
    DEFAULT;
    availTrucks.insert(truck_number);
}
void editTruck(){
    cout<<"Enter truck number: ";
    int truck_number;cin>>truck_number;cin.ignore();
    if(!trucks.count(truck_number)){
        RED;
        cout<<"\nTruck with this number does not exists.\n"<<endl;
        DEFAULT;
        return;
    }
    cout<<"\nCurrent details:- "<<endl;
    cout<<"1. Truck number: "<<trucks[truck_number]->truck_number<<endl;
    cout<<"2. Branch: "<<trucks[truck_number]->branch<<endl;
    cout<<"3. Volume: "<<trucks[truck_number]->volume<<" cubic meter"<<endl;
    cout<<"4. Driver_id: "<<trucks[truck_number]->driver_id<<endl;
    cout<<"5. Status: "<<trucks[truck_number]->status<<endl;
    cout<<"6. Source address: "<<trucks[truck_number]->source_address<<endl;
    cout<<"7. Destination address: "<<trucks[truck_number]->destination_address<<endl;
    cout<<"8. Cancel"<<endl;
    cout<<"Select option to edit: "<<endl;
    int opt;cin>>opt;
    cin.ignore();
    switch(opt){
        case 1: {
            RED;
            cout<<"Cannot change Truck number!\n"<<endl;
            DEFAULT;
            break;
        }case 2:{
            cout<<"Enter new Branch number: ";
            int branch;cin>>branch;cin.ignore();
            if(!branches.count(branch)){
                RED;
                cout<<"\nThis branch does not exists.\n"<<endl;
                DEFAULT;
                break;
            }
            branches[trucks[truck_number]->branch]->Trucks.erase(truck_number);
            branches[branch]->Trucks.insert(truck_number);
            trucks[truck_number]->branch=branch;
            break;
        }case 3:{
            cout<<"Enter new Volume(in cubic meter: max-500): ";
            int volume;cin>>volume;cin.ignore();
            trucks[truck_number]->volume=volume;
            break;
        }case 4:{
            cout<<"Enter new Driver id: ";
            int driver_id;cin>>driver_id;cin.ignore();
            trucks[truck_number]->driver_id=driver_id;
            break;
        }case 5:{
            cout<<"Enter Status: ";
            string status;
            getline(cin,status);
            trucks[truck_number]->status=status;
            break;
        }case 6:{
            cout<<"Enter Source address: ";
            string source_address;
            getline(cin,source_address);
            trucks[truck_number]->source_address=source_address;
            break;
        }case 7:{
            cout<<"Enter Destination address: ";
            string destination_address;
            getline(cin,destination_address);
            trucks[truck_number]->destination_address=destination_address;
            break;
        }default:
            cout<<endl;
            break;
    }
    if(opt!=8){
        GREEN;
        cout<<"\nChanges saved!\n"<<endl;
        DEFAULT;
    }
}
void removeTruck(){
    cout<<"Enter Truck number(to be removed): ";
    int truck_number;cin>>truck_number;cin.ignore();
    if(!trucks.count(truck_number)){
        RED;
        cout<<"\nTruck with this number does not exists.\n"<<endl;
        DEFAULT;
        return;
    }
    cout<<"Are you sure?(1 for confirmation): ";
    int confirm;cin>>confirm;cin.ignore();
    if(confirm!=1)
        return;
    branches[trucks[truck_number]->branch]->Trucks.erase(truck_number);
    trucks.erase(truck_number);
    GREEN;
    cout<<"\nTruck with number-"<<truck_number<<" removed successfully.\n"<<endl;
    DEFAULT;
    if(availTrucks.count(truck_number))
        availTrucks.erase(truck_number);
    if(bookedTrucks.count(truck_number))
        bookedTrucks.erase(truck_number);
}
void truckDetails(){
    cout<<"Enter Truck number: ";
    int truck_number;cin>>truck_number;cin.ignore();
    if(!trucks.count(truck_number)){
        RED;
        cout<<"\nTruck with this number does not exists.\n"<<endl;
        DEFAULT;
        return;
    }
    if(trucks[truck_number]->branch!=employees[currUser]->branch){
        RED;
        cout<<"\nThis truck is not present at your branch.\n"<<endl;
        DEFAULT;
        return;
    }
    cout<<"\nTruck details:- "<<endl;
    cout<<"1. Truck number: "<<trucks[truck_number]->truck_number<<endl;
    cout<<"2. Branch: "<<trucks[truck_number]->branch<<endl;
    cout<<"3. Volume: "<<trucks[truck_number]->volume<<" cubic meter"<<endl;
    cout<<"4. Driver_id: "<<trucks[truck_number]->driver_id<<endl;
    cout<<"5. Status: "<<trucks[truck_number]->status<<endl;
    cout<<"6. Source address: "<<trucks[truck_number]->source_address<<endl;
    cout<<"7. Destination address: "<<trucks[truck_number]->destination_address<<endl<<endl;
}