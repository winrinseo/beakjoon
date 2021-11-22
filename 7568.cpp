#include <iostream>
#include <vector>
using namespace std;
int N;
pair<int,int> p[55];
int seq[55];
int main(){
    ios::sync_with_stdio(0);
    cin.tie();
    cin>>N;
    for(int i = 0;i < N;i++){
        cin>>p[i].first>>p[i].second;
    }
    for(int i = 0;i < N;i++){
        int num = 0;
        for(int j = 0;j < N;j++){
            if(i==j) continue;
            //i보다 덩치가 크다면
            if(p[i].first < p[j].first&&p[i].second < p[j].second) num++;
        }
        seq[i] = num+1;
    }
    for(int i =0;i<N;i++)
        cout<<seq[i]<<" ";
}