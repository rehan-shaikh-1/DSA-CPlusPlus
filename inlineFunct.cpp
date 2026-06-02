#include<iostream>
using namespace std;
int globalVariable = 5;
inline int changeVal(int &var){
return ((var + 52)%10);
}
int main(){
    int var = 22;
    cout<<"Inline Function:"<<changeVal(var);
    return 0;
}

/*
    inline function is used to reduaced function call overhead and
    in code the line function name in other function replaced by the inline func code
*/