
// Input: n = 5
//     *
//    * *
//   *   *
//  *     *
// *       *
//  *     *
//   *   *
//    * *
//     *

#include <iostream>
using namespace std;

void hollowDiamond(int n) {
    // upper half including middle line
    for (int i = 1; i <= n; i++) {
        // leading spaces
        for (int s = 1; s <= n - i; s++) {
            cout << " ";
        }

        if (i == 1) {
            cout << "*";
        } else {
            cout << "*";
            for (int j = 1; j <= 2 * i - 3; j++) {
                cout << " ";
            }
            cout << "*";
        }
        cout << "\n";
    }

    // lower half
    for (int i = n - 1; i >= 1; i--) {
        // leading spaces
        for (int s = 1; s <= n - i; s++) {
            cout << " ";
        }

        if (i == 1) {
            cout << "*";
        } else {
            cout << "*";
            for (int j = 1; j <= 2 * i - 3; j++) {
                cout << " ";
            }
            cout << "*";
        }
        cout << "\n";
    }
}

int main() {
    int n = 5; // you can change or take input
    hollowDiamond(n);
    return 0;
}
