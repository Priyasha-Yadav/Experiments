
// Input: n = 5
//     A
//    ABA
//   ABCBA
//  ABCDCBA
// ABCDEDCBA
//  ABCDCBA
//   ABCBA
//    ABA
//     A

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
            cout << char('A' + j);
        }

        // decreasing part
        for (int j = i - 2; j >= 0; j--) {
            cout << char('A' + j);
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
            cout << char('A' + j);
        }

        // decreasing part
        for (int j = i - 2; j >= 0; j--) {
            cout << char('A' + j);
        }

        cout << "\n";
    }
}

int main() {
    int n = 5; // You can change this or take input
    alphabetDiamond(n);
    return 0;
}
