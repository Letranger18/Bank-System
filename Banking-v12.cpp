/* 

C++ Banking System | FEU Institute of Technology (2021)
Made by: Greg Allen Padilla, John Benedict Signo, John Christopher Punzalan, Victoria Faye Babasa
CCS006L Final Project

*/

#include <iostream>
#include <unistd.h>
#include <iomanip>
#include <fstream>
#define max 50

using namespace std;

// tab spacing
string tab = "\n\t ";

// arrays to store user data
string accountNo[max] = {};
string name[max]   = {};
double money[max]  = {};
double inimoney[max]  = {};

// Function Prototypes
void headerTitle();
void openAccount();
void deposit();
void withdraw();

void adminLog();
void adminMenu();
void showAccounts();
void searchAccount();
void closeAccount();

void saveToFile();
void loadFile();
void initialize();
void loadingscreen();
void generateAccNo(string &var);

// Main Function
int main() {
   
   system("clear||cls");
   initialize();
   loadingscreen();
   loadFile();
   
   int option;
   
   cout << fixed << setprecision(2);
    
    do { // Main Menu
        
        headerTitle();
        cout << tab << "  \e[1mWelcome to the Main Menu!\e[0m Enter a number to choose a service."
             << tab << "\e[1m\033[1;33m---------------------------------------------------------------\e[0m\033[0m"
             << tab << "\t             [1] ☛ Open an Account"
             << tab << "\t             [2] ☛ Balance Inquiry"
             << tab << "\t             [3] ☛ Deposit"
             << tab << "\t             [4] ☛ Withdrawal"
             << tab << "\t             [5] ☛ Admin Tool"
             << tab << "\t             [6] ☛ Exit"
             
             << tab << "\e[1m\033[1;33m---------------------------------------------------------------\e[0m\033[0m" << endl;

        cout << tab << "\t\t Enter your option: "; cin >> option;
        system("clear||cls");

        switch(option) {
            case 1: openAccount();      break;
            case 2: searchAccount();    break;
            case 3: deposit();          break;
            case 4: withdraw();         break;
            case 5: adminLog();         break;
            case 6: // Exit Display
                    headerTitle();
                    cout << tab << "\e[1m\033[1;33m---------------------------------------------------------------\e[0m\033[0m\n"
                         << tab << "\t   Thank you for trusting the FEU Islands bank!"
                         << tab << "\t If you have any concerns reguarding the program"
                         << tab << "\t    feel free to reach us out in the following: \n"
                         << tab << "\t\t \033[1;31m\e[1mG-Mail:\033[0m GregKalbo69@gmail.com"
                         << tab << "\t      \033[1;35mContact Number:\033[0m (+63)0932-8752-354"
                         << tab << "\t\t  \033[1;34mFacebook Page:\e[0m\033[0m HadjinaticsTM \n"
                         << tab << "\e[1m\033[1;33m---------------------------------------------------------------\e[0m\033[0m" << endl; break;

            default: 
                    headerTitle();
                    cout << tab << "  \e[1mWelcome to the Main Menu!\e[0m Enter a number to choose a service."
                         << tab << "\e[1m\033[1;33m---------------------------------------------------------------\e[0m\033[0m"
                         << tab << "\t"
                         << tab << "\t"
                         << tab << "\t"
                         << tab << "\t         \033[1;31mInvalid input. Please try again.\033[0m\n"
                         << tab << "\t"
                         << tab << "\t"
             
                         << tab << "\e[1m\033[1;33m---------------------------------------------------------------\e[0m\033[0m" << endl; break;
        }
        
        // pause screen then clear
        cout << tab << "\t\tPress \e[1mEnter\e[0m to continue . . .";
        
        cin.ignore();
        cin.get();
        system("clear||cls");

    } while (option != 6);


    return 0;
}


// Function to Add the header
void headerTitle() {
        cout << tab << "     \e[1m\033[1;33m====================================================="
             << tab << "\t         \033[1;32mF E U   I s l a n d s   B a n k \033[0m    "
             << tab << "     \033[1;33m=====================================================\e[0m\033[0m" << endl;
}

// Function to Loging in to Admin Tool
void adminLog() {
    int sk;
    
    headerTitle();
    cout << tab << "\t     \033[1;31m\e[1mWARNING!\e[0m\033[0m Enter the Password to Continue"
         << tab << "\e[1m\033[1;33m---------------------------------------------------------------\e[0m\033[0m" << endl;
    cout << tab << "\t\t    Security Key: "; cin >> sk;
    
    // Password input verifier
    if(sk == 6132) {
        system("clear||cls");
        adminMenu();
    }
    else {
        cout << tab << "\t     \033[1;31mWrong Password. Return to Main Menu.\033[0m\n"
             << tab << "\e[1m\033[1;33m---------------------------------------------------------------\e[0m\033[0m" << endl;
    }
}

