#include <iostream>
#include <algorithm>
#include <vector>
#define pii pair<int,int>
using namespace std;
int T,N;
int cnt[205] ,ccnt[205], fifth[205];
pii score[205];
vector<int> order;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>T;

    while(T--){
        order.clear();
        for(int i = 0;i<205;i++){
            cnt[i] = ccnt[i] = fifth[i] = 0;
            score[i] = {0 , i};
        }
        cin>>N;
        int s = 0;
        for(int i = 0;i<N;i++){
            int a;cin>>a;
            order.push_back(a);
            cnt[a]++;
            
        }

        for(int i = 0;i<order.size();i++){
            if(cnt[order[i]] < 6) continue;
            ccnt[order[i]]++;
            
            score[order[i]].first += ++s;
            if(ccnt[order[i]] > 4) score[order[i]].first -= s;
            if(ccnt[order[i]] == 5)
                fifth[order[i]] = s;
        }
        
        sort(score,score+205,[](pii & a , pii & b){
        if(a.first == b.first)
            return fifth[a.second] < fifth[b.second];
        return a.first < b.first;
        });

        for(int i = 0;i<205;i++){
            if(cnt[score[i].second] < 6 || score[i].first == 0)
                continue;
            
            cout<<score[i].second<<"\n";
            break;
        }
        
    }
    
    
}