#include<iostream>
using namespace std;
//(a,b) eavluate a then b as b is evaluated last it throws b valu
int main(){
    int a = 2;
    int b = 3;
    (a>b) ? cout<<a:cout<<b;
}