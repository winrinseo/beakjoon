#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int t, N, K, T, M;

int score[105][105];
int cnt[105];
int time[105];

struct team{
    int id , score , cnt , time;
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>t;

    while(t--){

        for(int i = 0;i<105;i++){
            cnt[i] = 0;
            time[i] = 0;
            for(int j = 0;j<105;j++){
                score[i][j] = 0;
            }
        }


        cin>>N>>K>>T>>M;

        for(int i = 0;i<M;i++){
            int a, b, c;
            cin>>a>>b>>c;

            score[a][b] = max(score[a][b] , c);
            cnt[a]++;
            time[a] = i+1;
        }

        vector<team> v;

        for(int i = 1 ;i<=N;i++){
            int sum = 0;
            for(int j = 1; j<=K; j++){
                sum += score[i][j];
            }


            v.push_back({ i , sum , cnt[i] , time[i]});

        }

        sort(v.begin() , v.end() , [](team & a , team & b){
            
            if(a.score == b.score){
                if(a.cnt == b.cnt){
                    return a.time < b.time;
                }
                return a.cnt < b.cnt;
            }
            return a.score > b.score;
        });

        for(int i = 0; i<N;i++){
            if(T == v[i].id){
                cout<<i + 1<<"\n";
                break;
            }
        }
    }
}