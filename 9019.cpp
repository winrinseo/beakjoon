#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
string d = "DSLR";
int T;
//역추적, 해당 숫자에 몇번 명령으로 들어왔는지
int track[10000],dir[10000];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>T;
    while(T--){
        int s,t;cin>>s>>t;
        for(int i = 0;i<10000;i++){
            track[i] = -1,dir[i] = -1;
        }
        track[s] = -2, dir[s] = -2;

        queue<int> q;

        q.push(s);

        while(!q.empty()){
            int h = q.front();q.pop();
            if(h==t) break;
            for(int i = 0;i<4;i++){
                int next = h;
                if(i==0) {
                    next *=2;
                    next%=10000;
                }else if(i==1){
                    next-=1;
                    if(next<0) next = 9999;
                }else if(i==2){
                    int a = next/1000;
                    next = (next-a*1000)*10+a;
                }else{
                    int a = next%10;
                    next/=10;
                    next+=a*1000;
                }

                if(track[next]==-1){
                    track[next] = h;
                    dir[next] = i;
                    q.push(next);
                }
            }
        }
        string answer;
        for(int i = t; track[i]>=0;i = track[i]){
            answer.push_back(d[dir[i]]);
        }
        reverse(answer.begin(),answer.end());
        cout<<answer<<"\n";
    }

}