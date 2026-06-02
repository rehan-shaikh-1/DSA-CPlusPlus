#include<iostream>
using namespace std;
//only the right most argument can be optional
//u cannnot put a as default argument
//but u can put c or b,c  or a,b,c as deafult args
void defaultArgs(int a = 1, int b = 1, int c = 5){
    cout<<" \ta + b + c :"<<a+b+c<<endl;
}
int main(){
    defaultArgs(3,7,5); //15
    defaultArgs(3,7); //10
    defaultArgs(); //1
}