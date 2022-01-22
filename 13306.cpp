#include <iostream>
#include <vector>
using namespace std;
int N,Q;
int p[200020];
vector<vector<int>> query;
struct unionfind{
    int parent[200020];
    unionfind(){
        for(int i = 0;i<=200020;i++)
            parent[i] = i;
    }
    int find(int u){
        if(u==parent[u])
            return u;
        return parent[u] = find(parent[u]);
    }
    void merge(int u,int v){
        u = find(u), v = find(v);
        if(u==v) return;
        parent[u] = v;
    }
};
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>Q;
    unionfind uf;
    vector<string> answer;
    for(int i = 0;i<N-1;i++){
        cin>>p[i+2];
    }
    for(int i = 0;i<N-1+Q;i++){
        int a,b,c; cin>>a;
        if(a==0){
            cin>>b;
            query.push_back({a,b});
        }else{
            cin>>b>>c;
            query.push_back({a,b,c});
        }
    }
    //쿼리를 거꾸로 수행한다.
    for(int i = query.size()-1;i>=0;i--){
        if(query[i][0]==0){
            uf.merge(query[i][1],p[query[i][1]]);
        }else{
            if(uf.find(query[i][1])==uf.find(query[i][2]))
                answer.push_back("YES");
            else answer.push_back("NO");
        }
    }
    for(int i = answer.size()-1;i>=0;i--)
        cout<<answer[i]<<"\n";
}