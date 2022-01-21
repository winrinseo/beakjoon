#include <iostream>
#include <algorithm>
using namespace std;
int seg[1<<18];
pair<int,int> coor[75005];
int T,N;
void upd(int i){
    i += N;
    seg[i]++;
    while(i>1){
        i/=2;
        seg[i] = seg[i*2]+seg[i*2+1];
    }
}
int sum(int idx,int st,int ed,int l,int r){
    if(r<st||ed<l) return 0;
    if(l<=st&&ed<=r) return seg[idx];
    int mid = (st+ed)/2;
    return sum(idx*2,st,mid,l,r)+sum(idx*2+1,mid+1,ed,l,r);
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>T;
    while(T--){
        cin>>N;
        fill(seg,seg+(1<<18),0);
        long long answer = 0;
        for(int i = 0;i<N;i++){
            cin>>coor[i].second>>coor[i].first;
        }
        sort(coor,coor+N);

        int c = 0;
        int Y[75001]={0};
        for(int i = 0;i<N;i++){
            //y좌표를 재정의
            if(i>0&&coor[i-1].first!=coor[i].first){
                c++;
            }
            Y[i] = c;
        }
        for(int i = 0;i<N;i++)
            coor[i].first = Y[i];
        sort(coor,coor+N,[](pair<int,int>& a,pair<int,int>& b){
            if(a.second==b.second) return a.first > b.first;
            return a.second < b.second;
        });
        
        for(int i = 0;i<N;i++){
            answer += sum(1,0,N-1,coor[i].first,N-1);
            upd(coor[i].first);
        }

        cout<<answer<<"\n";

    }
}