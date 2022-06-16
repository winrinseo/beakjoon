#include <iostream>
#include <set>
using namespace std;
int T,N;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>T;
    while(T--){
        cin>>N;
        multiset<int> s;
        for(int i = 0;i<N;i++){
            char a;int b;cin>>a>>b;
            if(a=='I'){
                s.insert(b);
            }else if(a=='D'){
                if(s.empty()) continue;
                if(b==-1){
                    s.erase(s.begin());
                }else{
                    s.erase(prev(s.end()));
                }
            }
        }
        if(s.empty()) cout<<"EMPTY"<<"\n";
        else cout<<*s.rbegin()<<" "<<*s.begin()<<"\n";
    }
}