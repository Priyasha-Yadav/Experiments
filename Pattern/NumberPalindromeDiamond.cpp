
// Input: n = 4
//       1
//     1 2 1
//   1 2 3 2 1
// 1 2 3 4 3 2 1
//   1 2 3 2 1
//     1 2 1
//       1

#include <iostream>
using namespace std;

void alphabetDiamond(int n) {
    // upper half including middle
    for (int i = 1; i <= n; i++) {
        // leading spaces
        for (int s = 1; s <= n - i; s++) {
            cout << " ";
        }

        // increasing part: A, AB, ABC...
        for (int j = 0; j < i; j++) {
            cout << 1 + j;
        }

        // decreasing part
        for (int j = i - 2; j >= 0; j--) {
            cout << 1 + j;
        }

        cout << "\n";
    }

    // lower half
    for (int i = n - 1; i >= 1; i--) {
        // leading spaces
        for (int s = 1; s <= n - i; s++) {
            cout << " ";
        }

        // increasing part
        for (int j = 0; j < i; j++) {
                   cout << 1 + j;

        }

        // decreasing part
        for (int j = i - 2; j >= 0; j--) {
            cout << 1 + j;
        }

        cout << "\n";
    }
}

int main() {
    int n = 5; // You can change this or take input
    alphabetDiamond(n);
    return 0;
}
