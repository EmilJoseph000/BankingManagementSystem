#include <iostream>
using namespace std;

class account{

private:
long accountNo;
string name;
long balance;


public:

account(){
    accountNo;
    name;
    balance;
  
}

long setAccountNo(long an){
    return accountNo=an;
}

void setName(string n){
    name = n;
}

void details(){
  cout<<accountNo<<" "<<name<<" "<<balance<<"\n";
  cout<<"Thank you for opening an account with BMS kakanaad"<<endl;
}

long setBalance(int bal){
  return balance=bal;
}



};


int main(){


     int numb,initial;
    string user;


    int options=0;
    int op;

    account a;

    cout<<"***Banking System***"<<endl;

    cout<<"\n"<<endl;

    cout<<"Select one option from below"<<endl;
    cout<<"\n"<<"1  open an account"<<endl;
    cout<<"2  Balance Enquiry"<<endl;
    cout<<"3  Deposit"<<endl;
    cout<<"4  withdrawal"<<endl;
    cout<<"5  close an account"<<endl;
    cout<<"6  show all accounts"<<endl;
    cout<<"7  quit"<<endl;

    cout<<"Enter your choice: ";

    cin>>options;

    do{
    
    switch(options){
        case 0: while(options==0){
            cout<<"choose an option from 1 to 7"<<endl;
            cin>>op;

        }
        options=op;
        break;

        case 1:cout<<"You have selected to open an account"<<endl;

  
                    cout<<"enter account number"<<endl;
                    cin>>numb;
                    a.setAccountNo(numb);
                    cin.ignore();
                    cout<<"\nPlease enter your name"<<endl;
                    getline(cin,user);
                    a.setName(user);
                    cin.ignore();  
                    cout<<"Enter your initial deposit"<<endl;
                    cin>>initial;
                    a.setBalance(initial);
                    cout<<"************************************"<<endl;
                    cout<<"Processing"<<endl;
                    cout<<"Account created. Thank you"<<endl;

                    a.details();
                    options=0;
                    
        break;

        case 2:cout<<"You have selected to check your balance"<<endl;
            
        break;

        case 3:cout<<"You have selected to deposit funds"<<endl;
        break;

        case 4:cout<<"You have selected to withdraw"<<endl;
        break;

        case 5:cout<<"You have selected to close your account"<<endl;
        break;

        case 6:cout<<"show all accounts"<<endl;
        break;

        case 7:cout<<"Exit"<<endl;
        break;

        default:cout<<"not a valid selection"<<endl;

    }
    }while(options!=7);   

    return 0;
}