#include <iostream>
#include <unordered_map>

using namespace std;
int N;
unordered_map<string,int> map;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>N;

    for(int i = 0 ;i<N;i++){
        string a;cin>>a;
        int b;cin>>b;
        map[a] += b; 
    }

    string ans = "NO";

    for(auto m : map){
        if(m.second == 5) ans = "YES";
    }
    cout<<ans;
}