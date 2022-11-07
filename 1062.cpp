#include <iostream>
#define ll long long
using namespace std;
int N,K;
ll s[55];
ll al = 0;
int solve(int cur,int k){
    if(cur >= 27) return 0;
    if(k>=K){
        int ret = 0;
        
        for(int i = 0;i<N;i++){
            if((s[i] & al) == s[i])
                ret++;
        }
        return ret;
    }
    int ret = 0;
    if(!(al & 1<<cur)){
        al |= 1<<cur;
        ret = max(ret,solve(cur+1,k+1));
        al &= ~(1<<cur);
    }

    ret = max(ret,solve(cur+1,k));

    return ret;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>K;

    for(int i = 0;i<N;i++){
        string ss;cin>>ss;
        for(int j = 0;j<ss.size();j++){
            s[i] |= 1<<(ss[j]-'a');
        }
    }
    al |= 1<<('a' - 'a');
    al |= 1<<('n' - 'a');
    al |= 1<<('t' - 'a');
    al |= 1<<('i' - 'a');
    al |= 1<<('c' - 'a');

    
    if(K < 5) cout<<0;
    else cout<<solve(0,5);
}