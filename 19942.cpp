#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N;
int mp[20],mf[20],ms[20],mv[20],pi[20];
int pp,ff,ss,vv;
int maxp = 10000000;
vector<int> an,pred;
void solve(int depth,int p,int f,int s,int v,int price){
    if((p>=pp&&f>=ff&&s>=ss&&v>=vv)){
        if(maxp > price){
            maxp = price;
            an = pred;
        }
        return;
    }
    if(depth==N) return;
    pred.push_back(depth+1);
    solve(depth+1,p+mp[depth],f+mf[depth],s+ms[depth],v+mv[depth],price+pi[depth]);
    pred.pop_back();
    solve(depth+1,p,f,s,v,price);
    
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    cin>>pp>>ff>>ss>>vv;
    for(int i = 0;i<N;i++){
        cin>>mp[i]>>mf[i]>>ms[i]>>mv[i]>>pi[i];
    }
    solve(0,0,0,0,0,0);
    sort(an.begin(),an.end());
    if(an.size()==0) {
        cout<<-1;
        return 0;
    }
    cout<<maxp<<"\n";
    for(int i = 0;i<an.size();i++)
        cout<<an[i]<<" ";
}