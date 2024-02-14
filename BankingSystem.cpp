#include <iostream>
#include <fstream>
#include <string>


using namespace std;

class account{

private:
char fname[50];
char lname[50];
long balance;
long accountNo;



public:

account(){
    accountNo;
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
/*
  cout<<"acc"<<endl;
  cin>>accountNo;
*/
  
}


long deposit(){

 // long amount;
  long accN;
  long deposit;
  
  string fname;
  string lname;
  long accountn;
  long balance;


  cout<<"Please enter your account number"<<endl;
  cin>>accN;

 /* cout<<"please enter your deposit amount"<<endl;
  cin>>amount;
*/
  fstream infile;

  infile.open("Bank.txt",ios::in);

  if(infile.is_open()){
      while(!infile.eof()){
        if(accN)
        infile >> fname;
        infile >> lname;
        infile >> accountn;
        infile >> balance;

        cout<<fname<<endl;
        break;

      }
    }


  infile.close();


  return 0;
}


long setLastAccountNo(){

  long counter=0;

  string name;
  string lname;
  long acn;
  long depo;

  account ac;

  ifstream filein;

  filein.open("Bank.dat",ios::in);
  if(filein.is_open()){
    while(!filein.eof()){

    filein.read((char*)&ac,sizeof(ac));
      

      
     counter++;
    }
    filein.close();
  }
  return accountNo=counter;
}


long getAccountNum(){
  return accountNo;
}



void accountDetails(){

  cout<<"\n";
  cout<<"Account Details are ";
  cout<<"\n";

   cout<<"First Name: "<<fname<<endl;
   cout<<"Last Name: "<<lname<<endl;
   cout<<"Account No: "<<accountNo<<endl;
   cout<<"Balance: "<<balance<<endl;
    
}


string getFirstName(){
  return fname;
}

string getLastName(){
  return lname;
}

long getBalance(){
  return balance;
}







};

void writeToAccount(){
  account ac;

  ac.setLastAccountNo();
  
  
  ofstream outfile;
  outfile.open("Bank.dat",ios::binary |ios::app);

  ac.createAccount();

  outfile.write((char*)&ac,sizeof(ac));
  outfile.close();
  ac.accountDetails();
  }


void searchInAccount(){

    account ac;
    long accountNo;

    cout<<"Please enter your account number"<<endl;
    cin>>accountNo;
  
    ifstream infile;
    infile.open("Bank.dat",ios::binary|ios::in);

      if(infile.is_open()){
        while(!infile.eof()){

          infile.read((char*)&ac,sizeof(ac));

        if(accountNo==ac.getAccountNum())
        {
          ac.accountDetails();
        }
          

        }


      }
        infile.close();
}

    


void showAllAccount(){

    account ac;
    ifstream infile;
    infile.open("Bank.dat",ios::binary|ios::in);

      if(infile.is_open()){
        while(!infile.eof()){

          infile.read((char*)&ac,sizeof(ac));

          
          ac.accountDetails();
          
        }
        
        
      }
        infile.close();
}


int main(){


account ac;

 searchInAccount();


 return 0;

}

