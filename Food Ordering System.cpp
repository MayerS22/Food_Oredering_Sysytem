#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include<fstream>
#include <stdlib.h>
#include <time.h>
#include<windows.h>
using namespace std;
HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
int* pointer, counter;
time_t now = time(0);
char* date_time = ctime(&now);
ifstream UN, Pass;
struct date {
    int d;
    int m;
    int y;
};
struct acc {
    string username = "";
    string phoneNumber = "";
    string Email = "";
    string pass = "";
    string passconf = "";
    date dob;
}user[100];
void selectitem(int y);
double Price(int x);
void TotalPrice(int x);
void TotalPrice();
bool Register();
bool login();
void MM1();
void MM2();
void SEarch();
void edit();
struct bfastmenuitem //defintion of a struct to store data for breakfast 
{
    string MenuList;
    double pricesmall, pricemedium, pricelarge, calories;
    double price;
};

struct lunchmenuitem
{
    double pricesmall, pricemedium, pricelarge, calories;
};

struct drinkmenuitem
{
    double pricesmall, pricemedium, pricelarge, calories;
};

struct CheckOut
{
    double TOTAL, QTY, PRICE;
    string iteem;

}list[100] = {};

bfastmenuitem MenuItem[40];

void bfastgetdata(); //prototype of a function to loads breakfast data about the items in struct
void bfastshowmenu(); // prototype of a function show the breakfast menu 


void lunchgetdata(); //prototype of a function to loads lunch data about the items in struct
void lunchshowmenu(); // prototype of a function show the lunch menu 


void drinkgetdata(); //prototype of a function to loads drink data about the items in struct
void drinkshowmenu(); // prototype of a function show the drink menu 




int main()
{
    MM1();
    MM2();
    TotalPrice();
}
void MM1() {
    char x;
    int choice;
    SetConsoleTextAttribute(h, 11);
    cout << "|_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_|Welcome|_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_|";
    cout << "\n\n press [1] to register\t press [2] to login\n"; cin >> choice;

    if (choice == 1)
    {
        system("cls");
        x = Register();
        if (x == false)
        {
            exit(EXIT_FAILURE);
        }
    }
    if (choice == 2)
    {
        system("cls");
        x = login();
        if (x == false)
        {
            exit(EXIT_FAILURE);
        }
    }
    while (choice != 1 && choice != 2)
    {
        system("cls");
        cout << "\t Invalid choice \n\t try again";
        cout << "\n\n press [1] to register\t press [2] to login\n"; cin >> choice;

        if (choice == 1)
        {
            x = Register();
            if (x == false)
            {

                exit(EXIT_FAILURE);

            }
        }
        if (choice == 2)
        {
            x = login();
            if (x == false)
            {

                exit(EXIT_FAILURE);

            }
        }
    }
}

void MM2() {
    char z;
    int y, ind = 0;
    pointer = &ind;

    do {

        cout << "+=====================================================+\n\n";
        cout << " press[1] for BreakFast\t press[2] for Lunch\n\n press[3] for Drinks\t press[4] for search" << endl;
        cin >> y;
        while (y > 4 && y < 1)
        {
            cout << "press[1] for BreakFast\t press[2] for Lunch\n press[3] for Drinks\t press[4] for Appetizers & Extras" << endl;
            cin >> y;
        }


        switch (y)
        {
        case 1:
            bfastgetdata();
            bfastshowmenu();
            break;
        case 2:
            lunchgetdata();
            lunchshowmenu();
            break;
        case 3:
            drinkgetdata();
            drinkshowmenu();
            break;

        case 4:
            SEarch();
            break;
        }
        selectitem(y);

        cout << "\n\tpress [y] To Do Another Operation || Press[c] For Checkout || Press[e] For Edit Your Order\n";
        cin >> z;
        system("cls");
        if (z == 'y' || z == 'Y')
        {
            ind++;
        }
        if (z == 'e' || z == 'E')
        {
            edit();
            TotalPrice();
        }
    } while (z == 'y' || z == 'Y');
}

