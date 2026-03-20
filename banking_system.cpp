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
        pin = rand()%100000 + 99999;
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
    if(amount <= 0){
        cout << "Invalid deposit amount.";
        return balance;
    }

    balance += amount; 
    return balance; 
} 

double withdraw(){ 
    double amount; 
    cout << "Enter amount to be withdraw: $"; 
    cin>>amount; 
    if(amount <= 0){
        cout << "Invalid withdrawal amount.\n";
        return balance;
    }
    if(amount > balance){
        cout << "Insufficient balance.\n";
        return balance;
    }

    balance -= amount; 
    return balance; 
}

bool validation(){ 
    long long acc; 
    int PIN; 
    if(name == ""){
        cout << "No account created yet!";
        return false;
    }

    cout << "Enter your account number: "; 
    cin >> acc; 

    if(acc == account_number){ 
        cout << "Enter your PIN number: "; 
        cin >> PIN; 

        if(PIN == pin){ 
            return true; 
        } 
        else{ 
            cout << "Incorrect PIN number"; 
            return false; 
        } 
    } 
    else{ 
        cout << "Incorrect account number"; 
        return false; 
    } 
}

int main(){ 
    cout << "WELCOME TO BANKING SYSTEM"; 
    cout << "1.Create account"; 
    cout << "2.Check account details"; 
    cout << "3.Deposite"; 
    cout << "4.Withdraw"; 
    cout << "5.Exit"; 
    while (true){ 
        int option; 
        cout << "Enter an option number: "; 
        cin >> option; 
        if(option == 1){ 
            create_account(); 
        } 
        else if(option == 2){ 
            validation(); 
            check_balance(); 
        } 
        else if(option == 3){ 
            validation(); 
            deposit(); 
        } 
        else if(option == 4){ 
            validation(); 
            withdraw(); 
        } 
        else if(option == 5){ 
            cout << "Thank you for using our Banking system"; 
            break; 
        } 
        else{ 
            cout << "Invalid option number entered!"; 
        } 
    } 
}
