#include <iostream>
using namespace std;
int T;
int N,L;
int p[25],c[25];
int solve(int cnt,int l){
    if(cnt==N) return 0;

    int ret = 0;
    //칼로리 제한에 걸리지 않을 경우만 선택한다.
    if(l+c[cnt]<=L)
        ret = max(ret,solve(cnt+1,l+c[cnt])+p[cnt]);
    ret = max(ret,solve(cnt+1,l));
    return ret;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>T;
    for(int i = 1;i<=T;i++){
        cin>>N>>L;
        for(int i = 0;i<N;i++){
            cin>>p[i]>>c[i];
        }
        int answer = solve(0,0);
        cout<<"#"<<i<<" "<<answer<<"\n";
    }
}