bool Register() {
    ofstream User, Pass, Data;
    char choice;
    int i = 0;


    cout << " Please enter username :\n"; cin.ignore(); getline(cin, user[i].username);     //username done

    cout << " Please enter phone number :\n"; cin >> user[i].phoneNumber;   //phonenumber done

    cout << " Please enter email :\n"; cin >> user[i].Email;  //email done

    cout << " Please enter Date of birth \n Day: "; cin >> user[i].dob.d;
    cout << "Month: "; cin >> user[i].dob.m;
    cout << "Year: "; cin >> user[i].dob.y;  //dob done

    cout << " Please enter password :\n\t\t";
    cout << "*The password must be diffrent of user name*\n\t\t*Atleast 8 charachters*\n "; //password notes
    cin >> user[i].pass;    //password done

    cout << " confirmation password :\n"; cin >> user[i].passconf;   //password confirmation

    //check for all data
    while (user[i].pass != user[i].passconf || user[i].pass.length() < 8 || user[i].phoneNumber.length() < 11 || user[i].phoneNumber.length() != 11 || user[i].dob.d > 31 || user[i].dob.m > 12 || user[i].dob.y > 2017)
    {
        if (user[i].dob.d > 31 || user[i].dob.m > 12 || user[i].dob.y > 2022)    //case 1 eltari5 3'lt
        {
            system("cls");
            cout << "invalid date";
            cout << " Please enter Date of birth \n Day: "; cin >> user[i].dob.d;
            cout << "Month: "; cin >> user[i].dob.m;
            cout << "Year: "; cin >> user[i].dob.y;  //dob done


        }
        if (user[i].dob.y > 2017)   //case 2 underage user
        {
            system("cls");
            cout << "Your age are not allowed";
            return false;
            break;

        }
        if (user[i].pass.length() < 8 && user[i].pass != user[i].passconf && user[i].phoneNumber.length() != 11)   //case 3 all data wrong
        {
            system("cls");
            cout << "Register faild\n\t\t The password is short ,don't identical and phone nummber is invalid \nTry again\n";
            user[i].phoneNumber.erase(); user[i].pass.erase(); user[i].passconf.erase();
            cout << "Please enter password :\n"; getline(cin, user[i].pass);
            cout << "confirmation password :\n"; getline(cin, user[i].passconf);
            cout << " Please enter phone number :\n"; cin >> user[i].phoneNumber;
        }
        if (user[i].phoneNumber.length() != 11) // case 4 phone number wrong
        {
            system("cls");
            cout << "Register faild\n\t\t The phone number is invalid\nTry again\n";
            user[i].phoneNumber.erase();
            cout << " Please enter phone number :\n"; cin >> user[i].phoneNumber;

        }
        if (user[i].pass != user[i].passconf) //case 5 el pass m4 zay b3d
        {
            system("cls");
            cout << "Register faild\n\t\t The password not identical\nTry again\n";
            user[i].pass.erase(); user[i].passconf.erase();
            cout << "Please enter password :\n"; getline(cin, user[i].pass);
            cout << "confirmation password :\n"; getline(cin, user[i].passconf);
        }
        if (user[i].pass.length() < 8)   //case 6 password short 
        {
            system("cls");
            cout << "Register faild\n\t\t The password is short\nTry again\n";
            user[i].pass.erase(); user[i].passconf.erase();
            cout << "Please enter password :\n"; getline(cin, user[i].pass);
            cout << "confirmation password :\n"; getline(cin, user[i].passconf);
        }

    }
    if (user[i].pass == user[i].passconf && user[i].pass.length() >= 8 && user[i].phoneNumber.length() == 11)  // kol haga tmam
    {
        system("cls");
        User.open("signUpUser.txt", ios::out | ios::app);
        User << "\n" << date_time << "\n" << "User[" << i + 1 << "] :\n" << user[i].username << "\n";
        User << "------------------------------------------------------------------------------------------";
        User.close();
        Data.open("signUpData.txt", ios::out | ios::app);
        Data << "\n" << date_time << "\n" << "User[" << i + 1 << "] :" << "\nPhone Number : " << user[i].phoneNumber << "\n Date Of Birth :" << user[i].dob.y << "/" << user[i].dob.m << "/" << user[i].dob.d << "\n Email :" << user[i].Email << "\n";
        Data << "------------------------------------------------------------------------------------------";
        Data.close();
        Pass.open("signUpPass.txt", ios::out | ios::app);
        Pass << "\n" << date_time << "\n" << "User[" << i + 1 << "] :\n" << user[i].pass << "\n";
        Pass << "------------------------------------------------------------------------------------------";
        Pass.close();
        cout << "\nRegister completed\n";
        for (int i = 0; i < 15; i++)
        {
            system("color a0");
        }
        system("color 07");
    }
    system("cls");
    cout << "\n            Welcome  $" << user[i].username << "$  to FCIS Burger Factory        \n ";
}
bool login() {
    string un, p;     //variables nqaren bin elly mtsgl we elly haid5lo
    int counter = 3;
    size_t s, u;
    bool y = 0, x = 0;
    UN.open("signUpUser.txt");
    Pass.open("signUpPass.txt");
    cout << " Please enter user name :\n"; cin.ignore(); getline(cin, user[99].username);
    cout << " Please enter password :\n";  cin.ignore(); getline(cin, user[99].pass);
    while (UN.good())
    {
        getline(UN, un); // get line from file
        u = un.find(user[99].username); // search
        if (u != string::npos)// string::npos is returned if string is not found  
        {
            x = 1;
        }
        while (Pass.good())
        {
            getline(Pass, p);
            s = p.find(user[99].pass);
            if (s != string::npos) // string::npos is returned if string is not found
            {
                y = 1;
                break;
            }

        }

        if (y && x)
        {
            system("cls");
            cout << "Login Successful\n";
            UN.close();
            Pass.close();
            for (int i = 0; i < 15; i++)//flash green screen 
            {
                system("color a0");//a a bg color &&  0 font color

            }
            system("color 07");
            system("cls");
            cout << "\n            Welcome  $" << user[99].username << "$  to FCIS Burger Factory        \n ";
            return true;
        }
    }
    if (y != 1 || x != 1)
    {
        do
        {
            system("cls");
            UN.close();
            Pass.close();
            UN.open("signUpUser.txt");
            Pass.open("signUpPass.txt");
            cout << "Login faild\n try again\t" << "You have\t" << counter << "  ATTEMPT(S)\n";
            user[99].username.clear(); user[99].pass.clear();
            cout << " Please enter user name :\n"; cin.ignore(); getline(cin, user[99].username);
            cout << " Please enter password :\n"; cin >> user[99].pass;
            while (UN.good())
            {
                getline(UN, un); // get line from file
                u = un.find(user[99].username); // search
                if (u != string::npos)
                {
                    x = 1;
                }
                while (Pass.good())
                {
                    getline(Pass, p);
                    s = p.find(user[99].pass);
                    if (s != string::npos) // string::npos is returned if string is not found
                    {
                        y = 1;
                        break;
                    }
                    else
                    {
                        break;
                    }
                }
            }
            UN.close();
            Pass.close();
            if (counter == 0)
            {
                system("cls");
                system("color 0c");// red color due to failed to login
                cout << "\t\t###########################\n";
                cout << "\t\t# YOU HAVE BEEN BANNED !! #";
                cout << "\n\t\t###########################\n\n";
                return false;
            }
            counter--;
        } while (y != 1 || x != 1);
    }
    if (y && x)
    {
        system("cls");
        cout << "Login Successful\n";
        UN.close();
        Pass.close();
        for (int i = 0; i < 15; i++)
        {
            system("color a0");

        }
        system("color 07");
        system("cls");
        cout << "\n            Welcome  $" << user[99].username << "$  to FCIS Burger Factory        \n ";
        return true;
    }
}

