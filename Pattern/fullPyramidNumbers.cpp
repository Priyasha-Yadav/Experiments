// Input example: n = 5

//         1
//       1 2 3
//     1 2 3 4 5
//   1 2 3 4 5 6 7
// 1 2 3 4 5 6 7 8 9

#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter number of rows: ";
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        for (int j = n; j > i; j--)
        {
            cout << "  ";
        }
        for (int k = 1; k <= 2*i -1; k++)
        {
            cout <<k<<" ";

        }
        cout << endl;
    }
    return 0;
}