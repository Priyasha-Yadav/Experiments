// 🐉 1. The Dragon and the Brave Compiler
// A dragon 🐲 guards a treasure chest. Each chest has goldCoins and rubyStones. The knight 🛡️ wants to calculate total wealth.
// Define a class TreasureChest with a constructor, and write a function to calculate total value (1 gold = 100, 1 ruby = 500).

#include<iostream>
using namespace std;

class TreasureChest {
private:
    int wealth;
public:
    TreasureChest() {
        wealth = 0;
    }

    void totalValue(int ruby, int coins) {
        if (ruby) {
            wealth += ruby * 500;
        }
        if (coins) {
            wealth += coins * 100;
        }

        cout << "💰 Total treasure value: " << wealth << " gold coins!\n";
    }
};

int main() {
    TreasureChest tc1;
    tc1.totalValue(3, 10); 
    return 0;
}
