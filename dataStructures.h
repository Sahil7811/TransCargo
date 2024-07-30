#include<bits/stdc++.h>
using namespace std;

#define RED SetConsoleTextAttribute(col, 4)
#define DEFAULT SetConsoleTextAttribute(col, 7)
#define CYAN SetConsoleTextAttribute(col, 11)
#define GREEN SetConsoleTextAttribute(col, 2)

HANDLE col=GetStdHandle(STD_OUTPUT_HANDLE);

class Employee{
public:
    int id;
    string name="",email="",password="",mobile="",address="";
    int branch,admin_level;
    Employee(int Id, string Name, string Email, string Password, string Mobile, string Address, int Branch, int Admin_level){
        id=Id;
        name=Name;
        email=Email;
        password=Password;
        mobile=Mobile;
        address=Address;
        branch=Branch;
        admin_level=Admin_level;
    }
};
class Truck{
public:
    int truck_number;
    int branch;
    int volume,driver_id;
    string status,source_address,destination_address;
    Truck(int Truck_number, int Branch, int Volume, int Driver_id, string Status, string Source_address, string Destination_address){
        truck_number=Truck_number;
        branch=Branch;
        volume=Volume;
        driver_id=Driver_id;
        status=Status;
        source_address=Source_address;
        destination_address=Destination_address;
    }
};
class Branch{
public:
    int branch_number;
    string name,address;
    set<int>Employees,Trucks,Consignments;
    long long total_revenue;
    Branch(int Branch_number, string Name, string Address){
        branch_number=Branch_number;
        name=Name;
        address=Address;
        total_revenue=0;
    }
};
class Consignment{
public:
    int cons_number,volume,pricing,amount,branch;
    string source_address,destination_address;
    string created_at,status="Pending";
    vector<int>trucks_used;
    Consignment(int Cons_number, int Volume, int Pricing, int Amount, string Source_address, string Destination_address, string Created_at, vector<int>Trucks_used){
        cons_number=Cons_number;
        volume=Volume;
        pricing=Pricing;
        amount=Amount;
        source_address=Source_address;
        destination_address=Destination_address;
        created_at=Created_at;
        trucks_used=Trucks_used;
    }
};

Employee* manager;
unordered_map<int,Employee*>employees;
unordered_map<int,Truck*>trucks;
unordered_map<int,Consignment*>consignments;
unordered_map<int,Branch*>branches;
int currUser;