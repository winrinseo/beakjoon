#include <iostream>
#include <unordered_set>

using namespace std;

int N , M;
unordered_set<string> s;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>N>>M;

    for(int i = 0;i<N;i++){
        string a;cin>>a;
        s.insert(a);
    }

    for(int i = 0;i<M;i++){

        string a; cin>>a;
        string t;
        for(int j = 0;j<=a.size();j++){
            if(a[j] == ',' || j == a.size()){
                
                if(s.find(t) != s.end())
                    s.erase(t);

                t.clear();
            }else{
                t.push_back(a[j]);
            }
        }
        cout<<s.size()<<"\n";
    }
}