// Function to use the Admin tools
void adminMenu(){
    int option;
    
    // Admin Tools Menu
    headerTitle();
    cout << tab << "\t\t     \e[1mAdmininistrator Tools\e[0m "
         << tab << "\e[1m\033[1;33m---------------------------------------------------------------\e[0m\033[0m"
         << tab << "\t             [1] ☛ Close an Account"
         << tab << "\t             [2] ☛ Show All Accounts"
         << tab << "\t             [3] ☛ Return to Menu"
         << tab << "\e[1m\033[1;33m---------------------------------------------------------------\e[0m\033[0m" << endl;
    
    cout << tab << "\t\t Enter your option: "; cin >> option;
    system("clear||cls");
    
    switch(option) {
            case 1: closeAccount();    break;
            case 2: showAccounts();    break;
            case 3: // Returns to Main Menu
                    headerTitle();
                    cout << tab << "\t\t  \e[1mReturning back to Main Menu\e[0m "
                         << tab
                         << tab << "     \033[1;33m=====================================================\e[0m\033[0m" << endl;
                    break;
            
            default: 
                    headerTitle();
                    cout << tab << "\t\t     \e[1mAdmininistrator Tools\e[0m "
                         << tab << "\e[1m\033[1;33m---------------------------------------------------------------\e[0m\033[0m"
                         << tab << "\t"
                         << tab << "\t        \033[1;31mInvalid input. Please try again.\033[0m\n"
                         << tab << "\t"
                         << tab << "\e[1m\033[1;33m---------------------------------------------------------------\e[0m\033[0m" << endl;
    }
}



// Function to create account and store in array
void openAccount() {
    string createID;
    string createName;

    double createMoney;
    
    headerTitle();    
    cout << tab << "\t\t\e[1mRegistration Information Receipt\e[0m"
         << tab << "\e[1m\033[1;33m---------------------------------------------------------------\e[0m\033[0m" << endl; 

    generateAccNo(createID);
    cout << "\n\t\t Account number generated: " << createID << endl;
    cin.ignore();
    cout << tab << "\t Enter an Account Name: "; getline(cin, createName);
    cout << tab << "\t Enter an Initial Deposit: $"; cin >> createMoney;
    
    if(cin.fail()) // prevents saving to file when istream fails
        return;
    
    cout << tab << "\t\t\033[1m\033[32mAccount successfully created.\033[0m\n"
         << tab << "\e[1m\033[1;33m---------------------------------------------------------------\e[0m\033[0m"
         << tab << " \e[1mREMINDER!\e[0m Always remember every information in this receipt"
         << tab << "   because it is required in Managment or the retrieval of your"
         << tab << "   account in an event of a loss. Never share it to anyone." << endl;
    int i = 0;
    // find empty array to store
    while(accountNo[i] != "\0") {
        i++;
    }

    accountNo[i] = createID;
    name[i] = createName;
    money[i] = createMoney;
    inimoney[i] = createMoney;
    saveToFile();
}

// Function to show all accounts on screen
void showAccounts() {
    int i = 0;
    const char separator    = ' ';
    const int accnWidth     = 10;
    const int nameWidth     = 12;
    const int nameWidth2    = 25;
    const int numWidth      = 3;
    
    // display all accounts in tabular format
    headerTitle();
    cout << tab << "\t\t       \e[1mList of Accounts\e[0m"
         << tab << "  \e[1m\033[1;33m-----------------------------------------------------------\033[0m"
         << tab << "  no.    Account No.    Account Holder             Balance   "
         << tab << "  \e[1m\033[1;33m-----------------------------------------------------------\033[0m" << endl;

    if (accountNo[0] == "\0") 
        cout << tab << "\t\t\033[1;31m There Isn't Any Existing Account.\n" 
             << tab << "  \e[1m\033[1;33m-----------------------------------------------------------\033[0m" << endl;
    while(accountNo[i] != "\0") {
        cout << " ";
        cout << left << "\t   " << setw(accnWidth) << setfill(separator) << i+1;
        cout << left << setw(nameWidth) << setfill(separator) << accountNo[i];
        cout << left << setw(nameWidth2) << setfill(separator) << name[i];
        cout << left << setw(numWidth) << setfill(separator) << "$" << money[i] << endl;
        i++;
        cout << tab << "  \e[1m\033[1;33m-----------------------------------------------------------\033[0m" << endl;
    }
}

