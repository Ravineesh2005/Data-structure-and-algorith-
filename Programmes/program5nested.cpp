#include<iostream>
using namespace std;

int fn(int n){

    if (n>100){
    return(n-10);
    }
    else{
        return fn(fn(n +11));

    }
}

int main(){

    cout<<fn(95)<<endl;
}