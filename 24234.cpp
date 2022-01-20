#include <iostream>
#include <map>
#include <vector>
using namespace std;
int N,Q;
int cnt[10005];

struct Trie{
    int cur = 0;
    map<int,pair<int,Trie*>> child;
};
void find(Trie* node,int prev,int pos,vector<int>& chess){
    if(pos==chess.size()) return;
    //기점의 수
    int point = 0;
    //자기 자신과 같은 기보를 제외한 모두 기점
    if(!node->child.count(chess[pos])){
        node->child[chess[pos]].first = 0;
        node->child[chess[pos]].second = new Trie();
    }
    
    point += node->cur;
    //자기 자신의 노드는 제외한다
    point -= node->child[chess[pos]].first;
    if(prev != -1) cnt[prev] += point;
    //해당 루트에 겹쳐있는 노드 수 증가
    node->child[chess[pos]].first++;
    //물고있는 자식 노드 수 증가
    node->cur++;
    find(node->child[chess[pos]].second,chess[pos],pos+1,chess);
    return;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>Q;

    Trie * root = new Trie();

    for(int i = 0;i<N;i++){
        int a;cin>>a;
        vector<int> s(a);
        for(int j = 0;j<a;j++) cin>>s[j];
        
        find(root,-1,0,s);
    }

    for(int i = 0;i<Q;i++){
        int a;cin>>a;
        cout<<cnt[a]<<"\n";
    }

}