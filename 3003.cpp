#include <iostream>
using namespace std;
int main(){
    int a[6] = {1,1,2,2,2,8};
    for(int i =0;i<6;i++){
        int b;cin>>b;
        a[i]-=b;
    }
    for(int i =0;i<6;i++) cout<<a[i]<<" ";
}