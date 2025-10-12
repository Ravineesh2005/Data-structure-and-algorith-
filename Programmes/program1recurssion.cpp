#include<iostream>
using namespace std;
void dispaly(int n){
    if (n>0){

        cout<<n<<endl;
        dispaly(n-1);
    }
}
int main(){
    int num = 10;
    dispaly(10);
    return 0;
}