void bfastgetdata()
{
    MenuItem[0].MenuList = "Toast";
    MenuItem[0].pricesmall = 2.00;
    MenuItem[0].pricemedium = 3.00;
    MenuItem[0].pricelarge = 4.00;
    MenuItem[0].calories = 313.00;
    MenuItem[1].MenuList = "Egg muffin";
    MenuItem[1].pricesmall = 3.00;
    MenuItem[1].pricemedium = 5.00;
    MenuItem[1].pricelarge = 6.00;
    MenuItem[1].calories = 139.00;
    MenuItem[2].MenuList = "Egg benedict";
    MenuItem[2].pricesmall = 3.00;
    MenuItem[2].pricemedium = 5.00;
    MenuItem[2].pricelarge = 6.00;
    MenuItem[2].calories = 276.00;
    MenuItem[3].MenuList = "Croissant";
    MenuItem[3].pricesmall = 5.00;
    MenuItem[3].pricemedium = 6.50;
    MenuItem[3].pricelarge = 8.00;
    MenuItem[3].calories = 406.00;
    MenuItem[4].MenuList = "Raspberry pie";
    MenuItem[4].pricesmall = 3.50;
    MenuItem[4].pricemedium = 5.00;
    MenuItem[4].pricelarge = 6.50;
    MenuItem[4].calories = 422.00;
    MenuItem[5].MenuList = "Granola parfait";
    MenuItem[5].pricesmall = 3.00;
    MenuItem[5].pricemedium = 5.00;
    MenuItem[5].pricelarge = 7.00;
    MenuItem[5].calories = 426.00;
    MenuItem[6].MenuList = "Biscuits";
    MenuItem[6].pricesmall = 2.00;
    MenuItem[6].pricemedium = 3.50;
    MenuItem[6].pricelarge = 5.00;
    MenuItem[6].calories = 353.00;
    MenuItem[7].MenuList = "Hash browns";
    MenuItem[7].pricesmall = 5.00;
    MenuItem[7].pricemedium = 7.00;
    MenuItem[7].pricelarge = 10.00;
    MenuItem[7].calories = 326.00;
    MenuItem[8].MenuList = "Potato puree";
    MenuItem[8].pricesmall = 3.00;
    MenuItem[8].pricemedium = 5.00;
    MenuItem[8].pricelarge = 6.00;
    MenuItem[8].calories = 88.00;
    MenuItem[9].MenuList = "Roasted veggies";
    MenuItem[9].pricesmall = 4.00;
    MenuItem[9].pricemedium = 6.00;
    MenuItem[9].pricelarge = 7.50;
    MenuItem[9].calories = 113.00;
}
void bfastshowmenu()
{
    system("cls");
    SetConsoleTextAttribute(h, 12);
    cout << "                Welcome to FCIS Burger Factory.          \n ";
    cout << "             +==================================+          \n\n";
    cout << "                  $  Breakfast Menu  $ \n\n";
    cout << "  && Please select the food that you would like to purchase. && \n\n\n";
    cout << "\t  Name \t\t          Small | Medium | Large | Calories\n" << endl;
    cout << "\t[1]" << MenuItem[0].MenuList << "\t           " << MenuItem[0].pricesmall << "\t|  " << MenuItem[0].pricemedium << "\t |  " << MenuItem[0].pricelarge << "\t |   " << MenuItem[0].calories << endl;
    cout << "\t[2]" << MenuItem[1].MenuList << "\t           " << MenuItem[1].pricesmall << "\t|  " << MenuItem[1].pricemedium << "\t |  " << MenuItem[1].pricelarge << "\t |   " << MenuItem[1].calories << endl;
    cout << "\t[3]" << MenuItem[2].MenuList << "\t           " << MenuItem[2].pricesmall << "\t|  " << MenuItem[2].pricemedium << "\t |  " << MenuItem[2].pricelarge << "\t |   " << MenuItem[2].calories << endl;
    cout << "\t[4]" << MenuItem[3].MenuList << "\t           " << MenuItem[3].pricesmall << "\t|  " << MenuItem[3].pricemedium << "\t |  " << MenuItem[3].pricelarge << "\t |   " << MenuItem[3].calories << endl;
    cout << "\t[5]" << MenuItem[4].MenuList << "           " << MenuItem[4].pricesmall << "\t|  " << MenuItem[4].pricemedium << "\t |  " << MenuItem[4].pricelarge << "\t |   " << MenuItem[4].calories << endl;
    cout << "\t[6]" << MenuItem[5].MenuList << "         " << MenuItem[5].pricesmall << "  \t|  " << MenuItem[5].pricemedium << "\t |  " << MenuItem[5].pricelarge << "\t |   " << MenuItem[5].calories << endl;
    cout << "\t[7]" << MenuItem[6].MenuList << "\t           " << MenuItem[6].pricesmall << "\t|  " << MenuItem[6].pricemedium << "\t |  " << MenuItem[6].pricelarge << "\t |   " << MenuItem[6].calories << endl;
    cout << "\t[8]" << MenuItem[7].MenuList << "\t           " << MenuItem[7].pricesmall << "\t|  " << MenuItem[7].pricemedium << "\t |  " << MenuItem[7].pricelarge << "\t |   " << MenuItem[7].calories << endl;
    cout << "\t[9]" << MenuItem[8].MenuList << "\t           " << MenuItem[8].pricesmall << "\t|  " << MenuItem[8].pricemedium << "\t |  " << MenuItem[8].pricelarge << "\t |   " << MenuItem[8].calories << endl;
    cout << "\t[10]" << MenuItem[9].MenuList << "        " << MenuItem[9].pricesmall << "\t|  " << MenuItem[9].pricemedium << "\t |  " << MenuItem[9].pricelarge << "\t |   " << MenuItem[9].calories << endl;
    cout << "\n\n";
    cout << "\t\t<<Note : All calories are calculated on the medium size>>      \n";
}

