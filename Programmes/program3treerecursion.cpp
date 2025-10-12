#include<iostream>
using namespace std;

void fn(int n , int* X){
   
    if(n>0){
        *X++;
        cout<<n<<endl;
        fn(n-1,X);
        fn(n-1,X);
    }
}

int main(){
    static int X = 0;
    int a = 8;
    fn(a,&X);
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<X<<endl;
    return 0;
}