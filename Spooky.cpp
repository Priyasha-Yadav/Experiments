// 🔥 8. The Cursed Constructor
// An ancient class Curse is accidentally instantiated:

// Curse c1("Darkness");
// Curse c2 = c1;
// Implement a parameterized constructor and copy constructor that outputs spooky messages like "Darkness duplicated... RUN."

#include <iostream>
#include <string>
using namespace std;

class Curse {
    string curse;

public:
    // Parameterized Constructor
    Curse(string c) : curse(c) {
        cout << "You are cursed 👻 with \"" << curse << "\"..." << endl;
        cout << "The air grows cold. Shadows whisper your name..." << endl;
    }

    // Copy Constructor
    Curse(const Curse& c) : curse(c.curse) {
        cout << "The curse \"" << curse << "\" has been duplicated... RUN!" << endl;
        cout << "Two fates now bound. Twice the doom..." << endl;
    }
};

int main() {
    Curse c1("Darkness");
    Curse c2 = c1;  
    return 0;
}
