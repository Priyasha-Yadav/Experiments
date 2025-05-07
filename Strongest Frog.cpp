// 🐸 5. Frog Squad STL Shenanigans
// A bunch of frogs 🐸 with different power levels are in a vector<int>.

// The frogs want to be sorted by power.
// Find the strongest frog.
// Remove the weakest (he croaked... literally).
// Use STL containers and algorithms to solve this. Add random emojis as output flair.
// Example:
// Input: A vector of frogs' power levels: {5, 2, 8, 3, 7, 1}
// Output:
// "Sorting frogs by power..."
// "The strongest frog has a power level of: 8"
// "The weakest frog has croaked!"
// "Remaining frogs: {2, 3, 5, 7}"


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
   vector<int> frogs = {99,100,57,53,83,88,77};
   sort(frogs.begin(), frogs.end());
   cout<<"The Choosen One has level: "<<frogs[frogs.size()-1]<<" 🐸"<<endl;
   frogs.erase(frogs.begin());
   cout<<"Croak! 🐸"<<endl;
   cout<<"{";
   for(const int& nums: frogs){
    cout<<nums<<" ";
   }
   cout<<"}"<<endl;

    return 0;
}
