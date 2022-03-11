#include <iostream>
#include <unordered_map>
using namespace std;

string s;
unordered_map<int,int> idx;
int psum[100005];
bool seg[400005];
bool init(int idx,int st,int ed){
    if(st==ed) return seg[idx] = s[st]=='S'||s[st]=='K';
    int mid = (st+ed)/2;
    return seg[idx] = init(idx*2,st,mid)|init(idx*2+1,mid+1,ed);
}
bool check(int idx,int st,int ed,int l,int r){
    if(r<st||ed<l) return 0;
    if(l<=st&&ed<=r) return seg[idx];
    int mid = (st+ed)/2;
    return check(idx*2,st,mid,l,r)|check(idx*2+1,mid+1,ed,l,r);
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>s;
    int answer = -1;
    idx[0] = 0;
    init(1,0,s.size()-1);
    for(int i = 1;i<s.size()+1;i++){
        int a = s[i-1]=='S' ? 2:s[i-1]=='K'? -1:0;
        psum[i] = psum[i-1] + a;
        if(idx.count(psum[i])){
            int index = idx[psum[i]];
            if(a==0){
                if(check(1,0,s.size()-1,index,i-1)){
                    answer = max(answer,i-index);
                }
            }else answer = max(answer,i-index);
        }else if(a!=0) idx[psum[i]] = i;
    }
    cout<<answer;
}