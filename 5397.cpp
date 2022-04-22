#include <iostream>
#include <deque>
using namespace std;
int T;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>T;
    while(T--){
        deque<char> f;
        deque<char> r;
        string k;
        cin>>k;

        for(int i = 0;i<k.size();i++){
            if(k[i]=='<'){
                if(!f.empty()){
                    r.push_front(f.back());
                    f.pop_back();
                }
            }else if(k[i]=='>'){
                if(!r.empty()){
                    f.push_back(r.front());
                    r.pop_front();
                }
            }else if(k[i]=='-'){
                if(!f.empty()){
                    f.pop_back();
                }
            }else{
                f.push_back(k[i]);
            }

        }
        while(!f.empty()){
            cout<<f.front();f.pop_front();
        }
        while(!r.empty()){
            cout<<r.front();r.pop_front();
        }
        cout<<"\n";
    }
}