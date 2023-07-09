#include <iostream>
#include <list>
using namespace std;

int T;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>T;

    while(T--){
        int N;cin>>N;
        int m = 0;
        list<int> l;
        int ans = 0;

        for(int i = 1;i<=20;i++){
            int a;cin>>a;
            if(m > a){
                int ii = 0;
                for(auto it = l.begin();it!=l.end();it++){
                    if(a < *it){
                        ans += (l.size() - ii);
                        l.insert(it , a);
                        break;
                    }
                    ii++;
                }
            }else{
                l.push_back(a);
            }
            m = max(m,a);
        }
        cout<<N<<" "<<ans<<"\n";
    }
}