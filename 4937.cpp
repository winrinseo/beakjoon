#include <iostream>
#include <vector>
using namespace std;

int N;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    while(1){
        cin>>N;
        if(N == -1) break;
        int n = N;
        int d = 2;
        bool flag = true;
        while(N != 1){
            if( N % d != 0){
                d += 1;
            }else{
                if(d % 10 != 3){
                    flag = false;
                    break;
                }
                N/=d;
            } 
        }
        cout<<n<<" ";
        if(flag) cout<<"YES";
        else cout<<"NO";
        cout<<"\n";
    }
}