// Function to search account from array
void searchAccount() {
    string search;
    int i = 0, counter = 0;

    headerTitle();
    cout << tab << "\t\t    \e[1mBalance Inquiry Receipt\e[0m " 
         << tab << "\e[1m\033[1;33m---------------------------------------------------------------\e[0m\033[0m";
    cout << tab << "\t\t Enter Account Number: "; cin >> search;
    
    cout << tab << "\t \e[1mAccNo.\t        Acc Holder      \tBalance\e[0m"
         << tab << "\e[1m\033[1;33m---------------------------------------------------------------\e[0m\033[0m";
         
    for(int i = 0; accountNo[i] != "\0" ; i++) {
        if(accountNo[i] == search) {    
            cout << tab << "\t " << accountNo[i] << "      \t" << name[i] << "\t\t\033[1;32m$" << money[i]
                 << tab << "\033[0m\033[1;33m================================================================\e[0m\033[0m\n";
            counter++;
        }
    }

    if (counter == 0) 
        cout << tab << "\t\t     \033[1;31mAccount not found.\033[0m\n"
             << tab << "\e[1m\033[1;33m---------------------------------------------------------------\e[0m\033[0m";
}

// Function to Deposit Funds
void deposit() {
   string search;
   double deposit;
   int counter = 0;

   headerTitle();
   cout << tab << "     \t\t\e[1m Deposit Transaction Slip\e[0m"
        << tab << "\e[1m\033[1;33m---------------------------------------------------------------\e[0m\033[0m" << endl; 
   cout << tab << "\t       Enter Account Number: "; cin >> search;

   // loop through arrays and find account
   for(int i=0; i <= max; i++) {

       if (accountNo[i] == search) {
           cout << tab << "\t       Enter Amount to Deposit: $"; cin >> deposit;
           money[i] += deposit;
           counter++;
           cout << tab << "\t\t \033[1m\033[32mDeposit was successfull!\033[0m\n"
                << tab << "\e[1m\033[1;33m---------------------------------------------------------------\e[0m\033[0m";
           break;
       }
   }

   if(counter == 0) {
       cout << tab << "\t\t   \033[1;31mAccount not found.\033[0m\n"
            << tab << "\e[1m\033[1;33m---------------------------------------------------------------\e[0m\033[0m";
       return; 
   }
    // prevent saving to file
    // when istream fails
    if (cin.fail())
        return;

   saveToFile();
}

// Function to Withdraw Funds
void withdraw() {
   string search;
   double withdraw;
   int counter = 0;

   headerTitle();
   cout << tab << "     \t\t\e[1mWithdrawal Transaction Slip\e[0m"
        << tab << "\e[1m\033[1;33m---------------------------------------------------------------\e[0m\033[0m" << endl;
   cout << tab << "\t       Enter Account Number: "; cin >> search;

   // loop through arrays and find account
   for(int i=0; i <= max; i++) {

       if (accountNo[i] == search) {
           cout << tab << "\t       Enter Amount to Withdraw: $"; cin >> withdraw;

           if (withdraw > money[i]) {
                cout << tab << "\t\t   \033[1;31mInsufficient Funds.\033[0m\n"
                     << tab << "\e[1m\033[1;33m---------------------------------------------------------------\e[0m\033[0m";
            } else {
                money[i] -= withdraw;
                cout << tab << "\t      \033[1m\033[32m$" << withdraw << "\033[0m \033[0m\033[32m was deducted to your account.\033[0m" 
                << tab << "\e[1m\033[1;33m---------------------------------------------------------------\e[0m\033[0m";
            }

           counter++;
           break;
       }
       // ends function when input fails
       // and prevent saving to file
       if (cin.fail())
        return;
   }

   if(counter == 0) {
       cout << tab << "\t\t    \033[1;31mAccount not found.\033[0m\n"
            << tab << "\e[1m\033[1;33m---------------------------------------------------------------\e[0m\033[0m";
       return;
   }
    saveToFile();
}

