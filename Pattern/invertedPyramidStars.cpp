// Input example: n = 5

// *********
//  *******
//   *****
//    ***
//     *


#include <iostream>
using namespace std;


int main(){
    char c = '*';
    int n;
    cout<<"Enter number of rows: ";
    cin>>n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j<i; j++ ){
            cout<<" ";
        }
        for(int k = 2*n - i + 1; k>i ; k--){
            cout<<c;
        }

        cout<<endl;
        
    }
    return 0;
}