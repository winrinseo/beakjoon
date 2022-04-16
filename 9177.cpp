#include <iostream>
using namespace std;
int N;
string a,b,t;
int dp[205][205];
int solve(int ap,int bp){
    if(ap+bp==t.size()) 
        return 1;
    
    int& ret = dp[ap][bp];
    if(ret!=-1) return ret;
    ret = 0;
    if((t[ap+bp]!=a[ap])&&(t[ap+bp]!=b[bp]))
        return ret;
    if(a[ap]==b[bp]){
        ret = max(solve(ap+1,bp),solve(ap,bp+1));
    }else{
        if(t[ap+bp]==a[ap]) ret = max(ret,solve(ap+1,bp));
        else if(t[ap+bp]==b[bp]) ret = max(ret,solve(ap,bp+1));
    }
    return ret;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    for(int n = 1;n<=N;n++){
        cin>>a>>b>>t;
        
        for(int i = 0;i<205;i++)
            fill(dp[i],dp[i]+205,-1);
        string answer = solve(0,0)==0?"no":"yes";
        cout<<"Data set "<<n<<": "<<answer<<"\n";
    }
    
}