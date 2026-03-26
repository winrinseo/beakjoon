#include <iostream>
#include <vector>
#define pii pair<int,int>
using namespace std;

int N,M;
vector<int> n;
vector<pii> col[100005];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>M;


    for(int i = 0;i<M;i++){
        int a;cin>>a;
        n.push_back(a);
    }

    int a,b;

    for(int j = 0;j<n[0]/2;j++){
        cin>>a>>b;
        
        col[0].push_back({a,b});
    }

    for(int i = 1;i<M;i++){
        
        for(int j = 0;j<n[i]/2;j++){
            cin>>a>>b;

            // 이전 수열과 겹치는 것만 포함
            for(int k = 0;k<col[i-1].size();k++){
                if(col[i-1][k].first <= b && col[i-1][k].second >= a){
                    col[i].push_back({a,b});
                    break;
                }
            }
        }
    }

    if(col[M-1].size() > 0) cout<<"YES";
    else cout<<"NO";
    
}