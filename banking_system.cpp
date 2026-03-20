#include <iostream>
#include <ctime>
#include <cstdlib>
#include <limits>
using namespace std;

string name;
double balance;
long long account_number;
int pin;

void create_account()
{
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Enter your name: ";
    getline(cin, name);
    if (name == ""){
        return;
    }
    else{
         srand(time(0));
        account_number = rand() % 900000000000LL + 100000000000LL;
        pin = rand()%10000 + 99999;
        cout << "\nACCOUNT CREATED SUCCESSFULLY!\n";
        cout <<"\nUsername: "<<name;
        cout << "\nAccount number: "<< account_number;
        cout <<"\nPIN number: "<<pin;
        cout << "\nCurrent balance: $"<< balance <<endl;
        cout << "===================================";
    }

}

void check_balance(){ 
    if(name == ""){ 
        return; 
    } 
    else{ 
        cout << "\nACCOUNT DETAILS\n"; 
        cout << "==================================="; 
        cout <<"\nUsername: "<<name; 
        cout << "\nAccount number: "<< account_number; 
        cout <<"\nPIN number: "<<pin; 
        cout << "\nCurrent balance: $"<< balance <<endl; 
        cout << "==================================="; 
    } 
}

double deposit(){ 
    double amount; 
    cout << "Enter amount to be deposited: $"; 
    cin>>amount; 
    balance += amount; 
    return balance; 
} 

double withdraw(){ 
    double amount; 
    cout << "Enter amount to be withdraw: $"; 
    cin>>amount; 
    balance -= amount; 
    return balance; 
}