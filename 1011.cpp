#include <iostream>
#include <math.h>
using namespace std;
int T;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>T;
    while(T--){
        long long x,y;cin>>x>>y;
        long long d = y-x;
        double rt = sqrt(d);
        long long rrt = int(rt);
        if(rrt*rrt==d){
            cout<<rrt*2-1<<"\n";
        }else if((rt-(double)rrt)>=0.5){
            cout<<rrt*2+1<<'\n';
        }else{
            cout<<rrt*2<<"\n";
        }
    }
}