void lunchgetdata()
{
    MenuItem[10].MenuList = "BeefBurger";
    MenuItem[10].pricesmall = 10.00;
    MenuItem[10].pricemedium = 13.00;
    MenuItem[10].pricelarge = 15.00;
    MenuItem[10].calories = 257.00;
    MenuItem[11].MenuList = "CheeseBurger";
    MenuItem[11].pricesmall = 12.00;
    MenuItem[11].pricemedium = 15.00;
    MenuItem[11].pricelarge = 17.00;
    MenuItem[11].calories = 303.00;
    MenuItem[12].MenuList = "ChickenBurger";
    MenuItem[12].pricesmall = 10.00;
    MenuItem[12].pricemedium = 13.00;
    MenuItem[12].pricelarge = 15.00;
    MenuItem[12].calories = 283.00;
    MenuItem[13].MenuList = "Crispy Chicken Sandwich";
    MenuItem[13].pricesmall = 12.00;
    MenuItem[13].pricemedium = 15.00;
    MenuItem[13].pricelarge = 17.00;
    MenuItem[13].calories = 278.00;
    MenuItem[14].MenuList = "Chicken Nuggets";
    MenuItem[14].pricesmall = 8.00;
    MenuItem[14].pricemedium = 10.00;
    MenuItem[14].pricelarge = 12.00;
    MenuItem[14].calories = 296.00;
    MenuItem[15].MenuList = "Chicken Ranch Wrap";
    MenuItem[15].pricesmall = 14.00;
    MenuItem[15].pricemedium = 17.00;
    MenuItem[15].pricelarge = 20.00;
    MenuItem[15].calories = 430.00;
    MenuItem[16].MenuList = "Taco";
    MenuItem[16].pricesmall = 15.00;
    MenuItem[16].pricemedium = 18.00;
    MenuItem[16].pricelarge = 20.00;
    MenuItem[16].calories = 226.00;
    MenuItem[17].MenuList = "Steak";
    MenuItem[17].pricesmall = 20.00;
    MenuItem[17].pricemedium = 22.00;
    MenuItem[17].pricelarge = 25.00;
    MenuItem[17].calories = 271.00;
    MenuItem[18].MenuList = "Sushi";
    MenuItem[18].pricesmall = 10.00;
    MenuItem[18].pricemedium = 12.00;
    MenuItem[18].pricelarge = 15.00;
    MenuItem[18].calories = 37.00;
    MenuItem[19].MenuList = "macaroni with white sauce";
    MenuItem[19].pricesmall = 12.00;
    MenuItem[19].pricemedium = 15.00;
    MenuItem[19].pricelarge = 17.00;
    MenuItem[19].calories = 340.00;

}
void lunchshowmenu()
{
    system("cls");
    SetConsoleTextAttribute(h, 12);
    cout << "                Welcome to FCIS Burger Factory.          \n ";
    cout << "             +==================================+          \n\n";
    cout << "                   $  Lunch Menu  $ \n\n";
    cout << "  && Please select the food that you would like to purchase. && \n\n\n";
    cout << "\t  Name \t\t                  Small | Medium | Large | Calories\n" << endl;
    cout << "\t[1]" << MenuItem[10].MenuList << "\t\t           " << MenuItem[10].pricesmall << "\t|   " << MenuItem[10].pricemedium << "\t|   " << MenuItem[10].pricelarge << "\t|    " << MenuItem[10].calories << endl;
    cout << "\t[2]" << MenuItem[11].MenuList << "\t                   " << MenuItem[11].pricesmall << "\t|   " << MenuItem[11].pricemedium << "\t|   " << MenuItem[11].pricelarge << "\t|    " << MenuItem[11].calories << endl;
    cout << "\t[3]" << MenuItem[12].MenuList << "\t           " << MenuItem[12].pricesmall << "\t|   " << MenuItem[12].pricemedium << "\t|   " << MenuItem[12].pricelarge << "\t|    " << MenuItem[12].calories << endl;
    cout << "\t[4]" << MenuItem[13].MenuList << "\t   " << MenuItem[13].pricesmall << "  \t|   " << MenuItem[13].pricemedium << "\t|   " << MenuItem[13].pricelarge << "\t|    " << MenuItem[13].calories << endl;
    cout << "\t[5]" << MenuItem[14].MenuList << "\t           " << MenuItem[14].pricesmall << "\t|   " << MenuItem[14].pricemedium << "\t|   " << MenuItem[14].pricelarge << "\t|    " << MenuItem[14].calories << endl;
    cout << "\t[6]" << MenuItem[15].MenuList << "\t           " << MenuItem[15].pricesmall << "\t|   " << MenuItem[15].pricemedium << "\t|   " << MenuItem[15].pricelarge << "\t|    " << MenuItem[15].calories << endl;
    cout << "\t[7]" << MenuItem[16].MenuList << "\t                           " << MenuItem[16].pricesmall << "\t|   " << MenuItem[16].pricemedium << "\t|   " << MenuItem[16].pricelarge << "\t|    " << MenuItem[16].calories << endl;
    cout << "\t[8]" << MenuItem[17].MenuList << "\t                   " << MenuItem[17].pricesmall << "\t|   " << MenuItem[17].pricemedium << "\t|   " << MenuItem[17].pricelarge << "\t|    " << MenuItem[17].calories << endl;
    cout << "\t[9]" << MenuItem[18].MenuList << "\t                   " << MenuItem[18].pricesmall << "\t|   " << MenuItem[18].pricemedium << "\t|   " << MenuItem[18].pricelarge << "\t|    " << MenuItem[18].calories << endl;
    cout << "\t[10]" << MenuItem[19].MenuList << "\t   " << MenuItem[19].pricesmall << "\t|   " << MenuItem[19].pricemedium << "\t|   " << MenuItem[19].pricelarge << "\t|    " << MenuItem[19].calories << endl;
    cout << "\n\n";
    cout << "\t\t<<Note : All calories are calculated on the medium size>>      \n";
}


