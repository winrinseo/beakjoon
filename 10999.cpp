#include <iostream>
#include <vector>
using namespace std;
using ll =long long;
int N,M,K;
ll arr[1000005];
ll seg[4000005];
ll lazy[4000005];

ll init(int node , int st,int ed){
    if(st==ed)
        return seg[node] = arr[st];
    int mid = (st+ed)/2;
    return seg[node] = init(node*2,st,mid)+init(node*2+1,mid+1,ed);
}
void propagate(int node,int st,int ed){
    //lazy에 값이 있을 경우 실행
    if(lazy[node]!=0){
        //리프 노드가 아닐 경우
        if(st != ed){
            //자식들에게 lazy값을 미룸
            lazy[node*2] += lazy[node];
            lazy[node*2+1] += lazy[node];
        }
        seg[node] += (lazy[node]*(ed-st+1));
        lazy[node] = 0;
        return;
    }
}
//해당 구간에 모두 k를 더함
void upd(int node,int ns,int nd,ll k,int st,int ed){
    propagate(node,ns,nd);
    if(ed < ns||nd < st) return;
    if(st<=ns&&nd<=ed){
        lazy[node] += k;
        propagate(node,ns,nd);
        return;
    }
    int mid = (ns+nd)/2;
    upd(node*2,ns,mid,k,st,ed);
    upd(node*2+1,mid+1,nd,k,st,ed);
    //자식들을 이용해 자신의 값을 갱신
    seg[node] = seg[node*2]+seg[node*2+1];
}
ll add(int node,int ns,int nd,int st,int ed){
    propagate(node,ns,nd);
    if(ed < ns||nd < st) return 0;
    if(st<=ns&&nd<=ed) return seg[node];
    int mid = (ns+nd)/2;
    return add(node*2,ns,mid,st,ed) + add(node*2+1,mid+1,nd,st,ed);
}
int main(){
    cin>>N>>M>>K;
    for(int i =1;i<=N;i++){
        cin>>arr[i];
    }
    init(1,1,N);
    for(int i = 0;i<M+K;i++){
        int cmd; cin>>cmd;
        if(cmd==1){
            ll b,c,d;
            cin>>b>>c>>d;
            upd(1,1,N,d,b,c);
        }else if(cmd==2){
            int b,c;
            cin>>b>>c;
            cout<<(ll)add(1,1,N,b,c)<<'\n';
        }
    }
}