#include<iostream>
using namespace std;

int main(){
    int a,b;
    char op;
    cout<<"enter the value of first operand:";
    cin>>a;

    cout<<"enter the value of second operand:";
    cin>>b;

    cout<<"enter the operation you want to perform:";
    cin>>op;

    switch(op){
        case '+': cout<<"addition of two operand is:"<<(a+b)<<endl;
        break;

        case '-': cout<<"subtraction of two operand is:"<<(a-b)<<endl;
        break;

        case '*': cout<<"multiplication of two operand is:"<<(a*b)<<endl;
        break;

        case '/': cout<<"division of two operand is:"<<(a/b)<<endl;
        break;

        case '%': cout<<"modulus of two operand is:"<<(a%b)<<endl;
        break;
    }
}