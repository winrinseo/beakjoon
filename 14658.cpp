#include <iostream>
#include <vector>
#include <algorithm>
#define pii pair<int,int>
using namespace std;

int N,M,L,K;
vector<pii> star; 
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>N>>M>>L>>K;

    for(int i = 0;i<K;i++){
        int a,b;cin>>a>>b;

        star.push_back({a,b});
    }

    sort(star.begin(),star.end());
    int answer = 0;
    for(int i = 0;i<star.size();i++){
        //트램펄린을 둘 y축 좌표
        vector<int> x;
        for(int j = i;j<star.size();j++){
            // 트램펄린과 y축이 겹친다면
            if(star[i].first + L >= star[j].first){
                x.push_back(star[j].second);
            }else break;
        }

        sort(x.begin(),x.end());
        
        for(int j = 0;j<x.size();j++){
            int cover = 0;
            //트램펄린을 둘 x축 좌표
            for(int k = j;k<x.size();k++){
                if(x[j] + L >= x[k]){
                    cover++;
                }else break;
            }

            answer = max(answer, cover);
        }

    }
    cout<<K - answer;

}