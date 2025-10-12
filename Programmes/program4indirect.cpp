#include<iostream>
using namespace std;
void fnB(int n);
//methoh A
void fnA(int n){

    if(n>0){

        cout<<n<<endl;
        fnB(n-1);
    }
}
// method B
void fnB(int n){
    if(n>1){
        cout<<n<<endl;
        fnA(n/2);
    }
}

int main(){

   int a = 10;
   fnA(a);
   return 0;
}