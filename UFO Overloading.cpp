// 👽 2. UFO Overloading
// Aliens 👾 abducted your math class. They're testing your coding skills. They demand:

// Math m;
// m.add(3, 5);
// m.add(3.14, 1.59);
// m.add("Cake", "Pie");
// Overload the add() function so the aliens don't vaporize Earth.

#include <iostream>
using namespace std;

// Aliens 👾

class Math
{
public:
    int add(int a, int b)
    {
        cout << a + b << " Damn you 👾";
        return a + b;
    }
    string add(string a, string b)
    {
        cout << a + b << " To hell with you 👾";
        return a + b;
    }
    double add(double a, double b)
    {
        cout << a + b << " Gimme my freaking homework 👾";
        return a + b;
    }
};

int main()
{
    Math m;
    m.add(3, 5);
    cout << endl;
    m.add(3.14, 1.59);
    cout << endl;
    m.add("Cake", "Pie");
    return 0;
}