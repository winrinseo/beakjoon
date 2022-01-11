#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N,M;
int arr[1500][1500];
vector<vector<int>> seg;
//2차원 세그먼트 트리
void update(int x,int y,int d){
    int i = y+N-1; int j = x+N-1;
    seg[i][j] = d;
    //1차원 세그먼트 트리 갱신(xquery)
    while(j>1){
        j/=2;
        seg[i][j] = seg[i][j*2]+seg[i][j*2+1];
    }
    //2차원 세그먼트 트리 갱신(yquery)
    while(i > 1){
        j = x+N-1;
        i/=2;
        seg[i][j] = seg[i*2][j]+seg[i*2+1][j];
        while(j > 1){
            j/=2;
            seg[i][j] = seg[i][j*2]+seg[i][j*2+1];
        }
    }
    return;
}
//x세그먼트 트리에 대한 질의
int xsum(int ynum,int idx,int st,int ed,int l,int r){
    if(r<st||ed<l) return 0;
    if(l<=st&&ed<=r) return seg[ynum][idx];
    int mid = (st+ed)/2;
    return xsum(ynum,idx*2,st,mid,l,r)+xsum(ynum,idx*2+1,mid+1,ed,l,r);
}
//y세그먼트 트리에 대한 질의
int ysum(int idx,int st,int ed,int l,int r,int x1,int x2){
    if(r<st||ed<l) return 0;
    if(l<=st&&ed<=r) return xsum(idx,1,1,N,x1,x2);
    int mid = (st+ed)/2;
    return ysum(idx*2,st,mid,l,r,x1,x2)+ysum(idx*2+1,mid+1,ed,l,r,x1,x2);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>M;
    seg = vector<vector<int>>(N*4,vector<int>(N*4,0));
    for(int i = 1;i<=N;i++)
        for(int j = 1;j<=N;j++){
            cin>>arr[i][j];
            update(i,j,arr[i][j]);
        }
    
    for(int i = 0;i<M;i++){
        int a;cin>>a;
        if(a==0){
            int b,c,d;cin>>b>>c>>d;
            update(b,c,d);
        }else{
            int b,c,d,e;cin>>b>>c>>d>>e;
            cout<<ysum(1,1,N,c,e,b,d)<<"\n";
        }
    }
}