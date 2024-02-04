#include <iostream>
#include <fstream>
#include <string>


using namespace std;

class account{

private:
string fname;
string lname;
long balance;
long accountNo;
long tracker=1;


public:

account(){
    accountNo;
    fname;
    lname;
    balance;
    tracker;

}

void createAccount(){

  cout<<"Please enter your first name"<<endl;
  cin>>fname;

  cout<<"please enter your second name"<<endl;
  cin>>lname;

  cout<<"please enter your initial deposit"<<endl;
  cin>>balance;
}


long deposit(){

 // long amount;
  long accN;
  long deposit;
  
  string fname;
  string lname;
  long accountn;
  long balance;
  long track;

  cout<<"Please enter your account number"<<endl;
  cin>>accN;

 /* cout<<"please enter your deposit amount"<<endl;
  cin>>amount;
*/
  fstream infile;

  infile.open("Bank.txt",ios::in);

  if(infile.is_open()){
    if(accN==2){
      while(!infile.eof()){
        infile >> fname;
        infile >> lname;
        infile >> accountn;
        infile >> balance;
        infile >> track;

        cout<<fname<<endl;
        break;

      }
    }
  }

  infile.close();


  return 0;
}




void showAllAccount(){

    string line;
  
    fstream myfile;
    myfile.open("Bank.txt",ios::in);

      if(myfile.is_open()){
        while(getline(myfile, line)){

          cout<<line<<endl;
        }

        myfile.close();
      }
      
}

long setLastAccountNo(){
  long line;
  long counter=0;

  string name;
  string lname;
  long acn;
  long depo;

  fstream filein;

  filein.open("Bank.txt",ios::in);
  if(filein.is_open()){
    while(!filein.eof()){
    filein >> name;
    filein >> lname;
    filein >> acn;
    filein >> depo;
    filein>> line;
      
     counter++;
    }
    filein.close();
  }
  return accountNo=counter;
}






void showAccount(){

   cout<<"first name: "<<fname<<endl;
   cout<<"last name: "<<lname<<endl;
   cout<<"Accoungt #: "<<accountNo<<endl;
   cout<<"Balance: "<<balance<<endl;
    
}



void writeToAccount(){

    ofstream outfile;
    outfile.open("Bank.txt",ios::app);

  if(outfile.is_open()){
    outfile<< fname<< endl;
    outfile<< lname<< endl;
    outfile<< accountNo<< endl;
    outfile<< balance<< endl;
    outfile<< tracker<<endl;
    outfile.close();
  }  
    

    }












};






int main(){


account a;



  

  
 
  

 return 0;

}