#include<bits/stdc++.h>
#include<windows.h>
using namespace std;

int lastConsignment=0;
void createConsignment(){
    int cons_number=++lastConsignment;
    int volume,pricing,amount;
    cout<<"Enter Volume of consignment(in cubic meter): ";cin>>volume;cin.ignore();
    cout<<"Enter Pricing(in Rs per volume) of consignment: ";cin>>pricing;cin.ignore();
    amount=pricing*volume;
    string source_address,destination_address;
    cout<<"Enter Sender's address of consignment: ";getline(cin,source_address);
    cout<<"Enter Reciever's address of consignment: ";getline(cin,destination_address);
    string created_at;
    time_t curr = time(0);
    created_at=ctime(&curr);
    vector<int>trucks_used;
    int reqTrucks=volume%500==0 ? volume/500 : volume/500+1;
    int avail=availTrucks.size();
    if(avail<reqTrucks){
        lastConsignment--;
        RED;
        cout<<"\nEnough Trucks for this consignment are not available. Come again when more trucks are purchased.\n"<<endl;
        DEFAULT;
        return;
    }
    while(reqTrucks--){
        int t=*availTrucks.begin();
        bookedTrucks.insert(t);
        availTrucks.erase(t);
        trucks_used.push_back(t);
        trucks[t]->status="Running";
        trucks[t]->source_address=source_address;
        trucks[t]->destination_address=destination_address;
        trucks[t]->branch=employees[currUser]->branch;
    }
    Consignment* consignment = new Consignment(cons_number,volume,pricing,amount,source_address,destination_address,created_at,trucks_used);
    consignment->branch = employees[currUser]->branch;
    consignments[cons_number]=consignment;
    branches[employees[currUser]->branch]->Consignments.insert(cons_number);
    GREEN;
    cout<<"\nConsignment created successfully.\n"<<endl;
    DEFAULT;
}
void completeConsignment(){
    cout<<"Enter consignment number: ";
    int cons_number;cin>>cons_number;cin.ignore();
    if(!consignments.count(cons_number)){
        RED;
        cout<<"\nNo consignment with this number.\n"<<endl;
        DEFAULT;
        return;
    }
    vector<int>temp=consignments[cons_number]->trucks_used;
    for(auto i:temp){
        availTrucks.insert(i);
        bookedTrucks.erase(i);
        trucks[i]->status="Free";
        trucks[i]->source_address="";
        trucks[i]->destination_address="";
    }
    consignments[cons_number]->status="Completed";
    branches[consignments[cons_number]->branch]->total_revenue+=consignments[cons_number]->amount;
    GREEN;
    cout<<"\nConsignment status updated.\n"<<endl;
    DEFAULT;
}
void consignmentDetails(){
    cout<<"Enter consignment number: ";
    int cons_number;cin>>cons_number;cin.ignore();
    if(!consignments.count(cons_number)){
        RED;
        cout<<"\nNo consignment with this number.\n"<<endl;
        DEFAULT;
        return;
    }
    cout<<"\nConsignment details:- "<<endl;
    cout<<"Consignment number: "<<cons_number<<endl;
    cout<<"Consignment Volume: "<<consignments[cons_number]->volume<<endl;
    cout<<"Consignment Pricing: "<<consignments[cons_number]->pricing<<endl;
    cout<<"Consignment Amount: "<<consignments[cons_number]->amount<<endl;
    cout<<"Consignment branch: "<<consignments[cons_number]->branch<<endl;
    cout<<"Consignment Sender's address: "<<consignments[cons_number]->source_address<<endl;
    cout<<"Consignment Receiver's address: "<<consignments[cons_number]->destination_address<<endl;
    cout<<"Consignment Created at: "<<consignments[cons_number]->created_at;
    cout<<"Trucks used(truck number): ";
    for(auto i:consignments[cons_number]->trucks_used){
        cout<<i<<" ";
    }cout<<endl;
    cout<<"Consignment status: "<<consignments[cons_number]->status<<endl<<endl;
}