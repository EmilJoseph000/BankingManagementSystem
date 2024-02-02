#include <iostream>
#include <fstream>
#include <map>
#include <string>


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

void createAccount(){

  cout<<"Please enter your first name"<<endl;
  cin>>fname;

  cout<<"please enter your second name"<<endl;
  cin>>lname;

  cout<<"please enter your initial deposit"<<endl;
  cin>>balance;


}


long getaccountnum(){

    return accountNo;
}


void showAccount(long acn){

    if(acn==accountNo){
        cout<<"first name: "<<fname<<endl;
        cout<<"last name: "<<lname<<endl;
        cout<<"Accoungt #: "<<accountNo<<endl;
        cout<<"Balance: "<<balance<<endl;
    }

}

    

void writeToAccount(){

    ofstream outfile;
    outfile.open("Bank.txt",ios::app);

  
    outfile<<createAccount();

    outfile.close();
    }












};

long account::nextAccountNo=0;





int main(){
    

account a;


cout<<"\n";


a.writeToAccount();




 return 0;

}