void drinkgetdata()
{
    MenuItem[20].MenuList = "Caffe Americano";
    MenuItem[20].pricesmall = 5.00;
    MenuItem[20].pricemedium = 7.00;
    MenuItem[20].pricelarge = 10.00;
    MenuItem[20].calories = 15.00;
    MenuItem[21].MenuList = "Cappuccino";
    MenuItem[21].pricesmall = 7.00;
    MenuItem[21].pricemedium = 9.00;
    MenuItem[21].pricelarge = 12.00;
    MenuItem[21].calories = 140.00;
    MenuItem[22].MenuList = "White Chocolate Mocha";
    MenuItem[22].pricesmall = 8.00;
    MenuItem[22].pricemedium = 10.00;
    MenuItem[22].pricelarge = 12.00;
    MenuItem[22].calories = 430.00;
    MenuItem[23].MenuList = "Lotus Latte Frappé";
    MenuItem[23].pricesmall = 12.00;
    MenuItem[23].pricemedium = 15.00;
    MenuItem[23].pricelarge = 18.00;
    MenuItem[23].calories = 267.00;
    MenuItem[24].MenuList = "Tea";
    MenuItem[24].pricesmall = 2.00;
    MenuItem[24].pricemedium = 3.00;
    MenuItem[24].pricelarge = 5.00;
    MenuItem[24].calories = 1.00;
    MenuItem[25].MenuList = "Lemonade";
    MenuItem[25].pricesmall = 7.00;
    MenuItem[25].pricemedium = 8.50;
    MenuItem[25].pricelarge = 10.00;
    MenuItem[25].calories = 40.00;
    MenuItem[26].MenuList = "Orange";
    MenuItem[26].pricesmall = 7.00;
    MenuItem[26].pricemedium = 8.50;
    MenuItem[26].pricelarge = 10.00;
    MenuItem[26].calories = 45.00;
    MenuItem[27].MenuList = "Mango";
    MenuItem[27].pricesmall = 10.00;
    MenuItem[27].pricemedium = 12.00;
    MenuItem[27].pricelarge = 15.00;
    MenuItem[27].calories = 128.00;
    MenuItem[28].MenuList = "Strawberry Banana Smoothie";
    MenuItem[28].pricesmall = 10.00;
    MenuItem[28].pricemedium = 13.50;
    MenuItem[28].pricelarge = 17.00;
    MenuItem[28].calories = 240.00;
    MenuItem[29].MenuList = "Mango Pineapple Smoothie";
    MenuItem[29].pricesmall = 10.00;
    MenuItem[29].pricemedium = 13.50;
    MenuItem[29].pricelarge = 17.00;
    MenuItem[29].calories = 250.00;
}
void drinkshowmenu()
{
    system("cls");
    SetConsoleTextAttribute(h, 12);
    cout << "                Welcome to FCIS Burger Factory.          \n ";
    cout << "             +==================================+          \n\n";

    cout << "                    $  Drinks Menu  $ \n\n";
    cout << "  && Please select the food that you would like to purchase. && \n\n\n";
    cout << "\t  Name \t\t                     Small | Medium | Large | Calories\n" << endl;
    cout << "\t[1]" << MenuItem[20].MenuList << "\t\t      " << MenuItem[20].pricesmall << "\t   |   " << MenuItem[20].pricemedium << "    |\t" << MenuItem[20].pricelarge << "  |\t" << MenuItem[20].calories << endl;
    cout << "\t[2]" << MenuItem[21].MenuList << "\t                      " << MenuItem[21].pricesmall << "\t   |   " << MenuItem[21].pricemedium << "    |   " << MenuItem[21].pricelarge << "  |   " << MenuItem[21].calories << endl;
    cout << "\t[3]" << MenuItem[22].MenuList << "\t      " << MenuItem[22].pricesmall << "\t   |   " << MenuItem[22].pricemedium << "   |\t" << MenuItem[22].pricelarge << "  |   " << MenuItem[22].calories << endl;
    cout << "\t[4]" << MenuItem[23].MenuList << "\t              " << MenuItem[23].pricesmall << "   |   " << MenuItem[23].pricemedium << "   |\t" << MenuItem[23].pricelarge << "  |   " << MenuItem[23].calories << endl;
    cout << "\t[5]" << MenuItem[24].MenuList << "\t\t                      " << MenuItem[24].pricesmall << "    |   " << MenuItem[24].pricemedium << "    |\t" << MenuItem[24].pricelarge << "   |   " << MenuItem[24].calories << endl;
    cout << "\t[6]" << MenuItem[25].MenuList << "\t\t              " << MenuItem[25].pricesmall << "    |   " << MenuItem[25].pricemedium << "  |   " << MenuItem[25].pricelarge << "  |   " << MenuItem[25].calories << endl;
    cout << "\t[7]" << MenuItem[26].MenuList << "\t\t              " << MenuItem[26].pricesmall << "    |   " << MenuItem[26].pricemedium << "  |   " << MenuItem[26].pricelarge << "  |   " << MenuItem[26].calories << endl;
    cout << "\t[8]" << MenuItem[27].MenuList << "\t\t              " << MenuItem[27].pricesmall << "   |   " << MenuItem[27].pricemedium << "   |   " << MenuItem[27].pricelarge << "  |   " << MenuItem[27].calories << endl;
    cout << "\t[9]" << MenuItem[28].MenuList << "\t      " << MenuItem[28].pricesmall << "   |   " << MenuItem[28].pricemedium << " |   " << MenuItem[28].pricelarge << "  |   " << MenuItem[28].calories << endl;
    cout << "\t[10]" << MenuItem[29].MenuList << "\t      " << MenuItem[29].pricesmall << "   |   " << MenuItem[29].pricemedium << " |   " << MenuItem[29].pricelarge << "  |   " << MenuItem[29].calories << endl;
    cout << "\n\n";
    cout << "\t          <<Note : All calories are calculated on the medium size>>      \n";
}


