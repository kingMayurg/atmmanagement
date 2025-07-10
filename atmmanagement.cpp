#include <iostream>
#include <string>
using namespace std;

class ATM{
private:
    string accountholder;
    int pin;
    double balance;
public:
    ATM(string name,int userpin,double initialbalance){
        accountholder=name;
        pin=userpin;
        balance=initialbalance;
    }
    bool authenticate(int enteredpin){
        return enteredpin==pin;
    }
    void showMenu() {
        int choice;
        do {
            cout<<"\n====== ATM MENU ======\n";
            cout<<"1. Check Balance\n";
            cout<<"2. Deposit\n";
            cout<<"3. Withdraw\n";
            cout<<"4. Exit\n";
            cout<<"Enter your choice: ";
            cin>>choice;
            switch(choice){
                case 1:checkbalance(); break;
                case 2:deposit(); break;
                case 3:withdraw(); break;
                case 4:cout<<"Thank you for using the ATM!\n";break;
                default:"Invalid choice. Try again.\n";
            }
        }while(choice!=4);
    }
    void checkbalance(){
        cout<<"Current Balance: "<<balance<<" rupees "<<endl;
    }
    void deposit() {
        double amount;
        cout<<"Enter amount to deposit:";
        cin>>amount;
        if(amount>0){
            balance+=amount;
            cout<<"rupees "<<amount<<" deposited successfully.\n";
        }else{
            cout<<"Invalid amount.\n";
        }
    }
    void withdraw() {
        double amount;
        cout<<"Enter amount to withdraw:";
        cin>>amount;
        if(amount>0&&amount<=balance){
            balance-=amount;
            cout<<"rupees "<<amount<<" withdrawn successfully.\n";
        }else{
            cout<<"Invalid or insufficient balance.\n";
        }
    }
};

int main() {
    string name;
    int pin;
    cout<<"====== Welcome to ATM ======\n";
    cout<<"Enter your name: ";
    getline(cin, name);
    cout<<"Set your PIN: ";
    cin>>pin;
    ATM userAccount(name, pin, 1000.0);
    int enteredpin;
    cout<<"\nEnter PIN to login: ";
    cin>>enteredpin;
    if(userAccount.authenticate(enteredpin)) {
        cout<<"Login successful!\n";
        userAccount.showMenu();
    }else{
        cout<<"Incorrect PIN. Access denied.\n";
    }

    return 0;
}
