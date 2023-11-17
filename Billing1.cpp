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
    m:
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
        data.close();
    }

    if(token==1)   
    goto m;
    else {
        data.open("database.txt",ios::app|ios::out);        
        data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<" "<<"\n";
        data.close();
    }
    cout<<"\n\n\t\t Record Inserted! ";
}
 
void shopping :: edit()
{
    fstream data, data1;
    int pkey;
    int token=0;
    int c; 
    float p;
    float d;
    string n ;
    cout<<"\n\t\t\t Modify the record";
    cout<<"\n\t\t\t Product code :";
    cin>>pkey;

    data.open("database.txt",ios::in);
    if(!data)
    {
        cout<<"\n\n File doesn't exist! ";
    }
    else {
        data1.open("database1.txt",ios::app|ios::out);  //Here we will save edited data in new file 
        data>>pcode>>pname>>price>>dis;
        while (!data.eof())
        {
            if(pkey==pcode){        
                cout<<"\n\t\t Product new code : ";
                cin>>c;
                cout<<"\n\t\t Name of the product :";
                cin>>n;
                cout<<"\n\t\t Price ";
                cin>>p;
                cout<<"\n\t\t Discount :";
                cin>>d;
                data1<<" "<<c<<" "<<n<<" "<<p<<" "<<d<<"\n";
                cout<<"\n\n\t\t Record Edited";
                token++;
            }
            else    //if ProductCode doesn't matches  within the  file then add in the new file  
            {
                data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
            }
            data>>pcode>>pname>>price>>dis;
        }
        data.close();
        data1.close();
                          //Rename database back to original database
        remove("database.txt");    
        rename("database1.txt","database.txt");

        if(token==0)
        {
            cout<<"\n\n Record not found sorry! ";
        }
    }

}

void shopping :: rem()
{
    fstream data, data1;
    int pkey;
    int token=0;
    cout<<"\n\n\t Delete product";
    cout<<"\n\n\t Product code: ";
    cin>>pkey;
    data.open("database.txt",ios::in);
    if(!data)
    {
        cout<<"File doesn't Exist";
    }
    else{
        data1.open("database1.txt",ios::app|ios::out);
        data>>pcode>>pname>>price>>dis;
        while (!data.eof())        //pkey entered by the administator it matches to product code if block exicute
        {
            if(pcode==pkey){
                cout<<"\n\n\t Product deleted Successfully";
                token++;
            }
            else{        // Not matches then data1 file displayed
                data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
            }
             data>>pcode>>pname>>price>>dis;
        }
        data.close();
        data1.close();

         remove("database.txt");    
         rename("database1.txt","database.txt");

       if(token==0)
        {
            cout<<"\n\n Record not found  ";
        }
        
    }


}

void shopping:: list()
{
    fstream data;
    data.open("database.txt",ios::in);
    cout<<"\n\n|________________________________________________\n";
    cout<<"ProNo\t\tName\t\tPrice\n";
    cout<<"\n\n|________________________________________________\n";
    data>>pcode>>pname>>price>>dis;
    while(!data.eof())              //for iteration from the list
    {
        cout<<pcode<<"\t\t"<<pname<<"\t\t"<<price<<"\n";
        data>>pcode>>pname>>price>>dis;

    }
    data.close();
}
void shopping :: receipt()
{
    m:
    fstream data;
    int arrc[100];
    int arrq[100];
    char choice;
    char c=0;
    float amount=0;
    float dis=0;
    float total=0;

    cout<<"\n\n\t\t\t\t RECEPT ";
    data.open("database.txt",ios::in);
    if(!data)
    {
        cout<<"\n\n Empty database";
    }
    else
    {
        data.close();
        list();
        cout<<"\n_________________________________________\n";
        cout<<"\n|                                        \n";
        cout<<"\n           Please Place the order        \n";
        cout<<"\n|                                        \n";
        cout<<"\n_________________________________________\n";
        do
        {
            cout<<"\n\n Enter Product code :";
            cin>>arrc[c];
            cout<<"\n\nEnter the product Quantity :";
            cin>>arrq[c];
            for(int i=0; i<c;i++)
            {
                if(arrc[c]==arrc[i])
                {
                    cout<<"\n\n Duplicate Product code, please try again";
                    goto m;
                }
            }
            c++;
            cout<<"\n\n Do you want to buy another product? if yes then press y else no";
            cin>>choice;

        }while(choice =='y');
       
        cout<<"\n\n\t\t\t______________________RECEIPT_____________________\n";
        cout<<"\n Product No \t product Name \t product quantity\tprice\tAmount\tAmount with discount\n";
        for(int i=0; i<c;i++)
        {
            data.open("database.txt",ios::in);
            data>>pcode>>pname>>price>>dis;
            while(!data.eof())
            {
                if(pcode==arrc[i])
                {
                    amount=price*arrc[i];
                    dis=amount*(dis/100);
                    total=total+dis;
                    cout<<"\n"<<pcode<<pname<<arrc[i]<<price<<amount<<dis;
                }
                data>>pcode>>pname>>price>>dis;
            }
        }
        data.close();
    }
      cout<<"\n\n___________________________________________________________";
      cout<<"\n Total Amount : "<<total;


}


int main()
{
    shopping s;
    s.menu();


}