// Function to Delete Account
void closeAccount() {
    string search;
    int counter = 0;

    headerTitle();
    cout << tab << "\t\t\t\e[1m\033[1;31mDelete an Account\033[0m\e[0m"
        << tab << "\e[1m\033[1;33m---------------------------------------------------------------\e[0m\033[0m" << endl;
    cout << tab << "\t\t    Enter Account Number: "; cin >> search;
    
    if(cin.fail())
        return;

    for(int i = 0; accountNo[i] != "\0"; i++) {
        // remove account from array if 
        // account exists        
        if (accountNo[i] == search) 
        {
            // remove by shifting array elements
            for (int j=i; accountNo[j] != "\0"; j++) 
            {
                accountNo[j] = accountNo[j + 1];
                name[j] = name[j + 1];
                money[j] = money[j + 1];
            }
            // update counter and stop search
            counter++;
            break;
        } 
        }

    // display appropriate end prompts
    if (counter == 0)  {
        cout << tab << "\t\t   \033[1;31mThe Account does not exist.\033[0m\n"
             << tab << "\e[1m\033[1;33m---------------------------------------------------------------\e[0m\033[0m";
        return;
    } else {
        cout << tab << "\t      \033[1;32mThe Selected Account was terminated.\033[0m\n"
             << tab << "\e[1m\033[1;33m---------------------------------------------------------------\e[0m\033[0m";
    }

    saveToFile();
    
}

// info display on startup
void initialize() {

    // text color fix for windows os
    #if defined _WIN32
        system("Color 0F");
    #endif
    
    cout << "\n\t     \e[1m____________________________________________________"
         << "\n\t\t                                        "
         << "\n\t\t          FEU Islands Banking System     "
         << "\n\t     ____________________________________________________\e[0m" << endl;
    
    cout << tab << "  A C++ Banking System designed by Computer Science Freshmen"
         << tab << " students from FEU Institute of Technology as a Final Project"
         << tab << "   for Computer Programming 1 under Doc. Hadji Javier Tejuco"
         << tab
         << tab
         << tab << "\t                  \e[1mMade by:"
         << tab << "\t              Greg Allen Padilla"
         << tab << "\t             John Benedict Signo"
         << tab << "\t          John Christopher Punzalan"
         << tab << "\t             Victoria Faye Babasa\e[0m"
         << tab
         << tab
         << tab << "     \e[2mMade in November 2021 by Group 69 from BSCSSE TN01\e[0m";

    cout << "\n\t     \e[1m____________________________________________________\e[0m" << endl
         
         << "\n\t\t        Press \e[1mEnter\e[0m to continue . . . ";

    cin.get();

    system("clear||cls");
}

// short loading pause on startup
void loadingscreen() {
    
    int timer = 2;

    cout << "\n\t Loading please wait ";
    
    // loading dots
    while(timer != 0) {
        cout << ". ";
        sleep(1);
        timer--;
    }
    cout << endl;
    system("clear||cls");
}

// Function to save array data to file
void saveToFile() {
    ofstream masterFile("Database.txt");
    // write array elements into file
    for(int i=0; accountNo[i] != "\0"; i++) {
        masterFile << accountNo[i] << ' ' << name[i] << "$ " << money[i] << endl;
    }

    masterFile.close();
}

// function to load preserved data from account file
void loadFile() {
    ifstream loadData;
    fstream accountFile("Database.txt", ios::in);

    // create file if it does not exist
    if(!accountFile) {
        cout << "\n\t Account file not found. Created new save file named 'Database.txt'."
             << "\n\t Please do not delete file to preserve data. \n";

        accountFile.open("Database.txt", ios::in | ios::out | ios::trunc);
        accountFile << "";
        accountFile.close();
        cin.get();
    }
    accountFile.close();

    loadData.open("Database.txt");
    // load file contents in arrays
    int i = 0;
    while(loadData >> accountNo[i]) {
        loadData >> ws; 
        getline(loadData, name[i], '$'); 
        loadData >> money[i];
        i++;
    } 

    loadData.close();
}

// function to generated uid for accountno
void generateAccNo(string &var) {
    string uid;
    int randonum;
    bool not_unique = true, found = false;
    // bool variables to check validity
    // of generated uid
    while(not_unique) {
        uid = "";

        //generate random uid using
        // rand function
        srand(time(NULL));
        for(int i = 1; i <= 3; i++) {
            randonum = rand()%9;
            uid += to_string(randonum);
        }

        // check whether generated id exists
        for(int i = 0; accountNo[i] != "\0"; i++) {
            if (accountNo[i] == uid) {
                found = true;
                break;
            } else found = false;
        }

        // quit loop if generated uid is valid
        if(found == false)
            not_unique = false;
    }

    // assign uid to passed (by ref) variable
    var = uid;
}