#include<iostream>
#include<fstream>

using namespace std;

class shopping
{
    private:
    int pcode;
    float price;
    float dis;
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
    m:
    int choice ;
    cout<<"\n\n\n\t\t\t Administrator menu";
    cout<<"\n\t\t\t|_____1) Add the Product_____|";
    cout<<"\n\t\t\t|                            |";
    cout<<"\n\t\t\t|_____2) Modify the Product__|";
    cout<<"\n\t\t\t|                            |";
    cout<<"\n\t\t\t|_____3) Delete the Product__|";
    cout<<"\n\t\t\t|                            |";
    cout<<"\n\t\t\t|_____4) Back to main menu___|";

    cout<<"\n\n\t Please Enter your choice";

    cin>>choice;

    switch (choice)
    {
    case 1:
        add();
        break;
    case 2:
        edit();
        break;    
    case 3:
        rem();
        break;
    case 4:
        menu();    
    default:
        cout<<"Invalid choice! ";
     
    }
   goto m;

}

void shopping :: buyer()
{
    m:
   int choice;
   cout<<"\t\t\t Buyer \n";
   cout<<"\t\t\t _________________\n";
   cout<<"                \n";
   cout<<"\t\t\t 1) Buy product \n";
   cout<<"                \n";
   cout<<"\t\t\t 2) Go back  \n";
   cout<<"\t\t\t Enter your choice : ";
   cin>>choice;

   switch (choice)
   {
   case 1:
       receipt();
       break;
   case 2:
       menu();

   default:
     cout<<"Invalid Choice";
    break;
   }
   goto m;
}

void shopping :: add()
{
    fstream data;                 
    int c ;
    int token=0;
    float p;
    float d;
    string n;

    cout<<"\n\n\t\t\t Add new product";
    cout<<"\n\n\t Product code of the product";
    cin>>pcode;
    cout<<"\n\n Name of the product";
    cin>>pname;
    cout<<"\n\n\t Price of the product";
    cin>>price;
    cout<<"\n\n\t Discount on the product";
    cin>>dis;

    data.open("database.txt",ios::in);
    if(!data)
    {
        data.open("database.txt",ios::app|ios::out);        //This ios prefix is used to open a file and append it to the end.
        data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<" "<<"\n";
        data.close();
    }
    else{
        data>>c>>n>>p>>d;
        while (!data.eof())                  //End of file fuction
                                            //while loop for checking every contant of file
     {
            if(c==pcode)
            {
                token++;
            }
            data>>c>>n>>p>>d;
        }
        
    }
}





