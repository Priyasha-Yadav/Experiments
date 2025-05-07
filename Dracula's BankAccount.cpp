// 🧛‍♂️ 3. Dracula’s Bank Account
// Count Dracula opened a C++ bank account to store blood units (in mL). He wants:

// To deposit blood (depositBlood(int)).
// To withdraw blood, but never overdraft.
// To print current balance.
// Create a class BloodBank with private members and proper encapsulation.

#include <iostream>
using namespace std;
// Blood 🩸

class BloodBank
{
private:
    double balance;

public:
    BloodBank()
    {
        balance = 0;
    }
    void depositBlood(int blood)
    {
        balance += blood;
    }
    void checkBalance()
    {
        cout << "Blood: " << balance << "mL" << " Blood🩸" << endl;
    }
    void withdraw(int blood)
    {
        if (balance >= blood)
        {
            balance -= blood;
        }
        else
        {
            cout << "Not enough blood 🩸" << endl;
            cout << "Find a human 🩸" << endl
                 << "time to make a blood bath" << endl;
            cout << "BWHAHAHAHAHA" << endl;
        }
    }
};

int main()
{
    BloodBank V1;
    V1.checkBalance();
    V1.withdraw(100);
    V1.depositBlood(1000);
    V1.withdraw(100);
    V1.checkBalance();
    return 0;
}