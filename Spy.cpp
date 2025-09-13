#include <iostream>
#include <string>
using namespace std;

class Agent {
public:
    Agent() {
        cout << "🕵️ Initializing secure comms channel..." << endl;
    }

    virtual void missionDetails() {
        cout << "The mission is classified. Proceed with extreme caution." << endl;
    }

    virtual ~Agent() = default;
};

class Hacker : public Agent {
public:
    void missionDetails() override {
        cout << "💻 System breach detected... Firewalls shattered... "
                "All enemy secrets are now mine! ⚡" << endl;
    }
};

class Diplomat : public Agent {
public:
    void missionDetails() override {
        cout << "🤵 With a glass of wine and a smile, I bent their will... "
                "The enemy surrendered everything in a single signature 🫣" << endl;
    }
};

class Sniper : public Agent {
public:
    void missionDetails() override {
        cout << "🎯 One breath. One shot. Silence... "
                "Target eliminated without a whisper." << endl;
    }
};

int main() {
    Agent* agents[] = { new Hacker(), new Diplomat(), new Sniper() };

    for (Agent* a : agents) {
        a->missionDetails();
    }

    for (Agent* a : agents) {
        delete a;
    }

    return 0;
}
