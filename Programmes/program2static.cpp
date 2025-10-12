#include<iostream>
using namespace std;

int fnwithoutstatic(int n ,int r = 0){
    
    if(n>0)
    {
        
        r++;
        return fnwithoutstatic(n-1) + n;
    }
    return 0;
}

int fnwithstatic(int n ){

    static int X =0;
    if(n>0)
    {
        X++;
        return fnwithstatic(n-1) + X;
    }
    return 0;
}

int main(){

    int p = 5;
    //with out static variable

    cout<<fnwithoutstatic(p)<<endl;

        //with static variable

    cout<<fnwithstatic(p)<<endl;

}