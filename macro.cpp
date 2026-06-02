#include<iostream>
/* pre-processoe directive */
#define sum 10
/* #define is used to create/define macros */
/* before the compilation the sum is replaced by its value in whole code */
/* sum = sum + 1 not possible bcoz :-:-: 10 = 10 + 1 this throw compilation error
    As we are not able to assign cout object a int value ie.>> orecedence jada hai so
    cout = sum + 1 is also not possible*/
using namespace std;
int main(){
    {
        cout<<"\nSum + 1 :"<<sum+1;        
    }
    {
        cout<<"\nSum +2 :"<<sum+2;
    }
}
/*Types of macros 
1.object like macro example: #define sum 10
2.chain macro ex: #define instagram folloers
                  #define followers 134k
                  instgram (replaced by 134k)
3.multi-line macro ex: #define 1, /
                               2, /
                               3
4.function like macro ex: #define max(a,b)  (((a) < (b)) ? (a) : (b))
*/