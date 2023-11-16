#include<iostream>
#include<fstream>

using namespace std;

class shopping
{
    private:
    int pcode;
    float price;
    float discount;
    string pname;

    public:
    void menu();
    void administrator();
    void buyer();
    void add();
    void edit();
    void rem();
    void list();
    void receipt();

};

void shopping :: menu()
{
    m:
    int choice;
    string email;
    string password;

    cout<<"\t\t\t\t__________________________________________\n";
    cout<<"\t\t\t\t                                          \n";
    cout<<"\t\t\t\t      SuperMarket Main Menu               \n";
    cout<<"\t\t\t\t                                          \n";
    cout<<"\t\t\t\t__________________________________________\n";
    cout<<"\t\t\t\t                                          \n";
    cout<<"\t\t\t\t| 1) Administrator     |\n";
    cout<<"\t\t\t\t|                      |\n";
    cout<<"\t\t\t\t| 2) Buyer             |\n";
    cout<<"\t\t\t\t|                      |\n";
    cout<<"\t\t\t\t| 3) Exit              |\n";
    cout<<"\t\t\t\t|                      |\n";
    cout<<"\n\t\t\t Please select! ";
    cin>>choice;

    switch (choice)
    {
    case 1:
        cout<<"\t\t\t Please Login \n";
        cout<<"\t\t\t Enter email  \n";
        cin>>email;
        cout<<"\t\t\t Enter Password  \n";
        cin>>password;

        if(email=="prath@gmail.com" && password=="Pass@123")
        {
            administrator();
        }
        else{
            cout<<"Invalid email/password";
        }
        break;

    case 2:
    {
       buyer(); 
    }
    case 3:
    {
        exit(0);
    }
    default:
    {
        cout<<"please select from given options";
    }
    }
goto m; 
}

void shopping :: administrator()
{
    int choice ;
    cout<<"\n\n\n\t\t\t Administrator menu";
    cout<<"\n\t\t\t|_____1) Add the Product_____|";
    cout<<"\n\t\t\t|                            |";
    cout<<"\n\t\t\t|_____2) Modify the Product__|";
    cout<<"\n\t\t\t|                            |";
    cout<<"\n\t\t\t|_____3) Delete the Product__|";
    cout<<"\n\t\t\t|                            |";



}







