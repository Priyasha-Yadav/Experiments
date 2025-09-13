// Input example: n = 6

// A
// B C
// D E F
// G H I J
// K L M N O
// P Q R S T U

#include <iostream>
using namespace std;

int main()
{
    char c = 'A';
    int n;
    cout << "Enter number of rows: ";
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            cout << c << " ";
            c++;
        }
        cout << endl;
    }
    return 0;
}
