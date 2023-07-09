#include <iostream>

using namespace std;
int N;

int maxw,maxh,hidx,widx;
int adj[6][2];
int line[6];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>N;
    
    for(int i = 0;i<6;i++){
        int a,b; cin>>a>>b;
        a--;

        if(a < 2){
            if(maxw < b){
                maxw = b; widx = i;
            }
        }else{
            if(maxh < b){
                maxh = b; hidx = i;
            }
        }
        adj[i][0] = (i-1+6)%6;
        adj[i][1] = (i+1)%6;
        line[i] = b;
    }
    int minsq = 1;
    for(int i = 0;i<6;i++){
        if(i == widx || i == hidx ) continue;
        if(adj[i][0] == widx ||adj[i][0] == hidx ||adj[i][1] == widx || adj[i][1] == hidx) continue;
        minsq *= line[i];
    }
    cout<<(maxh*maxw - minsq) * N;
}