void selectitem(int y)
{
    int ch, quantity;
    char con, size;

    if (y == 1)
    {
        cout << "Enter the item number that you want to order :  ";
        cin >> ch;

        switch (ch)
        {
        case 1:
            ch = ch - 1;
            TotalPrice(ch);
            break;
        case 2:
            ch = ch - 1;
            TotalPrice(ch);
            break;
        case 3:
            ch = ch - 1;
            TotalPrice(ch);
            break;
        case 4:
            ch = ch - 1;
            TotalPrice(ch);
            break;
        case 5:
            ch = ch - 1;
            TotalPrice(ch);
            break;
        case 6:
            ch = ch - 1;
            TotalPrice(ch);
            break;
        case 7:
            ch = ch - 1;
            TotalPrice(ch);
            break;
        case 8:
            ch = ch - 1;
            TotalPrice(ch);
            break;
        case 9:
            ch = ch - 1;
            TotalPrice(ch);
            break;
        case 10:
            ch = ch - 1;
            TotalPrice(ch);
            break;
        }
    }
    if (y == 2)
    {


        cout << "Enter the item number that you want to order :  ";
        cin >> ch;

        switch (ch)
        {
        case 1:
            ch = ch + 9;
            TotalPrice(ch);
            break;
        case 2:
            ch = ch + 9;
            TotalPrice(ch);
            break;
        case 3:
            ch = ch + 9;
            TotalPrice(ch);
            break;
        case 4:
            ch = ch + 9;
            TotalPrice(ch);
            break;
        case 5:
            ch = ch + 9;
            TotalPrice(ch);
            break;
        case 6:
            ch = ch + 9;
            TotalPrice(ch);
            break;
        case 7:
            ch = ch + 9;
            TotalPrice(ch);
            break;
        case 8:
            ch = ch + 9;
            TotalPrice(ch);
            break;
        case 9:
            ch = ch + 9;
            TotalPrice(ch);
            break;
        case 10:
            ch = ch + 9;
            TotalPrice(ch);
            break;
        }

    }
    if (y == 3)
    {


        cout << "Enter the item number that you want to order :  ";
        cin >> ch;

        switch (ch)
        {
        case 1:
            ch = ch + 19;
            TotalPrice(ch);
            break;
        case 2:
            ch = ch + 19;
            TotalPrice(ch);
            break;
        case 3:
            ch = ch + 19;
            TotalPrice(ch);
            break;
        case 4:
            ch = ch + 19;
            TotalPrice(ch);
            break;
        case 5:
            ch = ch + 19;
            TotalPrice(ch);
            break;
        case 6:
            ch = ch + 19;
            TotalPrice(ch);
            break;
        case 7:
            ch = ch + 19;
            TotalPrice(ch);
            break;
        case 8:
            ch = ch + 19;
            TotalPrice(ch);
            break;
        case 9:
            ch = ch + 19;
            TotalPrice(ch);
            break;
        case 10:
            ch = ch + 19;
            TotalPrice(ch);
            break;
        }

    }
}
int Quantity()
{
    int quantity;
    cout << "please enter quantity :  ";
    cin >> quantity;
    list[*pointer].QTY = quantity;
    return quantity;
}
double Price(int x)
{
    double price;
    char size;
    do {
        cout << "please enter size (s: for small , m: for medium , l: for large ) :  ";
        cin >> size;
        switch (size)
        {
        case 's':
        case 'S':
            price = MenuItem[x].pricesmall * Quantity();
            cout << "price : " << price;
            break;
        case 'm':
        case 'M':
            price = MenuItem[x].pricemedium * Quantity();
            cout << "price : " << price;
            break;
        case 'l':
        case 'L':
            price = MenuItem[x].pricelarge * Quantity();
            cout << "price : " << price;
            break;
        }
    } while (size != 'l' && size != 'L' && size != 's' && size != 'S' && size != 'm' && size != 'M');
    return price;
}
void TotalPrice(int x)
{
    list[*pointer].PRICE = Price(x);
    list[*pointer].iteem = MenuItem[x].MenuList;
    counter = list[*pointer].PRICE + counter;
    list[*pointer].TOTAL = counter;
}
void TotalPrice()
{
    double cash;
    srand(time(0));
    system("CLS");
    SetConsoleTextAttribute(h, 2);
    cout << "|_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_|CHECKOUT|_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_|";
    if (list[*pointer].QTY == 0)
    {
        cout << "\tYou Orderd Nothing ! \n\t Please Make Order First ";
        MM2();
    }
    cout << "\n\n\t\t\t" << date_time << "\n\n";
    cout << "\t\t\t\t Order # " << rand() % 100;
    cout << "\n-------------------------------------------------------------------------------\n";
    cout << "-------------------------------------------------------------------------------\n";
    cout << "\t" << "QTY" << "\t\t" << "ITEM" << "\t\t\t\t" << "PRICE";
    for (int i = 0; i <= *pointer; i++)
    {
        if (list[i].PRICE == 0)
        {
            continue;
        }
        cout << "\n\t" << list[i].QTY << "\t\t" << list[i].iteem << "\t\t\t" << list[i].PRICE << "\n";
    }
    cout << "-------------------------------------------------------------------------------\n";
    cout << "\t\tTotal Bill :" << list[*pointer].TOTAL << "\n";
    cout << "\t\tCash Tendered :"; cin >> cash;
    while (cash < list[*pointer].TOTAL)
    {
        cout << "insufficient funds\n";
        cout << "\t\tCash Tendered :"; cin >> cash;
    }
    cout << "\t\tChange :" << cash - list[*pointer].TOTAL;
    cout << "\n-------------------------------------------------------------------------------\n";
    cout << "\t\t\t\3 We wish you a sweet meal \3\n";
    cout << "\t\t\t\3 Thanks For Visiting \3\n";
    cout << "_________________________________________________________________________________\n";
    exit(EXIT_FAILURE);
}
void SEarch() {
    bfastgetdata();
    lunchgetdata();
    drinkgetdata();
    string search;
    int u;
    int index;
    bool x = 0;
    char z, s;
    system("CLS");
    do {
        SetConsoleTextAttribute(h, 5); //colour
        cout << "Please Enter The Item You Want to Search For : ";
        cin.ignore(); getline(cin, search); // to ignore spaces 
        for (int i = 0; i < 30; i++) // loop for search on each item in the menu list
        {


            if (search == MenuItem[i].MenuList) //comparing the string with each item in the menu
            {
                x = 1; //bool changed to true
                index = i;
                break;
            }
        }
        if (x == 1)
        {
            cout << "The Item is found : \n\t";
            cout << MenuItem[index].MenuList;

            if (index < 10)
            {
                cout << "\t In Breakfast Menu \t Press[y] To Check It | Press[b] To Get Back To Main Menu";
                cin >> z;
                if (z == 'Y' || z == 'y')
                {
                    bfastshowmenu();
                    do
                    {
                        cout << "\n Press[B] To Get Back To Main Menu";
                        cin >> s;
                    } while (s != 'B' && s != 'b');
                    if (s == 'B' || s == 'b') {

                        break;
                    }
                }
                else
                {

                    break;
                }
            }
            if (index < 20 && index >= 10)
            {

                cout << "\t In Lunch Menu \t Press[y] To Check It | Press[B] To Get Back To Main Menu";
                cin >> z;
                if (z == 'Y' || z == 'y')
                {
                    lunchshowmenu();
                    do
                    {
                        cout << "\n Press[B] To Get Back To Main Menu";
                        cin >> s;
                    } while (s != 'B' && s != 'b');
                    if (s == 'B' || s == 'b')
                    {

                        break;
                    }
                }
                else
                {

                    break;
                }
            }
            if (index < 30 && index >= 20)
            {
                cout << "\t In Drinks Menu \t Press[y] To Check It | Press[B] To Get Back To Main Menu";
                cin >> z;
                if (z == 'Y' || z == 'y')
                {
                    drinkshowmenu();
                    do
                    {
                        cout << "\n Press[B] To Get Back To Main Menu";
                        cin >> s;
                    } while (s != 'B' && s != 'b');
                    if (s == 'B' || s == 'b')
                    {

                        break;
                    }
                }
                else
                {
                    break;
                }
            }

        }
        else
        {
            cout << "The Item Is not found : \n\t";
            break;
        }

    } while (x == 0);
}

void edit()
{
    char x;
    int counter, S, qty;
    do {

        cout << "\n-------------------------------------------------------------------------------\n";
        cout << "-------------------------------------------------------------------------------\n";
        cout << "\t" << "QTY" << "\t\t" << "ITEM";
        for (int i = 0; i <= *pointer; i++)
        {
            cout << "\n   [" << i + 1 << "] " << list[i].QTY << "\t\t" << list[i].iteem << "\n";
            counter = *pointer + 1;
        }
        cout << "-------------------------------------------------------------------------------\n";


        cout << "Enter The Item Num for Delete : \n"; cin >> S;
        for (int i = S; i <= counter; i++)
        {
            list[i].TOTAL = list[i].TOTAL - list[i - 1].PRICE;
            list[i - 1].iteem = list[i].iteem;
            list[i - 1].PRICE = list[i].PRICE;
            list[i - 1].QTY = list[i].QTY;
        }

        cout << "Do Another Deletion y/n";
        cin >> x;

    } while (x == 'y' || x == 'Y');
}