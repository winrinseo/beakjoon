#include <iostream>

using namespace std;
int a,b,c;
int aa,bb,cc;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    for(int i = 0;i<3;i++){
        cin>>a>>b>>c;
        cin>>aa>>bb>>cc;
        cc-=c; if(cc<0){cc+=60;bb--;};
        bb-=b; if(bb<0){bb+=60;aa--;};
        aa-=a;
        cout<<aa<<" "<<bb<<" "<<cc<<"\n";
    }
}