// Input example: n = 5

//          1
//       2  3  4
//    5  6  7  8  9
// 10 11 12 13 14 15 16


#include <iostream>
using namespace std;


int main(){
    int n;
    cout<<"Enter number of rows: ";
    cin>>n;
    int count = 1;
    for(int i = 1; i <n; i++){
        for(int j = n - 1; j>i; j--){
            cout<<"   ";
        }
        for(int k = 1; k<= 2*i -1 ; k++){
           if(count<10){
            cout<<count<<"  ";
            count++;
           }
           else{
            cout<<count<<" ";
            count++;
           }
        }
        cout<<endl;
    }
    return 0;
}