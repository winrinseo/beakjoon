#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

struct suki{
  int s;
  string name;  
};

int N,M,Q;
map<string,int> algo;

map<string, vector<suki>> member;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>N;

    for(int i = 0;i<N;i++){
        string a; int b;
        cin>>a>>b;

        algo[a] = b;
    }

    cin>>M;

    for(int i = 0;i<M;i++){
        string a; int b;
        cin>>a>>b;
        vector<suki> v;

        for(auto it = algo.begin();it != algo.end();it++){
            v.push_back({abs(b - it->second) , it->first});
        }

        sort(v.begin() , v.end() , [](suki & a , suki & b){
            if(a.s == b.s){
                return a.name < b.name;
            }
            return a.s < b.s;
        });
        member[a] = v;
    }

    cin>>Q;
    string name;
    for(int i = 0;i<Q;i++){
        string a,b,c;
        cin>>a>>b>>c;

        if(b == "-"){
            cout<<"hai!"<<"\n";
            name = a;
        }else{
            cout<<member[name][1].name <<" yori mo "<<member[name][0].name<<"\n";
        }
    }

}