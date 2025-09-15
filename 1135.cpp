#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<int> adj[55];


int solve(int cur){

    vector<int> time;
    
    for(int & next : adj[cur]){
        int t = solve(next);
        time.push_back(t);
    }

    int ret = 0;

    sort(time.begin(),time.end(),[](int & a , int & b){
        return a > b;
    });

    for(int i = 0;i<time.size();i++){
        ret = max(ret , time[i] + i + 1);
    }
    return ret;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>N;

    for(int i = 0;i<N;i++){
        int a;cin>>a;

        if(a != -1)
            adj[a].push_back(i);
    }


    cout<<solve(0);

}