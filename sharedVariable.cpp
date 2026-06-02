#include<iostream>
using namespace std;
int globalVariable = 5;
void changeVal(int &var){
    globalVariable = globalVariable -1;
    cout<<"\nchanged globalVariable:"<<globalVariable;
    cout<<"\nVar: "<<var<<endl;
}
int main(){
    int var;
    cout<<"globalVariable:"<<globalVariable;
    changeVal(var);
    cout<<endl;
    return 0;
}

/*
    As globalVariable can be manipulated by any function to use for sharing 
    the varibale
*/