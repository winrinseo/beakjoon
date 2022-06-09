#include <iostream>
#include <queue>
using namespace std;
int N;
struct cmp{
    bool operator()(int& a,int& b){
        if(abs(a)==abs(b)) return a>b;
        return abs(a)>abs(b);
    }
};

priority_queue<int,vector<int>,cmp>pq;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    for(int i = 0;i<N;i++){
        int a;cin>>a;
        if(a==0){
            if(pq.empty()) cout<<0<<"\n";
            else {
                cout<<pq.top()<<"\n";
                pq.pop();
            }
        }else{
            pq.push(a);
        }
    }
}