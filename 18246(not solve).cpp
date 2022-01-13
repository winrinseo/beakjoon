#include <iostream>
#include <algorithm>

using namespace std;
int N,M;
int H = 1;
int arr[1502][1502];
int seg[4600][4600];

void init(){
    for(int i = 0; i < 1501; i++){
      for(int j = 0; j < 1501; j++)
        seg[i+H][j+H] = arr[i][j];
    }
    // 바깥 Segment Tree의 leaf node인 Segment들에 대한 처리
    for(int i = H; i < 2*H; i++){
      for(int j = H-1; j > 0; j--) seg[i][j] = max(seg[i][j<<1],seg[i][j<<1|1]);
    }
    // 바깥 Segment Tree의 leaf node가 아닌 Segment들에 대한 처리
    for(int i = H-1; i > 0; i--){
      for(int j = 1; j < 2*H; j++){
        seg[i][j] = max(seg[i<<1][j],seg[i<<1|1][j]);
      }
    }
}
int xmax(int ynum,int idx,int st,int ed,int l,int r){
    if(r<st||ed<l) return -1;
    if(l<=st&&ed<=r) return seg[ynum][idx];
    int mid = (st+ed)/2;
    return max(xmax(ynum,idx*2,st,mid,l,r),
        xmax(ynum,idx*2+1,mid+1,ed,l,r));
}
int ymax(int idx,int st,int ed,int l,int r,int x1,int x2){
    if(r<st||ed<l) return -1;
    if(l<=st&&ed<=r) return xmax(idx,1,0,1500,x1,x2);
    int mid = (st+ed)/2;
    return max(ymax(idx*2,st,mid,l,r,x1,x2),
        ymax(idx*2+1,mid+1,ed,l,r,x1,x2));
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>M;
    while(H < 1501) H *= 2;

    for(int i = 0;i < N;i++){
        int y1,x1,y2,x2;
        cin>>y1>>x1>>y2>>x2;
        //imos, 입력과 출력이 일어나는 곳만 표시
        arr[y1][x1]++;
        arr[y1][x2]--;
        arr[y2][x1]--;
        arr[y2][x2]++;
    }
    //가로 방향 누적합
    for(int i = 0;i<1501;i++){
        for(int j = 1;j<1501;j++){
            arr[i][j] += arr[i][j-1];
        }
    }
    //세로 방향 누적합
    for(int j = 0;j<1501;j++){
        for(int i = 1;i<1501;i++){
            arr[i][j] += arr[i-1][j];
        }
    }
    init();
   for(int i = 0;i<M;i++){
        int y1,x1,y2,x2;
        cin>>y1>>x1>>y2>>x2;
        cout<<ymax(1,0,1500,y1,y2,x1,x2)<<"\n";
    }
}