#include <iostream>
#include <fstream>


using namespace std;

class account{

private:
static long nextAccountNo;
string fname;
string lname;
long balance;
long accountNo;


public:

account(){
    nextAccountNo++;
    accountNo=nextAccountNo;
    fname;
    lname;
    balance;
  
}

void openAccount(){
     cout<<"\nPlease enter your first name"<<endl;
                    cin>>fname;
                    cout<<"\nPlease enter your last name"<<endl;
                    cin>>lname;
                    cin.ignore();
                    cout<<"Enter your initial deposit"<<endl;
                    cin>>balance;
                    cout<<"************************************"<<endl;
                    cout<<"Processing"<<endl;
                    cout<<"Account created. Thank you"<<endl;

                    fstream baccount;
                    baccount.open("Bank.txt",ios::app);
                        if(baccount.is_open()){
                            baccount<<fname<<endl;
                            baccount<<lname<<endl;
                            baccount<<balance<<endl;
                            baccount.close();
                        }
                    

}




void searchAccount(){
    long acno;
    string a;
    string b;
    long ano;

    fstream search;
    cout<<"enter your account number"<<endl;
    cin>>acno;

    search.open("Bank.txt",ios::in);
    while(!search.eof()){
    if(acno==accountNo){
       search>>a;
       search>>b;
       search>>ano;
       cout<<a<<" "<<b<<" "<<ano<<endl; 
        return;
    }
    
    cout<<"no record found"<<endl;
    return;
    }
    

    search.close();

}

int fundIn(int d){
  return  balance+=d;
}

void deposit(){

    long ac;
    long d;
    cout<<"Please enter your accout No to start depositing funds"<<endl;
    cin>>ac;

    fstream deposit;
    deposit.open("Bank.txt",ios::app);

    while(!deposit.eof()){
    if(ac==accountNo){
        cout<<"enter deposit amount"<<endl;
        cin>>d;
        deposit<<fundIn(d);
        return;
    }
    cout<<"account not found"<<endl;
    }

    deposit.close();
}

};

long account::nextAccountNo=0;


int main(){
    


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

                   a.openAccount();

                    options=0;
    
        break;            
        

        case 2:cout<<"You have selected to check your balance"<<endl;
        a.searchAccount();
            
        break;



        case 3:cout<<"You have selected to deposit funds"<<endl;
            a.deposit();
            
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