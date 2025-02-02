#include <iostream>
#include <vector>
#include <algorithm>
#define pii pair<int,string>

using namespace std;

int N,M;

vector<vector<pii>> v;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>N>>M;

    for(int i = 0;i<N;i++){
        int a;
        string b;

        cin>>a>>b;

        bool flag = false;

        for(int j = 0;j<v.size();j++){

            if(flag) break;

            if(v[j].size() >= M) continue;

            if(!v[j].empty() && ((v[j][0].first - 10) <= a && a <= (v[j][0].first + 10))){
                flag = true;

                v[j].push_back({a,b});
            }

        }

        if(!flag){
            v.push_back({{a,b}});
        }

    }
    
    for(int i = 0;i<v.size();i++){
        if(v[i].size() >= M){
            cout<<"Started!"<<"\n";
        }else{
            cout<<"Waiting!"<<"\n";
        }
        sort(v[i].begin() , v[i].end() , [](pii & a , pii & b){
            return a.second < b.second;
        });
        for(int j = 0;j<v[i].size();j++){
            cout<<v[i][j].first<<" "<<v[i][j].second<<"\n";
        }
    }

}