#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t=0;
    while(1){
        t++;
        string N;cin>>N;
        if(N=="0") break;
        while(1){
            string next;
            for(int i = 0;i<N.size();i+=2){
                for(int j = 0;j<N[i]-'0';j++)
                    next.push_back(N[i+1]);
            }
            if(N.size()%2==1||next==N){
                    cout<<"Test "<<t<<": "<<N<<"\n";
                    break;
                }else{
                    N = next;
            }
        }
    }
}