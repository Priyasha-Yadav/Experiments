// Input: n = 5

// 15
// 14 13
// 12 11 10
// 9  8  7  6
// 5  4  3  2  1

#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter number of rows: ";
    cin >> n;
    int count = n * (n + 1) / 2;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (count < 10)
            {
                cout << count << "  ";
            }
            else
            {
                cout << count << " ";
            }
            count--;
        }
        cout << endl;
    }

    return 0;
}