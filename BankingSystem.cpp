#include <iostream>
#include <fstream>
#include <string>
#include <cstring>


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

long setDeposit(long dep){
  return balance+=dep;
}

long cashOut(long withdraw){
  return balance-=withdraw;
}

void disable(){

strcpy(fname, "diabled");
strcpy(lname, "diabled");
balance=0;
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
  cout<<"\n"<<"\n"<<endl;
  
  ac.accountDetails();

  cout<<"\n"<<"\n"<<endl;
  cout<<"******Thank you for choosing Banking management solution"<<endl;
  
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
          break;
        }
          

        }
          

      }
        infile.close();
}

void withdraw(){

    account ac;
    long accountNo;
    long withdraw;

    cout<<"Please enter your account number"<<endl;
    cin>>accountNo;

    cout<<"Please enter the amount to withdraw"<<endl;
    cin>>withdraw;

    fstream file;
    file.open("Bank.dat",ios::binary|ios::in|ios::out);

      if(file.is_open()){
        while(!file.eof()){

          file.read((char*)&ac,sizeof(ac));

        if(accountNo==ac.getAccountNum())
        {
          cout<<"Current:"<<endl;
          ac.accountDetails();
          ac.cashOut(withdraw);

          file.seekp(static_cast<unsigned long>(file.tellg()) - static_cast<unsigned long>(sizeof(ac)));

          file.write((char*)&ac,sizeof(ac));
        }


        }


      }
        file.close();
}

void deposit(){

    account ac;
    long accountNo;
    long dep;

    cout<<"Please enter your account number"<<endl;
    cin>>accountNo;

    cout<<"Please enter the deposit amount"<<endl;
    cin>>dep;
  
    fstream file;
    file.open("Bank.dat",ios::binary|ios::in|ios::out);

      if(file.is_open()){
        while(!file.eof()){

          file.read((char*)&ac,sizeof(ac));

        if(accountNo==ac.getAccountNum())
        {
          cout<<"Current:"<<endl;
          ac.accountDetails();
          ac.setDeposit(dep);

          file.seekp(static_cast<unsigned long>(file.tellg()) - static_cast<unsigned long>(sizeof(ac)));

          file.write((char*)&ac,sizeof(ac));
        }


        }


      }
        file.close();
}


void del(){

  long acn;
  account ac;
  
  fstream file("Bank.dat",ios::binary | ios::in | ios::out);

  cout<<"enter account number to be deleted"<<endl;
  cin>>acn;

  while(!file.eof()){
    file.read((char*)&ac,sizeof(ac));
    if(acn==ac.getAccountNum()){

      ac.disable();
      
      file.seekp(static_cast<unsigned long>(file.tellg()) - static_cast<unsigned long>(sizeof(ac)));
      
    file.write((char*)&ac,sizeof(ac));
    
    }
  }
  file.close();

}


void showAllAccount(){

    account ac;
    ifstream infile;
    infile.open("Bank.dat",ios::binary|ios::in);
  
        while(!infile.eof() && infile.read((char*)&ac,sizeof(ac))){

          
          ac.accountDetails();
          
        }
        
        infile.close();
}


int main(){

    int selection;
    int option;


  cout<<"\n"<<"-----------------------------"<<"\n"<<endl;
  cout<<"\n"<<"      Enter your choice      "<<endl;
  cout<<"                           "<<endl;
  cout<<"            [1] MainMenu "<<endl;
  cout<<"            [0] Exit      "<<endl;
  cout<<"Enter choice [0] or [1]:";
  cin>>selection;

  
  while(selection==1){
    cout<<"\n"<<"\n"<<endl;

    cout<<"**********************************************************"<<endl;
    cout<<" ***************Banking Management System**************** "<<endl;

    cout<<"\n"<<"\n"<<"\n"<<endl;
    cout<<"Open Account     (1)"<<endl;
    cout<<"Make a deposit   (2)"<<endl;
    cout<<"Make a withdrawal(3)"<<endl;
    cout<<"View Account  (4)"<<endl;
    cout<<"Disable Account  (5)"<<endl;
    cout<<"Show all accounts(6)"<<endl;
    cout<<"Default Menu      (7)"<<endl;

    cout<<"\n"<<"\n"<<"\n"<<endl;

    cout<<"Please enter your selection: "<<endl;
    cin>>option;    

    
    switch(option){

      case 1:cout<<"\n"<<"You have selected to open an Account"<<"\n"<<endl;
             writeToAccount();
              break;

      case 2:cout<<"\n"<<"You have selected to make a deposit"<<"\n"<<endl;
              deposit();
               break;       
      
      case 3:cout<<"\n"<<"You have selected to make a withdrawal"<<"\n"<<endl;
              withdraw();
              break;
      
      case 4:cout<<"\n"<<"You have selected to view your account"<<"\n"<<endl;
              searchInAccount();
              break;
      
      case 5:cout<<"\n"<<"You have selected to Disable your account"<<"\n"<<endl;
              del();
              break;

      case 6:cout<<"\n"<<"You have selected to make show all accounts"<<"\n"<<endl;
              showAllAccount();
              break;
            

      case 7: cout<<"\n"<<"-----------------------------"<<"\n"<<endl;
              cout<<"\n"<<"      Enter your choice      "<<endl;
              cout<<"                           "<<endl;
              cout<<"            [1] MainMenu "<<endl;
              cout<<"            [0] Exit      "<<endl;
              cout<<"Enter choice [0] or [1]:";
              int choice;
              cin>>choice;
        
            if(choice==0){
              cout<<"                                                   "<<endl;
              cout<<"                                                  "<<endl;
              cout<<"**********************Exiting******************"<<endl;
              cout<<" *******************Thank you****************  "<<endl;
              cout<<"                                                "<<endl;
              cout<<"   _______                     _______           "<<endl;
              exit(0);
            }
            else cout<<". . . . . "<<endl;
                break;
      
      default:cout<<"* * * * * * * * * * *"<<endl;
              cout<<"  Invalid selection "<<endl;
              cout<<"please enter a number from 1 to 7 "<<endl;
              break;
    }
    
  };






 return 0;

}

