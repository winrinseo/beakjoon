#include <iostream>
#include <vector>

using namespace std;

int N;
string str;
vector<pair<char,int>> v;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>N>>str;
    v.push_back({str[0] , 1});
    for(int i = 1;i<N;i++){
        if(v[v.size()-1].first == str[i]){
            v[v.size()-1].second++;
        }else{
            v.push_back({str[i] , 1});
        }
    }


    int ans = N;
    //R
    int temp = 0;
    for(int i = 1;i<v.size();i++){
          if(v[i].first == 'R' && v[i].first != v[i-1].first)
            temp += v[i].second;
    }
    ans = min(ans , temp);
    temp = 0;
    for(int i = v.size()-2;i>=0;i--){
          if(v[i].first == 'R' && v[i].first != v[i+1].first)
            temp += v[i].second;
    }
    ans = min(ans , temp);

    //B
    temp = 0;
    for(int i = 1;i<v.size();i++){
          if(v[i].first == 'B' && v[i].first != v[i-1].first)
            temp += v[i].second;
    }
    ans = min(ans , temp);
    temp = 0;
    for(int i = v.size()-2;i>=0;i--){
          if(v[i].first == 'B' && v[i].first != v[i+1].first)
            temp += v[i].second;
    }
    ans = min(ans , temp);


    cout<<ans;

}