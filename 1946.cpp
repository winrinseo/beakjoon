#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int T,N;
bool check[100005];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>T;

    while(T--){
        cin>>N;
        //a는 서류점수 오름차순 , b는 면접점수 오름차순
        vector<pair<int,int>> a,b;

        for(int i = 0;i<N;i++){
            int c , d;
            cin>>c >> d;
            a.push_back({c,d});
            b.push_back({c,d});
        }

        sort(a.begin() , a.end() , [](pair<int,int> & i , pair<int,int> & j){
            return i.first < j.first;
        });

        sort(b.begin() , b.end() , [](pair<int,int> & i , pair<int,int> & j){
            return i.second < j.second;
        });

        int answer = 0;

        //서류 기준 순서대로
        for(int i = 0;i<N;i++){
            //뽑혔거나 떨어졌거나
            if(check[a[i].first]) continue;
            check[a[i].first] = 1;
            answer++;

            //면접 점수가 해당 지원자보다 낮다면 두 점수 모두 해당 지원자보다 낮으니 탈락임

            while(b.back().second > a[i].second){
                check[b.back().first] = 1;
                b.pop_back();
            }

        }


        for(int i = 1;i<=N;i++){
            check[i] = 0;
        }

        cout<<answer<<"\n";
    }
}