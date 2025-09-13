// Input example: n = 5

// *****
// *   *
// *   *
// *   *
// *****

#include <iostream>
using namespace std;

int main(){
    char c = '*';
    int n;
    cout<<"Enter number of rows: ";
    cin>>n;
    for(int i = 1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(j == 1 || j == n || i == 1 || i == n){
                cout<<c;
            }
            else{
                cout<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}