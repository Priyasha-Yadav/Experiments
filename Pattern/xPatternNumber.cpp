
// Input: n = 5

// 1   5
//  2 4
//   3
//  2 4
// 1   5


#include <iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter the number of rows: ";
    cin>>n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <=n; j++){
            if(i == j || i+j == n+1){
                cout<<j;
            }
            else{
                cout<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}

