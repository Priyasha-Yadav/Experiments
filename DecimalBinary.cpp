
#include <iostream>
using namespace std;

int decimalToBinary(int num)
{
    int pow = 1, rem = 0;
    int binary = 0;
    while (num)
    {
        rem = num % 2;
        num /= 2;
        binary += rem * pow;
        pow = pow * 10;
    }
    return binary;
}

int binaryToDecimal(int num)
{
    int decimal = 0;
    int rem = 0;
    int pow = 1;
    while (num)
    {
        rem = num % 10;
        decimal += rem * pow;
        num /= 10;
        pow *=2;
    }
    return decimal;
}

int main()
{
    for(int i = 1; i<=10; i++){
        cout<<binaryToDecimal(decimalToBinary(i))<< " ";
        cout<< decimalToBinary(i);
        cout<<endl;
    }
    return 0;
}