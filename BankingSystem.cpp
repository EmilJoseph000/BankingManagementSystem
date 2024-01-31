#include <iostream>
#include <fstream>
#include <map>


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

void createAccount(string fn,string ln,long init){
    fname=fn;
    lname=ln;
    balance=init;
  
}

long getaccountnum(){
    return accountNo;
}



long showdetails(long acn){

    if(acn==accountNo){
        cout<<fname<<endl;
        cout<<lname<<endl;
        cout<<accountNo<<endl;
        cout<<balance<<endl;
    }

    return 0;
}

long deposit(long acn,long amount){
    if(acn==accountNo){
        balance+=amount;
        cout<<"thank you for depositing"<<endl;
    }
    return 0;
}

long withdraw(long acn,long amount){
    if(acn==accountNo){
        balance-=amount;
        cout<<"thank you for withdrawing"<<endl;
    }
    return 0;
}

long balanceEnquiry(long acn){
    if(acn==accountNo){
    cout<<fname<<endl;
    cout<<lname<<endl;
    cout<<accountNo<<endl;
    cout<<balance<<endl;
    }   
    return 0;
}



long disableAccount(long acn){
    char ch;
    if(acn=accountNo){
        cout<<"are you that you want to close your account"<<endl;
        cout<<"select y/n"<<endl;
        cin>>ch;
        if(ch='y'){
            fname="disabled";
            lname="disabled";
    
        }
        else if (ch='n'){
            
        }
    }

        cout<<"thank you for choosing BMS"<<endl;

    return 0;
}

};

long account::nextAccountNo=0;





int main(){
    

account a;

a.createAccount("emil","joseph",5000);

cout<<a.getaccountnum();

cout<<"\n"<<endl;

a.showdetails(1);

a.deposit(1,4000);

cout<<"\n"<<endl;

a.showdetails(1);

cout<<"\n"<<endl;
cout<<"\n"<<endl;

a.withdraw(1,6000);

cout<<"\n"<<endl;

a.showdetails(1);

cout<<"\n"<<endl;

a.balanceEnquiry(1);

cout<<"\n"<<endl;

a.disableAccount(1);

cout<<"\n"<<endl;

a.showdetails(1);

 return 0;

}