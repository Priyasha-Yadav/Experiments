#include <iostream>
using namespace std;

// Recursive function to solve Tower of Hanoi
void towerOfHanoi(int n, char source, char auxiliary, char destination) {
    if (n == 1) {
        cout << "Move disk 1 from " << source << " to " << destination << endl;
        return;
    }

    // Move n-1 disks from source to auxiliary
    towerOfHanoi(n - 1, source, destination, auxiliary);

    // Move nth disk from source to destination
    cout << "Move disk " << n << " from " << source << " to " << destination << endl;

    // Move n-1 disks from auxiliary to destination
    towerOfHanoi(n - 1, auxiliary, source, destination);
}

int main() {
    int n; // Number of disks

    cout << "Enter the number of disks: ";
    cin >> n;

    cout << "\nSteps to solve Tower of Hanoi with " << n << " disks:\n\n";
    towerOfHanoi(n, 'A', 'C', 'B'); // A = source, B = auxiliary, C = destination

    return 0;
}
