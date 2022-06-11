#include <iostream>
#include <map>
#include <set>
using namespace std;
int N;
map<string,int> lot;
set<string> name;
int table[11][50005];
int cnt = 0;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    for(int i = 0; i<N;i++){
        string a,b;
        int f,t;
        cin>>a>>b>>f>>t;
        if(name.count(a)) continue;
        name.insert(a);
        if(!lot.count(b)) lot[b] = cnt++;
        table[lot[b]][f] += 1;
        table[lot[b]][t] -= 1;
    }
    for(int i = 0;i<cnt;i++){
        for(int j= 1;j<50005;j++){
            table[i][j] += table[i][j-1];
        }
    }
    string a;
    int c = 0;
    int answer[2];
    for(auto i = lot.begin();i!=lot.end();i++){
        int key = i->second;
        int lo = 1,hi = 1;
        while(hi<=50000){
            if(table[key][lo]!=table[key][hi]){
                if(c < table[key][lo]){
                    c = table[key][lo];
                    answer[0] = lo;
                    answer[1] = hi;
                    a = i->first;
                }
                lo = hi;
            }
            hi++;
        }
    }
    cout<<a<<" "<<answer[0]<<" "<<answer[1];
}