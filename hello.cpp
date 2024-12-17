#include <iostream>
#include <string>
#include <vector>
#include <windows.h>
#include <cstdlib>

void clearScreen()
{
    system("cls");
}
class account
{

public:
    std::string name;
    double amount;
    int selection;
    std::string password;

    void CheckBalance()
    {
        clearScreen();
        std::cout << "\033[32m" << "Your balance is $" << amount << "\033[0m" << std::endl;
        done();
    }

    void welcome()
    {
        clearScreen();
        std::cout << name << ", how may i assist you today? " << std::endl;
        std::cout << "1. Check balance" << std::endl << "2. Deposit" << std::endl << "3. Withdraw" << std::endl;
    }

    void deposit()
    {
        double depositAmount;
        
        std::cout <<  "Enter deposit amount " << std::endl;
        std::cin >> depositAmount;
        depositCalc(depositAmount);
        clearScreen();
        std::cout << "\033[32m" << "Your balance is now $" << amount << "\033[0m" << std::endl;
        done();
    }
    void depositCalc(double depositAmount)
    {
        amount = amount + depositAmount;
    }

    void withdraw()
    {            
        double withdrawAmount;
            {
            std::cout << "Enter withdraw amount " << std::endl;
            std::cin >> withdrawAmount;
            while (amount - withdrawAmount < 0)
            {
                std::cout << "Invalid funds, you only have $" << amount << " available" << std::endl;
                std::cout << std::endl << "Enter new withdraw amount" << std::endl;
                std::cin >> withdrawAmount;
            }
            withdrawCalc(withdrawAmount);
            clearScreen();
            std::cout << "\033[32m" << "Your balance is now $" << amount << "\033[0m" << std::endl;
            done();
            }
    }

    void withdrawCalc(double withdrawAmount)
    {
        amount = amount - withdrawAmount;
    }

    void accountAction()
    {
        welcome();
        std::cin >> selection;
        if (selection == 1)
        {
            CheckBalance();
        }
        else if (selection == 2)
        {
            deposit();
        }
        else if (selection == 3)
        {
            withdraw();
        }
    }

    void done()
    {
        std::cout << "Is there anything else i can assist with, " << name <<"?" << std::endl;
        std::cout << std::endl << "1. More" <<std::endl << "2. Logout" << std::endl;
        std::cin >> selection;
        if (selection == 1)
        {
            accountAction();
        }   
        else if (selection == 2)
        {
            exit;
        }
    }

    void login()
    {
        std::string enteredPwd;
        while (enteredPwd != password)
        {
            std::cout << "enter password" << std::endl;
            std::cin >> enteredPwd;
        }
        accountAction();
    }
};

int main()
{
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD dwMode = 0;
    GetConsoleMode(hOut, &dwMode);
    SetConsoleMode(hOut, dwMode | ENABLE_VIRTUAL_TERMINAL_PROCESSING);

    account account1;
    account1.name = "Steven";
    account1.amount = 100;
    account1.password = "steven";

    account account2;
    account2.name = "John";
    account2.amount = 2.50;
    account2.password = "john";

    account account3;
    account3.name = "Cena";
    account3.amount = 200000;
    account3.password = "cena";

    int selection = -1;

    std::cout << "Good morning, please select account" << std::endl;
    std::cout << "1. Steven" << std::endl << "2. John" << std::endl <<  "3. Cena " << std:: endl;
    std::cin >>  selection; 
    if (selection == 1)
    {
        account1.login();
    }
    else if (selection == 2)
    {
        account2.login();
    }
    else if (selection == 3)
    {
        account3.login();
    }

    return 0;
}